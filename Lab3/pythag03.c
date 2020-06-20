#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  int z = sqrt(pow(x,2)+pow(y,2));
  printf("Right angle triangle with right angled sides of length 3 and 4 has a hypotenuse of %d \n", z);
  return 0;
  }
  
