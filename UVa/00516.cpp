#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
const int limN = 33000;
const int limP = limN;

bool comp[limN + 1];
int primCnt = 0;
int primos[limP];
vector <par> facts[limN + 1];

void criba(int N = limN) {
    for(int i=2; i*i<=limN; i++)
        if(!comp[i])
            for(int j=i*i; j<=limN; j+=i)
                comp[j] = true;
    for(int i=2; i<=limN; i++)
        if(!comp[i])
            primos[primCnt++] = i;
}

void precarga(int N = limN) {
    for(int i=primCnt-1; i>=0; i--) {
        int p = primos[i];
        for(int j=p; j<=limN; j+=p) {
            int cnt = 0, x=j;
            while(x%p==0) {
                x /= p; cnt++;
            }
            facts[j].push_back(par(p, cnt));
        }
    }
}

void testCase(int N) {
    N --;
    int cnt = 0;
    for(const par &p:facts[N]) {
        if(cnt++)
            printf(" ");
        printf("%d %d", p.first, p.second);
    }
    printf("\n");
}

char* leeNum(char *s, int &ans) {
    ans = 0;
    while(isdigit(*s)) {
        ans = ans*10 + (*s - '0');
        s++;
    }
    if(*s)
        s++;    
    return s;
}

int leeLinea(char *s) {
    int ans = 1;
    int p, pot;
    while(*s) {
        s = leeNum(s, p);
        s = leeNum(s, pot);        
        while(pot--)
            ans *= p;
    }
    return ans;
}

int main() {
    char S[5000];
    criba();
    precarga();
    while(gets(S)) {
        if(S[0]=='0')
            break;
        testCase(leeLinea(S));
    }
}
