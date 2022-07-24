class CycleInDirectedGraph {
    int n ;
    vector<bool> vis , path ;
    bool cycle ;

public:

    CycleInDirectedGraph(vector<vector<int>> &g) {
        n =  g.size() ;
        cycle = 0 ;
        vis.resize(n , 0) ;
        path.resize(n , 0) ;

        dfs(1 , g) ;
    }

    void dfs(int v,  vector<vector<int>> &g) {
        vis[v] = 1 ;
        path[v] = 1 ;

        for (auto &x : g[v]) {
            if (!vis[x]) {
                dfs(x , g ) ;
            }
            else if (path[x]) {
                cycle = 1 ;
            }
        }

        path[v] = 0 ;
    }

    bool havingCycle() {
        return cycle ;
    }

};