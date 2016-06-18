#include "union_find.cpp"

class Edge{
public:
	int from, to, cost;
	Edge(int from, int to, int cost) : from(from), to(to), cost(cost){};

	bool operator < (const Edge& right)const{
		return cost < right.cost;
	}
};

vector<Edge> kruskal(int V, vector<Edge>& edges){
	auto union_find = UnionFind(V);
	sort(edges.begin(), edges.end());
	vector<Edge> res;
	for(auto& edge: edges){
		if(union_find.unite(edge.from, edge.to)){
			res.push_back(edge);
		}
	}
	return res;
}
