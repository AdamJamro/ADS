#include <iostream>
#include <fstream>
#include "graph.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
//    graph gdfs(5);
//    gdfs.add_edge(0, 1);
//    gdfs.add_edge(0, 2);
//    gdfs.add_edge(0, 3);
//    gdfs.add_edge(1, 2);
//    gdfs.add_edge(2, 4);
//    gdfs.add_edge(3, 3);
//    gdfs.add_edge(4, 4);
//
//    std::cout << "Depth-first traversal for the given graph:"<<std::endl;
//    gdfs.DFS();
//    std::cout<<std::endl;
//
//    std::cout << "Breadth-first traversal for the given graph:"<<std::endl;
//    gdfs.BFS();
//    std::cout << std::endl;
//
//    std::cout << "iterative Depth-first traversal for the given graph:"<<std::endl;
//    gdfs.DFS();
//    std::cout << std::endl;


//// ZAD1  //// //// //// //// //// //// //// ////
    std::fstream file1;
    std::fstream file2;
    std::fstream file3;
    file1.open("../graph_aod_L0_1.txt");
    file2.open("../graph_aod_L0_2.txt");
    file3.open("../made_up_graph.txt");
    auto* graph1 = new graph(file1);
    auto* graph2 = new graph(file2);
    auto* custom_graph = new graph(file3);

    std::cout<<"graph no. 1, dfs: "<<std::endl;
    graph* tree1 = graph1->DFS(true);
    tree1->print();
    delete tree1;
    std::cout<<std::endl;
    std::cout<<"graph no. 1, bfs: "<<std::endl;
    graph* tree2 = graph1->BFS(true);
    tree2->print();
    delete tree2;
    std::cout<<std::endl;

    std::cout<<"graph no. 2, dfs: "<<std::endl;
    tree1 = graph2->DFS(true);
    tree1->print();
    delete tree1;
    std::cout<<std::endl;
    std::cout<<"graph no. 2, bfs: "<<std::endl;
    tree2 = graph2->BFS(true);
    tree2->print();
    delete tree2;
    std::cout<<std::endl;

    std::cout<<"custom graph, dfs: "<<std::endl;
    auto* tree3 = custom_graph->DFS(true);
    tree3->print();
    std::cout<<std::endl;
    std::cout<<"custom graph, bfs: "<<std::endl;
    auto* tree4 = custom_graph->BFS(true);
    tree4->print();
    std::cout<<std::endl;


    file1.close();
    file2.close();
    file3.close();
    delete graph1;
    delete graph2;
    delete custom_graph;


    return 0;
}

