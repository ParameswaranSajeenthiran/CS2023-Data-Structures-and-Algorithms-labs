/* 
 * Compile this code and run.
 * On a Linux/Ubuntu system use the GNU C Compiler (gcc) as
 * >gcc memory_test.c
 * and execute the program as
 * >./a.out
 */

#include <stdio.h>
#include <stdlib.h>

void test1() {
 int i = 1; // allocated from initialized data segment
 int j; // allocated from uninitialized data segment
 int *ptr1; // allocated from heap segment
 ptr1 = malloc(sizeof(int)); // allocate memory
 printf("%i %i %i\n",i,j,*ptr1);
 i = 2;
 *ptr1 = 3;
 printf("%i %i %i\n",i,j,*ptr1);
 j = 4;
 free(ptr1); // deallocate memory
 printf("%i %i %i\n",i,j,*ptr1);
}

void func2(int *ptr1) { // pointer pass-by-value
 int *ptr2;
 printf("%i %i\n",*ptr1,*ptr2);
 ptr1 = malloc(sizeof(int)); // allocate memory
 ptr2 = malloc(sizeof(int)); // allocate memory
 printf("%i %i\n",*ptr1,*ptr2);
}

void test2() {
 int *ptr1; // allocated from heap segment
 printf("%i\n",*ptr1);
 func2(ptr1);
 printf("%i\n",*ptr1);
 free(ptr1); // deallocate memory
 printf("%i\n",*ptr1);
}

void func3(int **ptr1) { // pointer pass-by-reference
 int *ptr2;
 printf("%i %i\n",**ptr1,*ptr2);
 (*ptr1) = malloc(sizeof(int)); // allocate memory
 ptr2 = malloc(sizeof(int)); // allocate memory
 printf("%i %i\n",**ptr1,*ptr2);
}

void test3() {
 int *ptr1; // allocated from heap segment
 printf("%i\n",*ptr1);
 func3(&ptr1);
 printf("%i\n",*ptr1);
 free(ptr1); // deallocate memory
 printf("%i\n",*ptr1);
}

int main(int argc , char *argv[]) {
 printf("Test 1\n");
 test1();
 printf("Test 2\n");
 test2();
 printf("Test 3\n");
 test3();
}