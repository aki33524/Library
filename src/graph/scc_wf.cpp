#include "template.cpp"

vector<int> scc(vector<vector<bool>> E){
	int N = E.size();
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				E[i][j] |= (E[i][k] & E[k][j]);

	vector<int> colors(N, -1);
	int color = 0;
	for(int i=0; i<N; i++) if(colors[i]<0){
		for(int j=0; j<N; j++) if(E[i][j] && E[j][i])
			colors[j] = color;
		color++;
	}
	return colors;
}
