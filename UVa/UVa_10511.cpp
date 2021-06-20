#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_C = 105;

typedef ll Flow;
struct Edge {
    int dest, back;
    Flow f, c;
};

struct PushRelabel {
    vector<vector<Edge>> g;
    vector<Flow> ec;
    vector<Edge*> cur;
    vector<vi> hs; vi H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

    void add_edge(int s, int t, Flow cap, Flow rcap=0) {
        if (s == t) return;
        Edge a = {t, sz(g[t]), 0, cap};
        Edge b = {s, sz(g[s]), 0, rcap};
        g[s].push_back(a);
        g[t].push_back(b);
    }

    void add_flow(Edge& e, Flow f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }
    Flow maxflow(int s, int t) {
        int v = sz(g); H[s] = v; ec[t] = 1;
        vi co(2*v); co[0] = v-1;
        rep(i,0,v) cur[i] = g[i].data();
        trav(e, g[s]) add_flow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0)  // discharge u
                if (cur[u] == g[u].data() + sz(g[u])) {
                    H[u] = 1e9;
                    trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
                        H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        rep(i,0,v) if (hi < H[i] && H[i] < v)
                            --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
                    add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
        }
    }
};

struct Dict {
    map <string, int> dict;
    vector <string> rev ;

    inline int getId(string S) {
        auto it = dict.find(S);
        if(it == dict.end()) {
            rev.push_back(S);
            int x = dict.size();
            dict[S] = x;
            return x ;
        }
        return it->second;
    }
};

char tmp[LIM_C];
Dict namesDict, partiesDict, clubsDict;

string getStr(char* &c) {
    while(*c && !isalpha(*c) && !isdigit(*c)) c++;
    if(*c == 0) {
        return "";
    }
    char *ini = c ;
    while(*c && (isalpha(*c) || isdigit(*c))) c++;
    if(*c) {
        *c = 0 ;
        c ++;
    }
    return ini;
}

void processInput(vi &party, vector<vector <int>> &adj) {
    namesDict = Dict();
    partiesDict = Dict();
    clubsDict = Dict();
    int pos = 0 ;
    while(true) {
        cin.getline(tmp, LIM_C);
        if(tmp[0] == 0)
            break;
        char *c = tmp;
        string S = getStr(c);
        namesDict.getId(S);
        S = getStr(c);
        party.push_back(partiesDict.getId(S));
        adj.emplace_back();
        while((S = getStr(c)).size()) {
            adj[pos].push_back(clubsDict.getId(S));
        }
        pos ++;
    }
}

void testCase() {
    vi party;
    vector <vi> adj;
    processInput(party, adj);
    int nN = namesDict.rev.size();
    int pN = partiesDict.rev.size();
    int cN = clubsDict.rev.size();
    int ini = pN + cN + nN, fin = ini + 1;
    int maxC = (cN - 1) / 2 ;
    PushRelabel pr(fin + 1);

    for(int i=0; i < pN; i++) {
        pr.add_edge(ini, i, maxC);
    }
    for(int i=0; i < nN; i++) {
        pr.add_edge(party[i], pN + i, 1);
        for(const int j : adj[i]) {
            pr.add_edge(pN + i, pN + nN + j, 1);
        }
    }
    for(int i=0; i < cN; i++) {
        pr.add_edge(pN + nN + i, fin, 1);
    }

    if(pr.maxflow(ini, fin) != cN) {
        printf("Impossible.\n");
        return ;
    }

    for(int i=0; i < nN; i++)
        for(const auto e : pr.g[i + pN])
            if(e.f > 0)
                printf("%s %s\n", namesDict.rev[i].c_str(), clubsDict.rev[e.dest - (pN + nN)].c_str());
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC ;
    cin.getline(tmp, LIM_C);
    sscanf(tmp, "%d", &TC);
    cin.getline(tmp, LIM_C);
    for(int i=0; i < TC; i++) {
        if(i) printf("\n");
        testCase();
    }
}
