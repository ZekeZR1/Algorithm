﻿#include <iostream>
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

struct Node {
	int key;
	Node *left, *right, *parent;
};

Node *root, *NIL;

Node* treeMin(Node *x) {
	while (x->left != NIL) x = x->left;
	return x;
}


Node* find(Node* u, int k) {
	while (u != NIL && u->key != k) {
		if (k < u->key) u = u->left;
		else u = u->right;
	}
	return u;
}

Node* treeSuccessor(Node* x) {
	if (x->right != NIL) return treeMin(x->right);
	Node *y = x->parent;
	while (y != NIL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

void treeDelete(Node *z) {
	Node *y;
	Node *x;
	if (z->left == NIL || z->right == NIL) y = z;
	else y = treeSuccessor(z);
	if (y->left != NIL) {
		x = y->left;
	}
	else {
		x = y->right;
	}
	if (x != NIL) {
		x->parent = y->parent;
	}
	if (y->parent == NIL) {
		root = x;
	}
	else {
		if (y == y->parent->left) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
	}
	if (y != z)
		z->key = y->key;
	free(y);
}

void preParse(Node *u) {
	if (u == NIL)
		return;
	cout << ' ' << u->key;
	preParse(u->left);
	preParse(u->right);
}

void inParse(Node* u) {
	if (u == NIL)
		return;
	inParse(u->left);
	cout << ' ' << u->key;
	inParse(u->right);
}

void postParse(Node* u) {
	if (u == NIL)
		return;
	postParse(u->left);
	postParse(u->right);
	cout << ' ' << u->key;
}

void insert(int key) {
	Node *y = NIL;
	Node *x = root;
	Node *z;
	z = (Node*)malloc(sizeof(Node));
	//Node* z = new Node;
	z->key = key;
	z->left = NIL;
	z->right = NIL;
	while (x != NIL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NIL) {
		root = z;
	}
	else {
		if (z->key < y->key) {
			y->left = z;
		}
		else {
			y->right = z;
		}
	}
}

signed main() {
	int n, i, x;
	string com;
	cin >> n;
	rep(i, n) {
		cin >> com;
		if (com == "find") {
			int k;
			cin >> k;
			auto t = find(root, k);
			if (t == NIL)
				cout << "no" << endl;
			else
				cout << "yes" << endl;
		}
		if (com == "insert") {
			cin >> x;
			insert(x);
		}
		if (com == "print") {
			inParse(root);
			cout << endl;
			preParse(root);
			cout << endl;
		}
		if (com == "delete") {
			cin >> x;
			if (find(root, x) != NIL) {
				treeDelete(find(root, x));
			}
		}
	}
	return 0;
}