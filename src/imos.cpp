#include "template.cpp"

class Imos{
public:
	int H, W;
	vector<vector<int> > d;
public:
	Imos(vector<string>& field){
		H = field.size();
		W = field[0].size();
		d = vector<vector<int> >(H+1, vector<int>(W+1));

		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				d[i+1][j+1] = d[i+1][j] + d[i][j+1] - d[i][j] + field[i][j]-'0';
			}
		}
	}
	int area(int h1, int w1, int h2, int w2){
		//1-indexed, size of area s.t. [h1, h2) and [w1, w2)
		return d[h2][w2] - d[h2][w1] - d[h1][w2] + d[h1][w1];
	}
};
