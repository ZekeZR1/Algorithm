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

#define MAX 3000000 
char s[MAX + 10];
int wSum[MAX + 10];
int eSum[MAX + 10];

int dp[45];

int fibo(int n) {
	if (n == 0 || n == 1)
		return dp[n] = 1;
	if (dp[n] != -1)
		return dp[n];
	return dp[n] = fibo(n - 2) + fibo(n - 1);
}

signed main() {
	ios::sync_with_stdio(false);
	int i, n;
	cin >> n;
	rep(i, 45) dp[i] = -1;
	cout << fibo(n) << "\n";
	return 0;
}