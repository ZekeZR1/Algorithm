#include <iostream>
using namespace std;
 
int bubbleSort(int A[], int N){
  int i, j;
  bool flag = true;
  int sw = 0;
  for(i = 0; flag; i++){
    flag = false;
    for(j = N - 1; j >= i + 1; j--){
      if(A[j] < A[j - 1]){
        swap(A[j], A[j - 1]);
        flag = true;
        sw++;
      }
    }
  }
  return sw;
}
 
 
int main(){
   
  int N;
  cin >> N;
  int A[100];
  for(int i = 0; i < N; i++)
    cin >> A[i];
 
  int sw;
  sw = bubbleSort(A,N);
 
  for(int i = 0; i < N; i++){
    if(i) cout << ' ';
    cout << A[i];
   }
     
   cout << endl;
   cout << sw << endl;
 
  return 0; 
}
