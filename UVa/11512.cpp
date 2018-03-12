#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int dict[300];
int revDict[] = {'A', 'C', 'G', 'T'};

class TrieNode {
private:
    TrieNode* children[4];
    TrieNode* parent;
    char prevChar;
    int childCnt ;
    int pt ;
public:
    TrieNode() {
        prevChar = 5;
        pt = 0;
        childCnt = 0;
        parent = children[0] = children[1] = children[2] = children[3] = NULL;
    }
    TrieNode(TrieNode* dad, char pc) {
        prevChar = pc;
        pt = 0;
        parent = dad;
        childCnt = 0;
        children[0] = children[1] = children[2] = children[3] = NULL;
    }
    ~TrieNode() {
        delete children[0];
        delete children[1];
        delete children[2];
        delete children[3];
    }
    inline bool hasChild(int idx) {
        return children[idx]!=NULL;
    }
    void setAsEnd() {
        this->childCnt ++;
    }
    TrieNode* getChild(int idx) {
        if(children[idx]==NULL) {
            children[idx] = new TrieNode(this, idx);
            childCnt ++;
        }
        return children[idx];
    }
    void increasePt() {
        pt ++;
    }
    inline TrieNode* getParent() {
        return this->parent;
    }
    inline int getChildCnt() {
        return childCnt;
    }
    inline int getPt() {
        return pt;
    }
    inline int getPrevChar() {
        return prevChar;
    }
};

class Trie {
private:
    TrieNode* root ;
    void getLongestRep(TrieNode* &ans, int &maxD, TrieNode* pos, int d) {
        if(d>maxD && pos->getChildCnt()>1) {
            // printf("* [%d] ", pos->getChildCnt());
            ans = pos;
            maxD = d;
        }
        // if(pos!=root) {
        //     printf("%c (%d) [%d] => ", revDict[pos->getPrevChar()], d, pos->getChildCnt());
        //     for(int i=0; i<4; i++)
        //         if(pos->hasChild(i))
        //             printf("%c", revDict[i]);
        //     printf("\n");
        // }
        for(int i=0; i<4; i++)
            if(pos->hasChild(i))
                getLongestRep(ans, maxD, pos->getChild(i), d+1);
    }
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    void clear() {
        delete root;
    }
    void addStr(char *str, int k) {
        TrieNode* pos = this->root;
        for(int i=0; i<k; i++) {
            // printf("%d ", str[i]);
            pos->increasePt();
            pos = pos->getChild(str[i]);
        }
        pos->increasePt();
        pos->setAsEnd();
        // pos->increasePt();
        // printf("\n");
    }
    pair<int,string> getLongestRep() {
        int k = 0, reps = 0;
        TrieNode* pos = root;
        // cout << k << endl;
        this->getLongestRep(pos, k, root, 0);
        // cout << k << endl;
        if(pos==root) {
            return make_pair(0, "");
        }
        string str = string(k, 0);
        reps = pos->getPt();
        // reps = pos->getChildCnt();


        while(pos!=root) {
            str[--k] = revDict[pos->getPrevChar()];
            pos = pos->getParent();
        }
        
        return make_pair(reps, str);
    }
};

void testCase(char *str, int strTam) {
    Trie prefTrie;
    pair <int, string> ans;
    for(int i=0; i<strTam; i++) {
        str[i] = dict[(int) str[i]];
        // printf("%d ", str[i]);
    }
    // cout << endl;
    for(int i=0; i<strTam; i++) {
        prefTrie.addStr(str + i, strTam-i);
    }
    ans = prefTrie.getLongestRep();
    if(ans.first==0)
        printf("No repetitions found!\n");
    else
        printf("%s %d\n", ans.second.c_str(), ans.first);
}

int main() {
    for(int i=0; i<4; i++)
        dict[revDict[i]] = i;

    char line[limN];
    char *w = &line[0];
    size_t tam = sizeof(line);
    int n, tc ;

    // (n = getline(&w, &tam, stdin));
    // for(sscanf(line, "%d", &tc); tc; tc--) {
    //     ((n = getline(&w, &tam, stdin))!=-1);
    //     testCase(w, n-1);
    //     // return 0;
    // }
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        scanf("%s", line);
        testCase(line, strlen(line));
    }
}
