//
// Created by adame on 3/18/2023.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

class graph {
    // the key is to bear in mind that there are num_of_vertices + 1 vertices
    // (in my impl I added a 0 vertex that is separated from the graph just so to don't toil with any index shifting)
    // since graphs we're interested in class are such that begin from vertex 1 and go on to some n
    int num_of_vertices;
    std::list<int> *adjacency_list;
    void print_helper(int, std::string, bool*, std::list<int>&, bool);
    void sccKosaraju_ordering_helper(int i, bool *visited, std::stack<int>* stack);
    void tarjan_helper(int i, int *index_vals, int *low_link_vals, std::stack<int>& stack, bool *is_on_stack, std::vector<std::vector<int>>& components);
    void DFS_util(int, bool*);

public:
    explicit graph(int);
    explicit graph(std::fstream &);
    ~graph();
    void DFS();
    void DFS(std::list<int>&);
    graph* DFS(bool);
    graph* DFS(bool, std::list<int>&);
    void BFS();
    graph* BFS(bool);
    void add_edge(int x, int y);
    void recursive_DFS();
    std::list<int> print();
    int* get_topological_sort();
    int nodes_quantity();
    std::vector<std::vector<int>> sccKosaraju();
    std::vector<std::vector<int>> sccTarjan();
    std::list<int> print(bool print_to_std_out);
    static graph* transpose(graph *graph);

    std::list<int>* get_adjacency_list();

    std::vector<std::vector<int>> bipartite_components();
};




#endif //GRAPH_H
