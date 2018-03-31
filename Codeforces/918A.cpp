#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    int a=1, b=1 ;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        while(b < i) {
            int c = a+b;
            a = b ;
            b = c;
        }
        printf("%c", b==i? 'O' : 'o');
    }
    printf("\n");
}
