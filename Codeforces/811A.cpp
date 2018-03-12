#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i=1; ; i++) {
        if(a < i) {
            printf("%s\n", i%2? "Vladik" : "Valera");
            return 0;
        }
        a -= i;
        swap(a, b);
    }
}
