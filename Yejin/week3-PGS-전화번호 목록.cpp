// 프로그래머스-전화번호 목록
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
#include <string>
#define ll long long
#define PI 3.14159265358979
using namespace std;
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
bool desc(int a, int b){ return a > b; }

struct Node{
    Node *child[10];
    bool hasChild = false;
};

Node *root;

bool addToTree(string phone_number, Node *tree) {
    if(phone_number.empty()) {
        return true;
    }

    int first_num = stoi(phone_number.substr(0, 1));
    string remained = phone_number.substr(1);

    Node *node = (Node*)calloc(1,sizeof(Node));
    tree->child[first_num] = node;
    tree->hasChild = true;
    return addToTree(remained, tree->child[first_num]);
}

bool addToTreeWithCheck(string phone_number, Node *tree) {
    if(phone_number.empty() && tree->hasChild){
        return false;
    }
    if(!phone_number.empty() && !tree->hasChild){
        return false;
    }

    int first_num = stoi(phone_number.substr(0, 1));
    string remained = phone_number.substr(1);

    if(tree->child[first_num]) {
        return addToTreeWithCheck(remained, tree->child[first_num]);
    } else {
        Node *node = (Node*)calloc(1,sizeof(Node));
        tree->child[first_num] = node;
        tree->hasChild = true;
        return addToTree(remained, tree->child[first_num]);
    }
}

bool addToRoot(string phone_number) {
    int first_num = stoi(phone_number.substr(0, 1));

    if(root->child[first_num]) {
        return addToTreeWithCheck(phone_number, root);
    } else {
        return addToTree(phone_number, root);
    }
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    root = (Node*)calloc(1,sizeof(Node));

    for(auto phone : phone_book) {
        answer = addToRoot(phone);
        if(!answer) break;
    }
    
    return answer;
}

int main() {
    vector<string> phones;
    phones.push_back("119");
    phones.push_back("97674223");
    phones.push_back("1195524421");
    if(solution(phones)) {
        cout<< "true"<< endl;
    } else {
        cout<< "false"<<endl;
    }
    return 0;
}