https://www.hackerrank.com/challenges/array-splitting
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

long long n , a[16 * 1024 + 10] , sum[16 * 1024 + 10]  ;

unordered_map<long , long> m ;

void citeste(){
    cin >> n ;
    sum[0] = 0 ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
        sum[i] = sum[i - 1] + a[i] ;
        m[sum[i]] = i ;
    }
}

long long rezolva(int st , int dr){
   if(sum[dr] - sum[st - 1] == 0){
       return dr - st ;
   }
   long long x = sum[dr] + sum[st - 1] ;
   if(x % 2 == 0 && m.find(x / 2) != m.end()){
       auto it = m.find(x / 2) ;
       long long t = it -> second ;
       return 1 + max(rezolva(st , t) , rezolva(t + 1 , dr)) ;
   }
   else{
       return 0 ;
   }
}
int main() {
    int t ;
    cin >> t ;
    for(  ; t != 0 ; t --){
        citeste() ;
        cout << rezolva(1 , n) << "\n" ;
        m.clear() ;
    }
    return 0;
}
