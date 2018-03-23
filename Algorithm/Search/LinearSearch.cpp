#include <iostream>
using namespace std;
  
int linearSearch(int S[], int n, int key){
  int i = 0;
  S[n] = key;
  while(S[i] != key){
    i++;
  }
  return i != n;
}
 
int main(){
  int n, q, i, ans = 0;
  int S[10001], key;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> S[i];
  }
  cin >> q;
  for(i = 0; i < q; i++){
    cin >> key;
    if(linearSearch(S, n, key)) ans++;
  }
 
  cout << ans << endl;
 
  return 0;
}
