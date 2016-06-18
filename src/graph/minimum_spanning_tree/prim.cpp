#include "template.cpp"

class Edge{
public:
	int to, cost;
	Edge(int to, int cost): to(to), cost(cost){};

	bool operator > (const Edge& right) const{
		return cost > right.cost;
	}
};

vector<Edge> prim(vector<vector<Edge>>& G, int root){
	int V = G.size();
	vector<Edge> res;
	vector<bool> visited(V);
	priority_queue<Edge, vector<Edge>, greater<Edge>> queue;
	queue.push(Edge(root, 0));

	while(!queue.empty()){
		auto edge = queue.top(); queue.pop();
		if(visited[edge.to])
			continue;
		res.push_back(edge);
		visited[edge.to] = true;
		for(int i=0; i<G[edge.to].size(); i++){
			if(!visited[G[edge.to][i].to])
				queue.push(G[edge.to][i]);
		}
	}
	return res;
}

vector<Edge> prim(vector<vector<Edge>>& G){
	return prim(G, 0);
}
