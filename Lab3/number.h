#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

class Number
{
private:
    double img;
    double rel;

public:

    Number();

    Number(double r, double i);

    Number(double r, float theta);

    double showPolarR(double r, double i);

    double showPolarAngle(double r, double i);

    double getReal() {
        return rel;
    }

    double getImg() {
        return img;
    }

    void setReal(double i) {
        rel = i;
    }

    void setImg(double u) {
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

