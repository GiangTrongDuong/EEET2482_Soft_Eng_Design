#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book{
    private:
    string name;
    int price;

    public:
    Book(string name, int price){
        this->name = name;
        this->price = price;
    }

    void detail(){
        cout << "Book name: " << this->name << endl << "Price: "
        << this->price << endl << endl;

    }

    int getprice(){
        return this->price;
    }
};

int main(){

    // Book* ptr = new Book[3]{Book("BigBook",500),
    // Book("codeTreSoSinh",5000),Book("SachVan",7000)};

    

    //if(ptr == nullptr){
        // cerr << "Memory allocation failed.\n";
    // } else{
        // for(int i = 0; i < 3; i++){
         //     ptr[i].detail();
        // }
    // }

    // delete[] ptr;
    
    int num;

    cout << "Insert number to initialize array!";
    cin >> num;

    Book** ptr2 = new Book*[num];
    string arr[num];
    int arr2[num];
//Initialize book constructor
    for(int i = 0; i < num; i++){
        cout << "Insert name for book " << i + 1 << endl;
        cin.ignore();
        getline(cin,arr[i]);
        cout << "Insert price for book " << arr[i] << endl;
        cin >> arr2[i];

        ptr2[i] = new Book(arr[i], arr2[i]); 
    }

//find the highest price
    int maxprice = 0;
    for(int i = 0; i < num; i++){
        if(maxprice < ptr2[i]->getprice()){
            maxprice = ptr2[i]->getprice();
        }
    }
//return the highest price book
    for(int i = 0; i < num; i++){
        if(ptr2[i]->getprice() == maxprice){
            ptr2[i]->detail();
        }
    }

    delete[] ptr2;
}