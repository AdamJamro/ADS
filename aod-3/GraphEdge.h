#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <array>
#include "GraphNode.h"

using namespace std;
class GraphEdge {
private:
    int weight;
    GraphNode *Node1,*Node2;
public:
    GraphEdge( int weight,  GraphNode *Node1,  GraphNode *Node2);
    int getWeight() ;
    GraphNode *getNode1();
    GraphNode *getNode2();
    bool operator ==(GraphEdge *edge);
};
#endif //GRAPH_EDGE_H
