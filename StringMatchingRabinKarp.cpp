// Match the string s in given string t
class RabinCarp{
    const long long int p =  31 ;
    const long long int mod = 1e9 + 7  ;
    vector<long long int > pow, h ;
    long long int n , hash  ;

public:
    RabinCarp(string const &t){
        n =  t.length() ;
        pow.resize(n + 1) ;
        h.resize(n + 1 , 0 ) ;

        // Precalculating all the required powers of p ;
        pow[0] = 1;
        for(int i = 1 ; i <= n ; i++){
            pow[i] = (pow[i-1]*p)%mod ;
        }

        // Precalculating hash of the given text ;
        for(int i = 0  ; i < n ; i++){
            h[i+1] = (h[i] + (t[i] - 'a' + 1 )*pow[i])%mod ;
        }
    }

    vector<int> match(string const &s){
        vector<int> occr  ;
        if(s.length() > n)  return occr ;
        
        // Calculating hash of the given pattern..
        hash = 0  ;
        for(int i = 0 ;i < s.length() ; i++){
            hash  =  (hash + (s[i]- 'a' + 1 )*pow[i])%mod ;
        }

        // Now checking for every possible occurance of the pattern..
        // match at i iff , curr_hash/pow[i] == hash ==> curr_hash == hash*pow[i] ;
        for(int i = 0 ; i + s.length() -1 < n ; i++){
            long long int cur_hash = (h[i+s.length()] - h[i] + mod)%mod ;
            if(cur_hash == (hash*pow[i])%mod)   
                occr.push_back(i) ;
        } 

        return occr ;
    }

};