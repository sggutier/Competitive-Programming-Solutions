#include <bits/stdc++.h>
using namespace std;
const int limC = 300;

function<bool (const bool, const bool)> oprs[limC];
int N = 0;
char str[limC];
char vals[limC];

struct expr {
    // char yo ;
    char at ;
    function<bool (const bool, const bool)> tp ;
    expr *lo, *ro;
    expr() {
        at = 0;
        ro = lo = NULL ;
    }
    expr(char a) {
        // yo = a;
        at = a;
        ro = lo = NULL ;
    }
    void getIn() {
        // yo = str[N];
        if(islower(str[N])) {
            // cout << "buildin bowel " << yo << endl;
            at = str[N++];
        }
        else {
            // cout << "buildin conso " << yo << endl;
            at = 0;
            if(str[N]=='N') {
                tp = oprs[(int) str[N++]];
                lo = new expr();
                ro = new expr('#');
                lo -> getIn();
            }
            else {
                tp = oprs[(int) str[N++]];
                lo = new expr();
                lo -> getIn();
                ro = new expr();
                ro -> getIn();
            }
        }
    }
    bool eval() {
        if(at)
            return vals[(int) at];
        return tp(lo -> eval(), ro -> eval());
    }
    ~expr() {
        // cout << "deletin " << yo << endl;
        // cout << "left? :: " << (lo!=NULL? "yeah" : "nah") << endl;
        // cout << "right? :: " << (ro!=NULL? "yeah" : "nah") << endl;
        delete lo;
        delete ro;
    }
};

void testCase() {
    N = 0;    
    set <int> usd;
    int k = 0 ;
    int avil[6];
    int n = strlen(str);
    
    for(int i=0; i<n; i++) {
        if(islower(str[i]))
            usd.insert(str[i]);
    }

    for(const int &u:usd)
        avil[k++] = u;

    expr *E = new expr();
    E -> getIn();

    bool works = true;
    for(int b=(1<<k)-1; b>=0; b--) {
        for(int i=0; i<k; i++) {
            vals[avil[i]] = ((1<<i) & b)? 1 : 0;
        }
        if(!E->eval()) {
            works = false;
            break;
        }
    }
        
    delete E;    

    if(works)
        printf("tautology\n");
    else
        printf("not\n");

}

int main() {
    oprs['K'] = [](bool a, bool b) { return a && b ;} ;
    oprs['A'] = [](bool a, bool b) { return a || b ;} ;
    oprs['N'] = [](bool a, bool b) { return !a ;} ;
    oprs['C'] = [](bool a, bool b) { return !a || b ;} ;
    oprs['E'] = [](bool a, bool b) { return a == b ;} ;

    while(scanf("%s", str)!=EOF && str[0]!='0')
        testCase();
}
