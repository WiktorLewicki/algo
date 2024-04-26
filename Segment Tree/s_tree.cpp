#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
ll d[N*4], push[N*4];
int tab[N], n;
void add(int x, int val){
	d[x]+=val;
	push[x]+=val;
}
void prop(int x){
	add(x*2, push[x]);
	add(x*2+1, push[x]);
	push[x]=0;
}
void update(int x, int l, int r, int a, int b, ll val){
	if(a<=l&&r<=b){
		add(x, val);
		return;
	}
	prop(x);
	int sr=(l+r)/2;
	if(a<=sr){
		update(x*2, l, sr, a, b, val);
	}
	if(sr<b){
		update(x*2+1, sr+1, r, a, b, val);
	}
	d[x]=max(d[x*2], d[x*2+1]);
}
ll query(int x, int l, int r, int a, int b){
	if(a<=l&&r<=b){
		return d[x];
	}
	prop(x);
	ll res=-1e9;
	int sr=(l+r)/2;
	if(a<=sr){
		res=max(res, query(x*2, l, sr, a, b));
	}
	if(sr<b){
		res=max(res, query(x*2+1, sr+1, r, a, b));
	}
	d[x]=max(d[x*2], d[x*2+1]);
	return res;
}
void build(int x, int l, int r){
	if(l==r){
		if(l<=n) d[x]=tab[l];
		return;
	}
	int sr=(l+r)/2;
	build(x*2, l, sr);
	build(x*2+1, sr+1, r);
	d[x]=max(d[x*2], d[x*2+1]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int rozm=1;
	cin>>n;
	while(rozm<n){
		rozm<<=1;
	}
	for(int i=1;i<=n;i++){
		cin>>tab[i];
	}
	build(1, 1, rozm);
	int q;
	cin>>q;
	while(q--){
		char z;
		cin>>z;
		if(z=='U'){
			int a, b, val;
			cin>>a>>b>>val;
			update(1, 1, rozm, a, b, val);
		}
		else{
			int a, b;
			cin>>a>>b;
			cout<<query(1, 1, rozm, a, b)<<"\n";
		}
	}
	return 0;
}
