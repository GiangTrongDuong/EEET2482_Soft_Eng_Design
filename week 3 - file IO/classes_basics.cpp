/*
    FIRST EXAMPLE FOR CLASSES AND OBJECTS
*/

#if 1

#include <iostream>
using std::cout;

class Dog {       // The class
public:             // Access specifier
    int age;        // AttributeS (int variable)
    bool hungry = true; //can assign default value
    bool happy;

    void eat() { //Method (function)
        hungry = false; happy = true;
    }

    void info() { //Method (function)
        std::cout   << "age = " << age
                    << ", hungry = "  << hungry
                    << ", happy = " << happy << "\n";
    }
};


int main() {
    Dog Dog1, Dog2;  //Create objects of Dog 

    //Access their variables and functions
    Dog1.age = 5;
    Dog1.eat(); 
    std::cout << "Dog 1's info: "; 
    Dog1.info();

    Dog2.age = 10;
    std::cout << "Dog 2's info: "; 
    Dog2.info();

    return 0;
}

#endif










/*
    CLASS METHOD DEFINED OUTSIDE
*/
#if 0

#include <iostream>
using std::cout;

class Car {
public:
    int speed = 100; //default value is 100
    int add_speed(int num); //declare method
};

int Car::add_speed(int num) { //define method with scope
    speed += num;   
    return speed;
}

int main() {
    Car my_car; // Create an object of Car
    cout << "my_car's default speed: " << my_car.speed << "\n";
    std::cout << "my_car's new speed: " << my_car.add_speed(200);
    return 0;
}


#endif











/*
    CONTRUCTOR METHODS
*/
#if 0

#include <iostream>
using std::cout;

class Car {    // The class
public:          // Access specifier
    int speed = 100;     // Attribute
    int price = 1000;
    
    Car () { //Default Constructor with no parameter
        cout << "Default constructor is called \n";
    } 

    Car (int speed_val, int price_val) { //Parameterized Constructor 
        cout << "Parameterized constructor is called \n";
        speed = speed_val;
        price = price_val;
    }
};

int main() {
    // Create Car objects (will call the constructors)
    Car car1;
    Car car2(500, 5000);

    // Print values
    cout << "Car1: speed & price: " << car1.speed << " " 
                                    << car1.price << "\n";
    cout << "Car2: speed & price: " << car2.speed << " " 
                                    << car2.price << "\n";
  return 0;
}

#endif




















/*
    DEFAULT CONSTRUCTOR WITH DEFAULT ARGUMENTS
*/
#if 0

#include <iostream>
using std::cout;

class Car {    // The class
public:          // Access specifier
    int speed;     // Attribute
    int price;
    
    //Default constructor with default arguments
    /* Note: we can also use default arguments for some or all parameters 
    of a parameterized contructor or any C++ function */
    Car(int speed_val = 100, int price_val = 1000) { 
        cout << "Default constructor is called \n";
        speed = speed_val;
        price = price_val;
    } 

    void showInfo(){
        cout << "speed & price: " << speed << " " << price << "\n";
    }
};

int main() {
    // Create Car objects (will call the constructors)
    Car car1;
    Car car2(500);
    Car car3(500, 5000);

    // Print values
    cout << "Car1: "; car1.showInfo();
    cout << "Car2: "; car2.showInfo();
    cout << "Car3: "; car3.showInfo();                                  
  return 0;
}

#endif








/*
    Constructors with member initializer list
*/
#if 0

#include <iostream>
using std::cout;

class Car {    // The class
public:          // Access specifier
    int speed;     // Attribute
    int price;
    
    //Constructors with member initializer list (works for any constructor)
    Car(int speed_val = 100, int price_val = 1000) 
        : speed(speed_val), price(price_val) { 
        cout << "Default constructor is called \n";
    } 

    void showInfo(){
        cout << "speed & price: " << speed << " " << price << "\n";
    }
};

int main() {
    // Create Car objects (will call the constructors)
    Car car1;
    Car car2(500);
    Car car3(500, 5000);

    // Print values
    cout << "Car1: "; car1.showInfo();
    cout << "Car2: "; car2.showInfo();
    cout << "Car3: "; car3.showInfo();                                  
  return 0;
}

