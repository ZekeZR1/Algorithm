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
#include <fstream>
#include <codecvt>

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
const int INF = (1LL << 32);
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

static const int MAX = 1400;
int dp[MAX][MAX], G[MAX][MAX];

int getLargestSquare(int h, int w) {
	int maxWidth = 0;
	rep(i, h) {
		rep(j, w) {
			dp[i][j] = (G[i][j] + 1) % 2;
			maxWidth |= dp[i][j];
		}
	}
	FOR(i, 1, h) {
		FOR(j, 1, w) {
			if (G[i][j]) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				maxWidth = max(maxWidth, dp[i][j]);
			}
		}
	}
	return maxWidth * maxWidth;
}

signed main() {
	ios::sync_with_stdio(true);
	int h, w;
	cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			cin >> G[i][j];
		}
	}
	cout << getLargestSquare(h, w) << endl;;
	return 0;
}