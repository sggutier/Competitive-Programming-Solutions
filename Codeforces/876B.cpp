#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N, K, M ;
    vector <int> nums[limN];

    scanf("%d%d%d", &N, &K, &M);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        nums[a%M].push_back(a);
    }

    for(int i=0; i<M; i++) {
        if((int) nums[i].size() >= K) {
            printf("Yes\n");
            for(int j=K-1; j>=0; j--)
                printf("%d ", nums[i][j]);
            printf("\n");
            return 0;
        }
    }

    printf("No\n");
}
