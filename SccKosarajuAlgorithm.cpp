class SCC{
    int n ;
    vector<bool> vis ;
    vector<int> comp; 
    vector<int> st ;
    vector<vector<int>> comps ;
public:
    SCC(vector<vector<int>> &g , vector<vector<int>> &gg){
        n =  g.size() - 1  ;
        vis.resize(n + 1 , 0) ;

        // STEP-1 storing the vertices according to dfs finish time in stack st;
        for(int i = 1 ; i <= n ;i++){
            if(!vis[i]){
                dfs1(i , g) ;
            }
        }

        // STEP - 2 Reversing the graph (we have reversed graph gg)
        // STEP - 3 Do dfs according to the ordering stored in the stack and storing the each component in comp;

        vis.clear() ;
        vis.resize(n + 1 , 0) ;
        
        for(int i =  st.size() - 1 ; i >= 0 ; i--){
            if(!vis[st[i]]){
                // A new component starts here...
                dfs2(st[i] , gg) ;
                comps.push_back(comp) ;
                comp.clear() ;
            }
        }
    }

    void dfs1(int u , vector<vector<int>> &g){
        vis[u] =  1 ;
        for(auto &v : g[u]){
            if(!vis[v]){
                dfs1(v , g) ;
            }
        }
        // Storing in stack
        st.push_back(u) ;
    }

    void dfs2(int u , vector<vector<int>> &gg){
        vis[u] = 1 ;
        comp.push_back(u) ;

        for(auto &v : gg[u]){
            if(!vis[v]){
                dfs2(v , gg) ;
            }
        }
    }

    vector<vector<int>> components(){
        return comps ;
    }
};
