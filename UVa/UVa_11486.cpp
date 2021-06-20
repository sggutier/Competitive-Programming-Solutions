#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
const int B = 7;
const int limB = 1<<B;
const int limM = 35;

struct Mat {
    ll nums[limM][limM];
    Mat() {
        memset(nums, 0, sizeof(nums));
    }
    Mat(vector<vector <int>> A) {
        for(int i=0; i<limM; i++)
            for(int j=0; j<limM; j++)
                nums[i][j] = A[i][j];
    }    
};

Mat operator*(Mat A, Mat B) {
    Mat C ;
    for(int i=0; i<limM; i++) {
        for(int j=0; j<limM; j++) {
            for(int k=0; k<limM; k++) {
                C.nums[i][j] = (C.nums[i][j] + A.nums[i][k] * B.nums[k][j])%mod;
            }
        }
    }
    return C;
}

Mat BAS;
int E = 0;
int eno[limB];

Mat pot(long long k) {
    if(k==1)
        return BAS;
    Mat mit = pot(k/2);
    if(k%2)
        return mit*mit*BAS;
    else
        return mit*mit;
}

void precarga() {
    int bitCnt[limB];
    memset(bitCnt, 0, sizeof(limB));
    memset(eno, 0, sizeof(eno));

    for(int b=0; b<limB; b++) {
        int cnt = 0;
        for(int i=0; i<B; i++)
            if((1<<i) & b)
                cnt++;
        bitCnt[b] = cnt;
        if(cnt==4)
            eno[b] = E++;
    }

    for(int b=0; b<limB; b++) {
        if(bitCnt[b]!=4)
            continue;
        // for(int i=0; i<7; i++)
        //     printf("%d", (1<<i) & b? 1 : 0);
        // printf("\n");
        for(int w=(1<<4)-1; w>=0; w--) {
            int sum = 0;
            for(int i=0, cnt=0; i<B; i++) {
                if((1<<i) & b) {
                    if((1<<cnt) & w)
                        sum |= (1<<(i+1));
                    else
                        sum |= (1<<i)>>1;
                    cnt++;
                }
            }
            if(sum>=limB || bitCnt[sum]!=4)
                continue;
            BAS.nums[eno[b]][eno[sum]] ++;
            // printf("\t");
            // for(int i=0; i<7; i++)
            //     printf("%d", ((1<<i) & sum)? 1 : 0);
            // printf("\n");
        }
    }
}

void testCase() {
    int N;
    int ini = 0;
    scanf("%d", &N);
    for(int i=0; i<7; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp)
            ini |= (1<<i);
    }
    ini = eno[ini];
    if(N==1) {
        printf("1\n");
        return ;
    }
    Mat mo = pot(N-1);
    long long ans = 0;
    for(int i=0; i<limM; i++)
        ans = (ans + mo.nums[ini][i])%mod;
    printf("%lld\n", ans);
}

int main() {
    precarga();
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
