#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
ll push[4*N], d[4*N];
int sz[N], head[N], pos[N], ojc[N], gleb[N], pre[N], heavy[N], cur_pos=1, rozm=1, n, k;
vector<int>kraw[N];
bitset<N> odw;
void add(int x, ll val){
	d[x]+=val;
	push[x]+=val;
}
void pushuj(int x){
	add(x*2, push[x]);
	add(x*2+1, push[x]);
	push[x]=0;
}
void dfs(int x){
	pre[x]=cur_pos;
	sz[x]=1;
	odw[x]=true;
	int max_size=0;
	for(auto v : kraw[x]){
		if(!odw[v]){
			ojc[v]=x;
			gleb[v]=gleb[x]+1;
			dfs(v);
			sz[x]+=sz[v];
			if(sz[v]>max_size){
				max_size=sz[v];
				heavy[x]=v;
			}
		}
	}
}
void decompose(int x, int h){
	odw[x]=true;
	head[x]=h;
	pos[x]=cur_pos;
	cur_pos++;
	if(heavy[x]){
		decompose(heavy[x], h);
	}
	for(auto v : kraw[x]){
		if(!odw[v]&&v!=heavy[x]){
			decompose(v, v);
		}
	}
}
ll query(int x, int l, int r, int a, int b){
	if(a<=l&&r<=b){
		return d[x];
	}
	pushuj(x);
	ll res=0;
	int sr = (l+r)/2;
	if(a<=sr){
		res+=query(x*2, l, sr, a, b);
	}
	if(sr<b){
		res+=query(x*2+1, sr+1, r, a, b);
	}
	d[x]=d[x*2]+d[x*2+1];
	return res;
}
ll HLD_QUERY(int a, int b){
	ll res=0;
	for(; head[a]!=head[b]; b=ojc[head[b]]){
		if(gleb[head[a]]>gleb[head[b]]){
			swap(a, b);
		}
		res+=query(1, 1, rozm, pos[head[b]], pos[b]);
	}
	if(gleb[a]>gleb[b]){
		swap(a, b);
	}
	res+=query(1, 1, rozm, pos[a], pos[b]);
	return res;
}
void update(int x, int l, int r, int a, int b, int c){
	if(a<=l&&r<=b){
		add(x, c);
		return;
	}
	pushuj(x);
	int sr = (l+r)/2;
	if(a<=sr){
		update(x*2, l, sr, a, b, c);
	}
	if(sr<b){
		update(x*2+1, sr+1, r, a, b, c);
	}
	d[x]=d[x*2]+d[x*2+1];
}
void HLD_UPDATE(int a, int b, int c){
	for(; head[a]!=head[b]; b=ojc[head[b]]){
		if(gleb[head[a]]>gleb[head[b]]){
			swap(a, b);
		}
		update(1, 1, rozm, pos[head[b]], pos[b], c);
	}
	if(gleb[a]>gleb[b]){
		swap(a, b);
	}
	update(1, 1, rozm, pos[a], pos[b], c);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(rozm<n){
		rozm*=2;
	}
	for(int i=1;i<=n-1;i++){
		int a, b;
		cin>>a>>b;
		kraw[a].pb(b);
		kraw[b].pb(a);
	}
	dfs(1);
	ojc[1]=1;
	odw.reset();
	cur_pos=1;
	decompose(1, 1);
	int q;
	cin>>q;
	while(q--){
		char z;
		cin>>z;
		if(z=='U'){
			int a, b, c;
			cin>>a>>b>>c;
			HLD_UPDATE(a, b, c);
		}
		else{
			int a, b;
			cin>>a>>b;
			cout<<HLD_QUERY(a, b)<<"\n";
		}
	}
	return 0;
}
