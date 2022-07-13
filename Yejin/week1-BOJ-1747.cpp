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

bool isPrime(int n) {
    int i;
    for(i=2;i<=sqrt(n);i++) {
        if(n%i==0)
            return false;
    }
    return true;
}
bool isPalindrome(int n) {
    int i;
    int len = log10(n) + 1;
    for(i=0;i<len/2;i++) {
        if(int(n/pow(10,i))%10 != int(n/pow(10,len-1-i))%10)
            return false;
    }
    return true;
}
int main() {
    int n, i, j, answer;
    cin>>n;
    answer = max(n,2);

    while(answer>0) {
        if(isPalindrome(answer)&&isPrime(answer)) {
            cout<<answer<<endl;
            return 0;
        }
        answer++;
    }
    cout<<-1<<endl;

    return 0;
}
