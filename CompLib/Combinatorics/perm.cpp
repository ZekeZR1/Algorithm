int perm[MAX_N];

void permutation(int pos, int n) {
	if (pos == n) {
		//do
		return;
	}
	rep(i, n) {
		if (!used[i]) {
			perm[pos] = i;
			used[i] = true;
			permutation(pos + 1, n);
			used[i] = false;
		}
	}
	return;
}


void Permutation(int n) {
	rep(i, n)
		perm[i] = i * i;
	do {
		rep(i, n) cout << perm[i];
		cout << endl;
	} while (next_permutation(perm, perm + n));
	return;
}