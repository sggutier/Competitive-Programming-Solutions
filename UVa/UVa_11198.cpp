#include <bits/stdc++.h>
using namespace std;
const int MAX_P = 40320;
const int facts[] = {1, 1, 2, 6, 24, 120, 720, 5040};
const int N = 8;

int ords[MAX_P][N];
bool comp[2*N + 1];
int nums[N];
int minP[MAX_P];

void precarga();
void iToP(int pNum, int *arr);
int pToI(int *arr);
bool swapable(int *arr, int pos);
void testCase();
int bfs(int ini);

void testCase() {
    for(int i=1; i<8; i++)
        scanf("%d", &nums[i]);
    int arr[8];
    for(int i=0; i<8; i++)
        arr[i] = abs(nums[i])-1;
    sort(nums, nums+N, [] (int a, int b) {return abs(a) < abs(b);});
    printf("%d\n", bfs(pToI(arr))-1);
}

int main() {
    precarga();
    int tc = 0;
    while(scanf("%d", &nums[0])!=EOF && nums[0]) {
        printf("Case %d: ", ++tc);
        testCase();
    }
}

int bfs(int ini) {
    memset(minP, 0, sizeof(minP));
    minP[ini] = 1;
    queue <int> Q;
    int arr[N+1], nov[N+1];
    arr[N] = nov[N] = 0;
    Q.push(ini);

    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        int dst = minP[pos]+1;
        if(pos==0)
            return dst-1;
        iToP(pos, arr);
        for(int i=0; i<N; i++) {
            copy(arr, arr+N, nov);
            for(int j=i-1; j>=0; j--) {
                swap(nov[j], nov[j+1]);
                if(!swapable(nov, j))
                    continue;
                int sig = pToI(nov);
                if(!minP[sig]) {
                    minP[sig] = dst;
                    Q.push(sig);
                }
            }
            copy(arr, arr+N, nov);
            for(int j=i+1; j<N; j++) {
                swap(nov[j], nov[j-1]);
                if(!swapable(nov, j))
                    continue;
                int sig = pToI(nov);
                if(!minP[sig]) {
                    minP[sig] = dst;
                    Q.push(sig);
                }
            }
        }
    }
    
    return 0;
}

void precarga() {
    int L = 2*N;
    for(int i=2; i*i<=L; i++)
        if(!comp[i])
            for(int j=i*i; j<=L; j+=i)
                comp[j] = true;
    comp[0] = comp[1] = true;
    int arr[N];
    for(int i=0; i<N; i++)
        arr[i] = i;
    int cnt = 0;
    do {
        for(int i=0; i<N; i++)
            ords[cnt][i] = arr[i];
        cnt++;
    } while(next_permutation(arr, arr+N));
}

inline bool sgn(int n) {
    return n > 0;
}

bool swapable(int *arr, int pos) {
    if(pos && sgn(nums[arr[pos]])!=sgn(nums[arr[pos-1]]) && !comp[abs(nums[arr[pos]]) + abs(nums[arr[pos-1]])])
        return true;
    return (pos+1<N && sgn(nums[arr[pos]])!=sgn(nums[arr[pos+1]]) && !comp[abs(nums[arr[pos]]) + abs(nums[arr[pos+1]])]);
}

void iToP(int p, int *arr) {
    copy(ords[p], ords[p]+8, arr);
}

int pToI(int *arr) {
    int ans = 0, b;
    for(int i=0; i<N; i++) {
        b = 0;
        for(int j=i+1; j<N; j++)
            if(arr[i] > arr[j])
                b++;
        ans += facts[N-1-i]*b;
    }
    return ans;
}
