// 백준 내리막 길 https://www.acmicpc.net/problem/1520
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
#define PI 3.14159265358979
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

// 0:상 1:하 2:좌 3:우
int m, n;
ll dp[500][500]; 
int terrain[500][500];

ll recursive(int a, int b) {
    if(dp[a][b]!=-1) {
        return dp[a][b];
    }

    ll result = 0;
    if(a+1<m && terrain[a+1][b]<terrain[a][b]) {
        result += recursive(a+1, b);
    }

    if(a-1>=0 && terrain[a-1][b]<terrain[a][b]) {
        result += recursive(a-1, b);
    }

    if(b+1<n && terrain[a][b+1]<terrain[a][b]) {
        result += recursive(a, b+1);
    }

    if(b-1>=0 && terrain[a][b-1]<terrain[a][b]) {
        result += recursive(a, b-1);
    }

    dp[a][b] = result;
    return result;
}

int main() {
    ll i, j, k, result = 0;
    cin>>m>>n;

    for(j=0;j<m;j++) {
        for(i=0;i<n;i++) {
            cin>>terrain[j][i];
            dp[j][i] = -1;
        }
    }

    dp[m-1][n-1] = 1;

    recursive(0, 0);

    cout<<dp[0][0]<<endl;    

    return 0;
}