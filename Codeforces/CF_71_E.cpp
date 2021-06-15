#include <bits/stdc++.h>
using namespace std;
const int limN = 17;
const int limB = 1<<limN;

map <string, int> dico;
int sig[limB][limN];
bool usd[limB][limN];
int sumos[limB];
int bscs[limN];

int getSig(int pos, int msk);
void llena(int *elems, int pos, int msk=0, int sumo=0);

int main() {
    dico["H"] = 1;
    dico["He"] = 2;
    dico["Li"] = 3;
    dico["Be"] = 4;
    dico["B"] = 5;
    dico["C"] = 6;
    dico["N"] = 7;
    dico["O"] = 8;
    dico["F"] = 9;
    dico["Ne"] = 10;
    dico["Na"] = 11;
    dico["Mg"] = 12;
    dico["Al"] = 13;
    dico["Si"] = 14;
    dico["P"] = 15;
    dico["S"] = 16;
    dico["Cl"] = 17;
    dico["Ar"] = 18;
    dico["K"] = 19;
    dico["Ca"] = 20;
    dico["Sc"] = 21;
    dico["Ti"] = 22;
    dico["V"] = 23;
    dico["Cr"] = 24;
    dico["Mn"] = 25;
    dico["Fe"] = 26;
    dico["Co"] = 27;
    dico["Ni"] = 28;
    dico["Cu"] = 29;
    dico["Zn"] = 30;
    dico["Ga"] = 31;
    dico["Ge"] = 32;
    dico["As"] = 33;
    dico["Se"] = 34;
    dico["Br"] = 35;
    dico["Kr"] = 36;
    dico["Rb"] = 37;
    dico["Sr"] = 38;
    dico["Y"] = 39;
    dico["Zr"] = 40;
    dico["Nb"] = 41;
    dico["Mo"] = 42;
    dico["Tc"] = 43;
    dico["Ru"] = 44;
    dico["Rh"] = 45;
    dico["Pd"] = 46;
    dico["Ag"] = 47;
    dico["Cd"] = 48;
    dico["In"] = 49;
    dico["Sn"] = 50;
    dico["Sb"] = 51;
    dico["Te"] = 52;
    dico["I"] = 53;
    dico["Xe"] = 54;
    dico["Cs"] = 55;
    dico["Ba"] = 56;
    dico["La"] = 57;
    dico["Ce"] = 58;
    dico["Pr"] = 59;
    dico["Nd"] = 60;
    dico["Pm"] = 61;
    dico["Sm"] = 62;
    dico["Eu"] = 63;
    dico["Gd"] = 64;
    dico["Tb"] = 65;
    dico["Dy"] = 66;
    dico["Ho"] = 67;
    dico["Er"] = 68;
    dico["Tm"] = 69;
    dico["Yb"] = 70;
    dico["Lu"] = 71;
    dico["Hf"] = 72;
    dico["Ta"] = 73;
    dico["W"] = 74;
    dico["Re"] = 75;
    dico["Os"] = 76;
    dico["Ir"] = 77;
    dico["Pt"] = 78;
    dico["Au"] = 79;
    dico["Hg"] = 80;
    dico["Tl"] = 81;
    dico["Pb"] = 82;
    dico["Bi"] = 83;
    dico["Po"] = 84;
    dico["At"] = 85;
    dico["Rn"] = 86;
    dico["Fr"] = 87;
    dico["Ra"] = 88;
    dico["Ac"] = 89;
    dico["Th"] = 90;
    dico["Pa"] = 91;
    dico["U"] = 92;
    dico["Np"] = 93;
    dico["Pu"] = 94;
    dico["Am"] = 95;
    dico["Cm"] = 96;
    dico["Bk"] = 97;
    dico["Cf"] = 98;
    dico["Es"] = 99;
    dico["Fm"] = 100;
    int N, K ;
    char inis[limN][5], fins[limN][5];
    int elems[limN];

    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%s", inis[i]);
        elems[i] = dico[inis[i]];
    }
    for(int i=0; i<K; i++) {
        scanf("%s", fins[i]);
        bscs[i] = dico[fins[i]];
    }

    llena(elems, N-1);
    
    if( !getSig(K-1, (1<<N)-1) ) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int msk=(1<<N)-1, pos=K-1; pos>=0; pos--) {
        int cnt = 0;
        for(int i=0; i<N; i++) {
            if( ((1<<i) & sig[msk][pos]) == 0)
                continue;
            if(cnt++)
                printf("+");
            printf("%s", inis[i]);
        }
            
        printf("->%s\n", fins[pos]);
        msk -= sig[msk][pos];
    }
}

int getSig(int pos, int msk) {
    if(pos==-1)
        return -1;
    if(usd[msk][pos])
        return sig[msk][pos];
    usd[msk][pos] = true;
    for(int s=msk; s; s=(s-1)&msk)
        if(sumos[s] == bscs[pos] && getSig(pos-1, msk-s))
            return sig[msk][pos] = s;
    return 0;
}

void llena(int *elems, int pos, int msk, int sumo) {
    if(pos==-1) {
        sumos[msk] = sumo;
        return;
    }
    llena(elems, pos-1, msk, sumo);
    llena(elems, pos-1, msk + (1<<pos), sumo + elems[pos]);
}
