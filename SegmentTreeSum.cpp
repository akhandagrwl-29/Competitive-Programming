//Range Sum query and range updates with lazy Propogation...
class SegmentTree{ 
    vector<long long > tree;
    vector<long long > lazy ;
    vector<long long > arr ;
    long long n ;

public:

    SegmentTree(vector<long long> &v){
        n =  v.size() ;
        arr = v; 
        tree.resize(4*n + 1 ) ;
        lazy.resize(4*n + 1 , 0 ) ;
        build(0 , n-1 , 1) ;
    }

    void build(int s , int e , int node){
        if(s == e){
            tree[node] = arr[s] ;
            return ;
        }
        int mid = (s + e)>>1;
        build(s , mid , 2*node) ;
        build(mid + 1  , e , 2*node + 1 ) ;
        tree[node] = tree[2*node] + tree[2*node + 1] ;
    }

    long long get(int qs , int qe , int ss , int se , int node){
        // No overlap
        doLazy(ss , se , node) ;

        if(se < qs or ss > qe){
            return 0;
        }

        // Full OverLap
        if(qs <= ss and qe >= se){
            return tree[node] ;
        }

        int mid = (ss + se)>>1;
        long long left = get(qs , qe , ss , mid , 2*node) ;
        long long right = get(qs , qe , mid + 1 , se  , 2*node + 1 ) ;

        return left + right ;
    }

    void update(int qs ,  int qe , long long add , int ss , int se , int node){
        // Checking for any pending update.
        doLazy(ss , se , node) ;

        if(se < qs or ss > qe)
                return ;

        if(qs <= ss and qe >= se){
            tree[node] += add*(se - ss + 1 ) ;
            if(ss != se){
                lazy[2*node] += add ;
                lazy[2*node + 1 ] += add ;
            }
            return ;
        }

        int mid =  (ss + se)>>1 ;
        update(qs , qe , add , ss , mid , 2*node) ;
        update(qs , qe , add , mid + 1 , se , 2*node + 1) ;

        tree[node] =  tree[2*node] + tree[2*node + 1] ;
    }

    void updatePoint(int pos , ll num , int ss , int se , int node){
        if(ss == se){
            tree[node] = num ;
            arr[pos] = num ;
            return ;
        }

        int mid = (ss + se)>>1 ;
        
        if(pos <= mid)  updatePoint(pos , num , ss , mid , 2*node) ;
        else            updatePoint(pos , num , mid + 1 , se , 2*node + 1 ) ;
        tree[node] = tree[2*node] + tree[2*node + 1] ;
    }
    void doLazy(int ss , int se , int node){
        if(lazy[node]){
            tree[node] += (lazy[node]*(se - ss + 1)) ;
            if(ss != se){
                lazy[2*node] += lazy[node] ;
                lazy[2*node + 1] += lazy[node] ;
            }
            else{
                arr[ss] += lazy[node] ;
            }
            lazy[node] =  0;
        }
    }
    vector<long long > getArray(){
        return arr;
    }
};