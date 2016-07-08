#include "template.cpp"
typedef double D;	  // 座標値の型。Dかlong Dを想定

struct P {
	D x, y, z;
	P(){}
	P(D x, D y, D z) : x(x), y(y), z(z) {}
};

istream& operator >>(istream &is, P &p){
	return is >> p.x >> p.y >> p.z;
}
ostream& operator <<(ostream &os, P&p){
	return os << "(" << p.x << " " << p.y << " " << p.z << ")";
}

P operator +(const P &a, const P &b) {
	return P(a.x+b.x, a.y+b.y, a.z+b.z);
}

P operator -(const P &a, const P &b) {
	return P(a.x-b.x, a.y-b.y, a.z-b.z);
}

D dot(const P &p, const P &q) {
	return p.x*q.x + p.y*q.y + p.z*q.z;
}

P cross(const P &a, const P &b) {
	return P(a.y*b.z - b.y*a.z, a.z*b.x - b.z*a.x, a.x*b.y - b.x*a.y);
}

D abs(const P &p) {
	return sqrt(dot(p, p));
}
