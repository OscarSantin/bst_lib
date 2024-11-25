#include "bst_lib_santin.h"
#include <iostream>
#include <string>
using namespace std;




int main(){
    srand(time(NULL));
    node R(0);
    node*root=&R;
    for(int c=0;c<15;c++){
        root->insertR(rand()%12);
    }
    root->inOrder();
    return 0;
}
/*node::node(int k=0){
    data = k;
    rchild = nullptr;
    lchild = nullptr;
    weight = 0;
}
int node::getData(){
    return data;
}
void node::setData(int key){
    data=key;
}
node* node::getRchild(){
    return rchild;
}
void node::setRchild(node* setter){
    rchild=setter;
    return;
}
node* node::getLchild(){
    return lchild;
}
void node::setLchild(node* setter){
    lchild=setter;
    return;
} 
int node::getWeight(){
    return weight;
}
void node::setWeight(int n){
    weight=n;
}
node* node::insertR(int k){ 
    if(this==nullptr){
        return new node(k);
    }
    if(this->data==k){ 
        return this;
    }
    if(this->data>k){
        this->lchild=this->lchild->insertR(k);
    }
    else{
         this->rchild=this->rchild->insertR(k);
    }
    return this;
};                        
void node::inOrder() {                       
if (this == nullptr) return;
this->lchild->inOrder();
cout << this->data<< " ";
this->rchild->inOrder();
}*/