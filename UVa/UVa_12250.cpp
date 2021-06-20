#include <bits/stdc++.h>
using namespace std;

int main() {
    map <string, string> langs;
    char tmp[1005];
    int tc = 1;

    langs["HELLO"] = "ENGLISH";
    langs["HOLA"] = "SPANISH";
    langs["HALLO"] = "GERMAN";
    langs["BONJOUR"] = "FRENCH";
    langs["CIAO"] = "ITALIAN";
    langs["ZDRAVSTVUJTE"] = "RUSSIAN";

    while(scanf("%s", tmp)!=EOF && tmp[0]!='#') {
        printf("Case %d: ", tc++);
        if(langs.count(tmp))
            printf("%s\n", langs[tmp].c_str());
        else
            printf("UNKNOWN\n");
    }
            
    return 0;
}
