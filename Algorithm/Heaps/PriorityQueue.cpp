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

int A[2000000];
int h;
#define INFTY (1<<30)

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

void increaseKey(int i, int key) {
	if (A[i] > key)
		return;
	A[i] = key;
	while (i > 1 && A[parent(i)] < key) {
		swap(A[parent(i)], A[i]);
		i = parent(i);
	}
}

void insert(int key) {
	h++;
	A[h] = -INFTY;
	increaseKey(h, key);
}

int HeapExtractMax() {
	int max;
	if (h < 1)
		return -INFTY;
	max = A[1];
	A[1] = A[h--];
	maxHeapify(1);
	return max;
}

signed main() {
	int i;
	while (true) {
		string com;
		cin >> com;
		if (com == "end")
			break;
		if (com == "insert") {
			int k;
			cin >> k;
			insert(k);
		}
		if (com == "extract") {
			cout << HeapExtractMax() << endl;;
		}
	}
	return 0;
}