#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

bool usd[limN];
bool isComp[limN];
vector< pair<int, int> > ans;

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=2; i*i<=N; i++)
        if(!isComp[i])
            for(int j=i*i; j<=N; j+=i)
                isComp[j] = true;
    for(int p=N; p>=2; p--) {
        if(isComp[p]) continue;
        vector <int> nums ;
        nums.push_back(p);
        for(int j=3*p; j<=N; j+=p) {
            if(usd[j]) continue;
            nums.push_back(j);
        }
        if( p*2 <= N && nums.size() % 2 )
            nums.push_back(p*2);
        for(int i=nums.size()-1; i>0; i-=2) {
            usd[nums[i-1]] = usd[nums[i]] = true;
            ans.push_back({nums[i-1], nums[i]});
        }
    }
    printf("%d\n", (int) ans.size());
    for(const auto &a : ans)
        printf("%d %d\n", a.first, a.second);
}
