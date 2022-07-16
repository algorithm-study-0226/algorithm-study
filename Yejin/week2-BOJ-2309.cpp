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

int answer=100;
int Nan[10];
vector<int> picked;
// sort 처음에 해두면 좋을지도?
bool temp_sort(int a, int b){ return Nan[a]<Nan[b];}

bool pick(int n, int toPick, int sum) {
  if(sum>100) return false;
  else if(toPick == 0) {
      if(sum==100) return true;
      else return false;
  }
  
  int smallest = picked.empty() ? 0 : picked.back() + 1;
  // 이 단계에서 원소 하나를 고른다.
  for(int next = smallest; next < n; ++next) {
    picked.push_back(next);
    if(pick(n, toPick - 1, sum + Nan[next])) {
        return true;
    }
    picked.pop_back();
  }
  return false;
}

int main() {
    int t, i, j, temp, n=9;

    for(i=0;i<n;i++) {
        cin>>Nan[i];
    }
    pick(9, 7, 0);
    sort(picked.begin(), picked.end(), temp_sort);
    vector<int>::iterator iter;
    for (iter = picked.begin(); iter != picked.end(); iter++) {
		cout << Nan[*iter] << endl;
	}

    return 0;
};
