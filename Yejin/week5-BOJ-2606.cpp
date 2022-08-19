// 백준 바이러스 https://www.acmicpc.net/problem/2606
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

vector<int> graph[101];
int graph2[101][101] = {0,};
bool visited[101];
queue<int> q;
stack<int> s;

int visitedNumber = 0;

void adjacencyList() {
    int i, node, vertex, n1, n2;
    cin>>node>>vertex;

    for(i=0; i<vertex; i++) {
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

   for(i=1; i<node+1; i++) {
        vector<int>::iterator ptr;
        for (ptr = graph[i].begin(); ptr != graph[i].end(); ++ptr)
        {
            cout << *ptr << " ";
        }
        cout<<endl;
   } 
}

void adjacencyMatrix() {
    int i, j, node, vertex, n1, n2;
    cin>>node>>vertex;

    for(i=0; i<vertex; i++) {
        cin>>n1>>n2;
        graph2[n1][n2] = 1;
        graph2[n2][n1] = 1;
    }

    for(j=1; j<node+1; j++) {
        for(i=1; i<node+1; i++) {
            cout<<graph2[j][i];
        }
        cout<<endl;
    }
}

void enqueueAdjacencyNode(int node) {
    vector<int>::iterator ptr;
    for (ptr = graph[node].begin(); ptr != graph[node].end(); ++ptr)
    {
        q.push(*ptr);
    }
}

void dequeue() {
    int node = q.front();
    q.pop();
    if(!visited[node]) {
        visited[node] = true;
        visitedNumber++;
        enqueueAdjacencyNode(node);
    }
}

void bfsWithList() {
    int i, j, node, vertex, n1, n2;
    
    cin>>node>>vertex;

    for(i=0; i<vertex; i++) {
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    q.push(1);
    
    while(!q.empty()) {
        dequeue();
    }
    
    cout<<visitedNumber-1<<endl;
}

void pushAdjacencyNode(int node) {
    vector<int>::iterator ptr;
    for (ptr = graph[node].begin(); ptr != graph[node].end(); ++ptr)
    {
        s.push(*ptr);
    }
}

void popStack() {
    int node = s.top();
    s.pop();
    if(!visited[node]) {
        visited[node] = true;
        visitedNumber++;
        pushAdjacencyNode(node);
    }
}

void dfsWithList() {
    int i, j, node, vertex, n1, n2;
    
    cin>>node>>vertex;

    for(i=0; i<vertex; i++) {
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    s.push(1);
    
    while(!s.empty()) {
        popStack();
    }
    
    cout<<visitedNumber-1<<endl;
}

int main() {
    dfsWithList();

    return 0;
}