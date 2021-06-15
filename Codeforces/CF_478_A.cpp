#include <bits/stdc++.h>
using namespace std;

int main() {
    int sumo = 0;
    for(int i=0, a; i<5; i++) {
        scanf("%d", &a);
        sumo += a;
    }

    if(sumo %5 || sumo == 0)
        printf("-1\n");
    else
        printf("%d\n", sumo / 5);
}
