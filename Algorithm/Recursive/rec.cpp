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


int array_sum_from_i(vector<int>& data, int i) {
	if (i == data.size())
		return 0;
	return data[i] + array_sum_from_i(data, i + 1);
}

int array_sum(vector<int> &data) {
	return array_sum_from_i(data, 0);
}

int main()
{
	vector<int> a = { 0, 3, 9, 1, 5 };
	cout << array_sum(a) << endl;   // 0 + 3 + 9 + 1 + 5 = 18

	return 0;
}

