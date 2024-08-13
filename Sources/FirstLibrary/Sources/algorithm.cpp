#include <FirstLibrary/algorithm.hpp>

namespace Moci {
	void Graph::addEdge(int from, int to, int cost) {
		Edge edge = {to, head[from], cost};
		edges.push_back(edge);
		head[from] = ++cnt;
	}

	void Graph::dijkstra(int start) {
		std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
		std::vector<bool> vis;
		for (int i = 0; i < numVertex; i++) {
			dis[i] = INF;
			vis.push_back(false);
		}
		dis[start] = 0;
		q.push(std::make_pair(0, start));
		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
			if (vis[u]) continue;
			vis[u] = true;
			for (int i = head[u]; i; i = edges[i].next) {
				int v = edges[i].to;
				int cost = edges[i].cost;
				if (dis[v] > dis[u] + cost) {
					dis[v] = dis[u] + cost;
					if (!vis[v]) q.push(std::make_pair(dis[v], v));
				}
			}
		}
	}

	Graph::Graph(const int numVertex):
		head(numVertex, -1),
		dis(numVertex, INF),
		numVertex(numVertex) {
	}

	void Graph::print() const {
		std::cout << *this;
	}

	std::ostream& operator<<(std::ostream& stream, const Graph& graph) {
		for (int i = 0; i < graph.numVertex; i++) {
			stream << "dis[" << i << "] = " << graph.dis[i] << '\n';
		}
		return stream;
	}
}
