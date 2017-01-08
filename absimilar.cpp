// https://www.hackerrank.com/challenges/similarpair
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 100000 + 10;
int aib[Max], n, k;
vector<vector<int>> sons(Max);

inline int min(int a, int b){
    return (a < b) ? a : b;
}

inline int zero(int x){
    return (x & (x - 1)) ^ x;
}

void update(int x, int add){
    for(int i = x; i <= n; i += zero(i)){
        aib[i] += add;
    }
}

int sum(int x){
    int result = 0;
    for(int i = x ; i >= 1; i -= zero(i)){
        result += aib[i];
    }
    return result;
}

int count(int node){
    int a = max(0, node - k);
    int b = min(n, node + k);
    if(a == 0){
        return sum(b);
    }
    return sum(b) - sum(a - 1);
}

long long dfs(int node){
    long long result = 1LL * count(node);
    update(node, 1);
    for(int i : sons[node]){
        result += dfs(i);
    }
    update(node, -1);
    return result;
}

int main(){
    cin >> n >> k;
    vector<int> is_son(n + 2, 0);
    int root;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        sons[a].push_back(b);
        is_son[b] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(!is_son[i]){
            root = i;
            break;
        }
    }
    cout << dfs(root);
    return 0;
}
