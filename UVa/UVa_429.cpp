#include <bits/stdc++.h>
using namespace std;
const int limN = 30;

map <string,int> bfs(map<string, int> minP, string pos) {
    queue <string> Q;
    int len = pos.size();
    minP[pos] = 0;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        int dst = minP[pos] + 1;
        for(int i=0; i<len; i++) {
            char tmp = pos[i];
            for(int j='a'; j<='z'; j++) {
                pos[i] = j;
                map <string, int>::iterator it = minP.find(pos);
                if(it!=minP.end() && it->second==-1) {
                    minP[pos] = dst;
                    Q.push(pos);
                }
            }
            pos[i] = tmp;
        }
    }
    return minP;
}

void testCase() {
    char line[limN];
    char *w = &line[0];
    size_t tam = sizeof(line);
    int n ;


    map<string, int> dict[limN];
    while(true) {
        char tmp[limN];
        (n = getline(&w, &tam, stdin));
        sscanf(line, "%s", tmp);
        if(tmp[0]=='*')
            break;
        dict[strlen(tmp)][tmp] = -1;
    }
    while((n = getline(&w, &tam, stdin))!=-1) {
        if(n<=1)
            break ;
        char tmpA[limN], tmpB[limN];
        sscanf(line, "%s%s", tmpA, tmpB);
        int n = strlen(tmpA);
        printf("%s %s %d\n", tmpA, tmpB, bfs(dict[n], tmpA)[tmpB]);
    }
    
}

int main() {
    char line[limN];
    char *w = &line[0];
    size_t tam = sizeof(line);
    int n, tc ;

    (n = getline(&w, &tam, stdin));
    sscanf(line, "%d", &tc);
    (n = getline(&w, &tam, stdin));
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
        // return 0;
    }
    
    return 0;
}
