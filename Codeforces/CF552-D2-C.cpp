#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll limW = 3e9;

ll w, n;

bool bruta(ll pot=1, ll acum=0) {
    if(acum==n)
        return true;
    if(pot > limW)
        return false;
    return bruta(pot*w, acum + pot) || 
    bruta(pot*w, acum ) || 
    bruta(pot*w, acum - pot);    
}

int main() {    
    cin >> w >> n ;

    printf("%s\n", (w <= 3 || bruta())? "YES" : "NO");
}
