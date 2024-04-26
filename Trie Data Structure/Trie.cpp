#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int tab[N][26], cnt1[N], cnt2[N];
int t;
void insert(string s){
	int x = 0;
	cnt1[x]++;
	for(auto v : s){
		int p = (int)v - 65;
		if(!tab[x][p]){
			tab[x][p] = ++t;
		}
		x = tab[x][p];
		cnt1[x]++;
	}
	cnt2[x]++;
}
bool search(string s){
	int x = 0;
	for(auto v : s){
		int p = (int)v - 65;
		if(!tab[x][p]){
			return false;
		}
		x = tab[x][p];
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//use capital letters
	string s;
	cin>>s;
	insert(s);
	cin>>s;
	cout<<search(s);
	return 0;
}
	
	
