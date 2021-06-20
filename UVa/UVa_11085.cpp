#include <bits/stdc++.h>
using namespace std;

int ans ;
int org[8];
int rows[8];
bool usd[8];

void bruta(int pos=0, int sum=0) {
    if(pos==8) {
        ans = min(ans, sum);
        return;
    }
    for(int i=0; i<8; i++) {
        if(usd[i])
            continue;
        bool wks = true;
        for(int j=0; j<pos; j++) {
            if(pos-j == abs(i - rows[j]))  {
                wks = false;
                break;
            }
        }
        if(!wks)
            continue;
        usd[i] = true;
        rows[pos] = i;
        bruta(pos+1, sum + (i!=org[pos]? 1 : 0));
        usd[i] = false;
    }
}

void testCase() {
    org[0] --;
    for(int i=1; i<8; i++) {
        scanf("%d", &org[i]);
        org[i] --;
    }
    ans = (1<<30);
    bruta();
    printf("%d\n", ans);
}

int main() {
    int tc = 1;
    while(scanf("%d", &org[0])!=EOF) {
        printf("Case %d: ", tc++);
        testCase();
    }
}
