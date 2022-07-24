class Ancestor {
    int n , timer ;
    vector<int> tin  , tout ;
public:
    Ancestor(int v , vector<vector<int>> &g ) {
        n =  v ;
        timer = 0 ;
        tin.resize(n + 1) ;
        tout.resize(n + 1) ;

        tin[0] = 0  ;
        tout[0] = 0 ;

        dfs(1 , 0  , g ) ;
    }

    void dfs(int v , int u  , vector<vector<int>> &g) {
        tin[v] = ++timer ;
        for (auto &x : g[v]) {
            if (x != u) {
                dfs(x , v , g) ;
            }
        }
        tout[v] = timer ;
    }

    bool isAncestor(int u , int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
};