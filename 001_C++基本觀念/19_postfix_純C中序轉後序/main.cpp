#include <cstdlib>
#include <iostream>
#include <cstdio> 
using namespace std;
int postfix(char*); // 中序轉後序 
int priority(char); // 決定運算子優先順序 
int main(int argc, char *argv[])
{
    char input[80];
    printf("輸入中序運算式：");
    scanf("%s", input);
    postfix(input); 
    system("PAUSE");
    return EXIT_SUCCESS;
}
int postfix(char* infix) { 
    int i = 0, top = 0; 
    char stack[80] = {'\0'}; 
    char op; 

    while(1) { 
        op = infix[i]; 

        switch(op) { 
            case '\0': 
                while(top > 0) { 
                    printf("%c", stack[top]); 
                    top--; 
                } 
                printf("\n"); 
                return 0; 
            // 運算子堆疊 
            case '(': 
                if(top < (sizeof(stack) / sizeof(char))) { 
                    top++; 
                    stack[top] = op; 
                } 
                break; 
            case '+': case '-': case '*': case '/': 
                while(priority(stack[top]) >= priority(op)) { 
                    printf("%c", stack[top]); 
                    top--; 
                } 
                // 存入堆疊 
                if(top < (sizeof(stack) / sizeof(char))) { 
                    top++; 
                    stack[top] = op; 
                } 
                break; 
            // 遇 ) 輸出至 ( 
            case ')': 
                while(stack[top] != '(') { 
                    printf("%c", stack[top]); 
                    top--; 
                } 
                top--;  // 不輸出( 
                break; 
            // 運算元直接輸出 
            default: 
                printf("%c", op); 
                break; 
        } 
        i++; 
    } 
} 

int priority(char op) { 
    int p; 

    switch(op) { 
       case '+': case '-': 
            p = 1; 
            break; 
        case '*': case '/': 
            p = 2; 
            break; 
        default: 
            p = 0; 
            break; 
    } 

    return p; 
}
