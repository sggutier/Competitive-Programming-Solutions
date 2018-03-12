#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, sumo ;
    
    scanf("%d%d", &N, &sumo);

    if(N==1 && sumo==0) {
        printf("0 0\n");
        return 0;
    }
    if(sumo==0 || sumo > 9*N) {
        printf("-1 -1\n");
        return 0;
    }

    for(int i=N, s=sumo; i; i--) {
        for(int j=(i==N? 1 : 0); j<=9; j++) {
            if( (i-1)*9 >= s-j && s >= j) {
                printf("%d", j);
                s -= j;
                break;
            }
        }
    }
    printf(" ");

    for(int i=N, s=sumo; i; i--) {
        for(int j=9; j>=0; j--) {
            if( (i-1)*9 >= s-j && s >= j) {
                printf("%d", j);
                s -= j;
                break;
            }
        }
    }
    printf("\n");
}
