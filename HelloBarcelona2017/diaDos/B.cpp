#include <bits/stdc++.h>
using namespace std;
const int limB = 59049;

int vals[13];
int pots[13];
char str[300];
char *s = str;

class Expro ;
class Atom ;
class Ando ;
class Oro ;
class Noto ;

class Expro {
public:
    virtual bool eval() {
        cout << "Que chingados" << endl;
        return true;
    }
};

class Atom : public Expro {
public:
    int let ;
    Atom();
    bool eval();
};

class Ando : public Expro {
public:
    vector <Expro*> cosos;
    Ando();
    bool eval();
};

struct Oro : public Expro {
public:
    vector <Expro*> cosos;
    Oro();
    bool eval();
};

class Noto : public Expro {
public:
    Expro *e;
    Noto() {
        s += 4;
        if(*s=='(') {
            s += 2;
            e = new Oro();
            s += 2;
        }
        else if(*s=='n') {
            e = new Noto();
        }
        else {
            e = new Atom();
            //cout << "Metiendo un atomo" << endl;
            s += 2;
        }
    }
    bool eval() {
        return !e->eval();
    }    
};

int N;
Expro *jogo;
bool alice(int msk);
bool bob(int msk);
bool usd[limB];
bool memo[limB];

void imprime(int a, int b, int c) {
    for(int i=0; i<N; i++) {
        printf("%d ", vals[i]);
    }
    printf("=> %d %d %d\n", a, b, c);
}


bool juego(int msk, int rem) {
    if(usd[msk])
        return memo[msk];
    usd[msk] = true;
    if(rem==0) {
        bool val = memo[msk] = jogo->eval() ^ (N%2==1);
        //imprime(msk, rem, val);
        return val;
    }
    for(int i=0; i<N; i++) {
        if(vals[i]!=-1)
            continue;
        vals[i] = 0;
        if(!juego(msk + pots[i], rem-1)) {
            //imprime(msk, rem, true);
            vals[i] = -1;
            return memo[msk] = true;
        }
        vals[i] = 1;
        if(!juego(msk + 2*pots[i], rem-1)) {
            //imprime(msk, rem, true);
            vals[i] = -1;
            return memo[msk] = true;
        }
        vals[i] = -1;
    }
    //imprime(msk, rem, false);
    return memo[msk] = false;
}

int main() {
    vals[0] = -1;
    pots[0] = 1;
    for(int i=1; i<13; i++) {
        pots[i] = pots[i-1]*3;
        vals[i] = -1;
    }

    char tmp[30];
    fgets(tmp, 1000, stdin);
    int ko = strlen(tmp);
    tmp[ko-1] = 0;
    //cout << tmp << endl;
    N = atoi(tmp);
    fgets(str, 1000, stdin);
    int roo = strlen(str);
    str[roo] = 0;
    str[roo-1] = 0;
    //cout << str << endl;
    //cout << "tres" << endl;
    //gets(jogo);

    jogo = new Oro();

    printf("%s\n", juego(0, N)? "Alice" : "Bob");
    //printf("%s\n", jogo->eval()? "Alice" : "Bob");
    //vals[0] = 1;
    //printf("%s\n", jogo->eval()? "Alice" : "Bob");
}


Atom::Atom() {
    let = *s - 'A';
}

bool Atom::eval() {
        //printf("Evaluating %c -> %d\n", let+'A', vals[let]);
        return vals[let];
    }

Ando::Ando() {
    //cout << "Hola, acabo de entrar" << endl;
        do {
            if(*s=='a')
                s += 4;
            if(*s=='(') {
                s += 2;
                cosos.push_back(new Oro());
                s += 2;
            }
            else if(*s=='n') {
                cosos.push_back(new Noto());
            }
            else {
                cosos.push_back(new Atom());
                //cout << "Metiendo un atomo" << endl;
                s += 2;
            }
        } while(*s=='a');
    }

bool Ando::eval() {
        for( Expro *e:cosos) {
            if(!e->eval()) {
                //printf("Ando falso\n");
                return false;
            }
        }
        //printf("Ando verdadero\n");
        return true;
    }

Oro::Oro() {
        do {
            if(*s=='o')
                s += 3;
            cosos.push_back(new Ando());
        } while(*s=='o');
    }

bool Oro::eval() {
    //cout << "Evaluando Oro" << endl;
        for(Expro *e:cosos) {
            if(e->eval())
                return true;
        }
        return false;
    }    
