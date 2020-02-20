#ifndef W
#define W

#include <iostream>

using namespace std;

class Wheel{
public:

    Wheel();
    
    void setStartVal(int start);
    void setEndVal(int end);
    
    int spin();
    
    int startVal;
    int endVal;
    
};

#endif
