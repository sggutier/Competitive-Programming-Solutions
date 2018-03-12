#include <bits/stdc++.h>
using namespace std;

int N;
char str[20];
int nums[20];
long long calcWaysMemo[20][20];
bool usd[20][20];

long long calcWays(int row, int col) {
    if(nums[col]!=-1 && row!=nums[col])
        return 0LL;
    if(col==N-1)
        return 1LL;
    if(usd[row][col])
        return calcWaysMemo[row][col];
    usd[row][col] = true;
    long long ans;
    for(int i=0; i<N; i++)
        if(abs(row-i)>1)
            ans += calcWays(i, col+1);
    return calcWaysMemo[row][col] = ans;
}

void testCase() {
    N = strlen(str);
    for(int i=0; i<N; i++) {
        if(str[i]=='?')
            nums[i] = -1;
        else if(isdigit(str[i]))
            nums[i] = str[i]-'1';
        else
            nums[i] = str[i]-'A' + 9;
    }
    memset(usd, 0, sizeof(usd));
    long long ans = 0LL;
    for(int i=0; i<N; i++)
        ans += calcWays(i, 0);
    printf("%lld\n", ans);
}

int main() {
    while(gets(str) && str[0]) {
        testCase();
    }
}
