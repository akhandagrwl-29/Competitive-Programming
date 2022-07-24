class ArticAndBridges {
    vector<int> disc , low  , artic  ;
    vector<pair<int , int >> bridge ;
    int n , timer ;

public:

    ArticAndBridges(vector<vector<int>> &g) {
        n =  g.size() ;
        timer = 1 ;
        disc.resize(n , 0) ;
        low.resize(n) ;
        dfs(1 , 0 , g ) ;
    }

    void dfs(int v , int u , vector<vector<int>> &g) {
        disc[v] =  timer++ ;
        low[v] =  timer ;
        int cnt = 0 ;
        bool flag = 0 ;
        for (auto &x : g[v]) {
            if (!disc[x]) {
                if(u == 0)  cnt++ ;
                dfs(x , v , g) ;
                low[v] = min(low[v] , low[x]) ;

                // checking for v to be an articulation point
                if (u != 0 and low[x] >= disc[v]) {
                    flag = 1 ;
                }

                // checking for edge (v ---- x) to be a bridge.
                if (low[x] > disc[v]) {
                    bridge.push_back({v , x}) ;
                }
            }
            else if (x != u) {
                // #Backedge found , cycle found
                // updating low of current vertex.
                low[v] =  min(low[v] , disc[x]) ;
            }
        }

        // flag is true means current vertex is an Articulation point.
        if (flag) {
            artic.push_back(v) ;
        }

        // checking for root node to be an articulation point
        if (u == 0 and cnt > 1 ) {
            artic.push_back(v) ;
        }
    }

    vector<int> articulations() {
        return artic ;
    }

    vector<pair<int , int>> bridges() {
        return bridge ;
    }
};