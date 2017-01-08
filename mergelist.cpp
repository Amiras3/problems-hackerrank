//https://www.hackerrank.com/challenges/merge-list
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int l = 100 ;
const int mod = 1000000007 ;
int f[2 * l + 10] , finv[2 * l + 10] ;

void read(int &n , int &m){
    cin >> n >> m ;
}

int power(int x , int y){
    int put = 1 ;
    while(y){
        if(y & 1){
            put = (1LL * put * x) % mod ;
        }
        x = (1LL * x * x) % mod ;
        y = y / 2 ;
    }
    return put ;
}

void umple(){
    f[0] = 1 ; f[1] = 1 ; finv[0] = 1 ; finv[1] = 1 ;
    for(int i = 2 ; i <= 2 * l + 1  ; i ++){
        f[i] = (1LL * f[i - 1] * i) % mod ;
    }
}

int compute(int n , int m){
    int sol = f[n + m] ;
    sol = (1LL * sol * power(f[n] , mod -2)) % mod ;
    sol = (1LL * sol * power(f[m] , mod -2)) % mod ;
    return sol ;
}

void write(int n , int m){
    cout << compute(n , m) << '\n';
}

int main() {
    int t , n , m ;
    umple() ;
    cin >> t ;
    while(t){
        read(n , m) ;
        write(n , m) ;
        t -- ;
    }
    return 0;
}
