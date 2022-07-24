class TopoSort {
    int n ;
    vector<int> order ;
    vector<bool> vis ;
public:
    TopoSort(vector<vector<int>> &g) {
        n =  g.size() ;
        vis.resize(n , 0) ;
        for (int i = 1 ; i < n ; i++) {
            if (!vis[i]) {
                dfs(i , g ) ;
            }
        }
    }
    void dfs(int   u, vector<vector<int>> &g) {
        vis[u] = true ;
        for (auto &v : g[u]) {
            if (!vis[v]) {
                dfs(v , g) ;
            }
        }
        order.push_back(u) ;
    }
    vector<int> ordering() {
        reverse(order.begin() , order.end()) ;
        return order ;
    }
    vector<int> bfs(vector<vector<int>> &g) {
        vector<int> ordering ;
        int n =  g.size() ;
        vector<int> indeg(n , 0) ;

        for (int u = 1 ; u < n ; u++) {
            for (auto &v : g[u]) {
                indeg[v]++ ;
            }
        }

        // cout << indeg << ln ;

        queue<int> q;
        for (int i = 1 ; i < n ; i++) {
            if (indeg[i] == 0) {
                q.push(i) ;
            }
        }

        while (!q.empty()) {
            int u =  q.front() ;
            q.pop() ;
            ordering.push_back(u) ;

            for (auto &v : g[u]) {
                indeg[v]-- ;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return ordering ;
    }
};