#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int inf = 2e9;

int main() {
    int N ;
    int nums[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);

    for(int i=0; i<N; i++) {
        printf("%d %d\n", min(i+1<N? nums[i+1]-nums[i] : inf,
                              i? nums[i]-nums[i-1] : inf),
               max(i+1<N? nums[N-1]-nums[i] : -inf,
                   i? nums[i]-nums[0] : -inf));
    }
}
