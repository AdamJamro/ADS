//
// Created by adame on 3/18/2023.
//

#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include "graph.h"


graph::~graph() {
    delete[] adjacency_list;
}

graph::graph(int _num_of_vertices) {
    this->num_of_vertices = _num_of_vertices + 1;
    this->adjacency_list = new std::list<int>[num_of_vertices];
}

graph::graph(std::fstream &read_stream) {
    if (!read_stream.is_open()) {
        throw std::exception();
    }

    std::string text;
    std::string direction; // D - directed, U - undirected
    std::string _num_of_vertices;
    std::string _num_of_edges;

    if (!getline(read_stream, direction))
        throw std::exception();
    if (!getline(read_stream, _num_of_vertices))
        throw std::exception();
    if (!getline(read_stream, _num_of_edges))
        throw std::exception();

    this->num_of_vertices = std::stoi(_num_of_vertices) + 1;
    this->adjacency_list = new std::list<int>[num_of_vertices];

    std::string delimiter = " ";

    while (getline(read_stream, text)) {
        int source = std::stoi(text.substr(0, text.find(delimiter)));
        text.erase(0, text.find(delimiter) + delimiter.length());
        int destination = std::stoi(text.substr(0, text.find(delimiter)));
        add_edge(source, destination);
        if (std::equal(direction.begin(), direction.end(), "U")){
            add_edge(destination, source);
        }
    }
}

int graph::nodes_quantity() {
    return num_of_vertices - 1;
}

void graph::add_edge(int x, int y) {
    adjacency_list[x].push_back(y);
}

void graph::DFS_util(int x, bool visited[]) {
    if (visited[x]) {
        return;
    }

    visited[x] = true;
    std::cout << x << " ";

    std::list<int>::iterator i;
    for (i = adjacency_list[x].begin() ; i != adjacency_list[x].end() ; i++) {
        if (!visited[*i]){
            DFS_util(*i, visited);
        }
    }
}

void graph::recursive_DFS() {
    bool *visited = new bool[num_of_vertices];
    for (int i = 0 ; i < num_of_vertices ; i++) {
        visited[i] = false;
    }

    for (int i = 0 ; i < num_of_vertices ; i++ ) {
        DFS_util(i , visited);
    }

    delete[] visited;
}

void graph::BFS(){
    BFS(false);
}


graph* graph::BFS(bool doTree) {
    graph* tree = nullptr;
    if (doTree) {
        tree = new graph(num_of_vertices - 1);
    }

    bool *visited = new bool[num_of_vertices];
    for (int i = 0 ; i < num_of_vertices ; i++) {
        visited[i] = false;
    }

    std::list<int> queue;


    for(int i = 1 ; i < num_of_vertices ; i++) {
        if (!visited[i]) {
            visited[i] = true;
            queue.push_back(i);

            std::list<int>::iterator iterator;
            int current;
            while ( !queue.empty() ) {
                current = queue.front();
                std::cout << current << " ";
                queue.pop_front();


                for (iterator = adjacency_list[current].begin() ; iterator != adjacency_list[current].end() ; ++iterator ) {
                    if (!visited[*iterator]) {
                        visited[*iterator] = true;
                        queue.push_back(*iterator);

                        if(tree != nullptr){
                            tree->add_edge(current, *iterator);
                        }
                    }
                }
            }
        }

    }

    std::cout<<std::endl;
    delete[] visited;
    return tree;
}

void graph::DFS(){
    DFS(false);
}

void graph::DFS(std::list<int>& ordering) {
    DFS(false, ordering);
}

graph* graph::DFS(bool doTree, std::list<int>& ordering) {
    graph* tree = nullptr;

    if (doTree) {
        tree = new graph(num_of_vertices - 1);
    }


    bool *visited = new bool[num_of_vertices];
    for (int i = 0 ; i < num_of_vertices ; i++) {
        visited[i] = false;
    }

    std::list<int> stack;


    for(int i = 1 ; i < num_of_vertices ; i++) {

        if (!visited[i]) {
            stack.push_front(i);


            std::list<int>::reverse_iterator riterator;
            while ( !stack.empty() ) {

                int current = stack.front();
                stack.pop_front();
                if ( visited[current] ){
                    continue;
                }


                ordering.push_back(current);
                visited[current] = true;

                for (riterator = adjacency_list[current].rbegin() ; riterator != adjacency_list[current].rend() ; riterator++) {
                    if (current >= num_of_vertices){
                        throw std::exception();
                    }
                    if (!visited[*riterator]) {
                        stack.push_front(*riterator);
                        if(tree != nullptr){
                            tree->adjacency_list[current].push_front(*riterator);
                        }
                    }
                }
            }
        }
    }


    std::cout<<std::endl;
    delete[] visited;
    return tree;
}

