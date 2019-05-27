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
#include <iomanip>
#include  <cassert>

using namespace std;
using ll = long long int;
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i, a, b)  for(int i = (a); i < (b) ; i++)
#define pb push_back
#define SORT(v,n) sort(v, v+n)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cerr << #x << ": " << x << '\n'
#define elif else if
#define int ll
//const int INF = 100100100;
const int INF = (1LL << 32);
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;


static const int MMAX = 20;
static const int NMAX = 50000;
static const int INFTY = (1 << 29);

int n, m;
int C[21];
int T[NMAX + 1];

int getNumberOfCoin() {
	rep(i, NMAX) T[i] = INFTY;
	T[0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j + C[i] <= n; j++) {
			T[j + C[i]] = min(T[j + C[i]], T[j] + 1);
		}
	}
	return T[n];
}


signed main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> C[i];
	cout << getNumberOfCoin() << endl;
	return 0;
}

