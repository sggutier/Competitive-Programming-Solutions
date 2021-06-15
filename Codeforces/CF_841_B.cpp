#include <bits/stdc++.h>
using namespace std;

int main() {
    int s = 0;
    int N ;
    int ocnt = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        if(a%2)
            ocnt ++;
        s = (s+a)%2;
    }

    printf("%s\n", s? "First" : (ocnt>1? "First" : "Second"));
}
