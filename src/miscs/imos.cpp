#include "../template.cpp"

/*
 * 二次元累積和
 * 内部的には1-indexedで累積和を保持するが
 * 実際にareaで累積和を取得する時は終端開区間の0-indexed
 */

class Imos{
public:
	int H, W;

	//1-indexed
	vector<vector<int>> d;
public:
	Imos(vector<vector<int>>& field){
		H = field.size();
		W = field[0].size();
		d = vector<vector<int>>(H+1, vector<int>(W+1));

		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				d[i+1][j+1] = d[i+1][j] + d[i][j+1] - d[i][j] + field[i][j];
			}
		}
	}
	//0-indexed
	int area(int h1, int w1, int h2, int w2){
		//size of area s.t. [h1, h2) and [w1, w2)
		return d[h2][w2] - d[h2][w1] - d[h1][w2] + d[h1][w1];
	}
};
