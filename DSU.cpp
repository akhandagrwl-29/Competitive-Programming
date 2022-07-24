class DSU
{
    long long int  *parent , *rank;
    long long int n  ;

public:

    DSU(long long int size)
    {
        n =  size  +  1   ;
        parent = new long long int[size] ;
        rank =  new long long int[size]  ;
        make_set()  ;
    }

    void make_set()
    {
        for (long long int i  = 0 ; i < n ; i++)
        {
            parent[i] =  i ;
            rank[i] = 1  ;
        }
    }

    long long int  find(long long int x)
    {
        if (parent[x] ==  x)
            return x ;
        return parent[x] = find(parent[x])  ;
    }

    void union_set(long long int x , long long int y)
    {
        long long int a =  find(x) ;
        long long int b =  find(y) ;
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a , b) ;
            parent[b] = a ;
            rank[a] += rank[b] ;
        }
    }
};