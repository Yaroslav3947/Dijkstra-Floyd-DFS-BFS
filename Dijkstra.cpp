#include <bits/stdc++.h>

const int DIM = 100007;
const long long INF = INT_MAX;

typedef std::pair<long long, long long> pll;

std::vector<pll> vec[DIM];
std::priority_queue<pll, std::vector<pll>, std::greater<pll>> pq;

long long n, start, finish;
long long visited[DIM], distances[DIM], parents[DIM];

long long get(const std::string &message) {
    long long num;
    std::cout << "Enter " << message << ": ";
    std::cin >> num;
    return num;
}
void read_input() {
    long long m;
    n = get("number of nodes");
    m = get("number of edges");
    std::cout << "Input v1 - v1 and weight " << m << " times:\n";
    for (int i = 0; i < m; i++) {
        long long v1, v2, weight;
        std::cout << i + 1 << " ) ";
        std::cin >> v1 >> v2 >> weight;
        vec[v1].push_back({v2, weight});
        // vec[v2].push_back({v1, weight}); for not oriented graph
    }
    start = get("start");
    finish = get("finish"); 
}

void dijkstra() {
    long long current;

    for (int i = 1; i <= n; i++) {
        visited[i] = 0; // all unvisited
        distances[i] = INF; // all infinitive
        parents[i] = 0; // have no parents
    }

    distances[start] = 0; // from start to start 0
    pq.push({0, start}); 

    while (!pq.empty()) {
        current = pq.top().second; // take node
        pq.pop(); // pop pair

        if (visited[current] == true) continue; // if marked go to the another node

        visited[current] = true;

        for (auto x : vec[current]) { // relax all neighbor
            long long neighbor = x.first; // node
            long long weight = x.second;

            if (distances[current] + weight < distances[neighbor]) {
                distances[neighbor] = distances[current] + weight;
                parents[neighbor] = current;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }
}

// complexity n * log m + m
void print_path(long long node) {
    if (node == start) {
        std::cout << node;
        return;
    }
    print_path(parents[node]);
    std::cout << " -> " << node;
}

void write_output() {
    for(size_t i{1}; i <= n; i++) {
        std::cout << "from " << start << " to " << i << " : " << distances[i] << " | Path: ";
        if (distances[i] == INF) {
            std::cout << "No path";
        } else {
            print_path(i);
        }
        std::cout << '\n';
    }
}

int main() {
    read_input();
    dijkstra();
    write_output();

    return 0;
}
