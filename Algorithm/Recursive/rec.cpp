#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int sum_range(int a, int b) {
	if (a == b)
		return a;
	return sum_range(a + 1, b) + a;
}

vector<int> reverse_array_from_i(vector<int>& data, int i) {
	if (data.size() == i) {
		vector<int> empty_array(0);
		return empty_array;
	}
	vector<int> tmp = reverse_array_from_i(data, i + 1);
	tmp.push_back(data.at(i));
	return tmp;
}

vector<int> reverse_array(vector<int>& data) {
	return reverse_array_from_i(data, 0);
}

int array_sum_from_i(vector<int>& data, int i) {
	if (i == data.size())
		return 0;
	return data[i] + array_sum_from_i(data, i + 1);
}

int array_sum(vector<int> &data) {
	return array_sum_from_i(data, 0);
}

//n >=3
bool has_divisor(int n, int i) {
	if (n % i == 0)
		return true;
	if (i == n - 1)
		return false;
	return has_divisor(n, i + 1);
}

bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	else if (n == 2) {
		return true;
	}
	return !has_divisor(n, 2);
}

int main()
{
	vector<int> a = { 1, 2, 3, 4, 5 };
	vector<int> b = reverse_array(a);
	for (int i = 0; i < b.size(); i++) {
		cout << b.at(i) << endl;
	}
	return 0;
}

