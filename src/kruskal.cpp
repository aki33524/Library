#include "union_find.cpp"

class Edge{
public:
	int from, to, cost;
	Edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost){};

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
