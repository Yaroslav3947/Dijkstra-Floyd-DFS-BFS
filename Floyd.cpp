#include <bits/stdc++.h>

const int DIM = 107;
const long long INF = INT_MAX;

long long n, start, finish;
long long distances[DIM][DIM];

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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            distances[i][j] = INF;
        }
        distances[i][i] = 0;
    }

    std::cout << "Input v1 - v1 and weight " << m << " times:\n";
    for (int i = 0; i < m; i++) {
        long long v1, v2, weight;
        std::cout << i + 1 << " ) ";
        std::cin >> v1 >> v2 >> weight;
        distances[v1][v2] = weight;
    }
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (distances[i][k] != INF && distances[k][j] != INF) {
                    distances[i][j] = std::min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }
}

void write_output() {
    std::cout << std::setw(4) << " ";
    for (int j = 1; j <= n; j++) {
        std::cout << std::setw(4) << j;
    }
    std::cout << '\n';

    for (int i = 1; i <= n; i++) {
        std::cout << std::setw(4) << i;
        for (int j = 1; j <= n; j++) {
            if (distances[i][j] == INF) {
                std::cout << std::setw(4) << "INF";
            } else {
                std::cout << std::setw(4) << distances[i][j];
            }
        }
        std::cout << '\n';
    }
}

int main() {
    read_input();
    floyd();
    write_output();

    return 0;
}
