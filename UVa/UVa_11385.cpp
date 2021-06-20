#include <bits/stdc++.h>
using namespace std;
const int limF = 105;

map<int,int> fiToI;

void precarga() {
    long long a, b;

    a=1;
    b=1;
    for(int i=0; b<(1LL<<31); i++) {
        fiToI[(int) b] = i;
        int c = b;
        b = a+b;
        a = c;
    }
}

void testCase() {
    int N, maxF=0;
    int arr[limF];
    char S[limF];
    char ans[limF];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        arr[i] = fiToI[arr[i]];
        maxF = max(maxF, arr[i]);
    }   
    gets(S);
    gets(S);

    ans[maxF+1] = 0;
    for(int i=0; i<=maxF; i++)
        ans[i] = ' ';

    int cnt = 0;
    for(char *c = S; *c && cnt<N; c++) {
        if(!isupper(*c))
            continue;
        ans[arr[cnt]] = *c;
        cnt++;
    }
    printf("%s\n", ans);
}

int main() {
    precarga();

    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
