//
// Created by adame on 3/28/2023.
//

#include <iostream>
#include <fstream>
#include "graph.h"

int main() {
    //// ZAD 2 //// //// //// //// ////

    std::fstream abctest;
    abctest.open("../graphs/bundle2/g2a-1.txt");
    auto* abc = new graph(abctest);
    auto* top_test_sort = abc->get_topological_sort();
    for (int i = 0; i < abc->nodes_quantity(); i++ ){
        std::cout << top_test_sort[i + 1] << " ";
    }
    std::cout << std::endl;
    abctest.close();
    delete abc;
    delete top_test_sort;

    std::list<std::string> dictionary;
    dictionary.emplace_back("2/g2a-1.txt");
    dictionary.emplace_back("2/g2a-2.txt");
    dictionary.emplace_back("2/g2a-3.txt");
    dictionary.emplace_back("2/g2a-4.txt");
    dictionary.emplace_back("2/g2a-5.txt");
    dictionary.emplace_back("2/g2a-6.txt");
    dictionary.emplace_back("2/g2b-1.txt");
    dictionary.emplace_back("2/g2b-2.txt");
    dictionary.emplace_back("2/g2b-3.txt");
    dictionary.emplace_back("2/g2b-4.txt");
    dictionary.emplace_back("2/g2b-5.txt");
    dictionary.emplace_back("2/g2b-6.txt");
    do{
        std::fstream graph_bundle;
        std::string source = "../graphs/bundle";
        std::string destination = "../graphs/bundle";
        std::ofstream result_file(destination.append(dictionary.front(), 0 , dictionary.front().size() - 4).append("_test_result.txt"));
        source.append(dictionary.front());
        dictionary.pop_front();

        std::cout << "testing " << source << std::endl;
        graph_bundle.open(source);
        auto* temp_graph = new graph(graph_bundle);
        auto top_sort = temp_graph->get_topological_sort();
        graph_bundle.close();

        if (top_sort != nullptr){
            std::cout << "Test successful (no cycles detected)" << std::endl;
            result_file << "Test successful (no cycles detected). Printing topological sort:" << std::endl;

            for (int i = 0; i < temp_graph->nodes_quantity(); i++ ){
//                std::cout << top_sort[i + 1] << " ";
                result_file << top_sort[i + 1] << " ";
            }
        }
        else {
            result_file << "Invalid input. Cycle detected!" << std::endl;
        }


        delete top_sort;
        std::cout << std::endl;

    } while (!dictionary.empty());


    return 0;
}