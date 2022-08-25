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

int dp[11][100][2] ;


int countDigits(int x) {
	int ans = 0 ;
	while (x > 0) {
		ans++ ;
		x /= 10 ;
	}
	return ans ;
}

vector<int> storeDigits(int x) {
	vector<int>d ;
	while (x > 0) {
		d.pb(x % 10) ;
		x /= 10 ;
	}
	d.pb(0) ;
	reverse(all(d)) ;
	return d ;
}

int digSum(int pos, int n, int sum, bool flag, vector<int>&digits) {
	if (pos > n) {
		return sum ;
	}

	if (dp[pos][sum][flag] != -1) {
		return dp[pos][sum][flag] ;
	}

	int limit = 9 ;
	if (!flag) limit = digits[pos] ;

	int res = 0 ;
	for (int i = 0 ; i <= limit ; i++) {
		if (flag || i < limit) {
			res += digSum(pos + 1 , n, sum + i, true, digits) ;
		}
		else {
			res += digSum(pos + 1 , n, sum + i, false, digits) ;
		}
	}
	return dp[pos][sum][flag] = res ;
	// return res ;
}

int calculateDigitSum(int num) {

	int n = countDigits(num) ;
	vector<int>digits = storeDigits(num) ;
	// pos, n , sum, flag , limit array
	memset(dp, -1, sizeof dp) ;
	return digSum(1, digits.size()-1 , 0 , 0, digits) ;
}
void solve() {
	int x, y ;
	while (1) {
		cin >> x >> y ;
		if (x == -1) break ;
		cout << calculateDigitSum(y) - calculateDigitSum(max(0LL, x - 1)) << "\n" ;
	}
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
