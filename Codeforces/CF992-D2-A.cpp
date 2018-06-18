#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    set <int> nums;
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        if(a)
            nums.insert(a);
    }
    printf("%d\n", (int) nums.size());
}
