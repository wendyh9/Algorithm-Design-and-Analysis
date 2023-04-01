// author: Wendy Haw

#include <iostream>
#define MAX_N 21000
using namespace std;

// bellman-ford algorithm

// weighted edge
struct Edge{
    int source;
    int destination; 
    int weight;

    // default constructor
    Edge(){
        source = 0;
        destination = 0;
        weight = 0;
    }

    // custom constructor
    Edge(int source, int destination, int weight){
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }

    // destructor
    ~Edge(){}

};

struct Graph{
    int numVertices;
    int numEdges;

    struct Edge* edge;

    // default constructor
    Graph(){
        numVertices = 0;
        numEdges = 0;
    }

    // destructor
    ~Graph(){}
};

// create graph with given values of numVertices and numEdges 
struct Graph* createGraph(int numVertices, int numEdges){
    struct Graph* graph = new Graph;
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edge = new Edge[numEdges];

    return graph;
}

// initialize all distances as infinite
// make sure to pass distances by reference
void initializeSingleSource(Graph* graph, int distances[], int source){
    for (int i = 0; i < graph->numVertices; i++){
        distances[i] = MAX_N;
    }
    distances[source] = 0;
}

// relax each edge |numVertices| - 1 times
void relax(Graph* graph, int distances[]){
    int tempSource;
    int tempDestination;
    int tempWeight;

    for (int i = 1; i <= graph->numVertices - 1; i++)
        for (int j = 0; j < graph->numEdges; j++){
            tempSource = graph->edge[j].source;
            tempDestination = graph->edge[j].destination;
            tempWeight = graph->edge[j].weight;
            // if smaller weight is found
            // make sure distance is not infinity
            if ((distances[tempDestination] > (distances[tempSource] + tempWeight)) && distances[tempSource] != MAX_N){
                distances[tempDestination] = distances[tempSource] + tempWeight;
            }
        }
}

bool bellmanFord(Graph* graph, int source, int distances[]){    
    initializeSingleSource(graph, distances, source);

    relax(graph, distances);

    int tempSource;
    int tempDestination;
    int tempWeight;
    
    for (int i = 0; i < graph->numEdges; i++){
        tempSource = graph->edge[i].source;
        tempDestination = graph->edge[i].destination;
        tempWeight = graph->edge[i].weight;
        // if smaller weight is found
        // make sure distance is not infinity
        if ((distances[tempDestination] > (distances[tempSource] + tempWeight)) && distances[tempSource] != MAX_N){
            return false;
        }
    }
    return true;
}

int main(){

    int i;
    
    int numVertices;
    int numEdges;
    cin >> numVertices >> numEdges;

    // keeps track of distances from source to other vertices   
    int distances[numVertices];

    Graph* graph = createGraph(numVertices, numEdges);

    int tempSource;
    int tempDestination;
    int tempWeight;
    Edge tempEdge;

    // taking in input
    for (i = 0; i < numEdges; i++){
        cin >> tempSource >> tempDestination >> tempWeight;
        tempEdge = Edge(tempSource, tempDestination, tempWeight);
        graph->edge[i] = tempEdge;
    }
    
    bool exist = bellmanFord(graph, 0, distances);

    if (exist){
        cout << "TRUE" << endl;
        for (i = 0; i < numVertices; i++){
            if (distances[i] == MAX_N){
                cout << "INFINITY" << endl;
                continue;
            }
            cout << distances[i] << endl;
        }
    }
    else{
        cout << "FALSE" << endl;
    }

    return 0;
}