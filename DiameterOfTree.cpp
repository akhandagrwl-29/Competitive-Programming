class Diameter{
    pair<int  , int > ends;
    int len ;
public:
    Diameter(vector<vector<int>> &g){
        pair<int  , int > a =  dfs(1 , 0  , g) ;
        pair<int  , int > b =  dfs(a.second , 0  , g) ;
        ends  = {a.second , b.second} ;
        len =  b.first -1   ;
    }

    pair<int , int>dfs(int v , int u , vector<vector<int>> &g){
        pair<int , int>  num   =  make_pair(0 , v) ;
        for(auto &x : g[v]){
            if(x != u){
                pair<int ,int> a = dfs(x , v , g) ;
                if(a.first > num.first){
                    num  =  a   ;
                }
            }
        }
        num.first++  ;
        return num ; 
    }

    pair<int  , int > diameterEnds(){
        return ends  ;
    }
    int diameterLen(){
        return len ;
    }
};
