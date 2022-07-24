long long int power(long long int a , long long int b) {
    if (b == 0) {
        return 1;
    }
    long long int  num =  power(a , b >> 1LL) ;
    num *= num  ;
    return (b & 1LL) ? num : num * a ;
}