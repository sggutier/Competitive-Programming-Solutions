#include <bits/stdc++.h>
using namespace std;
const int inf = (1<<30);

int testCase(int k, char *str) {
    int len = strlen(str);
    int cnt = len/k;
    vector<vector <int>> minChunks(cnt+1, vector<int>(26, inf));
    for(int i=0; i<26; i++)
        minChunks[0][i] = 1;
    for(int c=0; c<cnt; c++) {
        vector<char> has(26);
        int w = 0;
        for(int i=0; i<k; i++) {
            if(has[str[i+c*k]-'a'])
                continue;
            has[str[i+c*k]-'a'] = true;
            w ++;
        }
        // printf("=> %d\n", c);
        // for(int i=0; i<26; i++) {
        //     if(minChunks[c][i]!=inf)
        //         printf("%c %d\n", i+'a', minChunks[c][i]);
        // }
        if(w==1) {
            int a;
            for(a=0; !has[a]; a++);
            int mino = inf;
            for(int b=0; b<26; b++) {
                mino = min(mino, minChunks[c][b] + (a==b? -1 : 0) + w);
            }
            minChunks[c+1][a] = mino;
            continue;
        }
        for(int a=0; a<26; a++) {
            if(!has[a])
                continue;
            int mino = inf;
            for(int b=0; b<26; b++) {
                mino = min(mino, minChunks[c][b] + (a==b? -1 : 0) + w);
            }
            for(int b=0; b<26; b++) {
                if(!has[b] || a==b)
                    continue;
                minChunks[c+1][b] = min(minChunks[c+1][b], mino);
            }
        }
        // cout << "fino " << endl;
    }
    // printf("=> %d\n", cnt);
    //     for(int i=0; i<26; i++) {
    //         if(minChunks[cnt][i]!=inf)
    //             printf("%c %d\n", i+'a', minChunks[cnt][i]);
    //     }
    return *min_element(minChunks[cnt].begin(), minChunks[cnt].end());
}

int main() {
    int tc;
    int a;
    char S[1005];

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        scanf("%d%s", &a, S);
        printf("%d\n", testCase(a,S));
    }
    
    return 0;
}
