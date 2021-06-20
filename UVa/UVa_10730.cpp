#include <bits/stdc++.h>
using namespace std;

bool testCase(int n) {
    vector <int> nums(n);
    vector <int> ido(n);
    int usd[n];
    int n2 = n/2;
    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
        ido[nums[i]] = i;
    }
    for(int d=-n2; d<=n2; d++) {
        memset(usd, 0, sizeof(usd));
        for(int i=1; i<n; i++) {
            int ant = nums[i]+d;
            if(0<=ant && ant < n) {
                if(ido[ant]<i) {
                    if(usd[ido[ant]])
                        return false;
                    usd[i] = true;
                }
            }
        }        
    }
    return true;
}



int main() {
    int n;
    while(scanf("%d:", &n)!=EOF && n) {
        printf("%s\n", testCase(n)? "yes" : "no");
    }
}
