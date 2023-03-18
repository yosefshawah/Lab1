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
followed by a new opt. Otherwise, cprt prints the dot ('.') character. After printing, 
cprt returns the value of c unchanged. */

char encrypt(char c);
/* Gets a char c and returns its encrypted form by adding 1 to its value.
 If c is not between 0x20 and 0x7E it is returned unchanged */

char decrypt(char c);
/* Gets a char c and returns its decrypted form by reducing 1 from its value.
 If c is not between 0x20 and 0x7E it is returned unchanged */

char xprt(char c);
/* xprt prints the value of c (if between 0x20 and 0x7E, otherwise it prints the dot ('.') character)
 in a hexadecimal representation followed by a new opt, and returns c unchanged. */



typedef struct{
char *name;
char (*fun)(char);
} fun_desc;


 

int main(int argc, char** argv){
    char opt[1];// option for functions
    //char* carray = {'\0'};  // initialize to the empty string
    char* carray = (char*)(malloc)(6);
    fun_desc menu[] = {{"Get string", my_get},{"Print string", cprt}, {"Encrypt", encrypt}, {"Decrypt", decrypt}, {"Print Hex", xprt}, {"NULL", NULL}};
    int menu_length = sizeof(menu) / sizeof(fun_desc);


    printf("Select operation from the following menu:\n");
   
    for(int i = 0; i < menu_length - 1; i++){
            printf("%d. %s\n", i, menu[i].name);
    }
    
    while(fgets(opt, 50, stdin)){
        
    int num = atoi(opt);
    
    if(num >= 0 && num <= 4){
        printf("Option : %d\n\n", num);
        printf("Within bounds\n");
    }

    else{
        printf("Not within bounds\n");
        printf("num value is %d\n", num);
        exit(0);
    }

    carray = map(carray, 5, menu[num].fun);

    printf("Select operation from the following menu:\n");
        
    for(int i = 0; i < menu_length - 1; i++){
            printf("%d. %s\n", i, menu[i].name);
    }   

    }

    free(carray);
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


