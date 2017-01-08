//https://www.hackerrank.com/challenges/k-candy-store
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define min(x , y) (x)<(y)?(x):(y)

const long long mod = 1000000000 ;

long long comb[2020][2020] , n , k ;

void citeste(){
    cin >> n >> k ;
}

void umple(){
    comb[0][0] = 1 ; comb[1][0] = 1 ; comb[1][1] = 1 ;
    for(long long i = 2 ; i <= 2000 ; i ++){
        comb[i][0] = 1 ;
        for(long long j = 1 ; j < i ; j ++){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod ;
        }
        comb[i][i] = 1 ;
    }
}

int main() {
    umple() ;
    int t ;
    cin >> t ;
    for(  ; t != 0 ; t --){
        citeste() ;
        cout << comb[n + k - 1][k]  << "\n" ;
    }
    return 0;
}
