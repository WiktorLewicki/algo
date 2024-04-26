#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
int t[N];
deque<pair<int, int>> Q;
void push(int a){
    while (!Q.empty() && Q.back().first <= t[a]){
        Q.pop_back();
	}
    Q.pb(make_pair(t[a], a));
}
void pop(int a){
    if (Q.front().second == a){
        Q.pop_front();
	}
}
int get_maximum() {
    if (Q.size() == 0){
        return -1;
	}
    return Q.front().first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
