#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
#include <set>
#define ll long long
#define PI 3.14159265358979
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

ll sum(ll d) {
    return d * (d+1) / 2;
}
void printAnswer(int len, int start) {
    int i;
    for(i=0;i<len;i++)
        cout<<start+i<<" ";
    cout<<endl;
}
int main() {
    int i, j, k, n, l;
    ll _sum;
    int low, high;
    int len, start;
    cin>>n>>l;

    for(i=l;i<=100;i++) {
        // 0 포함하는 경우만 따로 계산.
        if(n==sum(i-1)) {
            printAnswer(i, 0);
            return 0;
        } else if (n < sum(i-1)) {
            break;
        }
        
        // 이진 탐색.
        low = 1; high = n;
        while(1) {
            j = (low+high)/2;
            _sum = sum(i+j-1)-sum(j-1);
            if(n == _sum) {
                printAnswer(i, j);
                return 0;
            }
            
            if(high<=low) break;

            if (n < _sum) high = j-1;
            else low = j+1;
        }
    }
    cout<<-1<<endl;
        return 0;

    

    return 0;
}
