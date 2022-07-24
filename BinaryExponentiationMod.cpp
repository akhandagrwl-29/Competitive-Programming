long long int powerMod(long long int a , long long int b , long long int M) {
    if (b == 0) {
        return 1;
    }
    long long int  num =  power(a , b >> 1LL) ;
    num = (num * num) % M  ;
    return (b & 1LL) ? num : (num * a) % M ;
}