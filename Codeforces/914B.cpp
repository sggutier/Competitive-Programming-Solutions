#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
#define f first
#define s second

int main() {
    int N ;
    map <int, int> mp;
    vector <par> nums;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a ;
        scanf("%d", &a);
        mp[a]++;
    }

    for(const auto &p:mp)
        nums.push_back(p);

    for(int i=nums.size()-1; i>=0; i--) {
        // printf("%d %d\n", nums[i].f, nums[i].s);
        if(nums[i].s % 2) {
            printf("Conan\n");
            return 0;
        }
    }

    printf("Agasa\n");
}
