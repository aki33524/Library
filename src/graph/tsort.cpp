#include "graph.h"

vector<int> tsort(const Graph &g){
    int n = g.size(), k = 0;
    vector<int> ord(n), in(n);
    for(auto &es : g) for(auto &e : es) in[e.dst]++;
    queue<int> q;
    for(int i = 0; i < n; ++i) if (in[i] == 0) q.push(i);
    while(q.size()){
        int v = q.front(); q.pop(); ord[k++] = v;
        for(auto &e : g[v]) if(--in[e.dst] == 0) q.push(e.dst);
    }
    return *max_element(in.begin(), in.end()) == 0 ? ord : {};
}

vector<int> tsort(const Graph &g){
    int n = g.size();
    vector<int> res, vis(n);
    function<bool(int)> dfs = [&](int v){
        vis[v] = true;
        for(auto &e : g[v]) if(!vis[e.dst] && !dfs(e.dst)) return false;
        res.push_back(v);
        return true;
    };
    for(int i = 0; i < n; ++i) if(!vis[i]) if(!dfs(i)) return {};
    reverse(res.begin(), res.end());
    return res;
}
