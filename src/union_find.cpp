#include "template.cpp"

class UnionFind{
private:
	vector<int> __root;
	vector<int> __rank;

public:
	UnionFind(int n){
		__root.resize(n);
		__rank.resize(n);
		for(int i=0; i<n; i++){
			__root[i] = i;
			__rank[i] = 0;
		}
	}

	int root(int x){
		if(__root[x] == x)
			return x;
		return __root[x] = root(__root[x]);
	}

	void unite(int x, int y){
	    x = root(x);
	    y = root(y);

	    if(__rank[x] < __rank[y]){
	        __root[x] = y;
	    }else{
	    	__root[y] = x;
	        if(__rank[x] == __rank[y])
	        	__rank[x]++;
	    }
	}

	bool is_same_group(int x, int y){
	    return root(x) == root(y);
	}
};
