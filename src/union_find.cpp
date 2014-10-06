int _par[MAX_N];
int _rank[MAX_N];

void init(int n){
    for(int i=0; i<n; i++){
        _par[i] = i;
        _rank[i] = 0;
    }
}

int root(int x){
    if(x == _par[x])
        return x;
    return _par[x] = root(_par[x]);
}

void unite(int x, int y){
    x = root(x);
    y = root(y);

    if(_rank[x] < _rank[y]){
        _par[x] = y;
    }else{
        _par[y] = x;
        if(_rank[x] == _rank[y])
            _rank[x]++;
    }
}

bool is_same_group(int x, int y){
    return root(x) == root(y);
}
