#include <bits/stdc++.h>
using namespace std;

void caso(int n) {
    bool solucion = false;
    for(int b=1; b<=99999/n; b++) {
        bool* usado = new bool[10]();
        bool bueno = true;
        int a = b*n;
        string sa = to_string(a), sb = to_string(b);
        if(b < 10000 || a<10000)
            usado[0] = true;
        for(int i=0; i<(int) sa.size(); i++)
            usado[sa[i]-'0'] = true;
        for(int i=0; i<(int) sb.size(); i++)
            usado[sb[i]-'0'] = true;
        for(int i=0; i<10; i++)
            if(!usado[i])
                bueno = false;
        if(bueno) {
            solucion = true;
            printf("%05d / %05d = %d\n", b*n, b, n);
        }
        delete usado;
    }
    if(!solucion)
        printf("There are no solutions for %d.\n", n);
}

int main() {
    int n;
    bool primero = true;
    while(scanf("%d", &n)!=EOF && n!=0) {
        if(!primero)
            printf("\n");
        primero = false;
        caso(n);
    }
}
