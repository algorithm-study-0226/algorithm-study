// 공약수
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

int main() {
    ll i, _gcd, _lcm, numer;
    //lldiv_t result;
    float result;
    cin>>_gcd>>_lcm;
    ll multiple = _gcd * _lcm;
    int tempGCD;

    i=sqrt(multiple);
    while(i%_gcd!=0){
        i--;
    } 
    for(;i>=_gcd;i-=_gcd) {
        result = multiple % i;
        //cout<<i<<" "<<result<<", ";
        if(result == 0 && _gcd == gcd(multiple/i, i)) {
            break;
        }
            
    }

    cout<< i << " " << multiple / i <<endl;

    return 0;
}
