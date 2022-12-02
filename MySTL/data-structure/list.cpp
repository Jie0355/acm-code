//Title: List(Sequential)
//Date: 2022-02-28 19:25
#include <bits/stdc++.h>
using namespace std;
#define bug() -1;

/* The defininition of Sequential List */
#define LIST_MAX_SIZE 100;
typedef int ElemType;
typedef struct Node {
    ElemType *elem;
    int length;
}SqList;

/* Operates of Sequential List */
int ListInit(SqList &L) {
    L.elem = (SqList *)malloc(LIST_MAX_SIZE * sizeof(SqList));
    if (L.elem == NULL) return bug();
    L.length = 0;
    return 0;
}
void ListDestory(SqList &L) {
    L.elem = NULL;
    L.length = 0;
}
void ListClear(SqList &L) {
    free(L.elem);
    L.length = 0;
}
/* Return true if the list is empty */
bool isListEmpty(SqList L) {
    if (L.elem == NULL) return true;
    return false;
}
ElemType GetElem(SqList L, int i) {
    if (i <= 0 || i >= L.length + 1) return bug();//Segfault
    return L.elem[i - 1];
}
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i ++) {
        if (L.elem[i] == e) return i + 1;
    }
    return bug();
}
int PriorElem(SqList L, int curE) {
    int idx = -1, i;
    for (i = 0; i < L.length; i ++)
        if (L.elem[i] == curE) idx = i;
    if (idx > 0) return idx;
    return bug();
}
int NextElem(SqList L, int curE, int &nextE) {
    int idx = -1, i;
    for (i = 0; i < L.length; i ++)
        if (L.elem[i] == curE) idx = i;
    if (idx != -1 && idx != L.length - 1) return idx + 2;
    return bug();
}
int InsertElem(SqList &L, int i, int e) {
    if (i <= 0 || i >= L.length + 1) return bug();
    for (int j = L.length; j >= i; j --) L.elem[j] = L.elem[j - 1];
    L.elem[i - 1] = e; L.length ++;
    return 0;
}
int DeleteElem(SqList &L, int i) {
    if (i <= 0 || i >= L.length + 1) return bug();
    for (int j = i - 1; j >= L.length - 2; j ++) L.elem[j] = L.elem[j + 1];
    L.length --;
    return 0;
}

//Main
int main() {
    //Operates...
    return 0;
}

//Title: List(Linked)
//Date: 2022-03-07 17:00
#include <bits/stdc++.h>
using namespace std;
#define bug() -1;

/* The defininition of Linked List */
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
}*LinkList;

/* Operates of Linked List */
int LinkListInit(LinkList &L) {
    L = (LinkList)malloc(sizeof(struct Node));
    if (L == NULL) return bug();
    L->next = NULL;
    return 0;
}
void LinkListDestory(LinkList &L) {
    LinkList tmpNode;
    while (L) {
        tmpNode = L->next;
        L = L->next;
        free(tmpNode);
    }
}
/* Reverse a Link List and return the head pointer */
LinkList LinkListReverse(LinkList &L) {
    LinkList prev, next;
    prev = NULL;
    while (L) {
        next = L->next;
        L->next = prev;
        prev = L;
        L = next;
    }
    return prev;
}
int InsertNode(LinkList &L, int i, ElemType e) {
    if (i < 0) return bug();
    LinkList tmpNode, addNode;
    tmpNode = L; addNode = (LinkList)malloc(sizeof(struct Node));
    for (int k = 1; k <= i - 1; k ++) {
        if (!tmpNode->next) return bug();
        tmpNode = tmpNode->next;
    }
    addNode->data = e;
    addNode->next = tmpNode->next;
    tmpNode->next = addNode;
    return 0;
}
int DeleteNode(LinkList &L, int i) {
    LinkList p = L, tmpNode;
    if (i < 0) return bug();
    for (int k = 1; k <= i - 1; k ++) {
        if (!p->next) return bug();
        p = p->next;
    }
    tmpNode = p->next;
    p->next = tmpNode->next;
    free(tmpNode);
    return 0;
}
/* Delete node when it meet the condition */
int isDeleteNode(LinkList &L, /*CONDITION*/) {
    LinkList p, ptr;
    //Note the head node
    while (L) {
        if (/*CONDITION*/) {
            p = L;
            L = L->next;
            free(p);
        }
        else break;
    }
    if (L == NULL) return bug();
    p = L; ptr = L->next;
    while (ptr) {
        if (/*CONDITION*/) {
            p->next = ptr->next;
            free(ptr);
        }
        else p = ptr;
        ptr = p->next;
    }
    return 0;
}
ElemType GetNode(LinkList L, int i) {
    if (i < 0) return bug();
    for (int k = 1; k <= i - 1) {
        if (L->next == NULL) return bug();
        L = L->next;
    }
    return L->data;
}
int LocateNode(LinkList L, ElemType e) {
    for (int k = 1; !L->next; L = L->next, k ++) {
        if (L->data == e) return k;
    }
    return bug();
}

//Main
int main() {
    //Operates...
    return 0;
}