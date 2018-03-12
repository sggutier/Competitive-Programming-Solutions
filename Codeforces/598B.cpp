#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

int main() {
    char str[limN];
    char cpy[limN];
    int N;
    int a, b, k;

    scanf("%s", str);
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d%d", &a, &b, &k);
        a--, b--;
        int tam = b-a+1, d = tam - k%tam;
        for(int j=0; j<tam; j++)
            cpy[j] = str[a+j];
        for(int j=0; j<tam; j++) {
            str[a + j] = cpy[(j + d)%tam];
            //printf("%d => %d\n", a+j, a+(j+d)%tam);
        }
    }

    printf("%s\n", str);
}