graph* graph::DFS(bool doTree) {
    graph* tree = nullptr;

    if (doTree) {
        tree = new graph(num_of_vertices - 1);
    }


    bool *visited = new bool[num_of_vertices];
    for (int i = 0 ; i < num_of_vertices ; i++) {
        visited[i] = false;
    }

    std::list<int> stack;


    for(int i = 1 ; i < num_of_vertices ; i++) {

        if (!visited[i]) {
            stack.push_front(i);


            std::list<int>::reverse_iterator riterator;
            while ( !stack.empty() ) {

                int current = stack.front();
                stack.pop_front();
                if ( visited[current] ){
                    continue;
                }


                std::cout << current << " ";
                visited[current] = true;

                for (riterator = adjacency_list[current].rbegin() ; riterator != adjacency_list[current].rend() ; riterator++) {
                    if (current >= num_of_vertices){
                        throw std::exception();
                    }
                    if (!visited[*riterator]) {
                        stack.push_front(*riterator);
                        if(tree != nullptr){
                            tree->adjacency_list[current].push_front(*riterator);
                        }
                    }
                }
            }
        }
    }


    std::cout<<std::endl;
    delete[] visited;
    return tree;
}

void graph::print_helper(int root, std::string depth, bool* visited, std::list<int> &ordering, bool print_to_std_out){
    if (visited[root]) {
        return;
    }
    if(print_to_std_out){
        std::cout << depth << "|__>" << root << std::endl;
    }
    visited[root] = true;
    ordering.push_back(root);

    depth = std::string("    ").append(depth);
    for ( auto iterator = adjacency_list[root].begin() ; iterator != adjacency_list[root].end() ; iterator++ ){
        print_helper(*iterator, depth, visited, ordering, print_to_std_out);
    }
}

std::list<int> graph::print(){
    print(true);
    std::list<int> empty_list;
    return empty_list;
}

std::list<int> graph::print(bool print_to_std_out){
    std::string depth;
    std::list<int> ordering;
    auto* visited = new bool[num_of_vertices];
    for (int i = 0 ; i < num_of_vertices ; i++) {
        visited[i] = false;
    }

    for( int i = 1 ; i < num_of_vertices ; i++){
        print_helper(i, depth, visited, ordering, print_to_std_out);
    }

    delete[] visited;
    return ordering;
}

int* graph::get_topological_sort(){
    auto* in_degrees = new int[num_of_vertices]; //in degrees of i
    int* top_sort = new int[num_of_vertices];
    int sort_index_pointer = 1;

    for ( int i = 1 ; i < num_of_vertices ; i++ ) {
        in_degrees[i] = 0;
        top_sort[i] = 0;
    }

    for (int i = 1 ; i < num_of_vertices ; i++) {
        for ( auto neighbor : adjacency_list[i] ) {
            in_degrees[neighbor] += 1;
        }
    }

    auto* nodes_with_zero_degree = new std::list<int>;
    for (int i = 1 ; i < num_of_vertices ; i++) {
        if (in_degrees[i] == 0){
            nodes_with_zero_degree->push_front(i);
        }
    }

    while (!nodes_with_zero_degree->empty()) {

        if(sort_index_pointer >= num_of_vertices){
            std::cout << "myexcept: out of bound" << std::endl;
            return nullptr;
        }

        auto current_node = nodes_with_zero_degree->front();
        top_sort[sort_index_pointer++] = current_node;
        nodes_with_zero_degree->pop_front();

        for (auto neighbor : adjacency_list[current_node]){
            in_degrees[neighbor] -= 1;
            if (in_degrees[neighbor] == 0){
                nodes_with_zero_degree->push_back(neighbor);
            }
        }

    }

    if (top_sort[num_of_vertices - 1] == 0){ //if last elem is 0
        std::cout << "cycle detected" << std::endl;
        return nullptr;
    }

//    for ( int i = 1 ; i < num_of_vertices ; i++){
//        std::cout << top_sort[i] << " ";
//    }
//    std::cout << std::endl;

    return top_sort;

}

graph* graph::transpose(graph* graph) {
    auto* transposed_graph = new class graph(graph->num_of_vertices - 1);

    for (int current = 0; current < graph->num_of_vertices; current++) {

        std::list<int>::iterator iterator;
        for (iterator = graph->adjacency_list[current].begin();
            graph->adjacency_list[current].end() != iterator;
            iterator++) {

            transposed_graph->adjacency_list[*iterator].push_back(current);
        }
    }
    return transposed_graph;
}


std::vector<std::vector<int>> graph::sccTarjan() {
    auto* index_val = new int[num_of_vertices];
    auto* low_link_val = new int[num_of_vertices];
    auto* is_on_stack = new bool[num_of_vertices];
    std::stack<int> stack;
    std::vector<std::vector<int>> components;

    for (int i = 0; i < num_of_vertices; i++) {
        index_val[i] = 0;
        low_link_val[i] = 0;
        is_on_stack[i] = false;
    }

    // begin the algorithm

    for (int i = 1; i < num_of_vertices; i++) {
        if (index_val[i] == 0) {
            tarjan_helper(i, index_val, low_link_val, stack, is_on_stack, components);
        }
    }


    delete[] index_val;
    delete[] low_link_val;
    delete[] is_on_stack;
    return components;
}


