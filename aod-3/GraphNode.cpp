#include "GraphNode.h"
#include "GraphEdge.h"

GraphNode::GraphNode(int nodeIndex) {
    this->nodeIndex=nodeIndex;
}

std::vector<GraphEdge *> &GraphNode::getEdges()  {
    return edges;
}

void GraphNode::setEdges(const std::vector<GraphEdge *>& _edges) {
    GraphNode::edges = _edges;
}

void GraphNode::addEdge(int weight, GraphNode* node){
    GraphNode::edges.emplace_back(new GraphEdge(weight, this, node));
}

int GraphNode::getNodeIndex() const  {
    return nodeIndex;
}

GraphNode::~GraphNode() {
    for (auto edge : edges) {
        delete edge;
    }
}

