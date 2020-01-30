// Example program
#include <iostream>
#include <string>
using namespace std;

class P{
    private:
    int v;
    public:
    P(){
        v = 1;
        cout << v<<endl;
    }
    P(int a){
        v = a;
        cout << v<<endl;
    }
    ~P(){
        cout << "destroyed"<<v<<endl;
    }
};



int main()
{
 P a;
 P b(9);
 P c(88);
}

