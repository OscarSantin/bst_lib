#include "bst_lib_santin.h"
#include <iostream>
#include <string>
using namespace std;

node::node(int k) {
    data = k;
    rchild = nullptr;
    lchild = nullptr;
    weight = 0;
}

int node::getData() {
    return data;
}
void node::setData(int key) {
    data = key;
}
node* node::getRchild() {
    return rchild;
}
void node::setRchild(node* setter) {
    rchild = setter;
    return;
}
node* node::getLchild() {
    return lchild;
}
void node::setLchild(node* setter) {
    lchild = setter;
    return;
}
int node::getWeight() {
    return weight;
}
void node::setWeight(int n) {
    weight = n;
}
node* node::insertR(int k) {
    if (this == nullptr) {
        return new node(k);
    }
    if (this->data == k) {
        return this;
    }
    if (this->data > k) {
        this->lchild = this->lchild->insertR(k);
    }
    else {
        this->rchild = this->rchild->insertR(k);
    }
    return this;
}
void node::inOrder() {
    if (this == nullptr) return;
    this->lchild->inOrder();
    cout << this->data << " ";
    this->rchild->inOrder();
}
node* node::insertI(int k) {
    node* current = this;
    while (current != nullptr) {
        if (current->data == k) {
            break;
        }
        if (current->data > k) {
            if (current->lchild == nullptr) {
                current->lchild = new node(k);
                break;
            }
            current = current->lchild;
        }
        else {
            if (current->rchild == nullptr) {
                current->rchild = new node(k);
                break;
            }
            current = current->rchild;
        }
    }
    return this;
};
bool node::searchI(int k) {
    node* current{ this };
    while (current->data != k) {
        if (k > current->data) {
            current->rchild = current->rchild;
        }
        else {
            current = current->lchild;
        }
        if (current == nullptr) {
            cout << "key non presente" << endl;
            return false;
        }
    }
    return true;
};
bool node::searchR(int k) {
    //node* current{ this };
    if (this == nullptr)return false;
    if (this->data == k)return true;
    if (k > this->data) {
        return this->rchild->searchR(k);
    }
    else {
        return this->lchild->searchR(k);
    }
}