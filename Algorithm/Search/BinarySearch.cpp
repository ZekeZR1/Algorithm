#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
 
int A[100000],n;
 
int main(){
  int sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
 
  int q, k;
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> k;
    if(*lower_bound(A, A + n, k) == k) sum++;
  }
 
  cout << sum << endl;
 
  return 0;
}
