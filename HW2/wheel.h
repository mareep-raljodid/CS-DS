#include <iostream>

using namespace std;

class Wheel{
public:

    Wheel();
    
    void setStartVal(int start);
    void setEndVal(int end);
    
    int spin();
    
private:
    int startVal;
    int endVal;
    
};