#include <iostream>
#include <iomanip>
#include <math.h>

#include "number.h"
using namespace std;

Number& operator +(const Number& obj1, const Number& obj2)
{
	obj2.rel += obj1.rel;
    obj2.img += obj1.img;
	return obj2;
}
