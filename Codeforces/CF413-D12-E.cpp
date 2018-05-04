/*
- If one wants to go from some point in a clear rectangular section to another, the minimum
  distance is manhattan distance.
- If one wants to go from one closed place (a column where one of the two rows is blocked),
  to another one,  the minimum distance is the difference minimum distance from the beginning 
  of the reacheable space to the points.  It is like a thread that goes from left to right,
  there is only one path, similar to a line.
- The last part can be used for calculating the distance from a point in a clear rectangle
  to another one.  That distance would be the closest choke points, and adding to that
  the distance between the choke points.
- The part of calculating the distances from left for choke pointsand checking if some two
  points can be done with a bfs.
- The part of finding the closest choke points can be done with binary search.
- This gives complexity of O(n log n)
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define r first
#define c second
const int limN = 2e5 + 5;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {-0, 1, 0, -1};

int N ;
char mapa[2][limN];
int colCnt = 0;
int color[2][limN], minDst[2][limN];
vector <int> crs;
int renLib[limN];

bool esVald(const pii pos) {
    return pos.r >= 0 && pos.r < 2 && pos.c >= 0 && pos.c < N && mapa[pos.r][pos.c]=='.' && !color[pos.r][pos.c];
}

void marca(pii pos) {
    if(!esVald(pos)) return;
    colCnt ++;
    queue <pii> Q;
    minDst[pos.r][pos.c] = 1;
    color[pos.r][pos.c] = colCnt;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        for(int d=0, dst=minDst[pos.r][pos.c]+1; d<4; d++) {
            pii sig = {pos.r+dr[d], pos.c+dc[d]};
            if(!esVald(sig)) continue;
            color[sig.r][sig.c] = colCnt;
            minDst[sig.r][sig.c] = dst;
            Q.push(sig);
        }
    }
}

pii numAPii(int k) {
    k--;
    return {k/N, k%N};
}

int manh(const pii A, const pii B) {
    return abs(A.r - B.r) + abs(A.c - B.c);
}

int query(pii L, pii R) {
    if(L.c > R.c)
        swap(L, R);
    if(mapa[L.r][L.c]!='.' || mapa[R.r][R.c]!='.' || color[L.r][L.c]!=color[R.r][R.c])
        return -1;
    int ls, rs;
    ls = lower_bound(crs.begin(), crs.end(), L.c) - crs.begin();
    rs = upper_bound(crs.begin(), crs.end(), R.c) - crs.begin();
    if(ls==rs) {
        return manh(L, R);
    }
    ls = crs[ls];
    rs = crs[rs-1];
    return manh(L, {renLib[ls], ls})
        + manh(R, {renLib[rs], rs})
        + abs(minDst[renLib[ls]][ls] - minDst[renLib[rs]][rs]);
}

int main() {
    int Q ;

    scanf("%d%d", &N, &Q);
    for(int i=0; i<2; i++)
        scanf("%s", mapa[i]);

    crs.push_back(-1);
    for(int c=0; c<N; c++) {
        int cnt = 0;
        for(int r=0; r<2; r++) {
            marca({r, c});
            cnt += (mapa[r][c]=='.')? 1 : 0;
        }
        if(cnt<2)
            crs.push_back(c);
        if(cnt==1)
            renLib[c] = (mapa[0][c]=='.')? 0 : 1;
    }
    crs.push_back(N);

    while(Q--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(numAPii(a),  numAPii(b)));
    }
}
