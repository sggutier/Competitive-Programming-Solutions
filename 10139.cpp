#include <bits/stdc++.h>
using namespace std;
const int limP = 1e5;

int primCnt = 0;
int primos[limP];
bool comp[limP];

void criba() {
    for(int i=2; i*i<limP; i++)
        if(!comp[i])
            for(int j=i*i; j<limP; j+=i)
                comp[j] = true;
    for(int i=2; i<limP; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

void factoriza(int n, list<pair<int,int>> &ans) {
    for(int i=0; i<primCnt; i++) {
        int p = primos[i];
        if(n<p)
            break;
        if(n%p)
            continue;
        int cnt = 1;
        n /= p;
        while(n%p==0) {
            n /= p;
            cnt ++;
        }
        ans.push_back(make_pair(cnt, p));
    }
    if(n>1) {
        int q = sqrt(n);
        if(q*q==n)
            ans.push_back(make_pair(2, q));
        else
            ans.push_back(make_pair(1, n));
    }
}

bool valid(long long n, long long p, int req) {
    long long pot = p;
    while(n>=pot) {
        req -= n/pot;
        if(req<=0)
            return true;
        pot *= p;
    }
    return false;
}

bool testCase(int n, int m) {
    list<pair<int,int>> facts;
    factoriza(m, facts);

    // cout  << "done factorin" << endl;
    for(const auto &f:facts) {
        // cout << n << " " << f.second << " " << f.first << endl;
        // cout << valid(n, f.second, f.first) << endl;
        if(!valid(n, f.second, f.first))
            return false;
    }
    return true;
}

int main() {
    criba();
    
    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF) {
        if(testCase(n, m))
            printf("%d divides %d!\n", m, n);
        else
            printf("%d does not divide %d!\n", m, n);
    }
    
    return 0;
}
