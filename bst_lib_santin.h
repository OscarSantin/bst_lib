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
    node(int k=0){
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
    node* rcs(int v);
    void inOrder();
};
node* node::rcs(int v){ 
    if(this==nullptr){
        return new node(v);
    }
    if(this->data==v){ 
        return this;
    }
    if(this->data>v){
        this->lchild=this->lchild->rcs(v);
    }
    else{
         this->rchild=this->rchild->rcs(v);
    }
    return this;
};                        
    /*if(this==nullptr){
        return new node(v);
    }
    if(this->getData()==v){
        return R;
    }
    if(this->getData()>v){
        this=this->getLchild();
        this=rcs(v)
    }
    else{
         this=this->getRchild();
         this=rcs(v)
    }
    return this;};*/

/*node* itr(node*current,int k){   
    node*root=current;    
    if(current == nullptr)return new node(k);            
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
};*/
void node::inOrder() {                          //VISITA SOTTOALBERO SINISTRO, NODO, SOTTOALBERO DESTRO ok
if (this == nullptr) return;
this->lchild->inOrder();
cout << this->data<< " ";
this->rchild->inOrder();
}
