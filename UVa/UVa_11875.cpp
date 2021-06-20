#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n;
    vector <int> nums;

    scanf("%d", &n);
    nums = vector<int>(n);
    for(int i=0; i<n; i++)
        scanf("%d", &nums[i]);
    printf("%d\n", nums[n/2]);
}

int main() {
    int tc ;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
    
    return 0;
}
