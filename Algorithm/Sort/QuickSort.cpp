#include <iostream>
using namespace std;


void trace(int A[], int N) {
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
}

int partision(int A[], int n, int p, int r) {
	int x, i, j, t;
	x = A[r];
	i = p - 1;
	for (j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			t = A[i]; A[i] = A[j]; A[j] = t;
		}
	}
	t = A[i + 1]; A[i + 1] = A[r]; A[r]; A[r] = t;
	return i + 1;
}
void quickSort(int A[], int n, int p, int r) {
	int q;
	if (p < r) {
		q = partision(A, n, p, r);
		quickSort(A, n, p, q - 1);
		quickSort(A, n, q + 1, r);
	}
}

int main() {
	int a[5] = { 10,4,5,6,1 }, n = 5;
	int q, i;
	quickSort(a, n, 0, n - 1);
	trace(a, n);
	cout << endl;
	return 0;
}