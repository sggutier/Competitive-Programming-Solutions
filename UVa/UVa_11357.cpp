#include <bits/stdc++.h>
using namespace std;

char str[5010];
char *s;

struct Clause {
    int truLits, falsLits;
    Clause() {
        truLits = falsLits = 0;
        s++;
        do {
            if(*s=='~') {
                s++;
                falsLits |= (1<<(*(s++)-'a'));
            }
            else {
                truLits |= (1<<(*(s++)-'a'));
            }
        } while( *(s++)=='&' );
    }
    bool eval() {
        return (truLits & falsLits)==0;
    }
};

struct Formula {
    vector <Clause> clauses;
    Formula() {
        do {
            clauses.push_back(Clause());
        } while(*(s++)=='|');
    }
    bool eval() {
        for(Clause &c:clauses) {
            if(c.eval())
                return true;
        }
        return false;
    }
};

bool testCase() {
    s = str;
    Formula f;
    return f.eval();
}

int main() {
    gets(str);
    int tc;
    sscanf(str, "%d", &tc);
    while(tc--) {
        gets(str);
        printf("%s\n", testCase()? "YES" :"NO");
    }
}
