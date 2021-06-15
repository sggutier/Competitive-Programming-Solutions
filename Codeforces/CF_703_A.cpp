#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    int x=0, y=0;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        if(a>b)
            x++;
        else if(a<b)
            y++;
    }
    printf("%s\n", x>y? "Mishka" : (x<y? "Chris" : "Friendship is magic!^^"));
}
