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
using ullong = unsigned long long;
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


static const int N = 4;
static const int N2 = 16;
static const int LIMIT = 100;
static const char dir[4] = { 'r','u','l','d' };
int MDT[N2][N2];

struct Puzzle {
	int f[N2], space, MD;
};

Puzzle state;
int limit;
int path[LIMIT];

int GetAllMD(Puzzle pz) {
	int sum = 0;
	rep(i, N2) {
		if (pz.f[i] == N2) continue;
		sum += MDT[i][pz.f[i] - 1];
	}
	return sum;
}

bool isSolved() {
	rep(i, N2) if (state.f[i] != i + 1) return false;
	return true;
}

bool dfs(int depth, int prev) {
	if (state.MD == 0) return true;
	if (depth + state.MD > limit) return false;
	int sx = state.space / N;
	int sy = state.space % N;
	Puzzle tmp;

	rep(r, 4) {
		int tx = sx + dx[r];
		int ty = sy + dy[r];
		if (tx < 0 or ty < 0 or tx >= N or ty >= N)  continue;
		if (max(prev, r) - min(prev, r) == 2) continue;
		tmp = state;
		state.MD -= MDT[tx * N + ty][state.f[tx * N + ty] - 1];
		state.MD += MDT[sx * N + sy][state.f[tx * N + ty] - 1];
		swap(state.f[tx * N + ty], state.f[sx * N + sy]);
		state.space = tx * N + ty;
		if (dfs(depth + 1, r)) { path[depth] = r; return true; }
		state = tmp;
	}
	return false;
}

string iterative_deepening(Puzzle in) {
	in.MD = GetAllMD(in);
	for (limit = in.MD; limit <= LIMIT; limit++) {
		state = in;
		if (dfs(0, -100)) {
			string ans = "";
			rep(i, limit) ans += dir[path[i]];
			return ans;
		}
	}
}

signed main() {
	ios::sync_with_stdio(true);

	rep(i, N2) {
		rep(j, N2)
			MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
	}


	Puzzle in;
	rep(i, N2) {
		cin >> in.f[i];
		if (in.f[i] == 0) {
			in.f[i] = N2;
			in.space = i;
		}
	}

	cout << iterative_deepening(in).size() << endl;

	return 0;
}