#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string str;
    int i;
    
    cin >> str;
    cout << str.length()*2;
    string arr[str.length()*2];

    for(i = 0 ; i < str.size()*2; i++){
        arr[i] = str[i];
        i++;
        arr[i] = ' ';
    }
    int a;
    for (a = 0; a < arr->size(); a++){
        cout << arr[a];
    }

}