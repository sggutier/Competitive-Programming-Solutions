#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define r first
#define c second

inline int dst(par A, par B) {
    return abs(A.r - B.r) + abs(A.c - B.c);
}

par cords[25];

void testCase() {
    int N;
    par cits[25];
    int pop[25];
    int ans = (1<<30);
    int nums[5];
    int valsFin[5];
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &cits[i].r, &cits[i].c);
        scanf("%d", &pop[i]);
    }
    for(nums[0]=0; nums[0]<21; nums[0]++) {
        for(nums[1]=nums[0]+1; nums[1]<22; nums[1]++)  {
            for(nums[2]=nums[1]+1; nums[2]<23; nums[2]++) {
                for(nums[3]=nums[2]+1; nums[3]<24; nums[3]++) {
                    for(nums[4]=nums[3]+1; nums[4]<25; nums[4]++) {
                        int calc = 0;
                        for(int i=0; i<N; i++) {
                            int a = (1<<30);
                            for(int j=0; j<5; j++)
                                a = min(a, dst(cords[nums[j]], cits[i]));
                            calc += a*pop[i];
                        }
                        if(calc<ans) {
                            ans = calc;
                            for(int i=0; i<5; i++)
                                valsFin[i] = nums[i];
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<5; i++) {
        if(i)
            printf(" " );
        printf("%d", valsFin[i]);
    }
    printf("\n");
}

void precarga() {
    for(int i=0; i<25; i++)
        cords[i] = par(i/5, i%5);
}

int main() {
    precarga();
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
