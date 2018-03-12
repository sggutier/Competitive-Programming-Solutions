#include <bits/stdc++.h>
using namespace std;
const int limT = 6;

int tipCnt ;

struct seso {
    int arr[limT];
    seso() {
        for(int i=0; i<tipCnt; i++)
            arr[i] = 0;
    }
    bool operator<(const seso &otr) const {
        for(int i=0; i<tipCnt; i++)
            if(arr[i] != otr.arr[i])
                return arr[i] < otr.arr[i];
        return false;
    }
};

map <seso, int> minHMemo ;
int mixRes[limT][limT];
int mixHeat[limT][limT];

int minH(seso &stat, int rem) {
    if(rem==1) {
        return 0;
    }
    auto it = minHMemo.find(stat);
    if(it!=minHMemo.end()) {
        return it->second;
    }
    int ans = (1<<30);
    for(int i=0; i<tipCnt; i++) {
        if(!stat.arr[i])
            continue;
        if(stat.arr[i]>=2) {
            stat.arr[i] -= 2;
            stat.arr[mixRes[i][i]] ++;
            ans = min(ans, minH(stat, rem-1) + mixHeat[i][i]);
            stat.arr[mixRes[i][i]] --;
            stat.arr[i] += 2;
        }
        for(int j=0; j<tipCnt; j++) {            
            if(!stat.arr[j] || i==j)
                continue;
            stat.arr[i] -- ;
            stat.arr[j] -- ;
            stat.arr[mixRes[i][j]] ++;
            ans = min(ans, minH(stat, rem-1) + mixHeat[i][j]);
            stat.arr[mixRes[i][j]] --;
            stat.arr[j] ++ ;
            stat.arr[i] ++ ;
        }
    }
    // printf("V\n");
    // for(int i=0; i<tipCnt; i++)
    //     printf("%d ", stat.arr[i]);
    // printf("\n");
    // for(int i=0; i<tipCnt; i++) {
    //     if(!stat.arr[i])
    //         continue;
    //     if(stat.arr[i]>=2) {
    //         stat.arr[i] -= 2;
    //         stat.arr[mixRes[i][i]] ++;
    //         printf("Mixin %d and %d gives %d\n", i, i, minH(stat, rem-1) + mixHeat[i][i]);
    //         stat.arr[mixRes[i][i]] --;
    //         stat.arr[i] += 2;
    //     }
    //     for(int j=i+1; j<tipCnt; j++) {
    //         if(!stat.arr[j])
    //             continue;
    //         stat.arr[i] -- ;
    //         stat.arr[j] -- ;
    //         stat.arr[mixRes[i][j]] ++;
    //         printf("Mixin %d and %d gives %d\n", i, j, minH(stat, rem-1) + mixHeat[i][j]);
    //         stat.arr[mixRes[i][j]] --;
    //         stat.arr[j] ++ ;
    //         stat.arr[i] ++ ;
    //     }
    // }
    return minHMemo[stat] = ans;
}

void testCase() {
    scanf("%d", &tipCnt);
    for(int i=0; i<tipCnt; i++) {
        for(int j=0; j<tipCnt; j++) {
            scanf("%d%d", &mixRes[i][j], &mixHeat[i][j]);
            mixRes[i][j] --;
        }
    }
    seso so ;
    int tubeCnt;
    scanf("%d", &tubeCnt);
    for(int i=0; i<tubeCnt; i++) {
        int k ;
        scanf("%d", &k);
        so.arr[k-1]++;
    }
    char tmp[5];
    scanf("%s", tmp);
    minHMemo.clear();
    printf("%d\n", minH(so, tubeCnt));
}

int main() {
    int tc ;

    scanf("%d", &tc);
    while(tc--) {
        testCase();
    }
    
    return 0;
}
