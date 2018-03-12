#include <bits/stdc++.h>
using namespace std;

int N ;
string strs[30];

bool isSubstr(string &A, string &B) {
    if(A.size() > B.size())
        return false;
    int na = A.size(), nb = B.size();
    for(int i=0; i+na<=nb; i++)
        if(B.substr(i, na) == A)
            return true;
    return false;
}

void bruta(int rem, string s="") {
    if(rem==0) {
        for(int i=0; i<N; i++) {
            if(isSubstr(s, strs[i]))
                return;
        }
        cout << s << endl;
        exit(0);
    }
    for(char i='a'; i<='z'; i++) {
        bruta(rem-1, s + i);
    }
}

int main() {
    cin >> N ;
    for(int i=0; i<N; i++)
        cin >> strs[i];

    for(int i=0; ; i++)
        bruta(i);
}
