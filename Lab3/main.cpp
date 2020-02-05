#include <iostream>
#include <iomanip>
#include <math.h>

#include "number.h"

using namespace std;

int main() {
    Number n1(13,7);
    Number n2(44, 56.55f);

    n1 + n2;
    n1.display();
}
