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
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i, a, b)  for(int i = (a); i < (b) ; i++)
#define pb push_back
#define SORT(v,n) sort(v, v+n)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cerr << #x << ": " << x << '\n'
#define itn int
using ll = long long;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
///                →,↑,←,↓,↗,↖,↙,↘
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };


const int MAX = 100005;
const int NIL = -1;

struct Node {
	int parent;
	int left;
	int right;
};


Node T[MAX];
int n, D[MAX];

void print(int u) {
	int i, c;
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].parent << ", ";
	cout << "depth = " << D[u] << ", ";
	if (T[u].parent == NIL) cout << "root, ";
	else if (T[u].left == NIL)cout << "leaf, ";
	else cout << "internal node, ";

	cout << '[';
	for (i = 0, c = T[u].left; c != NIL; i++, c = T[c].right) {
		if (i) cout << ", ";
		cout << c;
	}
	cout << ']' << endl;
}

void rec(int u, int p) {
	D[u] = p;
	if (T[u].right != NIL) rec(T[u].right, p);
	if (T[u].left != NIL) rec(T[u].left, p + 1);
}

signed main() {
	int i, j, d, v, c, l, r;
	cin >> n;
	rep(i, n) T[i].parent = T[i].left = T[i].right = NIL;
	rep(i, n) {
		cin >> v >> d;
		rep(j, d) {
			cin >> c;
			if (j == 0) T[v].left = c;
			else T[l].right = c;
			l = c;
			T[c].parent = v;
		}
	}
	rep(i, n) {
		if (T[i].parent == NIL) r = i;
	}
	rec(r, 0);
	rep(i, n) print(i);
	return 0;
}