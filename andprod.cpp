// https://www.hackerrank.com/challenges/and-product
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void citeste(unsigned long long &a , unsigned long long &b){
    cin >> a >> b ;
}

unsigned long long solve(unsigned long long a , unsigned long long b){
    unsigned long long res = 0 ;
    int k ;
    for(k = 0 ; k <= 32 ; k ++){
        if(((a >> k)&1) && b - a < (1LL << k) - a % (1LL << k)){
            res += 1LL << k ;
        }
    }
    return res ;
}
int main() {
    int n ;
    unsigned long long a , b ;
    cin >> n ;
    while(n){
        citeste(a , b) ;
        cout << solve(a , b) << '\n' ;
        n -- ;
    }
    return 0;
}
