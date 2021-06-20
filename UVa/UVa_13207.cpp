#include <bits/stdc++.h>
using namespace std;
const int limN = 31;

map <int, map<int, map<int,int> > > posb;
int N, mit;
int nums[limN][3];
int A, B, C;

void genera(int pos, int a, int b, int c) {
    if(pos==N) {
        posb[a][b][c] = 1;
        //printf("%d %d %d\n", a, b, c);
        return;
    }
    genera(pos+1, a, b, c);
    genera(pos+1, a+nums[pos][0], b+nums[pos][1], c+nums[pos][2]);
}

bool encuentra(int pos, int a, int b, int c) {
    if(pos==mit) {
        //printf("=> %d %d %d\n", A -a, B-b, C-c);
        auto X = posb.find(A-a);
        if(X==posb.end())
            return false;
        auto Y = X->second.find(B-b);
        if(Y==X->second.end())
            return false;
        auto Z = Y->second.find(C-c);
        return Z!=Y->second.end();
    }
    return encuentra(pos+1, a, b, c) ||
    encuentra(pos+1, a+nums[pos][0], b+nums[pos][1], c+nums[pos][2]);
}

void testCase() {
    posb.clear();
    scanf("%d%d%d%d", &A, &B, &C, &N);
    mit = N/2;
    char tmp[10000];
    for(int i=0; i<N; i++) {
        scanf("%s", tmp);
        scanf("%d%d%d", &nums[i][0], &nums[i][1], &nums[i][2]);
    }
    genera(mit, 0, 0, 0);
    printf("%s\n", encuentra(0, 0, 0, 0)? "POSSIBLE" : "IMPOSSIBLE" );
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();

    return 0;
}
