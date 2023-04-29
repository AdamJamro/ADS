//
// Created by adame on 3/29/2023.
//

#include <list>
#include <stack>
#include <vector>
#include "graph.h"

class tarjan_scc_solver {
private:
    static const int UNVISITED = -1;
    int num_of_vertices, id, num_of_components;
    std::list<int>* adjacency_list;
    bool solved = false;
    int *index_val, *low_link_val;
    bool* is_on_stack;
    std::stack<int> stack;
    std::vector<std::vector<int>> components;

    void solve() {

        id = 0;

        for (int i = 0; i < num_of_vertices; i++) {
            index_val[i] = UNVISITED;
            low_link_val[i] = UNVISITED;
            is_on_stack[i] = false;
        }


        //begin the algorithm

        for (int i = 1; i < num_of_vertices; i++) {
            if (index_val[i] == UNVISITED) {
                solve_helper(i);
            }
        }
        solved = true;
    }


    void solve_helper(int i) {
        ++id;
        index_val[i] = id;
        low_link_val[i] = id;

        stack.push(i);
        is_on_stack[i] = true;

        // visit all neighbours and min low-link on callback
        for (auto iterator = adjacency_list[i].begin(); iterator != adjacency_list[i].end(); iterator++) {
            if (index_val[*iterator] == UNVISITED) {
                solve_helper(*iterator);
            }
            if (is_on_stack[*iterator]) {
                low_link_val[i] = std::min(low_link_val[i], low_link_val[*iterator]);
            }
        }

        // create a component
        if(index_val[i] == low_link_val[i]) {
            std::vector<int> temp_component;
            int node;
            while (true) {
                node = stack.top();
                stack.pop();
                temp_component.push_back(node);
                is_on_stack[node] = false;
//            if (low_link_val[node] != index_val[i]) {
//                std::cout << "WTF" << std::endl;
//            }
                low_link_val[node] = index_val[i];
                if (node == i) break;
            }
            components.push_back(temp_component);
        }
    }



public:
    explicit tarjan_scc_solver(graph* graph){
        if (graph == nullptr) {
            throw std::invalid_argument("Graph cannot be null.");
        }

        num_of_vertices = 1 + graph->nodes_quantity();
        adjacency_list = graph->get_adjacency_list();

        index_val = new int[num_of_vertices];
        low_link_val = new int[num_of_vertices];
        is_on_stack = new bool[num_of_vertices];

    }

    std::vector<std::vector<int>> get_components() {
        if (!solved) solve();
        return components;
    }

    ~tarjan_scc_solver() {
        delete[] index_val;
        delete[] low_link_val;
        delete[] is_on_stack;
    }
};