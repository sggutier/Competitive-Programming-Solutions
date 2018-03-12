#include <bits/stdc++.h>
using namespace std;

class expr {
public:
    char opr;
    string L, R;
    expr() {
    }
    expr(char _opr, string _L, string _R) {
        opr = _opr;
        L = _L;
        R = _R;
    }
    void print() ;
};

expr vars[300];

void expr::print() {
    if(L.size()==1 && !isdigit(L[0])) {
        bool ppar = opr=='*' && vars[(int) L[0]].opr=='+';
        if(ppar)
            printf("(");
        vars[(int) L[0]].print();
        if(ppar)
            printf(")");
    }
    else {
        printf("%s", L.c_str());
    }
    printf("%c", opr);
    if(R.size()==1 && !isdigit(R[0])) {
        bool ppar = opr=='*' || vars[(int) R[0]].opr=='+';
        if(ppar)
            printf("(");
        vars[(int) R[0]].print();
        if(ppar)
            printf(")");
    }
    else
        printf("%s", R.c_str());
}

void testCase() {
    int N;
    scanf("%d", &N);
    char L[25], R[25];
    char var, opr;

    scanf("%c", &opr);

    //printf("%d\n", N);
    for(int i=0; i<N; i++) {
        scanf("%c = %s %c %s", &var, L, &opr, R);        
        //printf("%c => [%s] [%c] [%s]\n", var, L, opr, R);
        vars[(int) var] = expr(opr, L, R);
        scanf("%c", &opr);
    }

    vars[(int) var].print();
    printf("\n");
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Expression #%d: ", i);
        testCase();
    }
    
    return 0;
}
