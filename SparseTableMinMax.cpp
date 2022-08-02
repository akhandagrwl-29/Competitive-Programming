class sparseTable {
    int n  , k ;
    vector<int> log ;
    vector<vector<int>> st ;
public:
    sparseTable( int size , vector< int> &v) {
        n =  size ;
        k =  log2(size)  ;

        // Building sparse Table
        st.resize(n , vector<int>(k + 1)) ;
        for (int i = 0  ; i  < n ; i++) {
            st[i][0] = v[i] ;
        }
        for (int j =  1 ; j <= k ; j++) {
            for (int i = 0 ; i + (1 << j) <= n ; i++) {
                st[i][j] =  max(st[i][j - 1] , st[i + (1 << (j - 1 ))][j - 1]) ;
            }
        }

        // Pre - calculating log2 values
        log.resize(n + 1 ) ;
        log[1] = 0  ;
        for (int i = 2 ; i <= n ; i++) {
            log[i] = log[i / 2] + 1  ;
        }
    }
    // Range Minimum query -- [L , R]  (zero based indexing).
        int query(int l , int r) {
        int j =  log[r - l + 1 ] ;
        return max(st[l][j] , st[r - (1 << j) + 1 ][j]) ;
    }

};
