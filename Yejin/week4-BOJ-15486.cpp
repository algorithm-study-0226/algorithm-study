// 백준 15486 퇴사 2 https://www.acmicpc.net/problem/15486
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#define ll long long
#define PI 3.14159265358979
#define max_int 2147483647
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

int dp[1500001] = {};
vector<pair<int, int> > job[1500001];
void solve(int a, int b) {
}
int main() {
    ll i, j, n, t, p, result = 0;

    dp[0]=0;

    cin>>n;

    for(i=1;i<=n;i++) {
        cin>>t>>p;
        if(i+t-1>1500000)
            continue;

        job[i+t-1].push_back(make_pair(t, p));
    }

    for(i=1;i<n+1;i++) {
        dp[i] = dp[i-1];

        for(j=0;j<job[i].size();j++) {
            dp[i] = max(dp[i - job[i][j].first] + job[i][j].second, dp[i]);
        }
    }

    cout<<dp[n]<<endl;    

    return 0;
}