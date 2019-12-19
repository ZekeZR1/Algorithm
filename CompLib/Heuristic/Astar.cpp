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
static const char dir[4] = { 'r','u','l','d' };
int MDT[N2][N2];

struct Puzzle {
	int f[N2], space, MD, cost;

	bool operator <(const Puzzle& p) const {
		rep(i, N2) {
			if (f[i] == p.f[i]) continue;
			return f[i] < p.f[i];
		}
		return false;
	}
};

struct State {
	Puzzle puzzle;
	int estimated;
	bool operator <(const State& s) const {
		return estimated > s.estimated;
	}
};

int GetAllMD(Puzzle pz) {
	int sum = 0;
	rep(i, N2) {
		if (pz.f[i] == N2) continue;
		sum += MDT[i][pz.f[i] - 1];
	}
	return sum;
}

int Astar(Puzzle s) {
	priority_queue<State> PQ;
	s.MD = GetAllMD(s);
	s.cost = 0;
	map<Puzzle, bool> V;
	Puzzle u, v;
	State initial;
	initial.puzzle = s;
	initial.estimated = GetAllMD(s);
	PQ.push(initial);

	while (!PQ.empty()) {
		State st = PQ.top(); PQ.pop();
		u = st.puzzle;

		if (u.MD == 0) return u.cost;
		V[u] = true;

		int sx = u.space / N;
		int sy = u.space % N;

		rep(r, 4) {
			int tx = sx + dx[r];
			int ty = sy + dy[r];
			if (tx < 0 or ty < 0 or tx >= N or ty >= N) continue;
			v = u;

			v.MD -= MDT[tx * N + ty][v.f[tx * N + ty] - 1];
			v.MD += MDT[sx * N + sy][v.f[tx * N + ty] - 1];

			swap(v.f[sx * N + sy], v.f[tx * N + ty]);
			v.space = tx * N + ty;
			if (!V[v]) {
				v.cost++;
				State news;
				news.puzzle = v;
				news.estimated = v.cost + v.MD;
				PQ.push(news);
			}
		}
	}
	return -1;
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

	cout << Astar(in) << endl;

	return 0;
}
