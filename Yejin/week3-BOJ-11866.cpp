// 백준 11866 요세푸스 문제 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define ll long long
#define PI 3.14159265358979
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

int main() {
    int i, j, n, k;
    cin>>n>>k;
    
    queue<int> q;
    for(i=1;i<n+1;i++) {
        q.push(i);
    }
    cout<<'<';
    for(i=0;i<n;i++) {
        if(i>0) {
            cout<<", ";
        }
        for(j=0;j<k-1;j++) {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        q.pop();
    }
    cout<<'>'<<endl;

    return 0;
}