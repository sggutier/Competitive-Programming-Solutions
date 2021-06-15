#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int N ;
    scanf("%d", &N);
    vector <int> nums(N);
    set <pair<int,int>> Q ;
    for(int i=0; i < N; i++) {
        scanf("%d", &nums[i]);
        Q.insert({-nums[i], i});
    }
    while(!Q.empty()) {
        int pos = Q.begin()->second;
        for(int i=pos; i < N; i++) {
            printf("%d ", nums[i]);
            Q.erase({-nums[i], i});
        }
        N = pos;
    }
    printf("\n");
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
