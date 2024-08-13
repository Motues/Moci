#include <FirstLibrary/algorithm.hpp>

namespace Moci {
	void Graph::addEdge(const int from, const int to, const int cost) {
		auto& next = Head[from];	// 使用 auto& 指定变量别名
		EdgeList.push_back({to, next, cost});
		next = ++cnt;
	}

	/// @date 2024/8/13 Verified
	void Graph::dijkstra(int start) {
		/* 使用空行，将初始化和正式开始工作的逻辑略微分离一些 */
		std::priority_queue<IntPair, std::vector<IntPair>, std::greater<>> q{}; // 此处不必特化 std::greater
		std::vector<bool> visited(VertexCount, false); // std::vector<bool> 好像有特别优化，我不太确定，此类型不能随意使用引用，见下文 [!] 标注的地方
		std::fill(++DistanceList.begin(), DistanceList.end(), INF); // 使用 std::fill 初始化除了第一个元素之外的所有元素
		DistanceList[start] = 0;
		q.emplace(0, start); // 直接 emplace 构造 pair 并加入队列

		while (!q.empty()) {
			const int cur_vertex_id = q.top().second;
			q.pop();
			// auto& cur_vertex_is_visited = visited[cur_vertex_id]; // [!] 这句话因为 std::vector<bool> 的特别实现会导致很多问题
			if (visited[cur_vertex_id]) continue;
			visited[cur_vertex_id] = true;
			for (int edge_id = Head[cur_vertex_id]; edge_id >= 0; edge_id = EdgeList[edge_id].next) { // 写明循环条件
				const auto& to_vertex_id = EdgeList[edge_id].to;   // 如果使用 c++ 17，还可以使用结构化绑定简化变量声明
				const auto& cost = EdgeList[edge_id].cost;	// 不用担心引用是 64 位指针实现，而 int 只用 32 位，所以引用有额外性能损耗的问题，编译器会优化这个引用为 int 的的问题，编译器会优化这个引用为 int 的

				const auto& cur_distance = DistanceList[cur_vertex_id]; // 使用 auto& 指定变量别名，因为下文没有修改，所以加上 const
				auto& to_distance = DistanceList[to_vertex_id]; // 使用 auto& 指定变量别名

				if (to_distance <= cur_distance + cost) continue;
				to_distance = cur_distance + cost; // 稍微分开上下两段

				if (visited[to_vertex_id]) continue; // 能够使用 continue 避免把长内容塞进 if 的地方就尽量使用 continue
				q.emplace(to_distance, to_vertex_id);
			}
		}
	}

	Graph::Graph(const int vertexCount):
		Head(vertexCount, -1),
		DistanceList(vertexCount, INF),
		VertexCount(vertexCount) {}

	void Graph::print() const { std::cout << *this; }

	std::ostream& operator<<(std::ostream& stream, const Graph& graph) {
		for (int i = 0; i < graph.VertexCount; i++) {
			stream << "dis[" << i << "] = " << graph.DistanceList[i] << '\n';
		}
		return stream;
	}
}