#endif



    
    












/*
    DATA ENSCAPSULATION
*/

#if 0

#include <iostream>
using std::cin;
using std::cout;

#define DEFAULT_VAL 100
#define PASSWORD_KEY 12345

class myclass {
    private: 
        int num = DEFAULT_VAL;    // Public access specifier

    public:
        int get_num(){ return num; }; //read the num value

        void set_num(int new_val){  //write new value for num
            int pwd;
            cout << "Enter password: ";  cin >> pwd;
            if (pwd == PASSWORD_KEY) {
                num = new_val;
                cout << "Set new value successfully ! \n";
            } else {
                cout << "Incorrect password ! \n";
            }
        }
};




int main() {
    myclass object1;
    cout   << "Current num value: " 
          << object1.get_num() << "\n";

    object1.set_num(200);
    cout   << "New num value: " 
           << object1.get_num();

    return 0;
}

#endif














/*
    C++ STRING CLASS
*/

#if 0

// comparing size, length, capacity and max_size
#include <iostream>
#include <string>
using std::cout;
using std::cin;

int main (){

    std::string str ("Hello World"); //create a string object
    // cout << str <<"\n";

    //Assign and append string
    str = "ABC";
    str = str + " DE";
    cout << str <<"\n";

    //Get length and access each character
    cout << "length: " << str.length() << "\n";
    cout << "1st char: " << str[0] << "\n";

    //NULL ('\0') is not the teminator character in string objects
    str[2] = '\0';
    cout << str <<"\n";

    //Compare string
    cout << ((str == "ABC DE") ? "YES \n" : "NO \n") ;
    
    //Get substring  substr(position, length)
    cout << "sub str: " << str.substr(1, 4) << "\n"; 

    //Input a line
    cout << "Input a string: ";
    getline(cin, str); 
    //std::cin >> str; //only get a word
    cout << str << "\n";
    

    return 0;
}

#endif











/*
    STRINSTREAM CLASS
*/


#if 0

#include <iostream>
#include <sstream>

int main() {
    std::string str = "51.40 1234 Hello World"; // create string
    std::stringstream ss;        // create a stringstream object   


    //std::cout << str;       //output the content of str string to console
    ss << str;              //output the content of str string to the ss string

    //Extract data from the stringstream
    float myFloat; 
    int   myInt;
    char  myCharArray[20];

    //std::cin >> myFloat >> myInt >> myCharArray; //read from console
    ss >> myFloat >> myInt >> myCharArray;       //extract from stringstream

    std::cout << "myFloat = " <<  myFloat << "\n" 
     	 	  << "myInt   = " <<  myInt << "\n" 
     	 	  << "myCharArray = " <<  myCharArray << "\n";

    return 0;
}

#endif











/*
    ARRAY OF OBJECTS
*/
#if 0

#include <iostream>
using std::cin;
using std::cout;
using std::string;

class Car {       
    public: 
        string brand;         
        int speed, price;

        Car (string brand_info, int speed_val, int price_val) {
            brand =  brand_info; speed = speed_val; price = price_val;
        }
};


int main() {
    Car MyCars[3] = { Car("Audi", 500, 10000), 
                      Car("BMW", 400, 8000), 
                      Car("Ferrari", 800, 20000) };

    for (int i = 0; i < 3; i++) {
        cout << "Car" << i << "'s brand, speed & price: "
             << MyCars[i].brand << " " 
             << MyCars[i].speed << " "
             << MyCars[i].price << "\n";
    }

  return 0;
}


#endif












/*
    C++ STRUCT
*/
#if 0

#include <iostream>
using std::cout;

struct product {
  int weight;
  double price;
};

int main() {
    product pd1, pd2;
    pd1.weight = 100; pd1.price = 10.25;
    pd2.weight = 200; pd2.price = 20.7;

    cout << "Product 1's weight and price: " 
         << pd1.weight << " " << pd1.price << "\n";
    cout << "Product 2's weight and price: " 
         << pd2.weight << " " << pd2.price << "\n";
}

#endif







