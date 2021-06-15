#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

struct BIT {
    int nums[limN];
    int n ;
    BIT() {        
    }
    BIT(int n) : n(n) {
        for(int i=0; i<=n; i++)
            nums[i] = 0;
    }
    void mete(int pos, int k=1) {
        for(pos++; pos<=n; pos += (pos & -pos))
            nums[pos] += k;
    }
    int saca(int pos) {
        int ans = 0;
        for(pos++; pos > 0; pos -= (pos & -pos))
            ans += nums[pos];
        return ans;
    }
};

void regula(int N, int *arr) {
    BIT bt(N);
    for(int i=0; i<N; i++) {
        bt.mete(arr[i]);
        arr[i] -= bt.saca(arr[i]-1);
    }
}

void restaura(int N, int *arr) {
    BIT bt(N);
    for(int i=0; i<N; i++)
        bt.mete(i);
    for(int i=0; i<N; i++) {
        int x=0, y=N-1, w = arr[i]+1;
        //printf("%d => ", w);
        while(x < y) {
            int z = (x+y)/2;
            if(bt.saca(z) < w)
                x = z+1;
            else
                y = z;
        }
        arr[i] = x;
        //printf("%d\n", x);
        bt.mete(arr[i], -1);
    }
}

int main() {
    int N;
    int a[limN], b[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &b[i]);

    regula(N, a);
    regula(N, b);
    for(int i=N-1, s=0; i>=0; i--) {
        int k = N-i;
        s += a[i] + b[i];
        a[i] = s%k;
        s /= k;
    }

    restaura(N, a);
    for(int i=0; i<N; i++)
        printf("%d ", a[i]);
    printf("\n");
}
