#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e6;

bool esComp[LIM_N];
int P ;
int primos[LIM_N];

void criba() {
    for(int i=2; i*i < LIM_N; i++)
        if(!esComp[i])
            for(int j=i*i; j < LIM_N; j+=i)
                esComp[j] = true;
    for(int i=2; i < LIM_N; i++)
        if(!esComp[i])
            primos[P++] = i;
}

int N = 0;
int nums[LIM_N + 5];

void sortNums() {
    queue<pair<int,int>> _Q, _R ;
    queue<pair<int,int>> *Q = &_Q, *R = &_R;
    Q->push({1, 0});
    while(!Q->empty()) {
        int N2 = N ;
        while(!Q->empty()) {
            auto p = Q->front(); Q->pop();
            long long n = p.first, k = p.second;
            nums[N2++] = n;
            for(int i=k; i < P; i++) {
                k = primos[i] * n;
                if(k > LIM_N) break;
                R->push({k, i});
            }
        }
        swap(Q, R);
        sort(nums+N, nums+N2);
        N = N2;
    }
}

int main() {
    criba();
    sortNums();
    int n, tc = 0 ;
    while(scanf("%d", &n) && n) {
        printf("Case %d: %d\n", ++tc, nums[n-1]);
    }
}
