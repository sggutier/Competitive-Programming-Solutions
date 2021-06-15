#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int N;
int nums[limN];
stack <int> S ;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &nums[i]);
    }
    int Q ;
    scanf("%d", &Q);
    for(int i=0, a; i<Q; i++) {
        scanf("%d", &a);
        nums[a] *= -1;
    }

    for(int i=N; i; i--) {
        if(nums[i] < 0) {
            S.push(-nums[i]);
            continue;
        }
        if(S.empty() || nums[i] != S.top()) {
            S.push(nums[i]);
            nums[i] *= -1;
        }
        else
            S.pop();
    }

    if(!S.empty())
        printf("NO\n");
    else {
        printf("YES\n");
        for(int i=1; i<=N; i++)
            printf("%d ", nums[i]);
        printf("\n");
    }
}
