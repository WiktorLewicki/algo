#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
vector<int> kraw[N][2], sss[N];
stack<int> toposort;
bitset<N> odw;
int t;
void dfs(int x, bool ok){
	odw[x]=true;
	for(auto v : kraw[x][ok]){
		if(!odw[v]) dfs(v, ok);
	}
	if(ok){
		sss[t].pb(x);
	}
	else toposort.push(x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a, b;
		cin>>a>>b;
		kraw[a][0].pb(b);
		kraw[b][1].pb(a);
	}
	for(int i=1;i<=n;i++){
		if(!odw[i]) dfs(i, 0);
	}
	odw.reset();
	while(!toposort.empty()){
		int x=toposort.top();
		if(!odw[x]){
			t++;
			dfs(x, 1);
		}
		toposort.pop();
	}
	for(int i=1;i<=t;i++){
		cout<<i<<": ";
		for(auto v : sss[i]){
			cout<<v<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
