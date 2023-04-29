//
// Created by adame on 27.04.2023.
//

#ifndef UNTITLED1_GRAPH_H
#define UNTITLED1_GRAPH_H


#include <utility>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <string>
#include <climits>
#include <queue>
#include "GraphNode.h"
#include "GraphEdge.h"

//typedef unordered_map<GraphNode* ,vector<GraphEdge*>> AdjacencyList;
//typedef vector<vector<int>> AdjacencyMatrix;

class Graph {

    int num_of_vertices;
public:
    [[maybe_unused]] explicit Graph(std::vector<GraphNode*> &_v) : graphNodes(_v) {
        num_of_vertices = static_cast<int>(graphNodes.size());
    };

    ~Graph();

    std::vector<GraphNode*> graphNodes;

    int* dijkstra_algorithm(GraphNode*);

    void printParents(int index, int sourceIndex, int *parentVertices);

    Graph(fstream &read_stream);

    void printParents(int index, int sourceIndex, int *parentVertices, int *distanceFromSource);
};


#endif //UNTITLED1_GRAPH_H
