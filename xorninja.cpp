#include <cmath>
// https://www.hackerrank.com/challenges/xoring-ninja
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1000000000 + 7 ;

void citeste(int &n , int a[]){
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
    }
}

int power(int x , int y){
    int p = 1 ;
    while(y){
        if(y & 1){
            p = (1LL * p * x) % mod ;
        }
        x = (1LL * x * x) % mod ;
        y /= 2 ;
    }
    return p ;
}

int check(int n , int k ,  int a[]){
    for(int i = 1 ; i <= n ; i ++){
        if((a[i] /  (1LL << k)) & 1){
            return 1 ;
        }
    }
    return 0 ;
}

int solve(int n , int a[]){
    int put = power(2 , n - 1) , res = 0 ;
    for(int k = 0 ; k <= 32 ; k ++){
        if(check(n , k , a)){
            int p1 = ((1LL << k) * put) % mod ;
            res = (1LL * res + 1LL * p1) % mod ;
        }
    }
    return res ;
}

int main() {
    int n , t ;
    int a[100000 + 10] ;
    cin >> t ;
    while(t){
        citeste(n , a) ;
        cout << solve(n , a) << '\n' ;
        t -- ;
    }
    return 0;
}
