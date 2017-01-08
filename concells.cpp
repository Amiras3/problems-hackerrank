// https://www.hackerrank.com/challenges/connected-cell-in-a-grid
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mat[30][30] ;
int n , m  ;
int check(int i , int j){
    if(0 <= i && i < n && 0 <= j && j < m && mat[i][j] == 1){
        return 1 ;
    }
    return 0 ;
}

int dfs(int i , int j){
    if(check(i , j) == 0){
        return 0 ;
    }
    mat[i][j] = 0 ;
    int count = 1 ;
    for(int p = -1 ; p <= 1 ; p++){
        for(int t = -1 ; t <= 1 ; t++){
            if(!(p == 0 && t == 0)){
                count += dfs(i + p , j + t) ;
            }
        }
    }
    return count ;
}

int main() {
    int result = 0 ;
    cin >> n >> m ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> mat[i][j] ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(mat[i][j] == 1){
                result = max(result , dfs(i , j)) ;
            }
        }
    }
    cout << result ;
    return 0;
}
