//https://www.hackerrank.com/challenges/picking-cards
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1000000007 ;
int n , a[50000 + 10] ;

void read(){
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
    }
    sort(a + 1 , a + n  + 1) ;
}

int solve(){
    int res = 1 ;
    for(int i = n ; i >= 1 ; i --){
        if(i <= a[i]){
            return 0 ;
        }
        else{
            res = (1LL * res * (i - a[i])) % mod ;
        }
    }
    return res ;
}

int main() {
    int t ;
    cin >> t ;
    while(t){
        read() ;
        cout << solve() << '\n' ;
        t -- ;
    }
    return 0;
}
