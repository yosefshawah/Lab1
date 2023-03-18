#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length * sizeof(char)));
  /* TODO: Complete during task 2.a */

     if (mapped_array == NULL) {
        printf("array length is 0.\n");
        return NULL;
    }

    for(int i = 0; i < array_length; i++){
        mapped_array[i] = f(array[i]);
    }

  return mapped_array;
}

char my_get(char c);
/* Ignores c, reads and returns a character from stdin using fgetc. */

char cprt(char c);
/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c 
followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, 
cprt returns the value of c unchanged. */

char encrypt(char c);
/* Gets a char c and returns its encrypted form by adding 1 to its value.
 If c is not between 0x20 and 0x7E it is returned unchanged */

char decrypt(char c);
/* Gets a char c and returns its decrypted form by reducing 1 from its value.
 If c is not between 0x20 and 0x7E it is returned unchanged */

char xprt(char c);
/* xprt prints the value of c (if between 0x20 and 0x7E, otherwise it prints the dot ('.') character)
 in a hexadecimal representation followed by a new line, and returns c unchanged. */



int main(int argc, char **argv){
  /* TODO: Test your code */

   int base_len = 5;
char arr1[base_len];
char* arr2 = map(arr1, base_len, my_get);
char* arr3 = map(arr2, base_len, cprt);
char* arr4 = map(arr3, base_len, xprt);
char* arr5 = map(arr4, base_len, encrypt);
char* arr6 = map(arr5, base_len, decrypt);
free(arr2);
free(arr3);
free(arr4);
free(arr5);
free(arr6); 
    return 0;

}


char xprt(char c){

    if(c >= 0x20 && c <= 0x7E)
        printf("%x\n", c);
    
    else 
        printf(".\n");
    
    return c;
}

char my_get(char c){
    return (char)fgetc(stdin);
}

char cprt(char c) {

    if(c >= 0x20 && c <= 0x7E)
        printf("%c\n", c);

    else 
        printf(".\n");
    return c;
}

char encrypt(char c){

    if(c + 1 >= 0x20 && c + 1 <= 0x7E)
        return (char)( c + 1);
    
    return c;
}

char decrypt(char c){

    if(c - 1 >= 0x20 && c - 1 <= 0x7E)
        return (char)( c - 1);
    
    return c;
}


