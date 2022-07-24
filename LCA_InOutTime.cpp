// Lca using timein and timeout
class __Lca {
    const int  M = 30 ;
    int n  , timer;
    vector<int> tin , tout ;
    vector<vector<int>> parent ;

public:
    __Lca(vector<vector<int>> &g) {
        n = g.size() ;
        tin.resize(n) ;
        tout.resize(n) ;
        parent.resize(n , vector<int>(M)) ;

        timer =  0 ;
        tin[0] = 0 ;		// Universal time_in
        tout[0] = n + 1  ;	// Universal time_out
        dfs(1, 0 , g) ;
        cal_sparse(1 , 0 , g) ;
    }

    void dfs(int v, int u , vector<vector<int>> &g) {
        tin[v] = ++timer ;
        for (auto &x : g[v]) {
            if (x != u) {
                dfs(x , v , g) ;
            }
        }
        tout[v] =  timer ;
        return ;
    }

    void cal_sparse(int v , int u , vector<vector<int>> &g) {
        parent[v][0] = u ;
        for (int j =  1 ; j < M ; j++) {
            parent[v][j] =  parent[parent[v][j - 1]][j - 1] ;
        }

        for (auto &x : g[v]) {
            if (x != u) {
                cal_sparse(x , v , g) ;
            }
        }
        return ;
    }

    bool is_ancestor(int u , int v) {
        // check whether u is an ancestor of v or not.
        return tin[u] <= tin[v] && tout[u] >= tout[v] ;
    }

    int lca(int u , int v) {
        if (is_ancestor(u , v))	return u ;
        if (is_ancestor(v , u)) 	return v ;

        for (int i =  M - 1  ; i >= 0 ; i--) {
            // is parent[u][i] is not a parent of v then move u to parent[u][i] ;
            if (!is_ancestor(parent[u][i] , v)) {
                u =  parent[u][i] ;
            }
        }
        return parent[u][0];
    }
};

