#include <bits/stdc++.h>
using namespace std;

struct Diro {
    int dirR, dirC;
    function<int(const int, const int)> getDim ;
    function<int(const int, const int)> getAnti ;
};

vector<vector<int>> pusha(const vector<vector<int>> &mat, const Diro &diro) {
    int R = mat.size(), C = mat[0].size();
    int D = diro.getAnti(R, C);
    vector<vector<int>> ans(R, vector<int>(C));
    vector<vector<int>> acm(D);
    for(int i=(diro.dirR + R) % (R+1); i >= 0 && i < R; i += diro.dirR) {
        for(int j=(diro.dirC + C) % (C+1); j >= 0 && j < C; j += diro.dirC) {
            if(mat[i][j]) {
                acm[diro.getAnti(i, j)].push_back(mat[i][j]);
            }
        }
    }
    for(int i = 0; i < D; i++) {
        int p = -1, prev = -1;
        for(const int a : acm[i]) {
            if(a != prev) {
                p++;
            }
            ans
                [((diro.getDim(p, i)+1)*diro.dirR + R) % (R+1)]
                [((diro.getAnti(p, i)+1)*diro.dirC + C) % (C+1)] += a;
            prev = a==prev? -1 : a;
        }
    }
    return ans;
}

int main() {
    cin.sync_with_stdio();
    cout.sync_with_stdio();
    int R, C;
    vector<vector<int>> mat;
    string instrs;
    map<char, Diro> dirs;
    auto getR = [](const int R, const int C) { return R; };
    auto getC = [](const int R, const int C) { return C; };

    cin >> R >> C;
    mat = vector<vector<int>>(R, vector<int>(C));
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> instrs;

    dirs['N'] = { 1, 1, getR, getC};
    dirs['S'] = {-1, 1, getR, getC};
    dirs['O'] = { 1, 1, getC, getR};
    dirs['E'] = { 1,-1, getC, getR};
    for(const auto c : instrs) {
        mat = pusha(mat, dirs[c]);
    }

    for(int i=0; i < R; i++) {
        int maxN = 0;
        for(int j=0; j < C; j++) {
            maxN = max(maxN, mat[i][j]);
        }
        if(maxN) {
            printf("%d\n", maxN);
        }
    }
}
