#include <iostream>
#include <cmath>  // For sqrt
#include <sstream>

using namespace std;

class Point {
private:
    float x, y;

public:
    // Constructor to initialize the point's coordinates
    Point(float in_x, float in_y) {
        x = in_x;
        y = in_y;
    }

    // Method to calculate the distance from the origin (0, 0)
    float distance_to_origin() {
        return sqrt(x * x + y * y);
    }

    //simple atan function
    float angle_from_point(){
        return atan2(y,x);
    }

    //simple sqrt function
    float distance(Point q){ 
        auto dx = x-q.x, dy = y-q.y; 
        return sqrt(dx*dx+dy*dy);
    }
    //Takes each of the respective points and divides it by two 
     Point halfway(Point q1){
        return Point((x+q1.x)/2, (y+q1.y)/2);
    };

    //operator takes the value and adds it by the q value inbound 
    Point operator+(Point q) {
        return Point( x+q.x,y+q.y );
    };
    //takes an argument q which multiplies to get the result. 
    Point operator*(float q){
        return Point(x*q, y*q);
    };
    //did this during class outputs it as a string 
    string as_string(){
    stringstream ss;
    ss <<"("<<x<<","<<y<<")";
    return ss.str();
  };

};

int main() {
    // Create a point object p1 at (1.0, 1.0, angle)
    Point p1(1, 2.2), q1(3.4, 5.6);
    

    // Takes the halfway and finds the distance
    cout << "The distance halfway: " << p1.halfway(q1).distance_to_origin() << '\n';
    //Uses the operator+ to add the points together
    cout << "Adding the points: " << (p1+q1).distance_to_origin() << '\n';
    //Uses the operator* to scale the points together
    cout << "Scaling points: " << (p1*4).distance_to_origin() << '\n';
    cout << p1.as_string() << '\n';

    return 0;
}
