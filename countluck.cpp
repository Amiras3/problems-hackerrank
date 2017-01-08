// https://www.hackerrank.com/challenges/count-luck
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, visited[1000 + 10][1000 + 10];
pair<int, int> parent[1000 + 10][1000 + 10];
char mat[1000 + 10][1000 + 10];

void read(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           cin >> mat[i][j];
        }
    }
    cin >> k;
}

pair<int, int> destination(char c){
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == c){
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

bool check(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    if(mat[i][j] == 'X'){
        return false;
    }
    return true;
}

void dfs(int i, int j, int ip, int jp){
    if(check(i, j) == false || visited[i][j]){
        return;
    }
    parent[i][j] = make_pair(ip, jp);
    visited[i][j] = 1;
    dfs(i - 1, j, i, j);
    dfs(i + 1, j, i, j);
    dfs(i, j - 1, i, j);
    dfs(i, j + 1, i, j);
}

int degree(int i, int j){
    int res = 0;
    if(check(i, j -1)){
        res++;
    }
    if(check(i, j + 1)){
        res++;
    }
    if(check(i - 1, j)){
        res++;
    }
    if(check(i + 1, j)){
        res ++;
    }
    return res ;
}

bool solve(){
    int result = 0;
    pair<int, int> M = destination('M');
    pair<int, int> star = destination('*');
    dfs(M.first, M.second, -1, -1);
    pair<int, int> par = parent[star.first][star.second];
    while(par.first != -1 && par.second != -1){
        if(degree(par.first, par.second) >= 3){
            result++;
        }
        par = parent[par.first][par.second];
    }
    if(degree(M.first, M.second) == 2){
        result++;
    }
    return k == result;
}

void reset(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = 0;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t){
       read();
        if(solve()){
            cout << "Impressed" << endl;
        }
        else{
            cout << "Oops!" << endl;
        }
        reset();
        t--;
    }
    return 0;
}
