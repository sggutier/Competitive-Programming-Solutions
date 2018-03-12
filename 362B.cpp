#include <bits/stdc++.h>
using namespace std;

int main() {
    int U, n;
    vector <int> nums;

    cin >> U >> n ;
    nums.resize(n);
    for(int &c : nums)
        cin >> c;
    sort(nums.begin(), nums.end());

    bool works = !n || (nums[n-1]!=U && nums[0]!=1);
    for(int i=2; i<n && works; i++) {
        works &= (nums[i] != nums[i-1]+1) || (nums[i] != nums[i-2]+2);
    }

    printf("%s\n", works? "YES" : "NO");
}
