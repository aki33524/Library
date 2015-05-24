#include "../template.cpp"

class Dice{
private:
	// 0-indexed
	// front right back left bottom top
	vector<int> face;

	//female
	int to_right[6][6] = {
			{-1, 3, 5, 3, 4, -1},
			{4, -1, 1, 6, -1, 3},
			{2, 6, -1, -1, 1, 5},
			{5, 1, -1, -1, 6, 2},
			{3, -1, 6, 1, -1, 4},
			{-1, 4, 2, 5, 3, -1}
	};

public:
	Dice(int t, int f, int r){
		face = vector(6);
		face[5] = t; face[4] = 7-t;
		face[0] = f; face[2] = 7-f;
		face[1] = r; face[3] = 7-r;
	}
	Dice(int t, int f){
		Dice(t, f, to_right[t-1][f-1]);
	}

	void rot(int dir){
	    int tmp = face[5];
	    face[5] = face[(dir+2)%4]; face[(dir+2)%4] = face[4];
	    face[4] = face[dir]; face[dir] = tmp;
	}
};
