/*
ID: me60
LANG: C++11
TASK: transform
*/
#include <bits/stdc++.h>
using namespace std;

class Square {
public:
    Square() {
    }
    Square(int n) {
        this -> n = n;
        this -> patt = vector <string> (n);
    }
    Square(vector <string> patt) {
        this -> n = (int) patt.size();
        this -> patt = patt;
    }
    int size() {
        return n;
    }
    vector <string> get_patt() {
        return this -> patt;
    }
    void getInput() {
        char* tmp = new char[n+5];
        for(int i=0; i<n; i++) {
            scanf("%s", tmp);
            patt[i] = tmp;
        }
        delete[] tmp;
    }
    Square& rotate() {
        vector <string> patt2 = this -> patt;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                patt2[j][n-i-1] = (this -> patt)[i][j];
            }
        }
        Square* ans = new Square(patt2);
        return *ans;
    }
    Square& reflect() {
        vector <string> patt2 = this -> patt;
        for(int i=0; i<n; i++) {
            reverse(patt2[i].begin(), patt2[i].end());
        }
        Square *ans = new Square(patt2);
        return *ans;
    }
    string toString() {
        string* ans = new string();
        for(int i=0; i<n; i++)
            *ans += (i==0? "" : "\n") + patt[i] ;
        return *ans;
    }
    bool operator==(Square other) {
        if(n!=other.size())
            return false;
        return patt==other.get_patt();
    }
private:
    int n;
    vector <string> patt;
};

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int n ;
    Square a;
    Square s, s2;
    scanf("%d", &n);
    s = Square(n);
    s.getInput();
    a = Square(n);
    a.getInput();
    s2 = s;
    for(int i=0; i<3; i++) {
        s2 = s2.rotate();
        if(a==s2) {
            printf("%d\n", i+1);
            return 0;
        }
    }
    s2 = s.reflect();
    for(int i=0; i<3; i++) {
        if(a==s2) {
            printf("%d\n", min(i+4, 5));
            return 0;
        }
        s2 = s2.rotate();
    }
    if(a==s)
        printf("%d\n", 6);
    else
        printf("%d\n", 7);
    return 0;
}
