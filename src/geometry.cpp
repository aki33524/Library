#include "template.cpp"
typedef complex<double> pt;

//内積
double dot(complex<double> l, complex<double> r){
	return imag(conj(l)*r);
	//return l.real()*r.real() + l.imag()*r.imag();
}

//外積
double cross(complex<double> l, complex<double> r){
	return real(conj(l)*r);
   // return l.real()*r.imag() - l.imag()*r.real();
}

//反時計回り
bool ccw(complex<double> l, complex<double> r){
    int a = cross(l, r);
    if(a == 0)
    	//重なる場合は問題によって適切な設定を
        return false;
    else
        return a > 0;
}

//線分(s1, e1)と線分(s2, e2)の交差判定
bool cross_over(complex<double> s1, complex<double> e1, complex<double> s2, complex<double> e2){
	//ccwについては重なる場合どちらを指定していてもこの関数はfalseを返す
	return (ccw(e1-s1, s2-s1)^ccw(e1-s1, e2-s1)) && (ccw(e2-s2, s1-s2)^ccw(e2-s2, e1-s2));
}

//点pと直線(s, e)の距離
double disLP(complex<double> p, complex<double> s, complex<double> e){
	return abs(cross(e-s,p-s))/abs(e-s);
}

//点pと線分(s, e)の距離
double disSP(complex<double> p, complex<double> s, complex<double> e){
	if(dot(e-s, p-s)<=0)
		return abs(p-s);
	if(dot(e-s, p-e)<=0)
		return abs(p-e);
	return disLP(p, s, e);
}
