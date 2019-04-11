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

int a[1000000];

#define  MAX 10000
struct Node { int parent, left, right; };
Node T[MAX];
int n;
int NIL = -1;

void preParse(int id) {
	if (id == NIL)
		return;
	cout << " " << id;
	preParse(T[id].left);
	preParse(T[id].right);
}

void inParse(int id) {
	if (id == NIL)
		return;
	inParse(T[id].left);
	cout << " " << id;
	inParse(T[id].right);
}

void postParse(int id) {
	if (id == NIL)
		return;
	postParse(T[id].left);
	postParse(T[id].right);
	cout << " " << id;
}

signed main() {
	cin >> n;
	int id, left, right, i;
	rep(i, n) T[i].parent = NIL;
	rep(i, n) {
		cin >> id >> left >> right;
		T[id].left = left;
		T[id].right = right;
		if (left != NIL)T[left].parent = id;
		if (right != NIL)T[right].parent = id;
	}
	int root;
	rep(i, n) if (T[i].parent == NIL) root = i;
	cout << "Preorder" << endl;
	preParse(root);
	cout << endl;
	cout << "Inorder" << endl;
	inParse(root);
	cout << endl;
	cout << "Postorder" << endl;
	postParse(root);
	cout << endl;
	return 0;
}