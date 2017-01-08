//https://www.hackerrank.com/challenges/xor-quadruples
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
long long v[5000] ;
long long m[3000 + 10][5000] ;

int main(){
    long long res = 0 ;
    int a[6] ;
    cin >> a[1] >> a[2] >> a[3] >> a[4] ;
    sort(a + 1 , a + 5) ;
    for(int i = 1 ; i <= a[1] ; i ++){
        for(int j = i ; j <= a[2] ; j ++){
            m[j][i ^ j] ++ ;
        }
    }
    for(int i = 1 ; i <= 3000 ; i ++){
        for(int j = 0 ; j <= 5000 - 10 ; j ++){
            m[i][j] += m[i - 1][j] ;
        }
    }
    for(int i = 1 ; i <= a[1] ; i ++){
        for(int j = i ; j <= a[2] ; j ++){
            v[j] ++ ;
        }
    }
    for(int i = 1 ; i <= 3000 ; i ++){
        v[i] += v[i - 1] ;
    }
    for(int i = 1 ; i <= a[3] ; i ++){
        for(int j = i ; j <= a[4] ; j ++){
            res += (v[i] - m[i][i ^ j]) ;
        }
    }
    cout << res ;
    return 0;
}
