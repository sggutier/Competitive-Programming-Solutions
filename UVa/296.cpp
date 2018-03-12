#include <bits/stdc++.h>
using namespace std;

pair<int,int> sameDigs(const char *a, const char *b) {
    int x=0, y=0;
    map <char, int> digs;
    for(int i=0; i<4; i++) {
        if(a[i]==b[i])
            x++;
        else
            digs[a[i]]++;
    }
    for(int i=0; i<4; i++) {
        if(a[i]!=b[i] && digs[b[i]]>0) {
            y ++ ;
            digs[b[i]] --;
        }
    }
    return make_pair(x, y);
}

void tc() {
    int guessNum;
    string* guessStrings;
    pair<int,int>* guesses;
    int cntAns = 0;
    string ans;
    scanf("%d", &guessNum);
    guessStrings = new string[guessNum];
    guesses = new pair<int,int>[guessNum];
    for(int i=0; i<guessNum; i++) {
        char tmp[30];
        scanf("%s %d/%d", tmp, &guesses[i].first, &guesses[i].second);
        guessStrings[i] = tmp;
    }

    for(int i=0; i<10000 && cntAns<2; i++) {
        char guess[20];
        bool works = true;
        sprintf(guess, "%04d", i);
        for(int j=0; j<guessNum; j++) {
            if(sameDigs(guess, guessStrings[j].c_str()) != guesses[j]) {
                works = false;
                break;
            }
        }
        if(works) {
            cntAns++;
            ans = guess;
        }
    }

    printf("%s\n", cntAns==1? ans.c_str() : (cntAns==0? "impossible" : "indeterminate"));
    
    delete[] guessStrings;
    delete[] guesses;
}

int main() {
    int T;
    for(scanf("%d", &T); T; T--)
        tc();
    return 0;
}
