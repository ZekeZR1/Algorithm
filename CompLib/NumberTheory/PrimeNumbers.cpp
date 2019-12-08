//エラトステネスの篩版素数判定

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