#include "template.cpp"

class Edge{
public:
	int to, cap, rev;
	Edge(int _to, int _cap, int _rev): to(_to), cap(_cap), rev(_rev){};
};

class FordFulkerson{
private:
	vector<vector<Edge>> G;
	vector<bool> used;

public:
	FordFulkerson(int n){
		G.resize(n);
		used.resize(n);
	}

	void add_edge(int from, int to, int cap){
		G[from].push_back(Edge(to, cap, G[to].size()));
		G[to].push_back(Edge(from, 0, G[from].size()-1));
	}

	int dfs(int v, int t, int f){
		if(v == t)
			return f;
		used[v] = true;
		for(int i=0; i<G[v].size(); i++){
			Edge& e = G[v][i];
			if(!used[e.to] && e.cap > 0){
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t){
		int res = 0;
		while(true){
			fill(used.begin(), used.end(), false);
			int f = dfs(s, t, INF);
			if(f == 0)
				return res;
			res += f;
		}
	}
};
