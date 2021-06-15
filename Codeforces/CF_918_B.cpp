#include <bits/stdc++.h>
using namespace std;

map <unsigned int, string> dico;

unsigned int toNum(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    return d + (c<<8) + (b<<16) + (a<<24);
}

int main() {
    int N, M ;
    char foo[15], bar[15];

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%s%s", foo, bar);
        int a, b, c, d;
        sscanf(bar, "%d.%d.%d.%d", &a, &b, &c, &d);
        dico[toNum(a, b, c, d)] = foo;
    }
    for(int i=0; i<M; i++) {
        scanf("%s%s", foo, bar);
        int a, b, c, d;
        sscanf(bar, "%d.%d.%d.%d", &a, &b, &c, &d);
        printf("%s %s #%s\n", foo, bar, dico[toNum(a, b, c, d)].c_str());
    }
}
