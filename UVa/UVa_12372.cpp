#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        bool works = true;
        int tmp;
        for(int j=0; j<3; j++) {
            scanf("%d", &tmp);
            if(tmp>20) {
                works = false;
            }
        }
        printf("Case %d: %s\n", i, works? "good" : "bad");
    }
    
    return 0;
}
