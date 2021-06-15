#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    int nums[105];
    int maxN = 0;
    int ans = 0;

    cin >> n ;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        maxN = max(maxN, nums[i]);
    }

    for(int i=0; i<n; i++)
        ans += maxN-nums[i];

    cout << ans << endl;
}
