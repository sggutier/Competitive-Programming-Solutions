#include <bits/stdc++.h>
using namespace std;
const int limN = 300;

int N;
char S[limN];

int parsea(int pos) {
    if(pos>=N)
        return pos+1;
    if(islower(S[pos])) {
        return pos+1;
    }
    if(S[pos]=='N') {
        return parsea(pos+1);
    }
    return parsea(parsea(pos+1));
}

int main() {
    while(scanf("%s", S)!=EOF) {
        N = strlen(S);
        printf("%s\n", parsea(0)==N? "YES":"NO");
    }
    return 0;
}
