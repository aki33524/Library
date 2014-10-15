#include "template.cpp"

struct Edge{
    int to, cost;
};

vector<int> dijkstra(vector<vector<Edge> >& G, int s){
    int N = G.size();
    vector<int> d(N, INF);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    d[s] = 0;
    q.push(make_pair(d[s], s));

    while(!q.empty()){
        pair<int, int> v = q.top(); q.pop();
        if(v.first != d[v.second])
            continue;

        for(int i=0; i<G[v.second].size(); i++){
            Edge e = G[v.second][i];
            if(e.cost + d[v.second] < d[e.to]){
                d[e.to] = e.cost + d[v.second];
                q.push(make_pair(d[e.to], e.to));
            }
        }
    }
    return d;
}
