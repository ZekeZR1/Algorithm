#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i, a, b)  for(int i = (a); i < (b) ; i++)
#define pb push_back
#define SORT(v,n) sort(v, v+n)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cerr << #x << ": " << x << '\n'
#define elif else if
#define itn ll
#define int ll
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
///                →,↑,←,↓,↗,↖,↙,↘
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };


class Edge {
public:
	int t;
	int w;
	Edge() {}
	Edge(int t, int w) : t(t), w(w) {}
};

int n;
static const int MAX = 100000;
vector<Edge> G[MAX];
bool vis[MAX];
int d[MAX];
static const int INFTY = (1 << 30);

void bfs(int s) {
	rep(i, n) d[i] = INFTY;
	queue<int> q;
	q.push(s);
	d[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		rep(i, G[u].size()) {
			Edge e = G[u][i];
			if (d[e.t] == INFTY) {
				d[e.t] = d[u] + e.w;
				q.push(e.t);
			}
		}
	}
}

void solve() {
	bfs(0);
	int maxv = 0;
	int tgt = 0;
	rep(i, n) {
		if (maxv < d[i]) {
			maxv = d[i];
			tgt = i;
		}
	}
	bfs(tgt);
	maxv = 0;
	rep(i, n) {
		if (d[i] == INFTY) continue;
		maxv = max(maxv, d[i]);
	}
	cout << maxv << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n - 1) {
		int s, t, w;
		cin >> s >> t >> w;
		G[s].pb(Edge(t, w));
		G[t].pb(Edge(s, w));
	}
	solve();
	return 0;
}
