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

int left(int i) {
	return i * 2;
}
int right(int i) {
	return i * 2 + 1;
}
int parent(int i) {
	return i / 2;
}

int A[500100] = { 0 };
int h;

void maxHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int largest;
	if (l <= h && A[i] < A[l])
		largest = l;
	else
		largest = i;
	if (r <= h && A[largest] < A[r])
		largest = r;
	if (largest != i) {
		swap(A[largest], A[i]);
		maxHeapify(largest);
	}
}

void buildMaxHeap() {
	for (int i = h / 2; i >= 1; i--) {
		maxHeapify(i);
	}
}
signed main() {
	int i;
	cin >> h;
	rep(i, h) cin >> A[i + 1];
	buildMaxHeap();
	rep(i, h) {
		cout << ' ' << A[i + 1];
	}
	cout << endl;
	return 0;
}