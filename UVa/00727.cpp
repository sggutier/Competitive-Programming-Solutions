#include <bits/stdc++.h>
using namespace std;

char *s;

class Expr;
class Num;
class Mult;
class Summ;

class Expr {
public:
    virtual void print() {
        printf("wtf\n");
    }
};

class Num : public Expr {
public:
    char n;
    Num(char k) {
        n = k;
    }
    void print() {
        putchar(n);
    }
};

class Mult : public Expr {
public:
    vector < pair<Expr*, char> > exprs;
    Mult() ;
    void print();
};

class Summ : public Expr {
public:
    vector < pair<Expr*, char> > exprs;
    Summ() ;
    void print();
    char* parse(char *s) ;
};

void Summ::print() {
    //printf("hiri\n");
    for(auto &e:exprs) {
        e.first -> print();
        if(e.second != '#')
            putchar(e.second);
    }
}

void Mult::print() {
    //printf("multo\n");
    for(auto &e:exprs) {
        e.first -> print();
        if(e.second != '#')
            putchar(e.second);
    }
}

Mult::Mult() {
    char prev = '#';
    while(true) {
        if(*s=='(') {
            s++;
            exprs.push_back(make_pair(new Summ(), prev));
            s++;
        }
        else if(isdigit(*s)) {
            exprs.push_back(make_pair(new Num(*s++), prev));
        }
        if(*s!='/' && *s!='*' && !isdigit(*s))
            break;
        if(!isdigit(*s)) {
            prev = *s;
            s++;
        }
        else
            prev = '#';
    }
}

Summ::Summ() {
    char prev = '#';
    while(true) {
        exprs.push_back(make_pair(new Mult(), prev));
        if(*s!='+' && *s!='-')
            break;
        prev = *s;
        s++;
    }
}

void testCase() {
    int n = 0;
    char S[500];
    char tmp[500];
    s = S;

    while(fgets(tmp, 500, stdin) && tmp[0]!='\n') {
        S[n++] = tmp[0];
    }
    S[n] = 0;

    Expr* ans = new Summ();
    ans -> print();
    putchar('\n');
}

int main() {
    int tc;
    char tmp[500];

    fgets(tmp, 500, stdin);
    tc = atoi(tmp);
    fgets(tmp, 500, stdin);
    
    for(int i=0; i<tc; i++) {
        if(i)
            putchar('\n');
        testCase();
    }
}
