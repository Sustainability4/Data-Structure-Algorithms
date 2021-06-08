#include <iostream>
using namespace std;
template <typename T>
// We have both X and Y of the same type T, what if we want both of them of 
// different type 
class Pair{
    T x; 
    T y;

    public:

    void setX(T x){
        this -> x = x; 
    }

    T getX(){
        return x;
    }

    void setY(T y){
        this->y = y;
    }

    T getY(){
        return y;
    }
};
// Different Type 
template <typename T, typename V>
class Pair{
    T x; 
    V y;

    public:

    void setX(T x){
        this -> x = x; 
    }

    T getX(){
        return x;
    }

    void setY(V y){
        this->y = y;
    }

    V getY(){
        return y;
    }
};
int main() {
    Pair<int> p1;
    Pair<char>c1;

    // for two templates 

    Pair<int,double> p3; 

    // Triplet

    Pair<Pair<int,int>, char> p4;
    Pair<int,int> p5;
    p5.setX(15);
    p5.setY(16);
    p4.setY('a');
    p4.setX(p5);

    p4.getX().getX();
    py.getX().getY();
}
