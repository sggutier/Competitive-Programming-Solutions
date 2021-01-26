#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxS = 20;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const char* lets = "URDL";

struct Stat {
    ll id;
    int r, c;
    int dst ;
};

ll pzl[4][4];

void dcdPzl(ll id) {
    for(int i=0; i < 16; i++) {
        pzl[i >> 2][i & 3] = id & 15;
        id >>= 4;
    }
}

ll encPzl() {
    ll ans = 0 ;
    for(int i=0; i < 16; i++) {
        ans |= pzl[i >> 2][i & 3] << (i << 2);
    }
    return ans;
}

typedef map <ll, pair<ll, int>> mapo;

ll bfs(mapo &ans, const mapo &refl) {
    queue <Stat> Q ;
    for(int i=0; i < 4; i++)
        for(int j=0; j < 4; j++)
            if(pzl[i][j] == 0) {
                ll id = encPzl();
                Q.push({id, i, j, 0});
                ans[id] = {0, 4};
                i = 4;
                break;
            }
    while(!Q.empty()) {
        Stat cur = Q.front(); Q.pop();
        if(refl.count(cur.id))
            return cur.id;
        if(cur.dst >= maxS)
            continue ;
        dcdPzl(cur.id);
        // printf("%llu < %llu %c\n", cur.id, ans[cur.id].first, lets[ans[cur.id].second]);
        // for(int i=0; i < 4; i++) {
        //     for(int j=0; j < 4; j++)
        //         printf("%llu ", pzl[i][j]);
        //     printf("\n");
        // }
        for(int d=0; d < 4; d++) {
            int x = cur.r + dr[d];
            int y = cur.c + dc[d];
            if(x < 0 || 3 < x || y < 0 || 3 < y)
                continue;
            int posC = cur.r * 4 + cur.c;
            int posNxt = x * 4 + y;
            ll nxtId = cur.id
                ^ (pzl[cur.r][cur.c] << (posC * 4))
                ^ (pzl[x][y] << (posNxt * 4))
                ^ (pzl[cur.r][cur.c] << (posNxt * 4))
                ^ (pzl[x][y] << (posC * 4));
            if(ans.count(nxtId)) {
                continue;
            }
            ans[nxtId] = {cur.id, d};
            Q.push({nxtId, x, y, cur.dst + 1});
        }
    }
    return 0;
}

mapo base;

void printWay(mapo &ans, ll pos, bool rev = false) {
    vector <int> dirs;
    while(true) {
        auto it = ans.find(pos);
        if(it->second.second == 4)
            break;
        dirs.push_back(it->second.second);
        pos = it->second.first;
    }
    if(rev)
        reverse(dirs.begin(), dirs.end());
    for(int d : dirs)
        printf("%c", lets[!rev? (d+2) % 4 : d]);
}

void testCase() {
    for(int i=0; i < 4; i++)
        for(int j=0; j < 4; j++)
            scanf("%llu", &pzl[i][j]);
    // printf("Got pzl\n");
    mapo revD;
    ll midPos = bfs(revD, base);
    if(midPos == 0) {
        printf("Thiz puzzle is not solvable.\n");
        return ;
    }
    // printf("Got midPos\n");
    printWay(revD, midPos, true);
    printWay(base, midPos);
    printf("\n");
}

int main() {
    for(int i=0; i < 15; i++)
        pzl[i >> 2][i & 3] = i+1;
    bfs(base, mapo());
    int tc ;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
    // ll id = encPzl();
    // printf("> %llu\n", id);
    // dcdPzl(id);
    // for(int i=0; i < 4; i++) {
    //         for(int j=0; j < 4; j++)
    //             printf("%d ", pzl[i][j]);
    //         printf("\n");
    //     }
}
