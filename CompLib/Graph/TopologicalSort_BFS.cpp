#include <iostream>
#include <sstream>
#include <regex>
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
//const int INF = 100100100;
const int INF = (1LL << 32);
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

static const int MAX = 100000;

bool V[MAX];
vector<int> G[MAX];
list<int> out;
int N;
int indeg[MAX];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	V[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		out.pb(u);
		rep(i, G[u].size()) {
			int v = G[u][i];
			indeg[v]--;
			if (indeg[v] == 0 and !V[v]) {
				V[v] = true;
				q.push(v);
			}
		}
	}
}


void tsort() {
	rep(i, N) indeg[i] = 0;
	rep(u, N) {
		rep(j, G[u].size()) {
			int v = G[u][j];
			indeg[v]++;
		}
	}
	rep(u, N) {
		if (!V[u] and indeg[u] == 0) {
			bfs(u);
		}
	}
	for (list<int>::iterator iter = out.begin(); iter != out.end(); iter++) {
		cout << *iter << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	int e;
	cin >> N >> e;
	rep(i, N) V[i] = false;
	rep(i, e) {
		int s, t;
		cin >> s >> t;
		G[s].pb(t);
	}
	tsort();
	return 0;
}

