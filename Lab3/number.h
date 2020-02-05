
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

<<<<<<< HEAD
    void display ();
};

inline void operator+ (Number &obj1, Number &obj2) {
=======
    void display();
    int showPolarR(int i, int r);
    double showPolarAngle(int i, int r);
};

void operator+ (Number& obj1, Number& obj2) {
>>>>>>> c72e60d252c3f94648c39db65723fdce6e9a8466
    obj1.setReal(obj1.getReal() + obj2.getReal());
    obj1.setImg(obj1.getImg() + obj2.getImg());
}

<<<<<<< HEAD
inline void operator- (Number &obj1, Number &obj2) {
=======
void operator- (Number& obj1, Number& obj2) {
>>>>>>> c72e60d252c3f94648c39db65723fdce6e9a8466
    obj1.setReal(obj1.getReal() - obj2.getReal());
    obj1.setImg(obj1.getImg() - obj2.getImg());
}

<<<<<<< HEAD
inline void operator* (Number &obj1, int x) {
=======
void operator* (Number& obj1, int x) {
>>>>>>> c72e60d252c3f94648c39db65723fdce6e9a8466
    obj1.setReal(obj1.getReal() * x);
    obj1.setImg(obj1.getImg() * x);
}

<<<<<<< HEAD
inline void operator/ (Number &obj1, int x) {
=======
void operator/ (Number& obj1, int x) {
>>>>>>> c72e60d252c3f94648c39db65723fdce6e9a8466
    obj1.setReal(obj1.getReal() / x);
    obj1.setImg(obj1.getImg() / x);
}

<<<<<<< HEAD
inline bool operator== (Number &obj1, Number &obj2){
    if((obj1.getReal() == obj2.getReal()) && (obj1.getImg() == obj2.getImg())){
=======
bool operator== (Number& obj1, Number& obj2) {
    if ((obj1.getReal() == obj2.getReal()) && (obj1.getImg() == obj2.getImg())) {
>>>>>>> c72e60d252c3f94648c39db65723fdce6e9a8466
        return true;
    }
    else {
        return false;
    }
}

