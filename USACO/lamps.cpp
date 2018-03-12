/*
ID: me60
LANG: C++11
TASK: lamps
*/
#include <bits/stdc++.h>
using namespace std;

void pressButton(int lampCnt, int s[2], bool lampStat[]) {
    for(int i=s[0]; i<lampCnt; i+=s[1])
        lampStat[i] ^= 1;
}

bool validConfig(int onCnt, int onLamps[], int offCnt, int offLamps[], bool lampStat[]) {
    for(int i=0; i<onCnt; i++)
        if(lampStat[onLamps[i]-1])
            return false;
    for(int i=0; i<offCnt; i++)
        if(!lampStat[offLamps[i]-1])
            return false;
    return true;
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    
    int lampCnt;
    int pressCnt;
    int onCnt=0, offCnt=0;
    int offLamps[105], onLamps[105];
    int switches[][2] = {{0, 1}, {0, 2}, {1, 2}, {0, 3}};
    bool lampStat[105];
    vector<string> ans;

    scanf("%d%d", &lampCnt, &pressCnt);
    for(scanf("%d", &onLamps[onCnt]); onLamps[onCnt]!=-1; scanf("%d", &onLamps[++onCnt]));
    for(scanf("%d", &offLamps[offCnt]); offLamps[offCnt]!=-1; scanf("%d", &offLamps[++offCnt]));

    for(int b=0; b<(1<<4); b++) {
        int cnt = 0;
        for(int i=0; i<4; i++) {
            if((1<<i) & b)
                cnt ++;
        }
        if(cnt>pressCnt || (pressCnt-cnt)%2!=0)
            continue;
        memset(lampStat, 0, sizeof(lampStat));
        for(int i=0; i<4; i++) {
            if((1<<i) & b)
                pressButton(lampCnt, switches[i], lampStat);
        }
        if(validConfig(onCnt, onLamps, offCnt, offLamps, lampStat)) {
            string tmp = "";
            for(int i=0; i<lampCnt; i++)
                tmp += (char) (1 - lampStat[i] + '0');
            ans.push_back(tmp);
        }
    }

    sort(ans.begin(), ans.end());

    if(ans.size()==0)
        printf("IMPOSSIBLE\n");
    else
        for(int i=0; i<(int) ans.size(); i++)
            printf("%s\n", ans[i].c_str());
    
    return 0;
}
