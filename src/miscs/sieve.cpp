#include "../template.cpp"

vector<int> sieve(int n){
    vector<int> primes;

    vector<bool> is_prime(n, true);
    is_prime[0] = false;

    for(int i=0; i<n; i++){
        if(is_prime[i]){
            primes.push_back(i+1);
            for(int j=2*i+1; j<n; j+=i+1)
                is_prime[j] = false;
        }
    }
    return primes;
}


vector<bool> sieve(int n){
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=0; i<n; i++){
        if(is_prime[i]){
            for(int j=2*i; j<n; j+=i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}
