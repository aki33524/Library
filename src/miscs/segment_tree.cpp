#include "../template.cpp"

class RMQ{
private:
    int N;
    vector<int> nodes;

    int query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l)
            return INF;
        if(a <= l && r <= b)
            return nodes[k];
        else{
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }

public:
    RMQ(int N_){
        N = 1;
        while(N < N_)
            N <<= 1;
        nodes.resize(2*N-1, INF);
    }

    void update(int k, int a){
        k += N - 1;
        nodes[k] = a;
        while(k > 0){
            k = (k - 1)/2;
            nodes[k] = min(nodes[k*2+1], nodes[k*2+2]);
        }
    }

    int query(int a, int b){
        return query(a, b, 0, 0, N);
    }
};
