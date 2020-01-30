#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAX 64

class cusData{
private:
    char name[MAX];    
    int bill;
public:
    cusData(char * nm, int bl) {
        strcpy(name,nm);
        bill = bl;
    }
    cusData() {
        strcpy(name, "empty");
        bill = 0;
    }
    void display(){
        cout << "Customer name: " << name <<endl;
        cout << "Customer's bill amount: " << bill <<endl;
    }
    int get_bill(){
         return bill;
    }
    char* get_name(){
        return name;
    }
    void set_name(char * n){
        strcpy(name,n);
    }
    ~cusData(){
        cout << "Object Destroyed" <<endl;
    }
};

int main()
{
    cusData a;
    a.display();
    cusData b("Raj", 100);
    b.display();
}

