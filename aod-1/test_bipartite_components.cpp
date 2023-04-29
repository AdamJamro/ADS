//
// Created by adame on 3/30/2023.
//

#include <iostream>
#include <fstream>
#include "graph.h"

int main() {
    std::vector<std::vector<int>> components;

    std::list<std::string> dictionary;
    dictionary.emplace_back("4/d4a-1.txt");
    dictionary.emplace_back("4/d4a-2.txt");
    dictionary.emplace_back("4/d4a-3.txt");
    dictionary.emplace_back("4/d4a-4.txt");
    dictionary.emplace_back("4/d4a-5.txt");
    dictionary.emplace_back("4/d4a-6.txt");

    dictionary.emplace_back("4/d4b-1.txt");
    dictionary.emplace_back("4/d4b-2.txt");
    dictionary.emplace_back("4/d4b-3.txt");
    dictionary.emplace_back("4/d4b-4.txt");
    dictionary.emplace_back("4/d4b-5.txt");
    dictionary.emplace_back("4/d4b-6.txt");

    dictionary.emplace_back("4/u4a-1.txt");
    dictionary.emplace_back("4/u4a-2.txt");
    dictionary.emplace_back("4/u4a-3.txt");
    dictionary.emplace_back("4/u4a-4.txt");
    dictionary.emplace_back("4/u4a-5.txt");
    dictionary.emplace_back("4/u4a-6.txt");

    dictionary.emplace_back("4/u4b-1.txt");
    dictionary.emplace_back("4/u4b-2.txt");
    dictionary.emplace_back("4/u4b-3.txt");
    dictionary.emplace_back("4/u4b-4.txt");
    dictionary.emplace_back("4/u4b-5.txt");
    dictionary.emplace_back("4/u4b-6.txt");

    do{
        std::fstream graph_bundle;
        std::string source = "../graphs/bundle";
        std::string result_file_destination = "../graphs/bundle";
        std::ofstream ResultFile(
                result_file_destination
                        .append(dictionary.front(), 0 , dictionary.front().size() - 4)
                        .append("_test_result.txt"));
        source.append(dictionary.front());
        dictionary.pop_front();

        std::cout << "testing " << source << std::endl;
        graph_bundle.open(source);
        auto* temp_graph = new graph(graph_bundle);
        graph_bundle.close();

        components = temp_graph->bipartite_components();
        delete temp_graph;



        int component_number = 1;
        for (auto component : components) {
            ResultFile << "component: " << component_number++ <<"\n";
            for ( auto val : component ) {
                ResultFile << val << " ";
            }
            ResultFile << std::endl;
            component.clear();
        }
        ResultFile << std::endl;
        components.clear();
    } while (!dictionary.empty());

    return 0;
}