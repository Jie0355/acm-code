//Title: Stack(Sequential)
//Date: 2022-03-14 21:30
#include <bits/stdc++.h>
using namespace std;
#define bug() -1;

/* The defininition of Sequential Stack */
#define STACK_MAX_SIZE 100;
#define STACK_SIZE_INCREMENT 50;
typedef int ElemType;
typedef struct Node {
    ElemType *base, *top;
    int stackSize;
}SqStack;

/* Operates of Sequential Stack */
int StackInit(SqStack &S) {
    S.base = (ElemType *)malloc(sizeof(STACK_MAX_SIZE * ElemType))
    if (!S.base) return bug();
    S.top = S.base;
    S.stackSize = STACK_MAX_SIZE;
    return 0;
}
void StackDestory(SqStack &S) {
    free(S.base);
    S.base = S.top = NULL;
    S.stackSize = 0;
}
/* Return true if the stack is empty */
bool isStackEmpty(SqStack S) {
    return !(S.top - S.base);
}
int StackLength(SqStack S) {
    int cnt = 0;
    ElemType *p;
    for (p = S.base; p < S.top; p++) cnt ++;
    return cnt;
}
int PushElem(SqStack &S, ElemType e) {
    if (StackLength(S) == STACK_MAX_SIZE) {
        ElemType *p;
        p = (ElemType *)realloc((STACK_SIZE_INCREMENT + STACK_MAX_SIZE) * sizeof(ElemType))
        if (p == NULL) return bug();
        S.base = p;
        S.top = S.base + S.stackSize;
        S.stackSize += STACK_SIZE_INCREMENT;
    }
    *(S.top ++) = e;
    return 0;
}
int PopElem(SqStack &S, ElemType &e) {
    if (!StackLength(S)) return bug();
    e = *(-- S.top);
    return 0;
}

//Main
int main() {
    //Operates...
    return 0;
}

//Title: Stack(Linked)
//Date: 2022-03-14 22:00
#include <bits/stdc++.h>
using namespace std;
#define bug() -1;

/* The defininition of Linked Stack */
#define MAX_STACK_SIZE 100;
#define STACK_SIZE_INCREMENT 50;
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
}*LinkStack;

/* Operates of Linked Stack */
int StackInit(LinkStack &S) {
    
}
int StackDestory(LinkStack &S) {
    
}
bool isStackEmpty(LinkStack S) {
    
}
int StackLength(LinkStack S) {
    
}
int PushElem(LinkStack &S, ElemType e) {
    
}
int PopElem(LinkStack &S, ElemType &e) {

}

//Main
int main() {
    //Operates...
    return 0;
}