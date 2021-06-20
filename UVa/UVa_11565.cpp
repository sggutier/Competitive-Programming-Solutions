#include <bits/stdc++.h>
using namespace std;

string ords[] = {"--+", "-+-", "+--", "+++"};

void testCase(int A, int B, int C) {
    int nums[3];
    int otrs[3];
    for(nums[0]=1; nums[0]*nums[0]*nums[0]<=B; nums[0]++) {
        if(B%nums[0])
            continue;
        int B2 = B/nums[0];
        for(nums[1]=nums[0]; nums[1]*nums[1]<=B2; nums[1]++) {
            if(B2%nums[1])
                continue;
            nums[2] = B2/nums[1];
            if(nums[0]*nums[0] + nums[1]*nums[1] + nums[2]*nums[2]==C) {
                for(int b=0; b<4; b++) {
                    int sum = 0;
                    for(int i=0; i<3; i++)
                        sum += (otrs[i]=(nums[i]*(ords[b][i]=='+'? 1 : -1)));
                    if(sum==A) {
                        sort(otrs, otrs+3);
                        if(otrs[1]!=otrs[0] && otrs[2]!=otrs[1] ) {
                            printf("%d %d %d\n", otrs[0], otrs[1], otrs[2]);
                            return ;
                        }
                    }
                }
            }
        }
    }
    printf("No solution.\n");
}

int main() {
    int tc;
    int a, b, c;

    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d%d", &a, &b, &c);
        testCase(a,b,c);
    }
    
    return 0;
}
