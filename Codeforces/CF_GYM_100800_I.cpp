#include <bits/stdc++.h>
using namespace std;

char str[10002];
char hard[] = {'b','c','d','g','k','n','p','t'};
int n;
vector <char> result;

bool findInHard(char c){
	for(int i=0; i<8; i++){
		if(c==hard[i])
			return true;
	}
	return false;
}

char transformToHard(char c){
	int n = c - 'a', mn = 100;
	char nw = 'a';
	for(int i=0, act; i<8; i++){
		act = hard[i] - 'a';
		if(abs(n-act)<mn){
			mn = abs(n-act);
			nw = hard[i]; 
		}
	}
	return nw;
}

int findWord(int ind){
	while(ind < n && str[ind]!=' ')
		ind++;
	if(str[ind]==' ' || str[ind]=='\n')
		ind--;
	return ind;
}

int haveSyllables(int first, int last){
	for(int i=first; i<=last; i++){
		if(str[i]=='-')
			return i;
	}
	return -1;
}

void replaceToHard(char c, int first, int last){
	for(int i=first; i<=last; i++){
		char actual = tolower(str[i]);
		if(findInHard(actual)){
			actual = c;
			if(str[i]==tolower(str[i]))
				str[i]=actual;
			else
				str[i]=toupper(actual);
		}
	}
}

void addFinal(char c){
	int n = c - 'a';
	if(n <= abs(n-('o'-'a')) && n <= abs(n-('u'-'a'))){
		result.push_back('a');
	}
	else if(abs(n-('o'-'a')) < n && abs(n-('o'-'a')) <= abs(n-('u'-'a')) ){
		result.push_back('o');
	}
	else{
		result.push_back('u');
	}
	result.push_back('h');
}

int processWord(int first){
	int last = findWord(first);
	char actual = tolower(str[first]);
	if(!findInHard(actual)){
		actual = transformToHard(actual);
		if(str[first]==tolower(str[first]))
			str[first]=actual;
		else
			str[first]=toupper(actual);
	}
	if(haveSyllables(first,last)!=-1){
		replaceToHard(tolower(str[first]),haveSyllables(first,last),last);
	}
	for(int i=first; i<=last; i++){
		if(str[i]!='-')
			result.push_back(str[i]);
	}
	if(findInHard(tolower(str[last]))){
		addFinal(tolower(str[last]));
	}
	return last;
}

int main(){
	fgets(str,10002,stdin);
	n = strlen(str)-1;
	for(int i=0; i<n; i++){
		if(str[i]!=' ')
			i = processWord(i);
		else
			result.push_back(' ');
	}
	for(int i=0; i<(int)result.size(); i++)
		printf("%c",result[i]);
	return 0;
}
