//lab3_cf.cpp
/*
Lab 3 has us make use of a while loop
and if/else statement
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int x = 0;
  int y = 5;

  while(x < y) {
    printf("%i\n", x);
    x = x + 3;
  }

  if (x % 2 ==0) {
    printf("X is even\n");
  } else{
    printf("X is odd\n");
  }


}