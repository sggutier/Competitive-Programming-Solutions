#include <bits/stdc++.h>
using namespace std;
const int limN = 1e7 + 5;

int N ;
char str[limN];

int getL(const int p)  {
    return str[p]==0? -1 : (str[p]-'A') % 2;
}

int main() {
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &N);
    fgets(str, sizeof(str), stdin);
    str[2*N-1] = 0;

    int funca = 1;
    for(int i=0; i<N && funca; i+=2) {
        // printf("%d %c%c\n", i, str[2*i], str[2*i + 2]);
        int a = getL(2*i);
        int b = getL(2*i + 2);
        // printf("\t %d %d\n", a, b);
        if(a != 0 || b != 1)
            funca = 0;
    }

    printf("%d\n", N-1+funca);
}
