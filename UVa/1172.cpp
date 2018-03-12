#include <bits/stdc++.h>
using namespace std;
const int limCityCnt = 1005;
const int maxStrLen = 15;

class City {
private:
    static map<string, int> osIDs;
    static int osCnt ;
public:
    int osID, valNum;
    City() {
    }
    City(string osName, int val) {
        map <string, int>::iterator it = osIDs.find(osName);
        if(it==osIDs.end())
            osID = osIDs[osName] = ++osCnt;
        else
            osID = it->second;
        valNum = val;
    }
    static void clearIDs() {
        osIDs.clear();
        osCnt = 0;
    }
};
int City::osCnt=0;
map<string, int> City::osIDs = map<string, int>();

pair<int,int> operator+(pair <int,int> A, pair<int,int> B) {
    return make_pair(A.first + B.first, A.second + B.second);
}

void testCase() {
    int upCnt, lowCnt;
    City upperCities[limCityCnt], lowerCities[limCityCnt];
    pair<int,int>** maxSum = new pair<int,int>*[limCityCnt];
    
    City::clearIDs();
    for(int i=0; i<limCityCnt; i++)
        maxSum[i] = new pair<int,int>[limCityCnt];
    maxSum[0][0] = make_pair(0, 0);
    
    scanf("%d", &upCnt);
    for(int i=1; i<=upCnt; i++) {
        char tmp[maxStrLen];
        int v;
        scanf("%s", tmp);
        scanf("%s%d", tmp, &v);
        upperCities[i] = City(tmp, v);
        maxSum[i][0] = make_pair(0, 0);
    }
    scanf("%d", &lowCnt);
    for(int i=1; i<=lowCnt; i++) {
        char tmp[maxStrLen];
        int v;
        scanf("%s", tmp);
        scanf("%s%d", tmp, &v);
        lowerCities[i] = City(tmp, v);
        maxSum[0][i] = make_pair(0, 0);
    }

    for(int i=1; i<=upCnt; i++) {
        for(int j=1; j<=lowCnt; j++) {
            maxSum[i][j] = max(maxSum[i-1][j], maxSum[i][j-1]);
            if(upperCities[i].osID==lowerCities[j].osID) {
                // maxSum[i][j].first += upperCities[i].valNum + lowerCities[j].valNum;
                // maxSum[i][j].second --;
                maxSum[i][j] = max(maxSum[i][j],
                                   maxSum[i-1][j-1] + make_pair(upperCities[i].valNum + lowerCities[j].valNum, -1));
            }
        }
    }

    printf("%d %d\n", maxSum[upCnt][lowCnt].first, -maxSum[upCnt][lowCnt].second);

    for(int i=0; i<limCityCnt; i++)
        delete[] maxSum[i];
    delete[] maxSum;
}

int main() {
    int tc;

    for(scanf("%d", &tc); tc; tc--)
        testCase();
    
    return 0;
}
