#include <bits/stdc++.h>
using namespace std;

int main() {
    int lumbs[10];
    int tc ;

    printf("Lumberjacks:\n");
    for(scanf("%d", &tc); tc; tc--) {
        bool works = true, worksB = true;
        for(int i=0; i<10; i++) {
            scanf("%d", &lumbs[i]);
            if(i && lumbs[i]<lumbs[i-1])
                works = false;
            if(i && lumbs[i]>lumbs[i-1])
                worksB = false;
        }
        printf("%srdered\n", (works || worksB)? "O" : "Uno");
    }
    
    return 0;
}
