#include "template.cpp"


int det(complex<double> l, complex<double> r){
    return l.real()*r.imag() - l.imag()*r.real();
}

bool cmp1(const complex<double>& l, const complex<double>& r){
    if(l.imag() == r.imag())
        return l.real() < r.real();
    else
        return l.imag() < r.imag();
}

bool cmp2(const complex<double>& l, const complex<double>& r){
    int a = det(l, r);
    if(a == 0)
        return abs(l) < abs(r);
    else
        return a > 0;
}

vector<complex<double> > graham_scan(vector<complex<double> > v){
    sort(v.begin(), v.end(), cmp1);

    complex<double> p0 = v[0];
    for(int i=0; i<v.size(); i++)
        v[i] -= p0;

    sort(v.begin(), v.end(), cmp2);

    vector<complex<double> > gs(v.size());
    int k = 0;
    for(int i=0; i<v.size(); i++){
        while(k > 1 && det(gs[k-1]-gs[k-2], v[i]-gs[k-1]) <= 0) k--;
        gs[k++] = v[i];
    }
    gs.resize(k);

    for(int i=0; i<gs.size(); i++)
        gs[i] += p0;

    return gs;
}
