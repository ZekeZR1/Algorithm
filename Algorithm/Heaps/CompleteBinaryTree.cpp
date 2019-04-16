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
///                →,↑,←,↓,↗,↖,↙,↘
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int parent(int i) { return i / 2; }
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }

signed main() {
	int i, h, A[250 + 1];
	cin >> h;
	rep(i, h) cin >> A[i + 1];
	rep(i, h) {
		cout << "node " << i + 1 << ": " << "key = " << A[i + 1] << ", ";
		if (parent(i + 1) >= 1) cout << "parent key = " << A[parent(i + 1)] << ", ";
		if (left(i + 1) <= h) cout << "left key = " << A[left(i + 1)] << ", ";
		if (right(i + 1) <= h) cout << "right key = " << A[right(i + 1)] << ", ";
		cout << endl;
	}
	return 0;
}