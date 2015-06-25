#include "../template.cpp"

ll gcd(ll a, ll b){
	//__gcd(a, b)
    return b ? gcd(b, a%b) : a;
}

//ax + by = gcd(a, b)を満たすx, yを求める
tuple<ll, ll> extgcd(ll a, ll b){
	if(b){
		ll x, y;
		tie(x, y) = extgcd(b, a%b);
		return make_tuple(y, x-a/b*y);
	}else{
		return make_tuple(1, 0);
	}
}

//mod mにおけるaの逆元を求める
ll mod_inverse(int a, int m){
	if(gcd(a, m) != 1)
		return -1;
	ll x, y;
	tie(x, y) = extgcd(a, m);
	return (m + x%m) %m;
}
