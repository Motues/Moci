#include <main.hpp>

int main() {
	hello();

	Moci::Graph g{5};

	g.addEdge(0, 1, 2);
	g.addEdge(4, 2, 2);
	g.addEdge(1, 2, 3);
	g.addEdge(0, 4, 1);
	g.addEdge(2, 3, 1);
	g.dijkstra(0);

	std::cout << g;
	return 0;
}
