//https://www.hackerrank.com/challenges/choose-and-calculate
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = 1000000007 ;
long long int n , k , a[100000 + 10] , f[100000 + 10] , finv[100000 + 10] ;

void read(){
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
    }
}

long long power(long long int x , long long int y){
    if(!y){
        return 1 ;
    }
    long long int put = 1 ;
    while(y){
        if(y & 1){
            put = (1LL * put * x) % mod ;
        }
        x = (1LL * x * x) % mod ;
        y = y / 2 ;
    }
    return put ;
}

void fill(){
    f[1] = 1 ; f[0] = 1 ; finv[0] = 1 ; finv[1] = 1 ;
    for(long long i = 2 ; i <= n ; i ++){
        f[i] = (1LL * i * f[i - 1]) % mod ;
        finv[i] = power(f[i] , mod - 2) % mod ;
    }
}

long long comb(long long x , long long y){
    long long int sol = f[x] ;
    sol = (1LL * sol * finv[y]) % mod ;
    sol = (1LL * sol * finv[x - y]) % mod ;
    return sol ;
}

int main() {
    read() ;
    fill() ;
    sort(a + 1 , a + n + 1) ;
    long long int sol = 0 ;
    for(long long i = n ; i >= k ; i --){
        long long x = (1LL * a[i] * comb(i - 1 , k - 1)) % mod  ;
        sol = (1LL * sol + x) % mod ;
    }
    for(long long  i = 1 ; i <= n - k + 1 ; i ++){
        long long y = 1LL * a[i] * comb(n - i , k - 1) % mod ;
        sol = (1LL * sol + 1LL * mod - y) % mod ;
    }
    cout << sol ;
    return 0;
}
