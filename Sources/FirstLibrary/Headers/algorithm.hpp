#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <queue>
#include <vector>

const int INF = 1e9;
typedef std::pair<int, int> PII;


class Graph {
    public:
        void addEdge(int from, int to, int cost);
        void dijkstra(int start);
        void print();
        Graph(int numVertex) : numVertex(numVertex), head(numVertex, -1), dis(numVertex, INF),cnt(0) {
            Edge edge = {0, 0, 0};
            edges.push_back(edge);
        };
    private:
        struct Edge {
            int to, next, cost;
        };
        std::vector<Edge> edges;
        std::vector<int> head;
        std::vector<int> dis;
        int cnt, numVertex;

};

#endif // ALGORITHM_HPP