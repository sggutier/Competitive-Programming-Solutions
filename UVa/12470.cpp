#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 9;

struct Mat {
    ll nums[3][3];
    Mat() {
        memset(nums, 0, sizeof(nums));
    }
    Mat(vector<vector <int>> A) {
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                nums[i][j] = A[i][j];
    }    
};

Mat operator*(Mat A, Mat B) {
    Mat C ;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                C.nums[i][j] = (C.nums[i][j] + A.nums[i][k] * B.nums[k][j])%mod;
            }
        }
    }
    return C;
}

Mat BAS({{0, 1, 0}, {0, 0, 1}, {1, 1, 1}});
Mat ID({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});

Mat pot(long long k) {
    if(k==1)
        return BAS;
    Mat mit = pot(k/2);
    if(k%2)
        return mit*mit*BAS;
    else
        return mit*mit;
}

void testCase(long long N) {
    if(N<=3) {
        printf("%lld\n", N-1);
        return;
    }
    Mat ans = pot(N-3);
    printf("%lld\n", (ans.nums[2][1] + 2*ans.nums[2][2])%mod);
}

int main() {
    //int tc = 0;
    long long n;
    while(scanf("%lld", &n)!=EOF && n) {
        //printf("Case %d: ", ++tc);
        testCase(n);
    }
}
