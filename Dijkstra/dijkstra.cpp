#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, ll>> kraw[N];
bitset<N> odw;
ll ans[N];
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a, b, c;
		cin>>a>>b>>c;
		kraw[a].pb({b, c});
		kraw[b].pb({a, c});
	}
	priority_queue<pair<ll, int>> order;
	order.push({0, 1});
	while(!order.empty()){
		auto x = order.top();
		order.pop();
		if(odw[x.second]) continue;
		odw[x.second]=true;
		ans[x.second]=-x.first;
		for(auto v : kraw[x.second]){
			order.push({x.first-v.second, v.first});
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
