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
int n;
vector<int> G[MAX];
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int current, int prev) {
	prenum[current] = lowest[current] = timer;
	timer++;
	visited[current] = true;
	int next;
	rep(i, G[current].size()) {
		next = G[current][i];
		if (!visited[next]) {
			parent[next] = current;
			dfs(next, current);
			lowest[current] = min(lowest[current], lowest[next]);
		}elif(next != prev) {
			lowest[current] = min(lowest[current], prenum[next]);
		}
	}
}

void art_points() {
	rep(i, n) visited[i] = false;
	timer = 1;
	dfs(0, -1);
	set<int> ap;
	int np = 0;
	FOR(i, 1, n) {
		int p = parent[i];
		if (p == 0) np++;
		elif(prenum[p] <= lowest[i]) ap.insert(p);
	}
	if (np > 1) ap.insert(0);
	for (set<int>::iterator it = ap.begin(); it != ap.end(); it++) {
		cout << *it << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	rep(i, m) {
		int s, t;
		cin >> s >> t;
		G[s].pb(t);
		G[t].pb(s);
	}
	art_points();
	return 0;
}

