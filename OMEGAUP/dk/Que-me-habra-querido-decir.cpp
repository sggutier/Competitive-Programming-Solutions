#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
const int limC = 128;

char strOrg[limN];
char decod[limC];
char tmp[limN];

int main() {
    fgets(strOrg, limN, stdin);
    for(int i=0; i<limC; i++)
        decod[i] = i;
    int N ;
    fgets(tmp, limN, stdin);
    sscanf(tmp, "%d", &N);
    for(int i=0; i<N; i++) {
        char X[5], Y[5];
        char a, b ;
        fgets(tmp, limN, stdin);
        sscanf(tmp, "%s%s", X, Y);
        a = tolower(Y[0]);
        b = tolower(X[0]);
        decod[(int) a] = b;
        a = toupper(Y[0]);
        b = toupper(X[0]);
        decod[(int) a] = b;
    }
    for(char *p = strOrg; *p; p++) {
        printf("%c", decod[(int) *p]);
    }
}
