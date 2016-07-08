#include "template.cpp"

//pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p){
	return s << "(" << p.first << ", " << p.second << ")";
}
template<typename T1, typename T2> istream& operator>>(istream& s, const pair<T1, T2>& p){
	return s >> p.first >> p.second;
}

//vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v){
	int len = v.size();
	for (int i = 0; i < len; ++i){
		s << v[i]; if (i < len - 1) s << " ";
	}
	return s;
}
template<typename T> istream& operator>>(istream& s, vector<T>& v){
	for(auto &x: v) s >> x;
	return s;
}

//2次元vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv){
	for(auto v: vv)
		s << v << endl;
	return s;
}
