#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
const int limN = 1e6;
const int limP = 1e5;

bitset <limN+1> comp;
int primCnt;
int primos[limP];
vector <par> divs[limN+1];
int ans[limN+1];

void criba() {
    for(int i=2; i*i<limN; i++)
        if(!comp[i])
            for(int j=i*i; j<limN; j+=i)
                comp[j] = true;
    for(int i=2; i<limN; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

void precarga() {
    criba();
    for(int i=0; i<primCnt; i++) {
        if(i==0 || i==2)
            continue;
        int p = primos[i];
        for(int j=p; j<=limN; j+=p) {
            int cnt = 0, n=j;
            while(n%p==0) {
                cnt ++;
                n /= p;
            }
            divs[j].push_back(par(i, cnt));
        }
    }
    vector <int> reps(primCnt, 0);
    int pots[] = {6, 2, 4, 8};
    int dos = 0, cinc=0;
    int res = 1;
    for(int i=2; i<=limN; i++) {
        int n = i;
        int a=0, b=0;
        while(n%2==0) {a++, n/=2;}
        while(n%5==0) {b++, n/=5;}
        dos = max(dos, a);
        cinc = max(cinc, b);
        //printf("%d => %d %d => ", i, dos, cinc);
        for(const auto &d:divs[i]) {
            //printf("(%d %d) ", primos[d.first], d.second);
            int dif = max(0, d.second-reps[d.first]), p = primos[d.first];
            reps[d.first] += dif;
            while(dif--)
                res = (res*p)%10;
        }
        //printf("\n");
        ans[i] = (pots[(dos-cinc)%4]*res)%10;
    }
    ans[1] = 1;
}

int main() {
    precarga();
    int n;
    while(scanf("%d", &n)!=EOF && n)
        printf("%d\n", ans[n]);
}
