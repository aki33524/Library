#include "template.cpp"

class TopologicalSort{
private:
	enum Color{WHITE, GRAY, BLACK};
	vector<Color> colors;

	void dfs(vector<vector<int> >& G, int u, vector<int>& res){
		colors[u] = GRAY;
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(colors[v] == GRAY)
				is_dag = false;
			if(colors[v] == WHITE)
				dfs(G, v, res);
		}
		res.push_back(u);
		colors[u] = BLACK;
	}
public:
	bool is_dag;

	vector<int> topological_sort(vector<vector<int> >& G){
		vector<int> res;
		colors.resize(G.size());
		fill(colors.begin(), colors.end(), WHITE);
		is_dag = true;
		for(int v = 0; v < G.size(); v++)
			if(colors[v] == WHITE)
				dfs(G, v, res);
		reverse(res.begin(), res.end());
		return res;
	}
};


