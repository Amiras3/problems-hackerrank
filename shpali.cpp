//https://www.hackerrank.com/challenges/short-palindrome
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string s ;
const long long mod = 1000000000 + 7 ;
long long inv(long long x){
    int put = 1 ;
    int exp = mod - 2 ;
    while(exp){
        if(exp & 1){
            put = (1LL * put * x) % mod ;
        }
        x = (1LL * x * x) % mod ;
        exp = exp / 2 ;
    }
    return put ;
}

long long invi ;
long long count(char c){
    long long ap = 0 ;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == c){
            ap++ ;
        }
    }
    long long result = 0 ;
    if(ap >= 4){
        result = (1LL * ap * (ap - 1)) % mod ;
        result = (1LL * result * (ap - 2)) % mod ;
        result = (1LL * result * (ap - 3)) % mod ;
        result = (1LL * result * invi) % mod ;
    }
    return result ;
}

long long count(char a , char b){
    int size = s.size() ;
    long long result = 0 ;
    long long ap = 0 ;
    long long ap1 = 0 ;
    long long apb[size + 5] ;
    apb[0] = 0 ;
    for(int i = 0 ; i < size ; i++){
        if(s[i] == a){
            ap++ ;
        }
        if(i != 0){
            apb[i] = apb[i - 1] ;
        }
        if(s[i] == b){
            apb[i] += ap ;
        }
    }
    for(int i = size - 1 ; i >= 1 ; i--){
        if(s[i] == a){
            ap1++ ;
        }
        if(s[i] == b){
            long long term = (ap1 * apb[i - 1]) % mod ;
            result = (result + term) % mod ;
        }
    }
    return result ;
}

int main() {
    invi = inv(24) ;
    cin >> s ;
    long long result = 0 ;
    for(char i = 'a' ; i <= 'z' ; i++){
        result = (result + count(i)) % mod ;
    }
    for(char i = 'a' ; i <= 'z' ; i++){
        for(char j = 'a' ; j <= 'z' ; j++){
            if(i != j){
                result = (result + count(i , j)) % mod ;
            }
        }
    }
    cout << result ;
    return 0;
}
