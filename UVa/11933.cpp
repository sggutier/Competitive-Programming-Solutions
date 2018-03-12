#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    int nums[] = {0, 0}, k=0;
    for(int i=0; i<32; i++) {
        if(((1<<i) & n)==0)
            continue;
        nums[k] |= (1<<i);
        k = (k+1)%2;
    }
    printf("%d %d\n", nums[0], nums[1]);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
