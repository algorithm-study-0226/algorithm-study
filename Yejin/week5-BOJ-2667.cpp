// 백준 2667 단지번호붙이기 https://www.acmicpc.net/problem/2667
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#define ll long long
#define PI 3.14159265358979
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

int map[26][26];
bool visited[26][26];
vector<int> numberOfGroups;
stack<int> s;


void pushAdjacencyNode(int node) {
    vector<int>::iterator ptr;
    //for (ptr = graph[node].begin(); ptr != graph[node].end(); ++ptr)
    //{
     //   s.push(*ptr);
    //}
}

void popStack() {
    int node = s.top();
    s.pop();
    //if(!visited[node]) {
     //   visited[node] = true;
     //   pushAdjacencyNode(node);
    //}
}

void dfsWithList() {
    char temp;
    int i, j, n, n1, n2;
    
    cin>>n;

    for(j=0;j<n;j++) {
        for(i=0;i<n;i++) {
            scanf("%c", &temp);
            printf("%c ", temp);
        }
    }
    printf("\n");

   // s.push(1);
    
    //while(!s.empty()) {
    //    popStack();
    //}
    
    //cout<<visitedNumber-1<<endl;
}

int main() {
    dfsWithList();

    return 0;
}