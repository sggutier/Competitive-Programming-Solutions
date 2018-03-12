/*
ID: me60
LANG: C++11
TASK: combo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    int lockSize;
    int combos[2][3];
    int myCombo[3];
    int ans = 0;

    scanf("%d", &lockSize);
    for(int j=0; j<2; j++)
        for(int i=0; i<3; i++)
            scanf("%d", &combos[j][i]);

    for(myCombo[0]=1; myCombo[0]<=lockSize; myCombo[0]++)  {
        for(myCombo[1]=1; myCombo[1]<=lockSize; myCombo[1]++)  {
            for(myCombo[2]=1; myCombo[2]<=lockSize; myCombo[2]++)  {
                bool works = false;
                for(int k=0; k<2; k++) {
                    int cnt = 0;
                    for(int i=0; i<3; i++) {
                        if(min(abs(myCombo[i]-combos[k][i]),
                               lockSize - abs(myCombo[i]-combos[k][i]))
                           <= 2)
                            cnt ++;
                    }
                    if(cnt==3)
                        works = true;
                }
                if(works)
                    ans ++;
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
