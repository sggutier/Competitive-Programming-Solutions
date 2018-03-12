#include <stdio.h>

int main() {
    int a, b, c;

    while(scanf("%d%d%d", &a, &b, &c)!=EOF && (a || b || c))
        if(b%2)
            printf("Keka\n");
        else
            printf("Gared\n");
    
    return 0;
}
