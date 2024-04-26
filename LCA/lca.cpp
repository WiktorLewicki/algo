#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const int K = 22;
vector<int> kraw[N];
int anc[N][K], gleb[N], ojc[N];
void calc(int x, int p){
	for(auto v : kraw[x]){
		if(v==p) continue;
		ojc[v]=x;
		gleb[v]=gleb[x]+1;
		calc(v, x);
	}
}
void make_anc(int n){
	for(int i=1;i<=n;i++){
		anc[i][0]=ojc[i];
	}
	for(int k=1;k<K;k++){
		for(int i=1;i<=n;i++){
			anc[i][k]=anc[anc[i][k-1]][k-1];
		}
	}
}
int lca(int a, int b){
	if(gleb[a]<gleb[b]){
		swap(a, b);
	}
	for(int k=K-1;k>=0;k--){
		if(gleb[anc[a][k]]>=gleb[b]){
			a=anc[a][k];
		}
	}
	if(a==b) return a;
	for(int k=K-1;k>=0;k--){
		if(anc[a][k]!=anc[b][k]){
			a=anc[a][k];
			b=anc[b][k];
		}
	}
	return ojc[a];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int a, b;
		cin>>a>>b;
		kraw[a].pb(b);
		kraw[b].pb(a);
	}
	calc(1, 0);
	ojc[1]=1;
	make_anc(n);
	int a, b;
	cin>>a>>b;
	cout<<lca(a, b)<<"\n";
	return 0;
}
