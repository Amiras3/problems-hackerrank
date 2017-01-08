// https://www.hackerrank.com/challenges/non-divisible-subset
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long  n , k , x , res = 0 , v[100 + 10] ;
    cin >> n >> k ;
    for(int i = 0 ; i <= 100 ; i ++){
        v[i] = 0 ;
    }
    for(int i = 1 ; i <= n ; i ++){
        cin >> x ;
        v[x % k] ++ ;
    }
    for(int i = 1 ; i <= k / 2 ; i ++){
        res += max(v[i] , v[k - i]) ;
    }
    if(v[0]){
        res ++ ;
    }
    if(k % 2 == 0 && v[k /2]){
        res -= v[k / 2] ;
        res ++ ;
    }
    cout << res ;
    return 0;
}
