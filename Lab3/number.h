#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

class Number
{
private:
    int img;
    int rel;

public:

    Number();

    Number(int i, int r);

    Number(int r, float theta);

    int showPolarR(int i, int r);

    double showPolarAngle(int i, int r);

    int getReal() {
        return rel;
    }

    int getImg() {
        return img;
    }

    void setReal(int i) {
        rel = i;
    }

    void setImg(int u) {
        img = u;
    }

    void display ();
};

inline void operator+ (Number& obj1, Number& obj2) {
    obj1.setReal(obj1.getReal() + obj2.getReal());
    obj1.setImg(obj1.getImg() + obj2.getImg());
}

inline void operator- (Number &obj1, Number &obj2) {
    obj1.setReal(obj1.getReal() - obj2.getReal());
    obj1.setImg(obj1.getImg() - obj2.getImg());
}

inline void operator* (Number &obj1, int x) {
    obj1.setReal(obj1.getReal() * x);
    obj1.setImg(obj1.getImg() * x);
}

inline void operator/ (Number &obj1, int x) {
    obj1.setReal(obj1.getReal() / x);
    obj1.setImg(obj1.getImg() / x);
}

inline bool operator== (Number &obj1, Number &obj2){
    if((obj1.getReal() == obj2.getReal()) && (obj1.getImg() == obj2.getImg())) {
        return true;
    }
    else {
        return false;
    }
}

