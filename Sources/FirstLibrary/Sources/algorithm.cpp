#include <algorithm.hpp>
#include <iostream>

void Graph::addEdge(int from, int to, int cost) {
    Edge edge = {to, head[from], cost};
    edges.push_back(edge);
    head[from] = ++cnt;
}

void Graph::dijkstra(int start) {
    std::priority_queue<PII, std::vector<PII>, std::greater<PII> > q;
    std::vector<bool> vis;
    for(int i = 0; i < numVertex; i++) {
        dis[i] = INF;
        vis.push_back(false);
    }
    dis[start] = 0;
    q.push(std::make_pair(0,start));
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i = head[u]; i ; i = edges[i].next) {
            int v = edges[i].to;
            int cost = edges[i].cost;
            if(dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                if(!vis[v]) q.push(std::make_pair(dis[v], v));
            }
        }
    }
}

void Graph::print() {
    for(int i = 0; i < numVertex; i++) {
        std::cout << "dis[" << i << "] = " << dis[i] << std::endl;
    }
}