//https://www.hackerrank.com/challenges/maximum-subarray-sum
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    long long n , m , x , sum = 0 , result = 0 ;
    set<long long> map ;
    int q ;
    cin >> q ;
    while(q){
        cin >> n >> m ;
        for(int i = 0 ; i < n ; i++){
            cin >> x ;
            sum = (sum + x) % m ;
            auto it = map.upper_bound(sum) ;
            if(it != map.end()){
                result = max(result , (sum - *it + m) % m) ;
            }
            result = max(result , sum) ;
            map.insert(sum) ;
        }
        cout << result << endl ;
        q-- ;
        sum = 0 ;
        result = 0 ;
        map.clear() ;
    }
    return 0;
}
