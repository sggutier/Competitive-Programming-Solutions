#include <bits/stdc++.h>
using namespace std;

char dict[300];

int main() {
    string rosetta[2] = {"CARScarsIuVEJxTXs UvOHhng yZKfAYmaqolMNtGQibw djPrCpek FWzLaySBaPyb RM gzYMynY",
                         "UnilEPFLvpVZzBNtL SCubWma ocIYneAPqxDshRkMGgJ fHrFUQTj XOwdPolyProg is awesome"};
    set <char> usdS;

    for(int i=0; i<(int) rosetta[0].size(); i++) {
        dict[rosetta[0][i]] = rosetta[1][i];
        usdS.insert(rosetta[1][i]);
    }
    for(int i='a'; i<='z'; i++)
        if(usdS.count(i)==0)
            dict['D'] = i;
    for(int i='A'; i<='Z'; i++)
        if(usdS.count(i)==0)
            dict['D'] = i;
    //cout << dict['D'] << endl;
    dict['D'] = 'K';

    int cnt, n;
    char s;

    scanf("%d\n", &cnt);
    while(scanf("%c", &s)!=EOF)
        printf("%c", s=='\n'? s:dict[s]);

    return 0;
}
