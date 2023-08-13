#include <iostream>
using namespace std;

// #define SIZE 5
// void printUs(int arr[], int n){
//     int i;
//     for (i = 0; i < n; i++)
//         cout << "arr[" << i << "]: " << arr[i] << "\n";
// }

int main(){
    // int arr[SIZE] = {3,5,1,7,2};

    // printUs(arr,SIZE);
    // return 0;
    int a, sum = 0;
    for (a = 0; a <= 10; a++) {
    if ( a % 2 == 1 )
      {continue;}

   sum += a;
   cout << sum << endl;
}
}
