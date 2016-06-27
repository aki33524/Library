#include "template.cpp"

//素数まとめ
//llを付ける場所に注意

//エラトステネスの篩
//verified by UVA10139
vector<int> primes;
void sieve(int n){
	//n = 0xb504の時prime ** 2 < 2^31 - 1
	vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=0; i<n; i++){
        if(is_prime[i]){
        	primes.push_back(i);
        	for(int j=i*i; j<n; j+=i)
        	    is_prime[j] = false;
        }
    }
}

//n!がpで何回割れるか（pは素数）
//verified by UVA10139
int get_powers(int n, int p){
    int res = 0;
    for(ll power= p ; power<=n ; power*=p)
        res += n/power;
    return res;
}

//因数分解 sieveと併用すること
//verified by UVA10139
map<int, int> factorize(int n){
    map<int, int> res;
    int i = 0;
    while(ll(primes[i])*primes[i] <= n){
    	//割れない間スキップ
        while(ll(primes[i])*primes[i] <= n && n%primes[i]) i++;
        while(n%primes[i] == 0){
            n /= primes[i];
            res[primes[i]]++;
        }
    }
   if(n != 1) res[n]++;
   return res;
}
//verified by UVA10139
map<int, int> factorize(int n){
	map<int, int> res;
	for(int i=0; ll(primes[i])*primes[i]<=n; i++){
		while(n%primes[i] == 0){
			n /= primes[i];
			res[primes[i]]++;
		}
	}
	if(n != 1) res[n]++;
	return res;
}

//約数の和
//sum a^i+1 - 1 / a - 1
int sum_div(int n){
	int res = 0;
	int i = 0;
	while(ll(primes[i])*primes[i] <= n){
		while(n%primes[i]) i++;
		int power = 0;
		while(n%primes[i] == 0){
			n /= primes[i];
			power++;
		}
		res += ((ll)pow(primes[i], power+1)-1) / (primes[i]-1);
	}
	if (n != 1) res *= ((ll)pow(n, 2.0) - 1) / (n - 1);
	return res;
}

