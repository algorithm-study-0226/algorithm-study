#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
#define ll long long
#define PI 3.14159265358979
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

int number = 10000;
bool A[10005];
int main() {
    int t, i, j, temp;
    
    cin>>t;
    A[0]=true;A[1]=true;
    for(i=2;i<=number;i++) {
        for(j=i+i;j<=number;j+=i) {
            if(A[j]) continue;
            A[j]=true;
        }
    }

    for(i=0;i<t;i++) {
        scanf("%d", &temp);
        for(j=temp/2;j>1;j--) {
            if(!A[j] && !A[temp-j]) {
                printf("%d %d\n", j, temp-j);
                break;
            }
        }
    }

    return 0;
}
