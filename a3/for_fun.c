
#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	for(int y = 1; y <= 99999999; y++){
	int *x = (int *)malloc(sizeof(int)*1);
	free(x);
	}
	return 0;
}