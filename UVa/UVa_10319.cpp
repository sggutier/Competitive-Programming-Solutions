#include <bits/stdc++.h>
using namespace std;

int nodCnt;
int rows, cols;
int dfsCnt;
stack <int> comp;
vector <int> dfs_low, dfs_num;
vector <bool> active;
vector<list <int>> adj;

bool testCase();
void tarjanSCC(int pos) ;

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        printf("%s\n", testCase()? "Yes" : "No");
    }
    return 0;
}

void tarjanSCC(int pos) {
    dfs_low[pos] = dfs_num[pos] = dfsCnt++;
    comp.push(pos);
    active[pos] = true;
    // printf("%d -> %d\n\t", pos, dfs_low[pos]);
    // for(const int &sig: adj[pos])
    //     printf("%d ", sig);
    // printf("\n");
    for(const int &sig: adj[pos]) {
        if(!dfs_low[sig])
            tarjanSCC(sig);
        if(active[sig])
            dfs_low[pos] = min(dfs_low[pos], dfs_low[sig]);
    }
    if(dfs_low[pos]==dfs_num[pos]) {
        int nod ;
        do {
            nod = comp.top();
            comp.pop();
            active[nod] = false;
        } while(pos!=nod) ;            
    }
}

bool testCase() {
    int qs;
    scanf("%d%d%d", &rows, &cols, &qs);
    nodCnt = 2*(rows+cols);
    int sumD[] = {0, rows};
    dfsCnt = 1;
    dfs_low = vector<int>(nodCnt, 0);
    dfs_num = vector<int>(nodCnt, 0);
    active = vector<bool>(nodCnt, 0);
    adj = vector<list <int>>(nodCnt);

    for(; qs; qs--) {
        int rods[2][2];
        bool eq = false;
        for(int i=0; i<2; i++) 
            for(int j=0; j<2; j++) {
                scanf("%d", &rods[i][j]);
                rods[i][j] += sumD[j]-1;
            }
        for(int j=0; j<2; j++) {
            if(rods[0][j]==rods[1][j]) {
                eq = true;
                if(rods[0][1-j]<rods[1][1-j])
                    adj[(2*rods[0][j] + 1)].push_back(2*rods[0][j]);
                else if(rods[0][1-j]>rods[1][1-j])
                    adj[(2*rods[0][j])].push_back(2*rods[0][j] + 1);
                
            }
        }
        if(eq)
            continue;
        int nods[2][2];
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                nods[i][j] = rods[i][j]*2 + (rods[0][1-j]>rods[1][1-j]);
            }
        }
        swap(nods[0][1], nods[1][1]);
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                // printf("%d ", nods[i][j]);
                int rev = nods[i][j] ;
                rev += (rev%2==0? 1 : -1);
                for(int k=0; k<2; k++)
                    adj[rev].push_back(nods[1-i][k]);
            }
            // printf("\n");
        }
    }

    // for(int i=0; i<nodCnt; i++) {
    //     printf("%d -> ", i);
    //     for(const int &nod: adj[i])
    //         printf("%d ", nod);
    //     printf("\n");
    // }

    for(int i=0; i<nodCnt; i++) {
        if(dfs_num[i]==0)
            tarjanSCC(i);
        if(dfs_low[i+(i%2==0? 1 : -1)]==dfs_low[i])
            return false;
    }

    return true;
}
