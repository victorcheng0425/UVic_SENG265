# include <stdio.h>
# include <math.h>

/*
 * Design a function expo(.....) with 2 parameters
 * When called from the main, the function will modify a, so that the value of a is changed to a^b (a to the power b)
 */
void expo(int *a, int *b){
  *a = pow(*a, *b);
}
int main(){

        int a = 20;
        int b = 2;

        // Call function expo(.......)
	expo(&a, &b);
        printf("Value of a is %d and value of b is %d\n", a, b);
        /* The outcome of this print statement should be printed to the console ----
        "Value of a is 400 and value of b is 2"
        */
	return 0;
}
