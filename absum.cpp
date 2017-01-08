// https://www.hackerrank.com/challenges/playing-with-numbers
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long n , q , a[100000 * 5 + 10] , sum[100000 * 5  + 10] ;

void read(){
    cin >> n ;
    cin >> a[0] ;
    for(int i = 1 ; i < n ; i++){
        cin >> a[i] ;
    }
    sort(a , a + n) ;
    sum[0] = a[0] ;
    for(int i = 1 ; i < n ; i++){
        sum[i] = sum[i - 1] + a[i] ;
    }
}

long long add(long long x){
    auto it = lower_bound(a , a + n , -x) ;
    int index = it - a ;
    if(index == n){
       return  - x * n - sum[n - 1] ;
    }
    if(index == 0){
        return sum[n - 1] + x * n ;
    }
    return sum[n - 1] - sum[index - 1] + (n - index) * x - x * index - sum[index - 1] ;
}
int main() {
    read() ;
    int x = 0 ;
    cin >> q ;
    while(q){
        int s ;
        cin >> s ;
        x+= s;
        cout << add(x) << endl ;
        q-- ;
    }
    return 0;
}

