vector<vector<int>>bridge_tree(vector<vector<int>>adj , vector<pair<int, int>>bridges , int n) {
    sort(bridges.begin() , bridges.end()) ;
    vector<int>vis(n + 1 , 0) ;
    int compId = 0 ;
    for (int i = 1 ; i <= n; i++ ) {
        if (vis[i] == 0) {
            compId++ ;
            queue<int>q ;
            q.push(i) ;
            while (!q.empty()) {
                int node = q.front() ;
                q.pop() ;
                vis[node] = compId ;
                for (auto child : adj[node]) {
                    if (vis[child] > 0) continue ;
                    if (binary_search(bridges.begin() , bridges.end(), make_pair(node , child))) continue ;
                    if (binary_search(bridges.begin() , bridges.end(), make_pair(child , node))) continue ;
                    q.push(child) ;
                }
            }
        }
    }
    vector<vector<int>>bridgeTree(compId + 1) ;
    for (auto i : bridges) {
        int x = vis[i.first] ;
        int y = vis[i.second] ;
        bridgeTree[x].push_back(y) ;
        bridgeTree[y].push_back(x) ;
    }
    return bridgeTree ;
}
