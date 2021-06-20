#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4;

char str[MAX_N];
char *s;

class Fact;
class Comp;
class Expr;

class Fact {
public:
    int x=0;
    Expr *e = NULL;
    Fact();
    ~Fact();
    int eval();
};

class Comp {
public:
    Fact *f;
    Comp *c;
    Comp();
    ~Comp();
    int eval();
};

class Expr {
public:
    Comp *c;
    Expr *e;
    Expr();
    ~Expr();
    int eval();
};

Fact::Fact() {
    if(*s=='(') {
        s++;
        try {
            e = new Expr();
        }
        catch (int e) {
            throw 23;
        }
        if(*(s++)!=')')
            throw 23;
    }
    else {
        if(!isdigit(*s))
            throw 23;
        while(isdigit(*s)) {
            x = x*10 + (*s-'0');
            s++;
        }
    }
}
Fact::~Fact() {
    delete e;
}


Comp::Comp() {
    try {
        f = new Fact();
    }
    catch (int e) {
        throw 23;
    }
    if(*s!='*' ) {
        c = NULL;
        return;
    }
    s++;
    try {
        c = new Comp();
    }
    catch (int e) {
        throw 23;
    }
}
Comp::~Comp() {
    delete f;
    delete c;
}

Expr::Expr() {
    try {
        c = new Comp();
    }
    catch (int e) {
        throw 23;
    }
    if(*s!='+') {
        e = NULL;
        return;
    }
    s++;
    try {
        e = new Expr();
    }
    catch (int e) {
        throw 23;
    }
}
Expr::~Expr() {
    delete c;
    delete e;
}

void testCase() {
    s = str;
    Expr *e = NULL;
    bool works = true;
    try {
        e = new Expr();
        if(*s)
            works = false;
        else
            printf("%d\n", e->eval());
    }
    catch (int e) {
        //printf("ERROR\n");
        works = false;
    }
    if(!works)
        printf("ERROR\n");
    delete e;
}
    
int Comp::eval() {
    int a = f->eval(), b=1;
    if(c!=NULL)
        b = c->eval();
    //printf("C => %d %d\n", a, b);
    return a*b;
}

int Expr::eval() {
    int a = c->eval(), b=0;
    if(e!=NULL)
        b = e->eval();
    //printf("E => %d %d\n", a, b);
    return a+b;
}

int Fact::eval() {
    //printf("F => %d\n", x);
    return e==NULL? x : e->eval();
}

int main() {
    int tc;
    gets(str);
    sscanf(str, "%d", &tc);
    while(tc--) {
        gets(str);
        testCase();
    }
}
