#include "template.cpp"

void dfs(vector<vector<int> >& G, int u, vector<int>& res, vector<bool>& used){
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!used[v])
			dfs(G, v, res, used);
	}
	res.push_back(u);
	used[u] = true;
}

vector<int> topological_sort(vector<vector<int> >& G, int s){
	vector<int> res;
	vector<bool> used(G.size(), false);
	dfs(G, s, res, used);
	reverse(res.begin(), res.end());
	return res;
}
