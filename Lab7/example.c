
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

        int count = 10;
        double *numbers;

        double *num = malloc(count * 1);
        // How to check if malloc fails????

        int i;
        // printf("Here\n");
        for (i = 0; i < count; i++){
                printf(" %d ----> %f\n", i, num[i]);
        }
        // printf("End\n");

        double x = 1.5;
        for (i = 0; i < count; i++){
                num[i] = x;
                x += 1;
        }

        for (i = 0; i < count; i++){
                printf(" %d ----> %f\n", i, num[i]);
        }


}
