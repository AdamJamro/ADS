#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H
#include <vector>
#include <optional>


//resolving a circular dependency by calling class GraphEdge instead of include "GraphEdge.h"
class GraphEdge;
class GraphNode {
private:
    std::vector<GraphEdge*> edges;
    int nodeIndex;
//    std::optional<GraphNode*> predecessor = {};

public:
    explicit GraphNode(int nodeIndex);
    ~GraphNode();
    std::vector<GraphEdge*>& getEdges();
    void setEdges(const std::vector<GraphEdge*> &edges);
    [[nodiscard]] int getNodeIndex() const;

    void addEdge(int weight, GraphNode *node);
};



#endif //GRAPHNODE_H
