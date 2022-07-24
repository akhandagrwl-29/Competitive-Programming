class Diameter{
    pair<int  , int > ends;
    int len ;
public:
    Diameter(vector<vector<int>> &g){
        pair<int  , int > a =  dfs(1 , 0  , g) ;
        pair<int  , int > b =  dfs(a.ss , 0  , g) ;
        ends  = {a.ss , b.ss} ;
        len =  b.ff -1   ;
    }

    pair<int , int>dfs(int v , int u , vector<vector<int>> &g){
        pair<int , int>  num   =  MP(0 , v) ;
        for(auto &x : g[v]){
            if(x != u){
                pair<int ,int> a = dfs(x , v , g) ;
                if(a.ff > num.ff){
                    num  =  a   ;
                }
            }
        }
        num.ff++  ;
        return num ; 
    }

    pair<int  , int > diameterEnds(){
        return ends  ;
    }
    int diameterLen(){
        return len ;
    }
};
