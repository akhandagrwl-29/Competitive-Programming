class DSU
{
    vector<int>parent , rank ;
    int n  ;
 
public:
 
    DSU(int size)
    {
        n =  size  +  1   ;
        parent.resize(n) ;
        rank.resize(n) ;
 
        make_set()  ;
    }
 
    void make_set()
    {
        for (int i  = 0 ; i < n ; i++)
        {
            parent[i] =  i ;
            rank[i] = 1  ;
        }
    }
 
    int  find(int x)
    {
        if (parent[x] ==  x)
            return x ;
        return parent[x] = find(parent[x])  ;
    }
 
    void union_set(int x , int y)
    {
        int a =  find(x) ;
        int b =  find(y) ;
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a , b) ;
            parent[b] = a ;
            rank[a] += rank[b] ;
        }
    }
};
