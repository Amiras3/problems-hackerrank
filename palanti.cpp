//https://www.hackerrank.com/challenges/antipalindromic-strings
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1000000007 ;

int power(int x , int y){
    if(!y){
        return  0 ;
    }
    int put = 1 ;
    while(y){
        if(y & 1){
            put = (1LL * put * x) % mod ;
        }
        x = (1LL * x * x) % mod ;
        y /= 2 ;
    }
    return put ;
}

void read(int &n , int &m){
    cin >> n >> m ;
}

int solve(int n , int m){
    int sol = 1 ;
    if(n == 1){
        return m ;
    }
    if(n == 2){
        return (1LL * m * (m -1)) % mod ;
    }
    sol = (1LL * m * (m -1)) % mod ;
    sol = (1LL * sol * power(m - 2 , n - 2)) % mod  ;
    return sol ;
}
int main() {
    int t , n , m;
    cin >> t ;
    while(t){
        read(n , m) ;
        cout << solve(n , m) << '\n' ;
        t -- ;
    }
    return 0;
}
