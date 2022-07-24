class Primes {
    int n ;
    vector<bool> is_prime ;
public:
    Primes(int num) {
        n =  num ;
        is_prime.resize(n + 1  , true) ;
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (is_prime[i] && (long long)i * i <= n) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
    }

    isPrime(int num) {
        return is_prime[num] ;
    }
};