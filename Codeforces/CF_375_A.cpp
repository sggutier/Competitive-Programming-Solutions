#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
bool esp[10] = {0, // 0
                      1, // 1
                      0, // 2
                      0, // 3
                      0, // 4
                      0, // 5
                      1, // 6
                      0, // 7
                      1, // 8
                      1}; // 9

int cnt[10];
char nums[limN] ;
char rdo[6] = "1689";

int main() {
    int N ;
    int sumo = 0;
    int pot = 1;

    scanf("%s", nums);
    N = strlen(nums);
    for(int i=0, w=0; i<N; i++) {
        int k = nums[i]-'0';
        if(!esp[k])
            continue;
        swap(nums[i], nums[w++]);
        esp[k] = false;
    }

    for(int i=N-1; i>=4; i--, pot=(pot*10)%7) {
        sumo = (sumo + (nums[i]-'0')*pot)%7;
    }
    
    do {
        int w ;
        sscanf(rdo, "%d", &w);
        if( (w*pot + sumo) %7 == 0) {
            printf("%s%s\n", rdo, nums+4);
            return 0;
        }
    } while(next_permutation(rdo, rdo+4));

    printf("0\n");
}
