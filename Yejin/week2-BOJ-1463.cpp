// 1로 만들기
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

int min_repeat_num = 1000001;
int Memo[1000001] = {};
void recursive(int n, int repeat_num) {
    // base case
    if(n==1) {
        min_repeat_num = min(min_repeat_num, repeat_num);
        return;
    }

    // 메모이제이션
    if(Memo[n]>repeat_num) {
        Memo[n]=repeat_num;
    } else return;
    
    // recursive case
    if(n%3==0) recursive(n/3, repeat_num+1);
    if(n%2==0) recursive(n/2, repeat_num+1);
    recursive(n-1, repeat_num+1);
}

int main() {
    int n;
    cin>>n;
    fill_n(Memo, n+1, 1000001);
    recursive(n, 0);
    cout<<min_repeat_num<<endl;

    return 0;
};
