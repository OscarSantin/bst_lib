// #include "bst_lib.h"
#include <iostream>
#include <string>
using namespace std;
struct node {
    int value;
    node *rchild;
    node *lchild;
    node(int k){
        value = k;
        rchild = nullptr;
        lchild = nullptr;
    }

};
node* rcs(node*R,int v){                         //INSERIMENTO RICORSIVO ok
    if(R==nullptr){
        return new node(v);
    }
    if(R->value==v){
        return R;
    }
    if(R->value>v){
        R->lchild=rcs(R->lchild,v);
    }
    else{
         R->rchild=rcs(R->rchild,v);
    }
    return R;
};
node* itr(node*current,int k){   
    node*root=current;    
    if(current == nullptr)return new node(k);            //INSERIMENTO ITERATTIVO ok
    while(current!=nullptr){
        if(current->value==k){
            break;
        }
        if(current->value>k){
            if(current->lchild==nullptr){
                current->lchild=new node(k);
                break;
            }
            current=current->lchild;
        }
        else{
            if(current->rchild==nullptr){
                current->rchild=new node(k);
                break;
            }
            current=current->rchild;
        }
    }
    return root;
};
node *findKey(node*current, int k){              //CERCARE KEY ok
    while(current!=nullptr){
        if(k>current->value){
            current=current->rchild;
        }
        else if(k<current->value){
            current=current->lchild;
        }
        else{
            return current;
        }
    }
    cout<<"key non presente"<<endl;
    return nullptr;
};
void deletenode(node*current, int k){         //ELIMINAZIONE DI NODI  ok
    node *parent;
    bool dxorsx;
    while(current!=nullptr){
        if(k>current->value){
            dxorsx=1;
            parent=current;
            current=current->rchild;
        }
        else if(k<current->value){
            dxorsx=0;
            parent=current;
            current=current->lchild;
        }
        else{
            break;
        }
    }
    if(current->lchild==nullptr && current->rchild==nullptr){
        if(dxorsx==1){
            parent->rchild=nullptr;
        }
        else{
            parent->lchild=nullptr;
        }
        delete current;
    }
    else if(current->lchild==nullptr){
        current->value=current->rchild->value;
        delete current->rchild;
        current->rchild=nullptr;
    }
    else if(current->rchild==nullptr){
        current->value=current->lchild->value;
        delete current->lchild;
        current->lchild=nullptr;
    }
    else{
       node* successorParent=current;
        node* successor=current->rchild;
        while (successor->lchild!=nullptr) {
            successorParent=successor;
            successor=successor->lchild;
        }
        current->value = successor->value;
        if (successorParent->lchild==successor) {
            successorParent->lchild=successor->rchild;
        } else {
            successorParent->rchild=successor->rchild;
        }
        delete successor;
}};
void preOrder(node* Node) {                          //VISITA NODO, SOTTOALBERO SINISTRO, SOTTOALBERO DESTRO ok
if (Node == nullptr) return;
cout << Node->value << " ";
preOrder(Node->lchild);
preOrder(Node->rchild);
}
void inOrder(node* Node) {                          //VISITA SOTTOALBERO SINISTRO, NODO, SOTTOALBERO DESTRO ok
if (Node == nullptr) return;
inOrder(Node->lchild);
cout << Node->value << " ";
inOrder(Node->rchild);
}
void postOrder(node* Node) {                        //VISITA SOTTOALBERO SINISTRO, SOTTOALBERO DESTRO, NODO ok
if (Node == nullptr) return;
postOrder(Node->lchild);
postOrder(Node->rchild);
cout << Node->value << " ";
}
int max(int n1,int n2){                            //MASSIMO TRA 2 NUMERI ok
    if(n1>n2){
        return n1;
    }
    else{
        return n2;
    };
}
int Hbst(node*Node) {                               //ALTEZZA MASSIMA ALBERO ok
  if (Node == nullptr) return 0;

  int l = Hbst(Node->lchild);
  int r = Hbst(Node->rchild);

  return max(l, r) + 1;
}
bool isBST(node* root){                           //VERIFICA BST 
    if(root==nullptr)return true;
    if(root->lchild==nullptr && root->rchild==nullptr){
        isBST(root->lchild);
        isBST(root->rchild);
    }
    else if(root->lchild==nullptr){
        if(root->value<root->rchild->value){
            isBST(root->rchild);
        }
    }
    else if(root->rchild==nullptr){
        if(root->value>root->lchild->value){
            isBST(root->rchild);
        }
    }
    else if(root->value>root->lchild->value  && root->value<root->rchild->value ){
        isBST(root->lchild);
        isBST(root->rchild);
    }
    else{
        return false;
    }
    return true;
}

