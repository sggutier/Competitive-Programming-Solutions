#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int n, n2;
string ini, fin;
char ans[limN*2];
stack<char> S;

void bruta(int iniPos, int finPos, int ansPos) {
    if(ansPos==n2) {
        printf("%s\n", ans);
        return ;
    }
    if(iniPos<n) {
        ans[2*ansPos] = 'i';
        S.push(ini[iniPos]);
        bruta(iniPos+1, finPos, ansPos + 1);
        S.pop();
    }
    if(!S.empty() && S.top()==fin[finPos]) {
        char k = S.top();
        S.pop();
        ans[2*ansPos] = 'o';
        bruta(iniPos, finPos+1, ansPos + 1);
        S.push(k);
    }
}

void testCase(char *tmpa, char *tmpb) {
    printf("[\n");

    ini = tmpa;
    fin = tmpb;
    n = ini.size(); n2 = 2*n;
    for(int i=2*n2; i>=0; i--)
        ans[i] = ' ';
    ans[2*n2-1] = 0;
    if((int) fin.size()==n)
        bruta(0, 0, 0);
    
    printf("]\n");
}

int main() {
    char A[limN], B[limN];

    while(scanf("%s%s", A, B)!=EOF) {
        testCase(A, B);
    }
    
    return 0;
}
