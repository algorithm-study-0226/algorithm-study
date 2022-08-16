// 백준 1935 후위 표기식2
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#define ll long long
#define PI 3.14159265358979
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

int N[30];
stack<double> _stack;
int main() {
    int i, j, n, result;
    string expression;
    cin>>n>>expression;
    for(i=0;i<n;i++) {
        cin>>N[i];
    }
    
    double left, right, temp_result;
    for(i=0;i<expression.length();i++) {
        if(expression[i]>64) {
            _stack.push(N[expression[i]-65]);
        } else {
            right = _stack.top();
            _stack.pop();
            left = _stack.top();
            _stack.pop();
            // cout<<left<<expression[i]<<right<<endl;
            if(expression[i]=='+')
                temp_result = left + right;
            else if(expression[i]=='-')
                temp_result = left - right;
            else if(expression[i]=='*')
                temp_result = left * right;
            else if(expression[i]=='/')
                temp_result = left / right;
            // cout<<temp_result<<endl;
            _stack.push(temp_result);
            
        }
    }

    printf("%.2f\n", _stack.top());
    return 0;
}