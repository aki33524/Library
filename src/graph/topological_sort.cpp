#include "template.cpp"

class TopologicalSort{
private:
	enum Color{WHITE, GRAY, BLACK};
	vector<Color> colors;
	vector<int> res;
	vector<vector<int> > G;

	void dfs(int u, vector<int>& res){
		colors[u] = GRAY;
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(colors[v] == GRAY)
				is_dag = false;
			if(colors[v] == WHITE)
				dfs(v, res);
		}
		res.push_back(u);
		colors[u] = BLACK;
	}
public:
	bool is_dag;

	TopologicalSort(vector<vector<int> >& _G) : G(_G){
		colors.resize(G.size());
		fill(colors.begin(), colors.end(), WHITE);
		is_dag = false;
	}

	vector<int> get_ordered_sequence(){
		is_dag = true;
		for(int v = 0; v < G.size(); v++)
			if(colors[v] == WHITE)
				dfs(v, res);
		reverse(res.begin(), res.end());

		if(!is_dag){
			throw "this graph is not DAG!";
		}
		return res;
	}
};


