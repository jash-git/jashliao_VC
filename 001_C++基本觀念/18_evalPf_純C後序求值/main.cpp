#include <cstdlib>
#include <cstdio> 
#include <iostream>
void evalPf(char*); 
double cal(double, char, double); 
using namespace std;

int main(int argc, char *argv[])
{
    char input[80]; 
    printf("¿é¤J«á§Ç¦¡¡G"); 
    scanf("%s", input); 
    evalPf(input); 

    system("PAUSE");
    return EXIT_SUCCESS;
}
void evalPf(char* postfix) { 
    double stack[80] = {0.0}; 
    char temp[2]; 
    char token; 
    int top = 0, i = 0; 

    temp[1] = '\0'; 

    while(1) { 
        token = postfix[i]; 
        switch(token) { 
            case '\0': 
                printf("ans = %f\n", stack[top]); 
                return; 
            case '+': case '-': case '*': case '/': 
                stack[top-1] = 
                       cal(stack[top-1], token, stack[top]); 
                top--; 
                break; 
            default: 
                if(top < sizeof(stack) / sizeof(float)) { 
                    temp[0] = postfix[i]; 
                    top++; 
                    stack[top] = atof(temp); 
                } 
                break; 
        } 
        i++; 
    } 
}
double cal(double p1, char op, double p2) { 
    switch(op) { 
        case '+': 
            return p1 + p2; 
        case '-': 
            return p1 - p2; 
        case '*': 
            return p1 * p2; 
        case '/': 
            return p1 / p2; 
    } 
}

