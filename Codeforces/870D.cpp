#include <bits/stdc++.h>
using namespace std;
const int limN = 5e3;

int N;
int querMemo[limN][limN];
bool usd[limN];
int p[limN];
int b[limN];
int ansCnt = 0;
int ansPos = 0;

int query(int a, int b) {
    if(querMemo[a][b]!=-1)
        return querMemo[a][b];
    if(a!=0 && b!=0)
        return querMemo[a][b] = query(a, 0) ^ query(0, b) ^ query(0, 0);
    printf("? %d %d\n", a, b);
    fflush(stdout);
    scanf("%d", &querMemo[a][b]);
    return querMemo[a][b];
}

bool makesSense() {
    for(int i=0; i<N; i++)
        if(query(0, i) != (p[0]^b[i]) || query(i, 0) != (p[i]^b[0]))
            return false;
    return true;
}

bool getPerm(int b0) {
    if(query(b0, 0) != b0)
        return false;
    memset(usd ,0, sizeof(usd));
    for(int i=0; i<N; i++) {
        b[i] = query(b0, i);
        if(b[i] >= N || usd[b[i]])
            return false;
        p[b[i]] = i;
        usd[b[i]] = true;
    }
    return makesSense();
}

int main() {
    scanf("%d", &N);
    memset(querMemo, -1, sizeof(querMemo));

    for(int i=0; i<N; i++) {
        if(!getPerm(i))
            continue;
        ansCnt++;
        ansPos = i;
    }

    getPerm(ansPos);

    printf("!\n");
    fflush(stdout);
    printf("%d\n", ansCnt);
    fflush(stdout);
    for(int i=0; i<N; i++) {
        if(i)
            printf(" ");
        printf("%d", p[i]);
    }
    printf("\n");
    fflush(stdout);
}
