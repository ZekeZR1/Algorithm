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

static const int MAX = 100;
static const int White = 0;
static const int Gray = 1;
static const int Black = 2;


int n, M[MAX][MAX];
int d[MAX], p[MAX], color[MAX];

void dijkstra() {
	rep(i, n) {
		color[i] = White;
		d[i] = INF;
		p[i] = -1;
	}
	d[0] = 0;
	while (true) {
		int u, mincost = INF;
		rep(i, n) {
			if (color[i] != Black and d[i] < mincost) {
				u = i;
				mincost = d[i];
			}
		}
		if (mincost == INF) break;
		color[u] = Black;
		int v;
		rep(v, n) {
			if (color[v] != Black and M[u][v] != INF) {
				if (d[u] + M[u][v] < d[v]) {
					d[v] = d[u] + M[u][v];
					p[v] = u;
					color[v] = Gray;
				}
			}
		}
	}
	rep(i, n) {
		cout << i << ' ' << d[i] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	int i, j, k;
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			M[i][j] = INF;
		}
	}
	rep(i, n) {
		int u, k;
		cin >> u >> k;
		rep(j, k) {
			int c, v;
			cin >> v >> c;
			M[u][v] = c;
		}
	}
	dijkstra();
	return 0;
}