//https://www.hackerrank.com/challenges/xor-se
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define max(x , y) (x) < (y) ? (y) : (x)

unsigned long long f(unsigned long long n){
    if(n == 0){
        return 0 ;
    }
    if(n == 1){
        return 1 ;
    }
    if(n == 2){
        return 3 ;
    }
    if( n % 2 == 0){
        return n + ((n - 1)/ 2 - 1) % 2 ;
    }
    else{
        return ((n - 1)/ 2 - 1) % 2 ;
    }
}

unsigned long long s(unsigned long long x){
    if(x == 0){
        return 0 ;
    }
    if(x == 1){
        return 1 ;
    }
    if(x == 2){
       return 2 ;
    }
    if(x % 2 == 0){
        return 2 * f(x / 2) ;
    }
    if(x % 2 == 1){
        return  (2 * f((x - 1)/ 2) + ((x - 1)/2 - 1) % 2) ;
    }
    return 0 ;
}

unsigned long long g(unsigned long long l , unsigned long long r){
    if(r - l % 2 == 1){
        unsigned long long x = max(0 , l - 2) ;
        return s(r - 1) ^ s(x) ;
    }
    else{
        return s(r) ^ s(max(0 , l - 1)) ;
    }
}

int main(){
    int t ;
    cin >> t ;
    unsigned long long l ,r ;
    for(  ; t > 0 ; t --){
        cin >> l >> r ;
        cout << g(l , r) << "\n" ;
    }
    return 0;
}
