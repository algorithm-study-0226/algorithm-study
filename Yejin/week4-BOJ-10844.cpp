// 백준 10844 쉬운 계단 수 https://www.acmicpc.net/problem/10844
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

ll dp[11][101];
int main() {
    ll i, j, n, result = 0;

    dp[0][1] = 0;
    for(i=1;i<10;i++) {
        dp[i][1] = 1;
    }

    cin>>n;

    for(i=2;i<=n;i++) {
        dp[0][i] = dp[1][i-1]%1000000000;
        dp[9][i] = dp[8][i-1]%1000000000;
        for(j=1;j<9;j++) {
            dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1])%1000000000;
        }
    }

    for(i=0;i<10;i++) {
        result += dp[i][n];
    }

    cout<<result%1000000000<<endl;    

    return 0;
}