#pragma once

#include <queue>
#include <vector>

namespace Moci {
    constexpr int INF = 1e9;
    using PII = std::pair<int, int>;

	class Graph {
    public:
        void addEdge(int from, int to, int cost);
        void dijkstra(int start);
        void print();

        explicit Graph(const int numVertex) :
			head(numVertex, -1),
			dis(numVertex, INF),
			numVertex(numVertex) {
        }

    private:
        struct Edge {
            int to, next, cost;
        };
        std::vector<Edge> edges{{0,0,0}};
        std::vector<int> head;
        std::vector<int> dis;
        int cnt{0};
		int numVertex;

    };
}

