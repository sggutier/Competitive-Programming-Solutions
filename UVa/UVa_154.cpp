#include <bits/stdc++.h>
using namespace std;

void test_case(char* line, int lineLen) {
    map <char, char> cityBins[105];
    int cityN = 0;
    pair<int,int> ans = make_pair(1<<30, 0);
    size_t len = 0;
    do {
        for(int i=0; i+1<lineLen; i+=4)
            cityBins[cityN][line[i + 0]] = line[i + 2];        
        cityN++;
    } while ((lineLen = getline(&line, &len, stdin)) != -1 && line[0]!='e');

    for(int i=0; i<cityN; i++) {
        int changes = 0;
        for(int j=0; j<cityN; j++) {
            for(auto& bin: cityBins[i])
                if(cityBins[j][bin.first]!=bin.second)
                    changes ++;
        }
        ans = min(ans, make_pair(changes, i));
    }

    printf("%d\n", ans.second + 1);
}

int main() {
    size_t len = 0;
    int n;
    char *line = NULL;
    while ((n = getline(&line, &len, stdin)) != -1 && line[0]!='#') {
        test_case(line, n);
    }
    free(line);
    return 0;
}
