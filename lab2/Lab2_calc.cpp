//Lab2_calc.cpp
/***
 * {Displays results of dividing an integer with an integer as well
 * as the results of dividing an integer with a float}
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    //numerical
    int int_x = 1;
    int int_y = 2;
    double double_z = 2.0;

    cout << "int divided by int" << int_x / int_y << endl;
    cout << "int divided by double" << int_x / double_z << endl;

}
