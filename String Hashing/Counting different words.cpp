#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int st1 = 131;
const int st2 = 137;
const int N = 1e5 + 5;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	set<pair<int, int>> words;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		int hash_1=1, hash_2=1;
		for(int i=(int)a.size()-1;i>=0;i--){
			hash_1=((ll)hash_1*st1+(int)a[0])%MOD1;
			hash_2=((ll)hash_2*st2+(int)a[0])%MOD2;
		}
		words.insert({hash_1, hash_2});
	}
	cout<<(int)words.size();
	return 0;
}
