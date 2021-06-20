#include <bits/stdc++.h>
using namespace std;
const int limC = 12;

function<bool (int, int)>fcs[3] = {[](int a, int b) {return a<b;},
                                   [](int a, int b) {return a==b;},
                                   [](int a, int b) {return a>b;} };

int lets[300];
char noms[2][15] = {"light", "heavy"};

int sumo(int msk, int *nums) {
    int ans = 0;
    for(int i=0; i<limC; i++)
        if((1<<i) & msk)
            ans += nums[i];
    return ans;
}

int toB(char *s) {
    int ans = 0;
    for(; *s; s++)
        ans += 1<<(*s-'A');
    return ans;
}

void testCase() {
    char tmp[10];
    int L[3], R[3], opr[3];
    int nums[limC];

    for(int i=0; i<3; i++) {
        scanf("%s", tmp);
        L[i] = toB(tmp);
        scanf("%s", tmp);
        R[i] = toB(tmp);
        scanf("%s", tmp);
        opr[i] = lets[(int) tmp[0]];
    }

    for(int i=0; i<limC; i++)
        nums[i] = 2;

    for(int i=0; i<limC; i++) {
        for(int val=1; val<=3; val+=2) {
            nums[i] = val;
            bool works = true;
            for(int j=0; j<3; j++) {
                if(fcs[opr[j]]( sumo(L[j], nums), sumo(R[j], nums) ) )
                    continue;
                works = false;
                break;
            }
            if(works) {
                printf("%c is the counterfeit coin and it is %s.\n", i+'A', noms[val/2]);
                return;
            }
        }
        nums[i] = 2;
    }
}

int main() {
    lets['d'] = 0;
    lets['e'] = 1;
    lets['u'] = 2;
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
