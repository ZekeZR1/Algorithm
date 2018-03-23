#include <iostream>
using namespace std;
 
int A[30],n;
 
int slove(int i,int m){
  if(m == 0) return true;
  if( i >= n) return false;
  int res = slove(i + 1, m) || slove(i + 1, m - A[i]);
  return res;
}
 
int main(){
  int q,i,M;
  cin >> n;
  for(i = 0; i < n; i++) cin >> A[i];
  cin >> q;
  for(i = 0; i < q; i++){
    cin >> M;
    if(slove(0,M)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
 
  return 0;
}
