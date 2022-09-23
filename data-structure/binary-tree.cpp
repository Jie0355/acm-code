//Title: Binary Tree(Linked)
//Date: 2022-3-28 18:40
#include <bits/stdc++.h>
using namespace std;
#define bug() -1;

/* The defininition of Linked Binary Tree */
typedef char ElemType;
typedef struct Node {
    ElemType Data;
    struct Node *NextChild;
    struct Node *NextSibling; 
}Tree, *BiTree;

/* Operates of Linked Binary Tree */
void CreateTree(BiTree &T) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        T = NULL;
        return;
    }
    T = (BiTree)malloc(sizeof(Tree));
    T->Data = ch;
    CreateTree(T->NextChild);
    CreateTree(T->NextSibling);
}
void PreOrder(BiTree T) {
    if (T == NULL) return;
    printf("%c", T->Data);
    PreOrder(T->NextChild);
    PreOrder(T->NextSibling);
}
void InOrder(BiTree T) {
    if (T == NULL) return;
    InOrder(T->NextChild);
    printf("%c", T->Data);
    InOrder(T->NextSibling);
}
void PostOrder(BiTree T) {
    if (T == NULL) return;
    PostOrder(T->NextChild);
    PostOrder(T->NextSibling);
    printf("%c", T->Data);
}

//Main...
int main() {
    //Operates...
    return 0;
}