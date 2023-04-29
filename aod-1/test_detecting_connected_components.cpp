//
// Created by adame on 3/28/2023.
//

#include <iostream>
#include <fstream>
#include "tarjan_scc_solver.cpp"
#include "graph.h"


int main() {
    //// ZAD 3 //// //// //// //// ////

    std::vector<std::vector<int>> components;

    std::list<std::string> dictionary;
    dictionary.emplace_back("3/debug_test.txt");
    dictionary.emplace_back("3/g3-1.txt");
    dictionary.emplace_back("3/g3-2.txt");
    dictionary.emplace_back("3/g3-3.txt");
    dictionary.emplace_back("3/g3-4.txt");
    dictionary.emplace_back("3/g3-5.txt");
    dictionary.emplace_back("3/g3-6.txt");
    dictionary.emplace_back("3/test_graph_connected.txt");
    dictionary.emplace_back("3/test_graph_strongly_connected.txt");
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

//        components = temp_graph->sccKosaraju();
//        components = temp_graph->sccTarjan();
        tarjan_scc_solver* solver = new tarjan_scc_solver(temp_graph);
        components = solver->get_components();

        delete temp_graph;
        delete solver;
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
//    dictionary.emplace_back("2/g2b-3.txt");

    return 0;
}