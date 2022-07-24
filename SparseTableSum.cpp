class sparseTableSum {

    long long int n  , k ;
    vector<vector<long long int>> st ;

public:

    sparseTableSum(long long int size , vector<long long int> &v) {
        n =  size ;
        k =  log2(size)  ;

        // Building sparse Table
        st.resize(n , vector<long long int>(k + 1)) ;
        for (int i = 0  ; i  < n ; i++) {
            st[i][0] = v[i] ;
        }
        for (int j =  1 ; j <= k ; j++) {
            for (int i = 0 ; i + (1 << j) <= n ; i++) {
                st[i][j]=st[i][j - 1]+st[i + (1 << (j - 1))][j - 1] ;
            }
        }
    }

    // Range Sum query -- [L , R]  (zero based indexing).
    long long int sum(int l , int r) {
        long long int sum = 0  ;
        for (int j = k ; j >= 0 ; j--) {
            if ((1 << j) <= r - l + 1) {
                sum += st[l][j] ;
                l += 1 << j ;
            }
        }

        return sum ;
    }

};