void graph::tarjan_helper(int i, int *index_val, int *low_link_val, std::stack<int>& stack, bool *is_on_stack, std::vector<std::vector<int>>& components) {
    static int id = 0;

    ++id;
    index_val[i] = id;
    low_link_val[i] = id;

    stack.push(i);
    is_on_stack[i] = true;

    // visit all neighbours and min low-link on callback
    for (auto iterator = adjacency_list[i].begin(); iterator != adjacency_list[i].end(); iterator++) {
        if (index_val[*iterator] == 0) {
            tarjan_helper(*iterator, index_val, low_link_val, stack, is_on_stack, components);
        }
        if (is_on_stack[*iterator]) {
            low_link_val[i] = std::min(low_link_val[i], low_link_val[*iterator]);
        }
    }

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

std::vector<std::vector<int>> graph::sccKosaraju() {

    std::vector<std::vector<int>> components;
    auto* stack = new std::stack<int>();


    auto* visited = new bool[num_of_vertices];
    for (int i = 0 ; i < num_of_vertices ; i++) {
        visited[i] = false;
    }

//    std::cout << "stack: ";
    for(int i = 1 ; i < num_of_vertices ; i++) {
        if (!visited[i]) {
            sccKosaraju_ordering_helper(i, visited, stack);
        }
    }
//    std::cout << "\n";


    auto* reverseGraph = transpose(this);

    for (int i = 0 ; i < num_of_vertices ; i++) {
        visited[i] = false;
    }

    while(!stack->empty()){
        int last_item_from_stack = stack->top();
        stack->pop();

        if (visited[last_item_from_stack]) {
            continue;
        }

//        reverseGraph.DFS_util(i, visited);

        std::vector<int> tmp_component;
        std::stack<int> dfs_helper_stack;
        dfs_helper_stack.push(last_item_from_stack);
//        auto dfs_helper_visited = new bool[num_of_vertices];


        while ( !dfs_helper_stack.empty() ) {

            int current = dfs_helper_stack.top();
            dfs_helper_stack.pop();
            if ( visited[current] ){
                continue;
            }


            tmp_component.push_back(current);
            visited[current] = true;

            for (auto iterator = reverseGraph->adjacency_list[current].begin() ; iterator != reverseGraph->adjacency_list[current].end() ; iterator++) {
                if (current >= num_of_vertices) {
                    throw std::exception();
                }
                if (!visited[*iterator]) {
                    dfs_helper_stack.push(*iterator);
                }
            }
        }
        components.push_back(tmp_component);
        tmp_component.clear();
    }

    delete stack;
    delete reverseGraph;
    delete[] visited;
    return components;
}

void graph::sccKosaraju_ordering_helper(int i, bool *visited, std::stack<int>* stack) {
    visited[i] = true;

    std::list<int>::reverse_iterator iterator;
    for (iterator = adjacency_list[i].rbegin(); iterator != adjacency_list[i].rend(); ++iterator) {
        if (!visited[*iterator]){
            sccKosaraju_ordering_helper(*iterator, visited, stack);
        }
    }
    stack->push(i);
//    std::cout<< i << " ";
}

std::vector<std::vector<int>> graph::bipartite_components(){
    auto* color = new char[num_of_vertices];
    auto* visited = new char[num_of_vertices];
    std::vector<std::vector<int>> components;
    components.resize(2);
    std::list<int> queue;

    for (int i = 0 ; i < num_of_vertices ; i++) {
        color[i] = '0';
        visited[i] = false;
    }


    std::vector<int> temp_component_red;
    std::vector<int> temp_component_blue;
    for (int i = 1 ; i < num_of_vertices ; i++) {


        queue.push_back(i);
        while ( !queue.empty() ) {

            int current = queue.front();
            queue.pop_front();

            if (color[current] == '0') {
                color[current] = 'R';
            }

            for (auto iterator = adjacency_list[current].begin(); iterator != adjacency_list[current].end() ; iterator++){
                if (color[*iterator] == '0') {
                    if (color[current] == 'R'){
                        color[*iterator] = 'B';
                        temp_component_blue.push_back(*iterator);
                    }
                    else if (color[current] == 'B') {
                        color[*iterator] = 'R';
                        temp_component_red.push_back(*iterator);
                    }
                }
                else if (color[*iterator] == color[current]) {
                    std::cout << "the graph is not bipartite!\n";
                    components.clear();
                    return components;
                }
            }
        }
    }
    if(!temp_component_red.empty()) {
        components.push_back(temp_component_red);
    }
    if(!temp_component_blue.empty()){
        components.push_back(temp_component_blue);
    }

    delete[] visited;
    delete[] color;
    return components;
}

std::list<int>* graph::get_adjacency_list() {
    return adjacency_list;
}

