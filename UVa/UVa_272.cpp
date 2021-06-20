#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    char c;
    bool loaded_p = false;
    while(scanf("%c",&c)!=EOF) {
        if(c!='\"')
            printf("%c",c);
        else {
            if(loaded_p)
                printf("\'\'");
            else
                printf("``");
            loaded_p ^= 1;
        }
    }
    
    return 0;
}
