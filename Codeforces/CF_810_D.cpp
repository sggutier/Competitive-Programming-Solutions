#include <bits/stdc++.h>
using namespace std;

bool queryNum(int a, int b) {
    printf("1 %d %d\n", a, b);
    fflush(stdout);
    char tmp[10];
    scanf("%s", tmp);
    return tmp[0] == 'T';
}

int findNum(int ini, int fin) {
    if(fin < ini)
        return -1;
    if(ini == fin)
        return ini;
    int piv = (ini + fin) >> 1;
    if(queryNum(piv, piv+1))
        return findNum(ini, piv);
    else
        return findNum(piv+1, fin);
}

int main() {
    int N, K ;
    scanf("%d%d", &N, &K);
    int fp = findNum(1, N);
    int sc = findNum(1, fp-1);
    if(sc == -1 || !queryNum(sc, fp))
        sc = findNum(fp+1, N);
    printf("2 %d %d\n", fp, sc);
    fflush(stdout);
}
