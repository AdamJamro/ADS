//
// Created by adame on 27.04.2023.
//

#include <map>
#include <iostream>
#include <fstream>
#include "Graph.h"


int *Graph::dijkstra_algorithm(GraphNode* source) {

    auto* distanceFromSource = new int[num_of_vertices];
    auto* predecessors = new int[num_of_vertices];

    for (int i = 0 ; i < num_of_vertices ; i++) {
        predecessors[i] = -1;
    }

//    auto* edgesShortestPath = new vector<GraphEdge*>;

// rather a cumbersome way to declare a heap:
    auto cmp_nodes = [&](GraphNode* n1, GraphNode* n2)
            {return distanceFromSource[n1->getNodeIndex()]
             > distanceFromSource[n2->getNodeIndex()];};
    std::priority_queue<GraphNode*, vector<GraphNode*>, decltype(cmp_nodes)> heap(cmp_nodes);

    int source_index = source->getNodeIndex();
    distanceFromSource[source_index] = 0;
    predecessors[source_index] = source_index;

    for (int i = 1; i < source_index; i++)
        distanceFromSource[i] = INT32_MAX; // ..[..-1] cuz somebody thought numbering nodes from 1 instead of 0 is cool
    for (int i = source_index + 1; i < num_of_vertices; i++)
        distanceFromSource[i] = INT32_MAX;

    std::set<int> visited_indexes;

    heap.push(source);
    while (!heap.empty() && visited_indexes.size() < num_of_vertices) {
        auto* current_node = heap.top();
//        std::cout << "\nheap.top() = " << current_node->getNodeIndex() << "\n";
        heap.pop();

        for (auto const& edge: current_node->getEdges()){
            auto* neighbor = edge->getNode2();

            if (distanceFromSource[neighbor->getNodeIndex()] > distanceFromSource[current_node->getNodeIndex()] + edge->getWeight()) {
                distanceFromSource[neighbor->getNodeIndex()] = distanceFromSource[current_node->getNodeIndex()] + edge->getWeight();
                predecessors[neighbor->getNodeIndex()] = current_node->getNodeIndex();
            }

            if (visited_indexes.count(neighbor->getNodeIndex()) == 0){
                heap.push(neighbor);
            }
        }
    }
    for (int j = 0; j < num_of_vertices; ++j) {
        std::cout << "Path to Node " << j << ": ";
        printParents(j, source->getNodeIndex(), predecessors, distanceFromSource);
        std::cout << endl;
    }
    delete[](distanceFromSource);
//    delete[](predecessors);
//    return edgesShortestPath;
    return predecessors;
}

void Graph::printParents(int index, int sourceIndex, int *parentVertices, int* distanceFromSource) {
    if (distanceFromSource[index] > num_of_vertices){
        cout<< "does not exist";
        return;
    }

    if (index != sourceIndex) {
        printParents(parentVertices[index], sourceIndex, parentVertices, distanceFromSource);
        cout<<" -> ";
    }
    cout << index ;

}

Graph::Graph(std::fstream &read_stream) {
    if (!read_stream.is_open()) {
        throw std::exception();
    }

    std::string text;
    std::string _num_of_vertices;

    if (!getline(read_stream, _num_of_vertices))
        throw std::exception();

    this->num_of_vertices = std::stoi(_num_of_vertices);
    graphNodes.reserve(num_of_vertices);
    for (int i = 0 ; i < num_of_vertices ; i++ ) {
        graphNodes.push_back(new GraphNode(i));
    }

    auto adjacency_list = std::list<std::list<int>>(num_of_vertices);

    std::string delimiter = " ";

    while (getline(read_stream, text)) {
        int source = std::stoi(text.substr(0, text.find(delimiter))) - 1;
        text.erase(0, text.find(delimiter) + delimiter.length());

        int destination = std::stoi(text.substr(0, text.find(delimiter))) - 1;
        text.erase(0, text.find(delimiter) + delimiter.length());

        int weight = std::stoi(text.substr(0, text.find(delimiter)));

        graphNodes[source]->addEdge(weight, graphNodes[destination]);
    }
}


Graph::~Graph() {
    for ( auto node : graphNodes) {
        delete node;
    }
}

