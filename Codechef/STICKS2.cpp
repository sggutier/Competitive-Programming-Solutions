#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

// void testCase() {
//     map <int, int> orgo, bro;
//     int N, K;

//     scanf("%d%d", &N, &K);
//     for(int i=0, a; i<N; i++) {
//         scanf("%d", &a);
//         orgo[a]++;
//     }

//     auto it = orgo.begin();
//     while(K--) {
//         // printf("k = %d, x = %d, y = %d\n", K+1, it->first, it->second);
//         it->second --;
//         bro[it->first]++;
//         if(!it->second)
//             it = orgo.erase(it);
//         else
//             it++;
//         if(it == orgo.end())
//             it = orgo.begin();
//     }

//     long long mla = 0, mlb = 0;
//     for(it = bro.begin(); it != bro.end(); it++) {
//         // printf("ans = %d %d\n", it->first, it->second);
//         if(it->second < 2)
//             continue;
//         if(it->second < 4)
//             mla = mlb;
//         else
//             mla = it->first;
//         mlb = it->first;        
//     }

//     printf("%lld\n", (mla*mlb) > 0? mla * mlb : -1);
// }

void testCase() {
    int N, K;
    int nums[limN];
    map <int, int> reps;
    long long mla = 0, mlb = 0;

    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums+N);

    nums[N] = 0;
    for(int w=0; w<4 && K; w++) {
        for(int i=0; i<N && K; i++) {
            if(nums[i] && nums[i] != nums[i+1]) {
                // printf("%d ", nums[i]);
                reps[nums[i]]++;
                nums[i] = 0;
                K --;
            }
        }
    }
    // printf("\n");

    for(auto &p : reps) {
        if(p.second < 2) continue;
        if(p.second >= 4)
            mlb = p.first;
        mla = mlb;
        mlb = p.first;
    }

    printf("%lld\n", (mla*mlb) > 0? mla*mlb : -1);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
