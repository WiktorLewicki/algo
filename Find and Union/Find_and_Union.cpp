#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int rep[N];
int find_rep(int a){
	if(rep[a]==a){
		return a;
	}
	return find_rep(rep[a]);
}
void union_rep(int a, int b){
	a=find_rep(a);
	b=find_rep(b);
	rep[b]=a;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		rep[i]=i;
	}
	int q;
	cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		union_rep(a, b);
	}
	int x, y;
	cin>>x>>y;
	if(find_rep(x)==find_rep(y)) cout<<"1\n";
	else cout<<"0\n";
	return 0;
}
