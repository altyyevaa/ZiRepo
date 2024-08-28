#include <CTurtle.hpp>
namespace ct = cturtle;

int main(){
    ct::TurtleScreen screen;
    screen.tracer(1, 1000);
    ct::Turtle turtle(screen);

    ct::Polygon upside_down_triangle = {
      {0, 0},   //First point
      {-5, -5}, //Second point
      {5, -5}  //and so on.
    };

    turtle.shape(upside_down_triangle);

    //Draw a square where each edge is 50 units long.
    for(int i = 0; i < 4; i++){
        //Stamp at the corner of the square.
        int corner_stamp = turtle.stamp();

        turtle.forward(25);
        turtle.stamp(); //Stamp half-way across the edge of the square.
        turtle.forward(25);

        turtle.right(90);
        //Clear the corner stamp.
        turtle.clearstamp(corner_stamp);
    }

    turtle.clearstamps();

    screen.bye();
    return 0;
}
