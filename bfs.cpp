#include <iostream>
#include <queue>
#include <vector>

const int MAXN = 100005;

std::vector<int> vec[MAXN];
bool visited[MAXN];

void bfs(int start) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        std::cout << curr << " ";

        for (auto neighbor : vec[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
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

    
    bfs(0); 

    return 0;
}