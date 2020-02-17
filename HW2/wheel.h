#include <iostream>
#include <string>

using namespace st;

class Wheel{
public:

    Wheel();
    
    int setStartVal(int start);
    int setEndVal(int end);
    
    void spin();
    
private:
    int startVal;
    int endVal;
    
};