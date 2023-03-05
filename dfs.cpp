#include <stack>
#include <vector>
#include <iostream>

const int MAX_NODES = 100005;
std::vector<int> vec[MAX_NODES]; 
bool visited[MAX_NODES]; 


// void dfs_recursive(int start) {
//     visited[start] = true; 
//     cout << start << " "; 

//     for (int neighbor : graph[start]) {
//         if (!visited[neighbor]) {
//             dfs_recursive(neighbor);
//         }
//     }
// }

void dfs_stack(int start) {
    std::stack<int> s;
    s.push(start);
    visited[start] = true; 

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        std::cout << current << " "; 

        for (int neighbor : vec[current]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int num_nodes, num_edges;
    std::cin >> num_nodes >> num_edges; // кількість вершин, кількість ребер

    for (int i = 0; i < num_edges; i++) {
        int v1, v2;
        std::cin >> v1 >> v2;
        vec[v1].push_back(v2);
        vec[v2].push_back(v1); 
    }

    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }


    dfs_stack(0);

    return 0;
}