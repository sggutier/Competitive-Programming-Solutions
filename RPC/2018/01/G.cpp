#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};

struct tri {
    int x, y, z;
    tri() {
    }
    tri(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }
    tri np(int d) {
        if(d==-1)
            return tri(x, y, z);
        return tri(x+dx[d], y+dy[d], z+dz[d]);
    }
    void printa() {
        printf("(%d %d %d)", x, y, z);
    }
};

bool operator==(const tri A, const tri B) {
    return A.x == B.x && A.y == B.y && A.z == B.z;
}

bool operator!=(const tri A, const tri B) {
    return !(A==B);
}

int bd(tri ini, tri fin) {
    if(ini.x!=fin.x)
        return ini.x < fin.x? 1 : 0;
    else if(ini.y!=fin.y)
        return ini.y < fin.y? 3 : 2;
    if(ini.z!=fin.z)
        return ini.z < fin.z? 5 : 4;
    return -1;
}

int dst(tri A, tri B) {
    return abs(A.x-B.x) + abs(A.y-B.y) + abs(A.z-B.z);
}

void printa2(tri* W) {
    W[0].printa();
    printf(" " );
    W[1].printa();
    printf("\n");
}

void saca(tri* ini, tri* fin, int a, int b) {
    if(ini[a] != fin[b])
        return;
    printa2(ini);
    for(int d=0; d<6; d++) {
        if(ini[a].np(d) != fin[b] && ini[a].np(d) != ini[b]) {
            ini[a] = ini[a].np(d);
            return;
        }
    }
}

void guia(tri *ini, tri *fin, int a, int b) {
    while(ini[a] != fin[a]) {
        // getchar();
        
        // printf("%d %d => ", a, b);
        int k = bd(ini[a], fin[a]);
        if(ini[a].np(k) == ini[b]) {
            tri anto(1e9, 1e9, 1e9);
            pair<int, int> sigo(1e9, 0);
            for(int v=0; v<2; v++) {
                printa2(ini);
                for(int d=0; d<6; d++) {
                    tri sp = ini[a].np(d);
                    if(sp != ini[b] && sp != anto && (v!=0 || d/2 != k/2))
                        sigo = min(sigo, {dst(sp, fin[a]), d});
                }
                anto = ini[a];
                ini[a] = ini[a].np(sigo.second);
            }
        }
        else {
            printa2(ini);
            ini[a] = ini[a].np(k);
        }
    }
}

int main() {
    tri ini[2], fin[2];
    for(int i=0; i<2; i++) {
        scanf("%d%d%d", &ini[i].x, &ini[i].y, &ini[i].z);
        scanf("%d%d%d", &fin[i].x, &fin[i].y, &fin[i].z);
    }

    saca(ini, fin, 0, 1);
    saca(ini, fin, 1, 0);
    guia(ini, fin, 0, 1);
    guia(ini, fin, 1, 0);

    printa2(fin);
}
