#include "template.cpp"

class UnionFind{
private:
	vector<int> _root;
	vector<int> _rank;

public:
	UnionFind(int n){
		_root.resize(n);
		_rank.resize(n);
		for(int i=0; i<n; i++){
			_root[i] = i;
			_rank[i] = 0;
		}
	}

	int root(int x){
		if(_root[x] == x)
			return x;
		return _root[x] = root(_root[x]);
	}

	bool unite(int x, int y){
		if(is_same_group(x, y))
			return false;

		x = root(x);
		y = root(y);

		if(_rank[x] < _rank[y]){
			_root[x] = y;
		}else{
			_root[y] = x;
			if(_rank[x] == _rank[y])
				_rank[x]++;
		}
		return true;
	}

	bool is_same_group(int x, int y){
		return root(x) == root(y);
	}
};
