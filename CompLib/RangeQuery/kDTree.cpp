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
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

class Node {
public:
	int location;
	int p, l, r;
	Node() {};
};

class Point {
public:
	int id, x, y;
	Point() {}
	Point(int id, int x, int y) : id(id), x(x), y(y) {}
	bool operator < (const Point& p) const {
		return id < p.id;
	}
	void Print() {
		cout << id << '\n';
	}
};


static const int MAX = 1000000;
static const int NIL = -1;
int N;
Point P[MAX];
Node T[MAX];
int np;

bool lessX(const Point& p1, const Point& p2) { return p1.x < p2.x; }
bool lessY(const Point& p1, const Point& p2) { return p1.y < p2.y; }

int makeKDTree(int l, int r, int depth) {
	if (!(l < r)) return NIL;
	int mid = (l + r) / 2;
	int t = np++;
	if (depth % 2 == 0) {
		sort(P + l, P + r, lessX);
	}
	else {
		sort(P + l, P + r, lessY);
	}
	T[t].location = mid;
	T[t].l = makeKDTree(l, mid, depth + 1);
	T[t].r = makeKDTree(mid + 1, r, depth + 1);
	return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> & ans) {
	int x = P[T[v].location].x;
	int y = P[T[v].location].y;
	int id = P[T[v].location].id;
	if (sx <= x && x <= tx && sy <= y && y <= ty) {
		ans.pb(P[T[v].location]);
	}

	if (depth % 2 == 0) {
		if (T[v].l != NIL) {
			if (sx <= x)
				find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
		}
		if (T[v].r != NIL) {
			if (x <= tx)
				find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
		}
	}
	else {
		if (T[v].l != NIL) {
			if (sy <= y)
				find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
		}
		if (T[v].r != NIL) {
			if (y <= ty)
				find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	int x, y, i, j;
	cin >> N;
	rep(i, N) {
		cin >> x >> y;
		P[i] = Point(i, x, y);
		T[i].l = T[i].r = T[i].p = NIL;
	}
	np = 0;
	int root = makeKDTree(0, N, 0);
	int q;
	cin >> q;
	vector<Point> ans;
	int sx, tx, sy, ty;
	rep(i, q) {
		cin >> sx >> tx >> sy >> ty;
		ans.clear();
		find(root, sx, tx, sy, ty, 0, ans);
		sort(ALL(ans));
		rep(j, ans.size()) {
			ans[j].Print();
		}
		cout << '\n';
	}
	return 0;
}