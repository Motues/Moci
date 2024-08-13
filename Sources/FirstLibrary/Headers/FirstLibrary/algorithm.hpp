#pragma once

#include <array>
#include <queue>
#include <vector>
#include <iostream>

namespace Moci {
    constexpr int INF = 1e9;
    using IntPair = std::pair<int, int>; // 感觉比 PII 更容易懂

	class Graph {
        struct Edge {
            int to, next, cost;
        };

        // 使用比较长的名称，更好地确定成员功能

        std::vector<Edge> EdgeList{{0,0,0}};
        std::vector<int> Head;
        std::vector<int> DistanceList;
        int cnt{0};
		int VertexCount;

    public:
        void addEdge(int from, int to, int cost);
        void dijkstra(int start);

        explicit Graph(int vertexCount);

        friend std::ostream& operator <<(std::ostream& stream, const Graph& graph);

        void print() const;
    };
}

