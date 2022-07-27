


/*Akhand Agarwal*/
#include <bits/stdc++.h>
using namespace std;


#define int long long
#define pll pair<int, int>
#define ppll pair<int, pair<int, int>>
#define vll vector<int>
#define hell 1e9+7
#define INF 1e18
#define vpll vector<pll>
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define test int t; cin>>t; while(t--)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
/*****************************************************************************************************/

void solve() {
	int nodes , edges;
	cin >> nodes >> edges;
	set<int>adj[nodes + 1];
	set<int>NonReachableNode;
	for(int i=1; i<=nodes; i++) NonReachableNode.insert(i);
	for (int i = 0; i < edges; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	queue<int>bfs;
	int ConnectedComponents = 0;
	vector<int>visited;
	for (int i = 1; i <= nodes; i++) {
		if (NonReachableNode.count(i)) {
			ConnectedComponents++;
			bfs.push(i);
			NonReachableNode.erase(i);
		}
		while (!bfs.empty()) {
			auto x = bfs.front();
			bfs.pop();

			for (auto j : NonReachableNode) {
				if (adj[x].count(j) == 0) { // No Edge of weight 1
					visited.push_back(j);
				}
			}
			while (visited.size()) {
				bfs.push(visited.back());
				NonReachableNode.erase(visited.back());
				visited.pop_back();
			}
		}
	}
	cout << ConnectedComponents - 1 << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// test
	solve();
}



//    Problem Link1 ->  https://codeforces.com/contest/1242/problem/B
//    Solution Link1->  https://codeforces.com/contest/1242/submission/165844482
//    Problem Link2 ->  https://codeforces.com/contest/190/problem/E
//    Solution Link2->  https://codeforces.com/contest/190/submission/165845971
