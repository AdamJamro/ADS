#include <iostream>
#include <fstream>
#include "Graph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//    std::vector<GraphNode> nodes;
//    nodes.emplace_back(1);
//    nodes.emplace_back(2);
//    nodes.emplace_back(3);
//    nodes.emplace_back(4);
//    nodes[0].addEdge(1, &nodes[1]);
//    nodes[0].addEdge(2, &nodes[2]);
//    nodes[2].addEdge(1, &nodes[3]);
//    nodes[1].addEdge(4, &nodes[3]);
//    nodes[0].addEdge(1, &nodes[1]);

//    Graph graph(nodes);
//    graph.dijkstra_algorithm(&nodes[0]);

    std::fstream file1;
    file1.open("../made_up_graph.txt");
    Graph graph(file1);
    graph.dijkstra_algorithm(graph.graphNodes.front());

    return 0;
}
