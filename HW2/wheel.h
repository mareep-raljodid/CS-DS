#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace st;

class Wheel{
public:

    Wheel();
    
    int setStartVal(int start);
    int setEndVal(int end);
    
    int spin();
    
private:
    int startVal;
    int endVal;
    
};