#ifndef _BST_LIB_SANTIN_H
#define _BST_LIB_SANTIN_H
#include <iostream>
#include <string>
using namespace std;

class node {
private:
    int data;
    node* rchild;
    node* lchild;
    int weight;
public:
    node(int k = 0);

    int getData();
    void setData(int key);
    node* getRchild();
    void setRchild(node* setter);
    node* getLchild();
    void setLchild(node* setter);
    int getWeight();
    void setWeight(int n);
    node* insertR(int k);
    void inOrder();
    bool searchI(int k);  // ricerca iterativa di k
    bool searchR(int k);  // ricerca ricorsiva di k
    node* insertI(int k);  // inserimento iterativa di k
};

#endif
