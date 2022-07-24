class Bipartite {
	vector<vector<int>>v;
	vector<int>col;
	vector<int>vis;
public:
	Bipartite(vector<vector<int>>&adj, int n) {
		v = adj;
		col.resize(n, 0);
		vis.resize(n, 0);
	}
	bool dfs(int node, int c) {
		vis[node] = 1;
		col[node] = c;

		for (auto i : v[node]) {
			if (vis[i] == 0) {
				if (dfs(i, c ^ 1) == 0)
					return 0;
			}
			else {
				if (col[node] == col[i]) return 0;
			}
		}
		return 1;
	}
	bool check_bipartite(int n) {

		bool is_bipartite = true;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				if (dfs(i, 0) == 0) is_bipartite = false;
			}
		}
		return is_bipartite;
	}
};
