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


static const int N = 3;
static const int N2 = 9;

struct Puzzle {
	int f[N2];
	int space;
	string path;

	bool operator <(const Puzzle& p) const {
		rep(i, N2) {
			if (p.f[i] == f[i]) continue;
			return f[i] > p.f [i];
		}
		return false;
	}
};

static const char dir[4] = { 'u','l','d','r' };


bool isTarget(Puzzle p) {
	for (int i = 0; i < N2; i++)
		if (p.f[i] != i+1) return false;

	return true;
}

string bfs(Puzzle s) {

	string path = "";
	queue<Puzzle> Q;
	Q.push(s);
	map<Puzzle, bool> V;
	V[s] = true;

	while (!Q.empty()) {
		auto p = Q.front();
		Q.pop();

		if (isTarget(p)) return p.path;

		int sx = p.space / N;
		int sy = p.space % N;

		rep(r, 4) {
			int tx = sx + dx[r];
			int ty = sy + dy[r];
			if (tx < 0 or ty < 0 or tx >= N or ty >= N) continue;
			auto v = p;
			swap(v.f[p.space], v.f[tx * N + ty]);
			v.space = tx * N + ty;
			if (V[v] == false) {
				V[v] = true;
				v.path += dir[r];
				Q.push(v);
			}
		}
	}

	return "";
}


signed main() {
	ios::sync_with_stdio(true);

	Puzzle in;

	rep(i, N2) {
		cin >> in.f[i];
		if (in.f[i] == 0) {
			in.space = i;
			in.f[i] = N2;
		}
	}

	cout << bfs(in).size() << endl;

	return 0;
}
