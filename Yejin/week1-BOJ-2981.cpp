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

set<int> resultSet;
int A[105];
int n;
int gcd2(int a, int b) {
    if(b==1) return -1;
    return a % b ? gcd2(b, a % b) : b; 
}

int multiGcd(ll subValue) {
    ll i, tempGcd;
    tempGcd = A[0]+subValue;
    for(i=1;i<n;i++) {
        tempGcd = gcd2(tempGcd, A[i]+subValue);
        if(tempGcd==-1)
            return -1;
    }
    return tempGcd;
}

void fetchDivisorFromGCD(int gcd) {
    int i;
    for(i=1;i<=sqrt(gcd);i++){
        if(gcd%i==0) {
            resultSet.insert(i);
            resultSet.insert(gcd/i);
        }
    }
}

void printResult() {
    std::set<int>::iterator it;
    for (it = ++resultSet.begin(); it != resultSet.end(); ++it) {
        printf("%d ", *it);
    }
}

int main() {
    int i, j, minimum=200000000, tempCD, resultGCD=-1;
    int anyNumberForRepeat = 50;
    int repeatCheckCount = 0;
    cin>>n;

    for(i=0;i<n;i++) {
        scanf("%d", &A[i]);
        minimum = min(minimum, A[i]);
    }

    sort(A, A+n, desc);

    i=0;
    while(1) {
        tempCD = multiGcd(i);
        //cout << i << "번쨰: "<< tempCD << endl;

        // 약수가 나오면 저장.
        if(tempCD!=-1&&repeatCheckCount==0){
            resultGCD = tempCD;
            repeatCheckCount = 1;
        }

        // N번이나 확인했는데 더 큰 약수가 없다. 끝!
        if(repeatCheckCount==anyNumberForRepeat)
            break;
        else if(repeatCheckCount>0&&repeatCheckCount<anyNumberForRepeat) {
            repeatCheckCount++;

            // 이번 약수가 더 크면 체크할 수를 변경하고, 커서 리셋.
            if(resultGCD < tempCD) {
                resultGCD = tempCD;
                repeatCheckCount = 1;
            }
            i+=resultGCD;
        }   
        else i++;

        if(i>1000000000) break;
    }
    
    fetchDivisorFromGCD(resultGCD);

    printResult();

    cout<<endl;

    return 0;
}
