#include "template.cpp"

vector<int> compress(vector<int> xs){
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    vector<int> ixs;
    for(auto v: xs)
        ixs.push_back(v);
    return ixs;
}

//全順序であることが重要で、その順序への単射と考える
//これは別段座標に限定すべき問題ではない
template<class T>
vector<T> compress(vector<T> values){
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());

    vector<T> images;
    for(auto v: values)
    	images.push_back(v);
    return images;
}
