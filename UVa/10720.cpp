#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N;
int nums[limN];

bool testCase() {
    int sumA = 0;
    for(int i=1; i<=N; i++)
        scanf("%d", &nums[i]);

    sort(nums+1, nums+N+1);
    reverse(nums+1, nums+N+1);
    
    for(int i=1; i<=N; i++) {
        sumA += nums[i];
        int sum = i*(i-1);
        for(int j=i+1; j<=N; j++) {
            //printf(" => %d %d\n", i, nums[j]);
            sum += min(i, nums[j]);
        }
        //printf("%d %d\n", sumA, sum);
        if(sumA > sum)
            return false;
    }

    return sumA%2==0;
}

int main() {
    while(scanf("%d", &N)!=EOF && N) {
        printf("%s\n", testCase()? "Possible" : "Not possible");
    }
}
