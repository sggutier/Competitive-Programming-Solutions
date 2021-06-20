#include <bits/stdc++.h>
using namespace std;
const int limLet = 26;
const int inf = 1e9;
#define par pair<int,int>
#define r first
#define c second

void testCase(const int rowCnt, const int colCnt) {
    map <int,int> repsRows[rowCnt], repsCols[colCnt];
    vector <int> varVal(limLet*limLet, -inf);
    vector <list<par>> varAprs(limLet*limLet);
    queue <int> singleRows, singleCols;
    vector <int> rowSums(rowCnt), colSums(colCnt);

    for(int i=0; i<rowCnt; i++) {
        for(int j=0; j<colCnt; j++) {
            char tmp[5];
            int var ;
            scanf("%s", tmp);
            var = (tmp[0]-'a')*26 + (tmp[1]-'a');
            repsRows[i][var]++;
            repsCols[j][var]++;
            varAprs[var].push_back(par(i,j));
        }
        scanf("%d", &rowSums[i]);
    }
    for(int j=0; j<colCnt; j++)
        scanf("%d", &colSums[j]);

    for(int i=0; i<rowCnt; i++)
        if(repsRows[i].size()==1)
            singleRows.push(i);
    for(int i=0; i<colCnt; i++)
        if(repsCols[i].size()==1)
            singleCols.push(i);

    while(!singleRows.empty() || !singleCols.empty()) {
        if(!singleRows.empty()) {
            int row = singleRows.front(); singleRows.pop();
            auto it = repsRows[row].begin();            
            if(it!=repsRows[row].end() && varVal[it->first]==-inf) {
                int val = it->first, reps = it->second;
                // printf("row %d, %c%c %d\n", row, val/26 + 'a', val%26+'a', reps);
                varVal[val] = rowSums[row]/reps;
                for(const auto &cords:varAprs[val]) {
                    rowSums[cords.r] -= varVal[val];
                    colSums[cords.c] -= varVal[val];
                    auto it = repsRows[cords.r].find(val);
                    if(it->second==1) {
                        repsRows[cords.r].erase(it);
                        if(repsRows[cords.r].size()==1)
                            singleRows.push(cords.r);
                    }
                    else
                        it->second --;
                    auto it2 = repsCols[cords.c].find(val);
                    if(it2->second==1) {
                        repsCols[cords.c].erase(it2);
                        if(repsCols[cords.c].size()==1)
                            singleCols.push(cords.c);
                    }
                    else
                        it2->second --;
                }
            }
        }
        if(!singleCols.empty()) {
            int col = singleCols.front(); singleCols.pop();
            auto it = repsCols[col].begin();
            if(it!=repsCols[col].end() && varVal[it->first]==-inf) {
                int val = it->first, reps = it->second;
                // printf("col %d, %c%c %d\n", col, val/26 + 'a', val%26+'a', reps);
                varVal[val] = colSums[col]/reps;
                for(const auto &cords:varAprs[val]) {
                    rowSums[cords.r] -= varVal[val];
                    colSums[cords.c] -= varVal[val];
                    auto it = repsRows[cords.r].find(val);
                    if(it->second==1) {
                        repsRows[cords.r].erase(it);
                        if(repsRows[cords.r].size()==1)
                            singleRows.push(cords.r);
                    }
                    else
                        it->second --;
                    auto it2 = repsCols[cords.c].find(val);
                    if(it2->second==1) {
                        repsCols[cords.c].erase(it2);
                        if(repsCols[cords.c].size()==1)
                            singleCols.push(cords.c);
                    }
                    else
                        it2->second --;
                }
            }
        }
    }

    int fin = limLet*limLet;
    for(int i=0; i<fin; i++) {
        if(varVal[i]!=-inf)
            printf("%c%c %d\n", (i/26) + 'a', i%26 + 'a', varVal[i]);
    }
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
    
    return 0;
}
