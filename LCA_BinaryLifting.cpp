// Just declare an object of class Lca and pass adjacency list to the constructor
// lca(u , v) is a member functoin which returns LCA of u and v.

class Lca {
    const int  M = 30 ;
    int n ;
    vector<int> dep ;
    vector<vector<int>> parent ;
public:
    Lca(vector<vector<int>> &g) {
        n = g.size() ;
        dep.resize(n , 0) ;
        parent.resize(n , vector<int>(M)) ;

        dfs(1, 0 , g) ;
        cal_sparse(1 , 0 , g) ;
    }

    void dfs(int v, int u , vector<vector<int>> &g) {
        for (auto &x : g[v]) {
            if (x != u) {
                dep[x] =  dep[v] +  1  ;
                dfs(x , v , g) ;
            }
        }
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

    int lca(int u , int v) {
        if (u == v)	return u ;
        if (dep[u] < dep[v])	swap(u , v) ;

        // Now u is always down to v

        int diff =  dep[u]  - dep[v] ;

        for (int j =  M - 1 ; j >= 0 ; j--) {
            if ((1 << j)&diff) {
                u = parent[u][j] ;
            }
        }
        // After this U and V are on same depth

        if (u == v)		return v ;
        //  v was ancestor of u.

        for (int j =  M - 1 ; j >= 0 ; j--) {
            if (parent[u][j] != parent[v][j]) {
                u = parent[u][j] ;
                v = parent[v][j] ;
            }
        }
        // Here i am standing on different nodes
        return parent[u][0] ;
    }
};