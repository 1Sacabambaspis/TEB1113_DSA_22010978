#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs_helper(char current, unordered_map<char, vector<char>>& graph, unordered_set<char>& visited) {
    visited.insert(current);
    cout << current << " ";

    for (char neighbor : graph[current]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs_helper(neighbor, graph, visited);
        }
    }
}

void dfs(char start, unordered_map<char, vector<char>>& graph) {
    unordered_set<char> visited;
    cout << "DFS Order: ";
    dfs_helper(start, graph, visited);
    cout << endl;
}

int main() {
    // Define the directed graph using adjacency list
    unordered_map<char, vector<char>> graph;

    // Add edges
    graph['B'] = {'A', 'D', 'E'};
    graph['A'] = {'B', 'C', 'D'};
    graph['C'] = {'A', 'D'};
    graph['D'] = {'A', 'B', 'C', 'D', 'E'}; // D has a self-loop
    graph['E'] = {'B', 'D'};

    // Start DFS from 'B'
    dfs('B', graph);

    return 0;
}

