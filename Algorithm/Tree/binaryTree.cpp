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
#define elif else if
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
int n, Depth[MAX], Degree[MAX], Sibling[MAX], Height[MAX];

void print(int u) {
	int i, c;
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].parent << ", ";
	cout << "sibling = " << Sibling[u] << ", ";
	cout << "degree = " << Degree[u] << ", ";
	cout << "depth = " << Depth[u] << ", ";
	cout << "height = " << Height[u] << ", ";

	if (T[u].parent == NIL) cout << "root";
	elif(T[u].left == NIL && T[u].right == NIL) cout << "leaf";
	else cout << "internal node";
	cout << endl;
	/*cout << '[';
	for (i = 0, c = T[u].left; c != NIL; i++, c = T[c].right) {
	if (i) cout << ", ";
	cout << c;
	}
	cout << ']' << endl;*/
}

void rec(int u, int p) {
	Depth[u] = p;
	if (T[u].right != NIL) rec(T[u].right, p);
	if (T[u].left != NIL) rec(T[u].left, p + 1);
}

void DepRec(int id, int depth) {
	if (id == NIL)
		return;
	Depth[id] = depth;
	DepRec(T[id].left, depth + 1);
	DepRec(T[id].right, depth + 1);
}

int HeightRec(int id) {
	int h1 = 0, h2 = 0;
	if (T[id].left != NIL)
		h1 = HeightRec(T[id].left) + 1;
	if (T[id].right != NIL)
		h2 = HeightRec(T[id].right) + 1;
	return Height[id] = max(h1, h2);
}

signed main() {
	int i, j, n, id, left, right;
	cin >> n;
	rep(i, n) T[i].parent = T[i].left = T[i].right = Sibling[i] = NIL;
	rep(i, n) Degree[i] = 0;
	rep(i, n) {
		cin >> id >> left >> right;
		T[id].left = left;
		T[id].right = right;
		if (left != NIL) {
			T[left].parent = id;
			if (right != NIL) Sibling[left] = right;
			Degree[id]++;
		}
		if (right != NIL) {
			T[right].parent = id;
			if (left != NIL) Sibling[right] = left;
			Degree[id]++;
		}
	}
	int root;
	rep(i, n) if (T[i].parent == NIL) root = i;
	DepRec(root, 0);
	HeightRec(root);
	rep(i, n) print(i);
	return 0;
}