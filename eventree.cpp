// https://www.hackerrank.com/challenges/even-tree
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int matrix[200][200] , n , m ;
int visited[200] ;
int cou[200] ;
void citeste(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        matrix[a][b] = 1 ;
        matrix[b][a] = 1 ;
    }
}

int dfs(int node){
    visited[node] = 1 ;
    cou[node] = 1 ;
    for(int i = 1 ; i <= n ; i++){
        if(visited[i] == 0 && matrix[node][i] == 1){
            cou[node] += dfs(i) ;
        }
    }
    return cou[node] ;
}

int main() {
    citeste() ;
    dfs(1) ;
    int result = -1 ;
    for(int i = 1 ; i <= n ; i++){
        if(cou[i] % 2 == 0){
            result++ ;
        }
    }
    cout << result ;
    return 0;
}
