#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book{
    private:
    string* name;
    int price;

    public:
    Book(string name, int price){
        cout <<"Constructor!\n";
        this->name = new string(name);
        this->price = price;
    }

    ~Book(){
        cout << "Destructor!\n";
        delete name;
    }

    void detail(){
        cout << "Book name: " << *this->name << endl << "Price: "
        << this->price << endl << endl;

    }

    int getprice(){
        return this->price;
    }
};

int main(){    
    Book* ptr = new Book[3]{Book("BigBook",500),
    Book("codeTreSoSinh",5000),Book("SachVan",7000)};

    

    if(ptr == nullptr){
        cerr << "Memory allocation failed.\n";
    } else{
        for(int i = 0; i < 3; i++){
             ptr[i].detail();
        }
    }

    delete[] ptr;
}