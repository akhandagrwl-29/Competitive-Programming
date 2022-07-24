class TravSales {
    vector<vector<int>> g , dp;
    int allVis , n ;

public:

    TravSales(vector<vector<int>> &v) {
        g = v ;
        n = v.size()  ;
        allVis = ( 1 << n ) - 1  ;
        dp.resize( (1 << n)  , vector<int>(n , -1)) ;
        dp[1][0] = tsp(1 , 0) ;
    }
    int tsp(int vis , int u) {
        if (vis == allVis) {
            return dp[vis][u] = g[u][0] ;
        }

        if (dp[vis][u] != -1)
            return dp[vis][u] ;

        int ans = INT_MAX ;

        for (int v = 0 ; v < n ; v++) {
            if ((vis & (1 << v)) == 0) {
                int num  = g[u][v] +  tsp( (vis | (1 << v)) , v ) ;
                ans  = min(ans , num)  ;
            }
        }

        return dp[vis][u] =  ans  ;
    }

    int ans() {
        return dp[1][0] ;
    }

};