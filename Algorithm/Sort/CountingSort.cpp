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
typedef long long ll;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
///                →,↑,←,↓,↗,↖,↙,↘
int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

#define NMAX 2000001
#define VMAX 10000
ll A[NMAX], C[VMAX + 1], B[NMAX];

signed main() {
	int n;
	cin >> n;
	int i;
	rep(i, VMAX) C[i] = 0;
	rep(i, n) {
		cin >> A[i + 1];
		C[A[i + 1]]++;
	}
	rep(i, VMAX) C[i + 1] = C[i + 1] + C[i];
	FOR(i, 1, n + 1) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
	rep(i, n) {
		if (i) cout << " ";
		cout << B[i + 1];
	}
	cout << endl;
	return 0;
}