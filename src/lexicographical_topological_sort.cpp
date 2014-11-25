#include "template.cpp"

class LexicographicalTopologicalSort{
private:
	enum Color{WHITE, GRAY, BLACK};
	vector<Color> colors;
	vector<int> res;
	vector<vector<int> > G;

	vector<int> merge(vector<vector<int> >& vec){
		int s = 0;
		for(int i=0; i<vec.size(); i++){
			s += vec[i].size();
			vec[i].push_back(INF);
		}

		vector<int> ret;
		vector<int> indices(vec.size());
		while(--s){
			vector<int> v;
			for(int i=0; i<vec.size(); i++)
				v.push_back(vec[i][indices[i]++]);
			sort(v.begin(), v.end());
			ret += v;
		}
		return ret;
	}

	vector<int> dfs(int u){
		colors[u] = GRAY;

		vector<vector<int> > vec;
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(colors[v] == GRAY)
				is_dag = false;
			if(colors[v] == WHITE)
				vec.push_back(dfs(v));
		}
		vector<int> ret = merge(vec);
		ret.push_back(u);
		colors[u] = BLACK;
		return ret;
	}
public:
	bool is_dag;

	LexicographicalTopologicalSort(vector<vector<int> >& _G) : G(_G){
		colors.resize(G.size());
		fill(colors.begin(), colors.end(), WHITE);
		is_dag = true;
		vector<vector<int> > vec;
		for(int v = 0; v < G.size(); v++)
			if(colors[v] == WHITE)
				vec.push_back(dfs(v));
		res = merge(vec);
		reverse(res.begin(), res.end());
	}

	vector<int> get_ordered_sequence(){
		if(!is_dag){
			throw "this graph is not DAG!";
		}
		return res;
	}
};


