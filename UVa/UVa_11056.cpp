#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

string namesLow[limN];
char names[limN][30];
int nums[limN] ;
int idx[limN];

void testCase(int N) {
    for(int i=0; i<N; i++) {
        idx[i] = i;
        char tmp[50];
        scanf("%s", names[i]);
        namesLow[i] = names[i];
        for(int j=namesLow[i].size()-1; j>=0; j--)
            namesLow[i][j] = tolower(names[i][j]);
        scanf("%s", tmp);
        int k = 0;
        nums[i] = 0;
        for(int j=0; j<3; j++) {
            scanf("%d", &k);
            scanf("%s", tmp);
            if(j!=2)
                nums[i] = nums[i]*60 + k;
            else
                nums[i] = nums[i]*1000 + k;
        }
        // printf("%s %d\n", names[i], nums[i]);
    }

    sort(idx, idx+N, [](const int &x, const int &y) {
            if(nums[x] != nums[y])
                return nums[x] < nums[y];
            return namesLow[x] < namesLow[y];
        });
    
    for(int i=0; i<N; i++) {
        if(i%2==0)
            printf("Row %d\n", i/2 + 1);
        printf("%s\n", names[idx[i]]);
    }
    printf("\n");
            
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n) {
        testCase(n);
    }
}
