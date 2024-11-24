// #include "bst_lib.h"
#include <iostream>
#include <string>
using namespace std;
class node {
    private:
    int data;
    node *rchild;
    node *lchild;
    int weight;
    public:
    node(int k){
        data = k;
        rchild = nullptr;
        lchild = nullptr;
        weight = 0;
    }
    int getData(){
        return data;
    }
    void setData(int key){
        data=key;
    }
    node* getRchild(){
        return rchild;
    }
    void setRchild(node* setter){
        rchild=setter;
        return;
    }
    node* getLchild(){
        return lchild;
    }
    void setLchild(node* setter){
        lchild=setter;
        return;
    }
    int getWeight(){
        return weight;
    }
    void setWeight(int n){
        weight=n;
    }
};
node* itr(node*current,int k){   
    node*root=current;    
    if(current == nullptr)return new node(k);            //INSERIMENTO ITERATTIVO ok
    while(current!=nullptr){
        if(current->getData()==k){
            break;
        }
        if(current->getData()>k){
            if(current->getLchild()==nullptr){
                current->setLchild(new node(k));
                break;
            }
            current=current->getLchild();
        }
        else{
            if(current->getRchild()==nullptr){
                current->setRchild(new node(k));
                break;
            }
            current=current->getRchild();
        }
    }
    return root;
};
void inOrder(node* Node) {                          //VISITA SOTTOALBERO SINISTRO, NODO, SOTTOALBERO DESTRO ok
if (Node == nullptr) return;
inOrder(Node->getLchild());
cout << Node->getData() << " ";
inOrder(Node->getRchild());
}
/*node* rcs(node*R,int v){                         //INSERIMENTO RICORSIVO ok
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
    node *parent{nullptr};
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
            cout<<"nodo non trovato";
            return;
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
bool isBST(node* root){  
    bool f;                         //VERIFICA BST 
    if(root==nullptr)return true;
    if(root->lchild==nullptr && root->rchild==nullptr){
        f=isBST(root->lchild);
        f=isBST(root->rchild);
    }
    else if(root->lchild==nullptr){
        if(root->value<root->rchild->value){
            f=isBST(root->rchild);
        }
    }
    else if(root->rchild==nullptr){
        if(root->value>root->lchild->value){
            f=isBST(root->rchild);
        }
    }
    else if(root->value>root->lchild->value  && root->value<root->rchild->value ){
        f=isBST(root->lchild);
        f=isBST(root->rchild);
    }
    return f;
}*/
