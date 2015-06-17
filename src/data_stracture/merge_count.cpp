#include "../template.cpp"

long long int merge_count(vector<int> &A){
    int n = A.size();
    if(n <= 1)
        return 0;

    vector<int> L(A.begin(), A.begin()+n/2);
    vector<int> R(A.begin()+n/2, A.end());

    long long int cnt = merge_count(L) + merge_count(R);

    L.push_back(INF); R.push_back(INF);
    int li = 0, ri = 0, ai = 0;
    while(ai<n){
        if(L[li] <= R[ri]){
            A[ai++] = L[li++];
        }else{
            cnt += L.size()-1 - li;
            A[ai++] = R[ri++];
        }
    }
    return cnt;
}
