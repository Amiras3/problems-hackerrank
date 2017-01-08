// https://www.hackerrank.com/challenges/gridland-metro
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

long long not_cover(long long m , vector<pair<long long , long long>> trains){
    long long count = 0 ;
    long long st = trains[0].first , dr = trains[0].second ;
    count = st - 1 ;
    for(int i = 1 ; i < trains.size() ; i++){
        if(trains[i].first > dr){
            count += trains[i].first - dr -1 ;
        }
        if(trains[i].second > dr){
            dr = trains[i].second ;
        }
    }
    count += (m - dr) ;
    return count ;
}

int main() {
    long long  n , m , k , result = 0 ;
    cin >> n >> m >> k ;
    int linii = 0 ;
    int r[2000] ;
    unordered_map<long long , int> ap ;
    map<long long , vector<pair<long long , long long>>> map ;
    for(int i = 0 ; i < k ; i++){
        long long c1 , c2 ;
        cin >> r[i] >> c1 >> c2 ;
        map[r[i]].push_back(make_pair(c1 , c2)) ;
    }
    for(int i = 0 ; i < k ; i++){
        if(ap[r[i]] == 0)
        sort(map[r[i]].begin() , map[r[i]].end()) ;
        ap[r[i]] = 1 ;
    }

    for(int i = 0 ; i < k ; i++){
        ap[r[i]] = 0 ;
    }
    for(int i = 0 ; i < k ; i++){
        if(ap[r[i]] == 0){
            linii ++ ;
            result += not_cover(m , map[r[i]]) ;
        }
        ap[r[i]] = 1 ;
    }
    result += (n - linii) * m ;
    cout << result ;
    return 0;
}
