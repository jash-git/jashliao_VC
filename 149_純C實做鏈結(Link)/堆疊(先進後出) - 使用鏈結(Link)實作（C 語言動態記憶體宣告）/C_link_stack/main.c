//堆疊(先進後出) - 使用鏈結(Link)實作（C 語言動態記憶體宣告）
//http://openhome.cc/Gossip/AlgorithmGossip/StackByLink.htm
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node* creates(void);         // 建立堆疊
int isEmpty(Node*);           // 堆疊已空
int stacktop(Node*);   // 傳回頂端元素
Node* add(Node*, int);   // 新增元素
Node* delete(Node*);     // 刪除元素
void list(Node*);      // 顯示所有內容

int main(void) {
    Node* sTop;
    int input, select;

    sTop = creates();

    while(1) {
        printf("\n\n請輸入選項(-1結束)：");
        printf("\n(1)插入值至堆疊");
        printf("\n(2)顯示堆疊頂端");
        printf("\n(3)刪除頂端值");
        printf("\n(4)顯示所有內容");
        printf("\n\$c>");
        scanf("%d", &select);

        if(select == -1)
            break;

        switch(select) {
            case 1:
                printf("\n輸入值：");
                scanf("%d", &input);
                sTop = add(sTop, input);
                break;
            case 2:
                printf("\n頂端值：%d", stacktop(sTop));
                break;
            case 3:
                sTop = delete(sTop);
                break;
            case 4:
                list(sTop);
                break;
            default:
                printf("\n選項錯誤！");
        }
    }

    printf("\n");

    return 0;
}

Node* creates() {
    return NULL;
}

int isEmpty(Node* top) {
    return (top == NULL);
}

int stacktop(Node* top) {
    return top->data;
}

Node* add(Node* top, int item) {
    Node* newnode;

    newnode = (Node*) malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("\n記憶體配置失敗！");
        exit(1);
    }

    newnode->data = item;
    newnode->next = top;
    top = newnode;

    return top;
}

Node* delete(Node* top) {
    Node* tmpnode;

    tmpnode = top;
    if(tmpnode == NULL) {
        printf("\n堆疊已空！");
        return NULL;
    }

    top = top->next;
    free(tmpnode);

    return top;
}

void list(Node* top) {
    Node* tmpnode;
    tmpnode = top;

    printf("\n堆疊內容：");
    while(tmpnode != NULL) {
        printf("%d ", tmpnode->data);
        tmpnode = tmpnode->next;
    }
}
