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

vector<int> topological_sort(vector<vector<int> >& G){
	vector<int> res;
	vector<bool> used(G.size(), false);
	for(int v = 0; v < G.size(); v++)
		if(!used[v])
			dfs(G, v, res, used);
	reverse(res.begin(), res.end());
	return res;
}
