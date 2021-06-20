#include <bits/stdc++.h>
using namespace std;

string words[3] = {"one", "two", "three"};

int diff(string A, string B) {
    if(A.size()!=B.size())
        return B.size() + 20;
    int ans = 0;
    for(int i=0; i<(int) A.size(); i++)
        if(A[i]!=B[i])
            ans ++;
    return ans;
}

int main() {
    int n;
    char tmp[1005];
    for(scanf("%d", &n); n; n--) {
        scanf("%s", tmp);
        for(int j=0; j<3; j++) {
            if(diff(words[j], tmp)<=1) {
                printf("%d\n", j+1);
            }
        }
    }
    return 0;
}
