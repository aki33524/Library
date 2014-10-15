#include "template.cpp"

class Imos{
public:
	int H, W;
	vector<vector<int> > d;
public:
	Imos(vector<string>& field){
		H = field.size();
		W = field[0].size();
		d = vector<vector<int> >(H, vector<int>(W));
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				d[i][j] = field[i][j] - '0';
			}
		}
		for(int i=0; i<H-1; i++){
			for(int j=0; j<W; j++){
				d[i+1][j] += d[i][j];
			}
		}
		for(int j=0; j<W-1; j++){
			for(int i=0; i<H; i++){
				d[i][j+1] += d[i][j];
			}
		}
	}
	int area(int h1, int w1, int h2, int w2){
		//[h1, h2) and [w1, w2)
		int ret = 0;
		ret += d[h2-1][w2-1];
		ret -= h1 == 0 ? 0 : d[h1-1][w2-1];
		ret -= w1 == 0 ? 0 : d[h2-1][w1-1];
		ret += (h1 == 0 || w1 == 0) ? 0 : d[h1-1][w1-1];
		return ret;
	}
};
