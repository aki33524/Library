#include "template.cpp"

struct Edge {
	int from, to, weight;
};

bool has_negative_cycle(int n, vector<Edge> edges, int s){
	// 0-indexed
	// n := number of vertexes

	vector<int> d(n, INF);
	//vector<int> par(n, -1); //parent

	d[s] = 0;
	int i;
	for(i=0; i<n; i++){
		bool updated = false;
		for(int j=0; j<edges.size(); j++){
			Edge& edge = edges[j];
			if(d[edge.from]+edge.weight < d[edge.to]){
				d[edge.to] = d[edge.from]+edge.weight;
				//par[edge.to] = edge.from;
				updated = true;
			}
		}
		if(!updated)
			break;
	}
	return i == n-1;
}
