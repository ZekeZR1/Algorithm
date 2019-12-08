//エラトステネスの篩版素数判定 O(N log log N)

vector<bool> primelist(pow(10, 8), true);

void eratos(int size) {
	primelist[0] = primelist[1] = false;
	for (int i = 2; i <= sqrt(size); i++) {
		if (primelist[i]) {
			int j = i + i;
			while (j <= size) {
				primelist[j] = false;
				j += i;
			}
		}
	}
}

bool isPrime(int x) {
	return primelist[x];
}

signed main() {
	ios::sync_with_stdio(true);
	int n, ans = 0;
	cin >> n;
	vector<int> x(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	std::vector<int>::iterator iter = std::max_element(x.begin(), x.end());
	size_t index = std::distance(x.begin(), iter);
	eratos(x[index]);

	for (int i = 0; i < n; i++) {
		if (isPrime(x[i])) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}


//素数判定アルゴリズム O(Σ[i=1,n]√xi)
bool isPrime2(int x) {
	if (x == 0 or x == 1) return false;
	if(x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 0; i * i < x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

//べき乗
ullong power(ullong x, ullong n) {
	ullong res = 1;
	if (n > 0) {
		res = power(x, n / 2);
		if (n % 2 == 0) res = (res * res) % MOD;
		else res = (((res * res) % MOD) * x) % MOD;
	}
	return res;
}


//最大公約数
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
