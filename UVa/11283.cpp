#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
const int limM = 4;
const int limD = 8;
const int limN = 25;
const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
#define r first
#define c second

//char mapa[limN][limN + 5];
string mapa[4];
bool usd[limN][limN];

bool matchea(int r, int c, char *v) {
    if(0>r || r>=limM || 0>c || 0>=limM )
        return false;
    //printf("%d %d %s\n", r, c, v);
    if(mapa[r][c]!=*v || usd[r][c])
        return false;
    if(*(v+1)==0)
        return true;
    //printf("Trying to match %s at %d %d\n", v, r, c);    
    usd[r][c] = true;
    for(int d=0; d<limD; d++) {
        //printf("Tryna with (%d) %d %d\n", d, r+dr[d], c+dc[d]);
        if(matchea(r+dr[d], c+dc[d], v+1))
            return true;
    }
    return usd[r][c] = false;
}

int tostCaso() {
    int n, wCnt;
    //char vort[limN*50];
    string vort;
    int ans = 0;

    //gets(vort);
    getline(cin, vort);
    for(int i=0; i<limM; i++)
        getline(cin, mapa[i]);
        //gets(mapa[i]);
        //scanf("%s", mapa[i]);
    //gets(vort);
    //scanf("%s", vort);
    cin >> wCnt ;
    cin.ignore(100, '\n');
    //scanf("%d", &wCnt);
    //wCnt = atoi(vort);
    //sscanf(vort, "%d", &wCnt);
    while(wCnt--) {
        //gets(vort);
        //scanf("%s", vort);
        getline(cin, vort);
        //n = strlen(vort);
        n = vort.size();
        if(n>16)
            continue;        
        char ko[25];
        for(int i=0; i<n; i++)
            ko[i] = vort[i];
        ko[n] = 0;
        memset(usd, 0, sizeof(usd));
        //printf("Looking for %s (%d)\n", vort.c_str(), wCnt);
        for(int i=0; i<limM; i++) {
            for(int j=0; j<limM; j++) {
                if(matchea(i, j, ko)) {
                    //printf("Found %s\n", vort.c_str());
                    ans += n>=8? 11 : (n==7? 5 : max(1, n-3));
                    i = limM;
                    break;
                }
                // else
                //     printf("Not worked at %d %d\n", i, j);
            }
        }
        //printf("Finished looking %s (%d)\n", vort, wCnt);
    }
    // printf("Hiar\n");
    // cout << ans << endl;
    // printf("^^^^^\n");
    // return 1;
    return ans;
}

int main() {
    int tc;
    //char tmp[limN];
    //gets(tmp);
    //scanf("%s", tmp);
    //sscanf(tmp, "%d", &tc);
    cin >> tc;
    cin.ignore(100, '\n');
    //tc = atoi(tmp);
    for(int i=1; i<=tc; i++) {
        //cout << i << endl;
        int w = tostCaso();
        //cout << w << endl;
        printf("Score for Boggle game #%d: %d\n", i, w);
        // Score for Boggle game 
        // cout << w << endl;
        // printf("%d\n", w);
    }
}
