#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

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
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
int i, j, k;

static const int MAX = 10000;
static const int White = 0;
static const int Gray = 1;
static const int Black = 2;

vector<pair<int, int>> adj[MAX];
int n;

void dijkstra() {
	int d[MAX], p[MAX], color[MAX];
	priority_queue<pair<int, int>> PQ;
	rep(i, n) {
		color[i] = White;
		d[i] = INF;
	}
	d[0] = 0;
	PQ.push(make_pair(0, 0));
	color[0] = Gray;
	while (!PQ.empty()) {
		pair<int, int> f = PQ.top();
		PQ.pop();
		int u = f.second;
		color[u] = Black;
		if (d[u] < f.first * (-1)) continue;
		rep(j, adj[u].size()) {
			int v = adj[u][j].first;
			if (color[v] == Black) continue;
			if (d[v] > d[u] + adj[u][j].second) {
				d[v] = d[u] + adj[u][j].second;
				PQ.push(make_pair(d[v] * -1, v));
				color[v] = Gray;
			}
		}
	}
	rep(i, n) {
		cout << i << ' ' << (d[i] == INF ? -1 : d[i]) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		int u, k;
		cin >> u >> k;
		rep(j, k) {
			int v, c;
			cin >> v >> c;
			adj[u].pb(make_pair(v, c));
		}
	}
	dijkstra();
	return 0;
}