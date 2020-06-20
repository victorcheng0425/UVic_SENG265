#include <stdio.h>

/*
 * Design a function rotate(.....) with as many parameters as needed
 * When called from the main, the function will modify the values of a b c and d in the way explained in the following example.
 * STARTING VALUE: a: 10, b: 20, c: 30, d: 40
 * AFTER CALLING ROTATE: a: 20, b: 30, c: 40, d: 10
 */

int main(){
    int a = 111;
    int b = 222;
    int c = 333;
    int d = 444;

    printf("a is %d\nb is %d\nc is %d\nd is %d\n", a, b, c, d);


    // Call the function rotate()
    printf("a is %d\nb is %d\nc is %d\nd is %d\n", a, b, c, d);
    /* The outcome of this print statement should be printed to the console as below
        a is 222
        b is 333
        c is 444
        d is 111
    */

    // Call the function rotate again.
    printf("a is %d\nb is %d\nc is %d\nd is %d\n", a, b, c, d);
    // What is the outcome of this print statement?

}
