#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 300;

struct BIT {
    int arr[MAX_N];
    void reset() {
        memset(arr, 0, sizeof(arr));
    }
    void mete(int pos, int nov=1) {
        for(; pos<MAX_N; pos += (pos & -pos))
            arr[pos] += nov;
    }
    int saca(int pos) {
        int ans = 0;
        for(; pos; pos -= (pos & -pos))
            ans += arr[pos];
        return ans;
    }
};

BIT bt;
int N;
char lineas[MAX_N][MAX_N];
int dRat[MAX_N], perms[MAX_N];

int calcDst(char *nums) {
    bt.reset();
    
    int ans = 0LL;
    for(int i=N-1; i>=0; i--) {
        ans += bt.saca(nums[i]-1);
        bt.mete(nums[i]);
    }

    return ans;
}

void testCase() {
    int K;
    
    scanf("%d%d", &N, &K);
    for(int i=0; i<K; i++) {
        scanf("%s", lineas[i]);
        dRat[i] = calcDst(lineas[i]);
        perms[i] = i;
    }

    sort(perms, perms+K, [] (const int &a, const int &b) -> bool {return dRat[a] != dRat[b]? dRat[a] < dRat[b] : a<b;});

    for(int i=0; i<K; i++)
        printf("%s\n", lineas[perms[i]]);
}

int main() {
    int tc = 0;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
