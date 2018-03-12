/*
ID: me60
LANG: C++11
TASK: castle
*/
#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define r first
#define c second

int connexRooms(vector<vector<int>> &walls, vector<vector<int>> &roomID, par pos, int color) {
    int dr[] = {0, -1, 0, 1};
    int dc[] = {-1, 0, 1, 0};
    stack <par> Q;
    int ans = 0;

    Q.push(pos);
    roomID[pos.r][pos.c] = color;
    while(!Q.empty()) {
        ans ++;
        pos = Q.top();
        Q.pop();
        for(int d=0; d<4; d++) {
            if(((1<<d) & walls[pos.r][pos.c]))
                continue ;
            par novPos = par(pos.r + dr[d], pos.c + dc[d]);
            if(roomID[novPos.r][novPos.c]!=color) {
                roomID[novPos.r][novPos.c] = color;
                Q.push(novPos);
            }
        }
    }

    return ans;
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    
    int rows, cols;
    vector <vector<int>> walls, roomID;
    int roomN=0, maxRoomSize=0;
    int colorNum = 0;
    pair<int, pair<par, char>> bestRemoval = make_pair(0, make_pair(par(0,0), 'W'));

    scanf("%d%d", &cols, &rows);
    roomID = walls = vector< vector<int> >(rows, vector<int>(cols, 0));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &walls[i][j]);
        }
    }

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(roomID[i][j])
                continue;
            maxRoomSize = max(maxRoomSize, connexRooms(walls, roomID, par(i,j), ++colorNum));
            roomN ++;
        }
    }

    for(int j=0; j<cols; j++) {
        for(int i=0; i<rows; i++) {
            if(i>0 && (walls[i][j] & (1<<1))) {
                walls[i][j] ^= (1<<1);
                bestRemoval = max(bestRemoval,
                                  make_pair(connexRooms(walls, roomID, par(i,j), ++colorNum),
                                            make_pair(par(-j,i), 'N')));
                walls[i][j] ^= (1<<1);    
            }
            if(j<cols-1 && (walls[i][j] & (1<<2))) {
                walls[i][j] ^= (1<<2);
                bestRemoval = max(bestRemoval,
                                  make_pair(connexRooms(walls, roomID, par(i,j), ++colorNum),
                                            make_pair(par(-j,i), 'E')));
                walls[i][j] ^= (1<<2);    
            }
        }
    }

    printf("%d\n", roomN);
    printf("%d\n", maxRoomSize);
    printf("%d\n", bestRemoval.first);
    printf("%d %d %c\n", bestRemoval.second.first.c + 1, -bestRemoval.second.first.r + 1, bestRemoval.second.second);
    
    return 0;
}
