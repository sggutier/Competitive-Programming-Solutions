#include <stdio.h>
#include <set>

using namespace std;

set< pair<int,int> > chosto;
set< pair<int,int> >::iterator it;

int main(){
    int n;
    pair<int,int> t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&t.first,&t.second);
        chosto.insert(t);
    }
    for (it = chosto.begin(); it != chosto.end(); it++)
        printf("%d %d\n", (*it).first, it->second);
}
