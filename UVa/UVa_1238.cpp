#include <bits/stdc++.h>
using namespace std;
const int limS = 3000;
const int limN = 31;

bool ans[2*limS+1];
bool usd[limN][limN][2*limS+1];
int numCnt ;
int nums[limN];
bool isNeg[limN];

void parseaLinea(char *S) {
    int N = strlen(S), ult=-1;
    numCnt = 0;
    S[N] = ' ';
    for(int i=0; i<=N; i++) {
        if(isdigit(S[i])) {
            if(ult==-1)
                ult = 0;
            ult = ult*10 + S[i]-'0';
        }
        else {
            if(ult!=-1) {
                nums[numCnt++] = ult;
                ult = -1;
            }
            if(S[i]!=' ')
                isNeg[numCnt] = S[i]=='-';
        }
    }
}

void bruta(int pos=0, int negs=0, int sgn=1, int sumo=0) {
    if(pos == numCnt) {
        ans[sumo + limS] = true;
        return;
    }
    if(isNeg[pos]) {
        sgn *= -1;
        negs += 1;
    }
    sumo += nums[pos]*sgn;
    if(usd[pos][negs][sumo]) {
        return;
    }
    usd[pos][negs][sumo] = true;
    bruta(pos+1, negs, sgn, sumo);
    if(negs>0)
        bruta(pos+1, negs-1, -sgn, sumo);
}

void testCase(char *S) {
    memset(usd, 0, sizeof(usd));
    memset(ans, 0, sizeof(ans));
    parseaLinea(S);
    bruta();
    int cnt = 0;
    for(int i=2*limS; i>=0; i--)
        if(ans[i])
            cnt ++;
    printf("%d\n", cnt);
}

int main() {
    char S[1000];
    while(gets(S))
        testCase(S);
}
