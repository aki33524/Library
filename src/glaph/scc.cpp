#include "template.cpp"

class SCC{
private:
	int V;
	vector<vector<int>> G;
	vector<vector<int>> rG;
	vector<int> vs;
	vector<bool> used;
	vector<int> cmp;

	void dfs(int u){
		used[u] = true;
		for(int v: G[u]) if(!used[v])
			dfs(v);
		vs.push_back(u);
	}

	void rdfs(int u, int k){
		used[u] = true;
		cmp[u] = k;
		for(int v: rG[u]) if(!used[v])
			rdfs(v, k);
	}

public:
	SCC(int V): V(V){
		G.resize(V);
		rG.resize(V);
		vs.resize(V);
		used.resize(V); //fill(used.begin(), used.end(), false);
	}

	void add_edge(int from, int to){
		G[from].push_back(to);
		rG[to].push_back(from);
	}

	int solve(){
		fill(used.begin(), used.end, false);
		for(int i=0; i<V; i++) if(!used[i])
			dfs(i);

		fill(used.begin(), used.end, false);
		int k = 0;
		for(int i=vs.size()-1; i>=0; i--) if(!used[vs[i]])
			rdfs(vs[i], k++);
		return k;
	}
};
