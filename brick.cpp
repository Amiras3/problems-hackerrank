//https://www.hackerrank.com/challenges/play-game
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long n , a[100000 + 10] , dp[100000 + 10] , sum[100000 + 10] ;

void citeste(){
    cin >> n ;
    for(int i = 1 ; i <= n  ; i ++){
        cin >> a[i] ;
    }
}

long long solve(){
    if(n == 1){
        return a[1] ;
    }
    if(n == 2){
        return a[1] + a[2] ;
    }
    if(n == 3){
        return a[1] + a[2] + a[3] ;
    }
    sum[0] = 0 ;
    sum[1] = a[1] ;
    for(int i = 2 ; i <= n ; i++){
        sum[i] = sum[i - 1] + a[i] ;
    }
    dp[n] = a[n] ;
    dp[n - 1] = a[n] + a[n - 1] ;
    dp[n - 2] = a[n] + a[n - 1] + a[n - 2] ;
    for(int i = n - 3 ; i >= 1 ; i --){
        dp[i] = max(a[i] + sum [n] - sum[i] - dp[i + 1] , a[i] + a[i + 1] + sum[n] - sum[i + 1] - dp[i + 2]) ;
        dp[i] = max(dp[i] ,  a[i] + a[i + 1] + a[i + 2] + sum[n] - sum[i + 2] - dp[i + 3]) ;
    }
    return dp[1] ;
}

int main() {
    int t ;
    cin >> t ;
    while(t){
        citeste() ;
        cout << solve() << '\n' ;
        t -- ;
    }
    return 0;
}
