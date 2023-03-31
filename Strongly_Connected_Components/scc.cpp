// author: Wendy Haw

#include <iostream>
#include <vector>
#include <stack>
#define MAX_N 21000
using namespace std;

struct Vertex{
    // SCC’s ID is defined as the smallest index of any vertex in the SCC
    // need to check if id is correct and adjust accordingly
    int id;

    // when vertex is first examined for adjacent vertices
    int startTime; 
    
    // when vertex is finished examined for ajdacent vertices
    int finishTime;
    
    // holds adjacent vertices
    vector<Vertex*> adjVertices;

    // default constructor
    Vertex(){
        id = 0;
        startTime = MAX_N;
    }

    // custom constructor
    Vertex(int id){
        this->id = id;
        startTime = MAX_N;
    }

    // destructor
    ~Vertex(){
        adjVertices.clear();
    }
};

stack<int> Stack;

struct Graph{
    vector<Vertex*> vertices;

    // default constructor
    Graph(){

    }

    // custom constructor
    Graph(int numVertices){
        vertices.resize(numVertices);
        
        for(int i = 0; i < numVertices; i++){
            vertices[i] = new Vertex(i);
        }
    }

    // destructor
    ~Graph(){
        vertices.clear();      
    }

    // looks for adjacent vertices and assign startTime, finishTime for individual vertex
    void DFS1(Vertex* vertex, int &time){
        vertex->startTime = time++;
        
        for(int i = 0; i < vertex->adjVertices.size(); i++){
            if(vertex->adjVertices[i]->startTime == MAX_N){
                DFS1(vertex->adjVertices[i], time);
            }
        }
        
        Stack.push(vertex->id);
        
        vertex->finishTime = time++;
    }

    // goes through each vertex in vertices to look for adjacent vertices
    void DFS2(){
        for(int i = 0; i < vertices.size(); i++){
            vertices[i]->startTime = MAX_N;
        }

        int time = 0;

        for(int i = 0; i < vertices.size(); i++){
            if(vertices[i]->startTime == MAX_N){
                DFS1(vertices[i], time);
            }
        }
    }

};

// finds SCC by using adjVertices (vertices that can potentially make up a SCC)
void findSCC(Vertex* vertex, vector<Vertex*> &SCC){
    vertex->startTime = 1;
    SCC.push_back(vertex);
    
    for(int i = 0; i < vertex->adjVertices.size(); i++){
        if(vertex->adjVertices[i]->startTime == MAX_N){
            findSCC(vertex->adjVertices[i], SCC);
        }
    }
}

// assigns id to vertice
int findID(vector<Vertex*> SCC){
    int id = MAX_N;
    
    for(int i = 0; i < SCC.size(); i++){
        if(SCC[i]->id < id){
            id = SCC[i]->id;
        }
    }
    
    return id;
}

// store id of each vertex in idArr
void storeID(vector<vector<Vertex*>> SCCgroup, int idArr[]){
    for(int i = 0; i < SCCgroup.size(); i++){
        int id = findID(SCCgroup[i]);
        for(int j = 0; j < SCCgroup[i].size(); j++){
            idArr[SCCgroup[i][j]->id] = id;
        }
    }    
}

int main(){
    
    int numVertices;
    int numEdges;
    cin >> numVertices >> numEdges;

    Graph graph(numVertices);
    Graph tPoseGraph(numVertices);

    int a, b;
    for(int i = 0; i < numEdges; i++){
        cin >> a >> b;
        graph.vertices[a]->adjVertices.push_back(graph.vertices[b]);
        tPoseGraph.vertices[b]->adjVertices.push_back(tPoseGraph.vertices[a]);
    }

    graph.DFS2();

    for(int i = 0; i < tPoseGraph.vertices.size(); i++){
        tPoseGraph.vertices[i]->startTime = MAX_N;
    }

    vector<vector<Vertex*>> SCCgroup;

    while(Stack.empty() == false){
        int temp = Stack.top();
        Stack.pop();
        if(tPoseGraph.vertices[temp]->startTime == MAX_N){
            vector<Vertex*> SCC;
            findSCC(tPoseGraph.vertices[temp], SCC);
            SCCgroup.push_back(SCC);
        }
    }

    // holds ids for each vertice
    int* idArr = new int[numVertices];

    storeID(SCCgroup, idArr);

    // print ids
    for(int i = 0; i < numVertices; i++){
        cout << idArr[i] << endl;
    }

    // deallocate heap memory used by arr
    delete[] idArr;

    return 0;
}