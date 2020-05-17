//佇列(Queue)(先進先出) - 使用鏈結實作（C語言動態記憶體宣告）

//http://openhome.cc/Gossip/AlgorithmGossip/QueueByLink.htm

#include <stdio.h>

#include <stdlib.h>



struct node {

    int data;

    struct node *next;

};



typedef struct node Node;



void createq();

void showfront();

void addq(int);

void delq();

void showqueue();



Node *front, *rear;



int main(void) {

    int input, select;



    createq();



    while(1) {

        printf("\n\n請輸入選項(-1結束)：");

        printf("\n(1)插入值至佇列");

        printf("\n(2)顯示佇列前端");

        printf("\n(3)刪除前端值");

        printf("\n(4)顯示所有內容");

        printf("\n\$c>");

        scanf("%d", &select);



        if(select == -1)

            break;



        switch(select) {

            case 1:

                printf("\n輸入值：");

                scanf("%d", &input);

                addq(input);

                break;

            case 2:

                showfront();

                break;

            case 3:

                delq();

                break;

            case 4:

                showqueue();

                break;

            default:

                printf("\n選項錯誤！");

        }

    }



    printf("\n");



    return 0;

}



void createq() {

    front = rear = (Node*) malloc(sizeof(Node));

    front->next = rear->next = NULL;

}



void showfront(){

    if(front->next == NULL)

        printf("\n佇列為空！");

    else

        printf("\n頂端值：%d", front->next->data);

}



void addq(int data) {

    Node *newnode;



    newnode = (Node*) malloc(sizeof(Node));



    if(front->next == NULL)

        front->next = newnode;



    newnode->data = data;

    newnode->next = NULL;

    rear->next = newnode;

    rear = newnode;

}



void delq() {

    Node* tmpnode;



    if(front->next == NULL) {

        printf("\n佇列已空！");

        return;

    }



    tmpnode = front->next;

    front->next = tmpnode->next;

    free(tmpnode);

}



void showqueue() {

    Node* tmpnode;



    tmpnode = front->next;



    printf("\n 佇列內容：");

    while(tmpnode != NULL) {

        printf("%d ", tmpnode->data);

        tmpnode = tmpnode->next;

    }

}
