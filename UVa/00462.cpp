#include <bits/stdc++.h>
using namespace std;
const int limN = 13;

int stCnt[300];

int rule1(string *cds) {
    int ans = 0;
    for(int i=0; i<limN; i++) {
        //printf("%s %d =>", cds[i].c_str(), ans);
        switch(cds[i][0]) {
        case 'A':
            ans += 4;
            break;
        case 'K':
            ans += 3;
            break;
        case 'Q':
            ans += 2;
            break;
        case 'J':
            ans += 1;
            break;
        }        
        //printf(" %d\n", ans);
    }
    //printf("Rule 1: %d\n", ans);
    return ans;
}

int rule234(string *cds, const char t, int mx) {
    mx ++;
    int ans = 0;
    for(int i=0; i<limN; i++) {
        if(cds[i][0]==t && stCnt[(int) cds[i][1]] <= mx)
            ans -= 1;
    }
    //printf("Rule 234 (%c): %d\n", t, ans);
    return ans;
}

int rule567(int c, int p) {
    int ans = 0;
    for(int i=0; i<300; i++)
        if(stCnt[i]==c)
            ans += p;
    //printf("Rule 567 (%d %d): %d\n", c, p, ans);
    return ans;            
}

int stopped(string *s) {
    for(int t=0; t<300; t++) {
        if(stCnt[t] == -1)
            continue;
        bool works = false;
        for(int i=0; i<limN; i++) {
            if(s[i][1] != t)
                continue;
            if(s[i][0]=='A' && stCnt[t]>0) {
                works = true;
                break;
            }
            if(s[i][0]=='K' && stCnt[t]>1) {
                works = true;
                break;
            }
            if(s[i][0]=='Q' && stCnt[t]>2) {
                works = true;
                break;
            }
        }
        //printf("%c %s\n", (char) t, works? "works" : "doesn't work");
        if(!works)
            return 0;
    }
    return 1;
}

void testCase(string* s) {
    for(int i=1; i<limN; i++)
        cin >> s[i];
    memset(stCnt, -1, sizeof(stCnt));
    stCnt['S'] = 0;
    stCnt['H'] = 0;
    stCnt['D'] = 0;
    stCnt['C'] = 0;
    for(int i=0; i<limN; i++) {
        stCnt[(int) s[i][1]] ++;
    //     printf("%c", s[i][1]);
    }
    // printf("\n");
    // printf("%d %d %d %d\n", stCnt['S'],
    //        stCnt['H'],
    //        stCnt['C'],
    //        stCnt['D']);
    int pA = rule1(s) + rule234(s, 'K', 0) + rule234(s, 'Q', 1) + rule234(s, 'J', 2);
    int pB = pA + rule567(2, 1) + rule567(1, 2) + rule567(0, 2);
    pA *= stopped(s);
    if( pA >= 16 )
        printf("BID NO-TRUMP\n");
    else if( pB >= 14 ) {
        int maxA = 0;
        for(int i=0; i<300; i++)
            maxA = max(maxA, stCnt[i]);
        printf("BID %c\n", stCnt['S']==maxA? 'S' : (stCnt['H']==maxA? 'H' : (stCnt['D']==maxA? 'D' : 'C')));
    }
    else
        printf("PASS\n");
}

int main() {
    string s[limN];
    while(cin >> s[0])
        testCase(s);
}
