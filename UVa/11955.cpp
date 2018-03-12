#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    char strA[50], strB[50];
    int pot ;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        scanf("(%s+%s)", strA, strB);
        printf("%s %s %d\n", strA, strB, pot);
    }
    
    return 0;
}
