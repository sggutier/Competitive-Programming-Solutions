#include <cstdio>
// typedef long double ld;
// const int limN = 3e5 + 5;

// ld lgs[limN];
int ans[25]  = {0 ,2 ,3 ,5 ,8 ,12 ,20 ,34 ,57 ,98 ,170 ,300 ,536 ,966 ,1754 ,3210 ,5910 ,10944 ,20366 ,38064 ,71421 ,134480 ,254016 };

int main() {
    // for(int i=1; i<limN; i++)
    //     lgs[i] = log2l(i);

    // ld sm = 0;
    // printf("0 ");
    // for(int i=1, a=1; i<limN; i++) {
    //     sm += lgs[i];
    //     while(sm >= (1<<a)) {
    //         printf(",%d ", i-1);
    //         ans[a] = i-1;
    //         a++;
    //     }
    // }

    int n ;
    while(scanf("%d", &n) && n) {
        printf("%d\n", ans[(n-1940)/10]);
    }
}
