// 백준 11049 행렬 곱셈 순서  https://www.acmicpc.net/problem/10844
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
#define PI 3.14159265358979
#define max_int 2147483647
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

int dp[501][501] = {};
int matrix[501][2];
void solve(int a, int b) {
    int i, temp_result, minimum=max_int;
    if(a==b)
        return;
    if(dp[a][b]!=0)
        return;

    for(i=0;i<b-a;i++) {
        solve(a, a+i);
        solve(a+i+1, b);
        temp_result = dp[a][a+i] + dp[a+i+1][b] + matrix[a][0] * matrix[a+i][1] * matrix[b][1];
        minimum = min(minimum, temp_result);
    }

    dp[a][b] = minimum;
}
int main() {
    ll i, j, n, result = 0;

    cin>>n;

    for(i=0;i<n;i++) {
        cin>>matrix[i][0]>>matrix[i][1];
    }

    solve(0, n-1);

    cout<<dp[0][n-1]<<endl;    

    return 0;
}