#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e7 ;

int firstApr[LIM_N + 1];
int acm[LIM_N + 1];

void digPs(int pos=0, int sm=0, int pt=LIM_N / 10) {
    if(pt == 0) {
        if(pos + sm <= LIM_N && !firstApr[pos + sm])
            firstApr[pos + sm] = pos ;
        return;
    }
    for(int i=0; i < 10; i++)
        digPs(pos + pt*i, sm + i, pt / 10);
}

void init() {
    digPs();
    for(int i=1; i <= LIM_N; i++) {
        acm[i] = acm[i-1];
        if(!firstApr[i]) {
            acm[i] ++;
            firstApr[i] = -1;
        }
    }
}

int main() {
    init();
    int N ;
    char tmp[50000];
    fgets(tmp, sizeof(tmp), stdin);
    sscanf(tmp, "%d", &N);
    for(int i=0, a, b; i < N; i++) {
        fgets(tmp, sizeof(tmp), stdin);
        printf("Case %d: ", i+1);
        int x = sscanf(tmp, "%d%d", &a, &b);
        if(x == 2)
            printf("%d\n", acm[b] - acm[a-1]);
        else
            printf("%d\n", firstApr[a]);
    }
}
