#include "template.cpp"

// 1-indexed
class BIT{
private:
	vector<int> bit;

public:
	BIT(int n){
		bit.resize(n);
	}

	int sum(int i){
		int s = 0;
		while(i > 0){
			s += bit[i];
			i -= i&-i;
		}
		return s;
	}

	void add(int i, int v){
		while(i <= bit.size()){
			bit[i] += v;
			i += i&-1;
		}
	}
};
