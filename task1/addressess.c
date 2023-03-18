#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int addr5;
int addr6;

int foo()
{
    return -1;
}
void point_at(void *p);
void foo1();
char g = 'g';
void foo2();

int main(int argc, char **argv)
{ 
    // int addr2;
    // int addr3;
    // char *yos = "ree";
    // int *addr4 = (int *)(malloc(50));
    
    // printf("Print addresses:\n");
    // printf("- &addr2: %p\n", &addr2);// it is on the stack on .data
    // printf("- &addr3: %p\n", &addr3);// same thing its on .data after 4 bits of addr2
    // printf("- foo: %p\n", &foo);// 
    // printf("- &addr5: %p\n", &addr5);// 

    // printf("- argc %p\n", &argc);// it is on the stack
    // printf("- argv %p\n", argv);// it is on the stack
    // printf("- &argv %p\n", &argv);// it is on the stack
    
    // printf("Print distances:\n");
    // point_at(&addr5);

    // printf("Print more addresses:\n");
    // printf("- &addr6: %p\n", &addr6);
    // printf("- yos: %p\n", yos);
    // printf("- gg: %p\n", &g);
    // printf("- addr4: %p\n", addr4);
    // printf("- &addr4: %p\n", &addr4);

    // printf("- &foo1: %p\n", &foo1);
    // printf("- &foo1: %p\n", &foo2);
    
    // printf("Print another distance:\n");
    // printf("- &foo2 - &foo1: %ld\n", (long) (&foo2 - &foo1));

   
    printf("Arrays Mem Layout (T1b):\n");
    int iarray[3];
    float farray[3];
    double darray[3];
    char carray[3]; 
    /* task 1 b here */
    /* iarray, iarray+1, farray, farray+1, darray, darray+1, carray and carray+1
    **************************************************************
    there is no differance between iarray or &iarray when you want to print the value of the address of the array, not the value!
    
    */
    printf("irray: %x\n", iarray);
    printf("farray: %x\n", farray);
    printf("darray: %x\n", darray);
    printf("carray: %x\n", carray);
    printf("irray + 1: %x\n", iarray + 1);
    printf("farray + 1: %x\n", farray + 1);
    printf("darray + 1: %x\n", darray + 1);
    printf("carray + 1: %x\n", carray + 1);



    
    printf("Pointers and arrays (T1d): \n");
    int iarray2[] = {1,2,3};
    char carray2[] = {'a','b','c'};
    int* iarray2Ptr = iarray2;
    char* carray2Ptr = carray2; 

    /* task 1 d here */
    //the pointer is pointing to the first element in the array.
    //the number that is added to the pointer is multiplyed by the size of type of the pointer and then added to it so that way 
    //we can access the rest of the elements of the array with ease.

    printf("iarray2[0]: %x\n", *(iarray2Ptr + 0));//for the sake of understanding
    printf("iarray2[1]: %x\n", *(iarray2Ptr + 1));
    printf("iarray2[2]: %x\n", *(iarray2Ptr + 2));

    printf("carray2[0]: %x\n", *(carray2Ptr + 0));//for the sake of understanding
    printf("iarray2[1]: %x\n", *(carray2Ptr + 1));
    printf("iarray2[2]: %x\n", *(carray2Ptr + 2));

    printf("Command line arg addresses (T1e):\n");
    /* task 1 e here */
    for(int i = 0; i < argc; i++){
        printf("address of argv[%d]: %x\n", i, (argv + i));
        printf("content of argv[%d]: %s\n", i, *(argv + i));

    }
    
    return 0;
}

void point_at(void *p)
{
    int local;
    static int addr0 = 2;
    static int addr1;

    long dist1 = (size_t)&addr6 - (size_t)p;
    long dist2 = (size_t)&local - (size_t)p;
    long dist3 = (size_t)&foo - (size_t)p;

    printf("- dist1: (size_t)&addr6 - (size_t)p: %ld\n", dist1);
    printf("- dist2: (size_t)&local - (size_t)p: %ld\n", dist2);
    printf("- dist3: (size_t)&foo - (size_t)p:  %ld\n", dist3);
    
    printf("Check long type mem size (T1a):\n");
    /* part of task 1 a here */

    printf("- addr0: %p\n", &addr0);
    printf("- addr1: %p\n", &addr1);
}

void foo1()
{
    printf("foo1\n");
}

void foo2()
{
    printf("foo2\n");
}








//task 1a
/*Read, compile and run the addresses.c (You can find the file in the course Moodle) program (remember to use the -m32 flag).
Can you tell the location (stack, code, etc.) of each memory address?
What can you say about the numerical values? Do they obey a particular order?

    they do, each object takes how many bytes that object hold in the program, for example int takes 4 bytes 


























notes for me: source: https://en.wikibooks.org/wiki/C_Programming/Pointers_and_arrays

Note that for addition and subtraction of integers and pointers,
 the value of the pointer is not adjusted by the integer amount, 
 but is adjusted by the amount multiplied by the size of the type to which the pointer refers in bytes. 
(For example, pointer + x can be thought of as pointer + (x * sizeof(*type)).) 

*you can add and subtract pointers, one useful example is to get the index of an element in an array by doing:
(p - arrayName), this will gives you the index, where p is a "iterator" which type is pointer, and arraName is the array



-review multidimensional arrays how they work.

-review Pointers to functions.









*/
