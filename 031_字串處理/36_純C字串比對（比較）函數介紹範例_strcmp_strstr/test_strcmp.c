#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
                                                                                
int main(int argc, char* argv[]) {
    char passwd[] = "123456";
    char input[7];
	
    printf("½Ð¿é¤J±K½X¡G");
    gets(input);
	
    if(strcmp(passwd, input) == 0) {
        puts("±K½X¥¿½T");
    }
    else {
        puts("±K½X¿ù»~");
    }
	
    return 0; 
}