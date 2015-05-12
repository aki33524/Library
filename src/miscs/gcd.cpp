#include "../template.cpp"

ll gcd(ll a, ll b){
    return b ? gcd(b, a%b) : a;
}

tuple<ll, ll> extgcd(ll a, ll b){
	if(b){
		ll x, y;
		tie(x, y) = extgcd(b, a%b);
		return make_tuple(y, x-a/b*y);
	}else{
		return make_tuple(1, 0);
	}
}
