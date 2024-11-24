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
