// https://www.hackerrank.com/challenges/cut-the-tree
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> edges(100000 + 10);
int cost[100000 + 10];
int sum[100000 + 10];
void read(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
}

void compute(int node, int parent){
    sum[node] += cost[node];
    for(int j : edges[node]){
        if(j != parent){
            compute(j, node);
        }
    }
    for(int j : edges[node]){
        if(j != parent){
            sum[node] += sum[j];
        }
    }
}


int main(){
    read();
    compute(1, 0);
    int result = 1000000000;
    for(int i = 2; i <= n; i ++){
        if(result > fabs(sum[1] - 2 * sum[i])){
            result = fabs(sum[1] - 2 * sum[i]);
        }
    }
    cout << result;
    return 0;
}
