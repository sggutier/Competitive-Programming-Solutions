#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    char str[1005];
    scanf("%d%s", &N, str);
    for(int i=0, u=0; i<N; i++) {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='y') {
            if(u==0)
                printf("%c", str[i]);
            u = 1;
        }
        else {
            u = 0;
            printf("%c", str[i]);
        }
    }
    printf("\n");
}
