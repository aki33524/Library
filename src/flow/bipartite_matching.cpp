#include "template.cpp"

class BipartiteGraph{
private:
	int lV, rV;
	int V;
	vector<vector<int> > G;
	vector<int> match;
	vector<bool> used;

	bool dfs(int v){
		used[v] = true;
		for(int i=0; i<G[v].size(); i++){
			int u = G[v][i], w = match[u];
			if(w < 0 || (!used[w] && dfs(w))){
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
public:
	BipartiteGraph(int _lV, int _rV): lV(_lV), rV(_rV){
		V = rV + lV;
		G.resize(V);
		match.resize(V);
		used.resize(V);
	}

	void add_edge(int l, int r){
		r += lV;
		G[l].push_back(r);
		G[r].push_back(l);
	}

	int max_matching(){
		fill(match.begin(), match.end(), -1);
		int res = 0;
		for(int i=0; i<lV; i++){
			if(match[i] < 0){
				fill(used.begin(), used.end(), false);
				res += dfs(i);
			}
		}
		return res;
	}
};
