class Number
{
private:
    int img;
    int rel;
 
public:

    Number ();
    
    Number (int i, int r);

    Number (int r, float theta);
    
    int getReal () {
        return rel;
    }

    int getImg () {
        return img;
    }

    virtual void display () = 0;
};
