#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
#define f first
#define s second

struct Nodo {
    Nodo *sig = NULL, *prev = NULL;
    int tip, cnt, pos ;
    Nodo() {
    }
    Nodo(int _tip, int _cnt, int _pos) {
        tip = _tip;
        cnt = _cnt;
        pos = _pos;
    }
    Nodo(int _tip, int _cnt, int _pos, Nodo *_p, Nodo *_s) {
        tip = _tip;
        cnt = _cnt;
        pos = _pos;
        sig = _s;
        prev = _p;
    }
};

struct NoCont {
    Nodo *x ;
    NoCont(Nodo *_x) {
        x = _x;
    }
};

bool operator<(const Nodo &A, const Nodo &B) {
    if(A.cnt != B.cnt)
        return A.cnt > B.cnt;
    return A.pos < B.pos;
}

bool operator<(const NoCont &A, const NoCont &B) {
    return *A.x < *B.x;
}

void hazLista(Nodo *ini, int N, int *arr) {
    Nodo *pos = ini;
    for(int i=0, t=arr[0], c=0; ; i++, c++) {
        if(t != arr[i] || i == N) {
            pos -> sig = new Nodo(t, c, i, pos, NULL);
            //printf("Creando %d %d %d\n", t, c, i);
            pos -> sig -> prev = pos;
            pos = pos -> sig;
            t = arr[i];
            c = 0;
        }
        if(i==N)
            break;
    }
    pos -> sig = ini;
    ini -> prev = pos;
}

int main() {
    int N ;
    int arr[limN];
    Nodo *ini = new Nodo(-1, 0, -1);
    int ans = 0;
    set <NoCont> nods;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    hazLista(ini, N, arr);

    for(Nodo* pos = ini->sig; pos != ini; pos = pos->sig) {
        nods.emplace(pos);
    }

    while(!nods.empty()) {
        ans ++;
        Nodo *x = (nods.begin()) -> x;
        //printf("Borrando %d %d %d\n", x -> tip, x -> cnt, x -> pos);
        // getchar();
        nods.erase(nods.begin());
        if(x -> sig != ini && x -> prev != ini && x -> prev->tip == x -> sig->tip) {
            nods.erase(NoCont(x -> prev));
            nods.erase(NoCont(x -> sig));
            Nodo *nov = new Nodo(x -> sig->tip, x -> prev->cnt + x -> sig->cnt, x -> sig->pos, x -> prev->prev, x -> sig->sig);
            nov -> prev -> sig = nov;
            nov -> sig -> prev = nov;
            nods.emplace(nov);
            delete x -> sig;
            delete x -> prev;
        }
        else {
            x -> sig->prev = x -> prev;
            x -> prev->sig = x -> sig;
        }
        delete x;
    }

    printf("%d\n", ans);
}
