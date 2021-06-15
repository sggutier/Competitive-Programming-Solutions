#include <bits/stdc++.h>
using namespace std;

struct Frac {
    int num, den;
    Frac(int _num, int _den) : num(_num), den(_den) {}
    
};

int main() {
    int N ;
    int a, b, c=0 ;
    char w ;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%c", &w);
        scanf("%c", &w);
        scanf("%d+%d", &a, &b);
        scanf("%c", &w);
        scanf("%c", &w);
        scanf("%d", &c);
        printf("%d %d => %d\n", a, b, c);
    }
}
