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

class UnionFind {
    vector<int> par;
    int cnt;
public:
    UnionFind(int size_) : par(size_, -1), cnt(size_) { }
    void unite(int x, int y){
        if ((x = find(x)) != (y = find(y))) {
            if (par[y] < par[x]) swap(x, y);
            par[x] += par[y]; par[y] = x; cnt--;
        }
    }
    bool same(int x, int y){ return find(x) == find(y); }
    int find(int x){ return par[x] < 0 ? x : par[x] = find(par[x]); }
    int size(int x){ return -par[find(x)]; }
    int size(){ return cnt; }
};
