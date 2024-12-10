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

//node::node() {};

int node::getData() const{
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
int node::getWeight() const{
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
            current = current->rchild;
        }
        else {
            current = current->lchild;
        }
        if (current == nullptr) {
            //cout << endl << "key non presente";
            return false;
        }
    }
    return true;
};

bool node::searchR(int k) {
    //node* current{ this };
    if (this == nullptr) { 
        //cout << endl << "key non presente";
        return false;
    }
    if (this->data == k)return true;
    if (k > this->data) {
        return this->rchild->searchR(k);
    }
    else {
        return this->lchild->searchR(k);
    }
}

void node::preOrder() {
    if (this == nullptr) return;
    cout << this->data << " ";
    this->lchild->inOrder();
    this->rchild->inOrder();
};

void node::postOrder() {
    if (this == nullptr) return;
    this->lchild->inOrder();
    this->rchild->inOrder();
    cout << this->data << " ";
};

node* node::deleteNode(int k) {
    node* current{ this };
    node* parent=current;
    while (current->data != k) {
        parent = current;
        if (k > current->data) {
            current = current->rchild;
        }
        else {
            current = current->lchild;
        }
        if (current == nullptr) {
            cout << endl << "key non presente" << endl;
            return this;
        }
    }
    if (current->lchild == nullptr && current->rchild == nullptr) {
        if (current == this) { 
            delete current;
            return nullptr;
        }
        if (parent->lchild == current) {
            parent->lchild = nullptr;
        }
        else {
            parent->rchild = nullptr;
        }
        delete current;
        return this;
    }
    if (current->lchild == nullptr) { 
        if (current == this) {
            node* help = current->rchild;
            delete current;
            return help;
        }
        if (parent->lchild == current) {
            parent->lchild = current->rchild;
        }
        else {
            parent->rchild = current->rchild;
        }    
        delete current;
        return this;
    }
    else if (current->rchild == nullptr) { 
        if (current == this) { 
            node* help = current->lchild;
            delete current;
            return help;
        }
        if (parent->lchild == current) {
            parent->lchild = current->lchild;
        }  
        else {
            parent->rchild = current->lchild;
        }
        delete current;
        return this;
    }
    node* help = current;//2 figli
    current = this->rchild;
    while (current->lchild != nullptr) {
        parent = current;
        current = current->lchild;
    }
    help->data = current->data;
    if (parent->lchild == current) {
        parent->lchild = current->rchild;
    }
    else {
        parent->rchild = current->rchild;
    }
    delete current;
    return this;
};

bool node::isBst(int minVal, int maxVal) {        
        if (this == nullptr) return true;

        if (this->data <= minVal || this->data >= maxVal) {
            return false;
        }
        if (this->rchild == nullptr) {
            return this->lchild->isBst(minVal, this->data) && true;
        }
        else if (this->lchild == nullptr) {
            return this->rchild->isBst(this->data, maxVal) && true;
        }
        else if (this->rchild == nullptr && this->lchild == nullptr) {
            return true;
        }
        return this->lchild->isBst( minVal, this->data) &&
            this->rchild->isBst( this->data, maxVal);
    }

ostream& operator<<(ostream& os, const node& n) {
    os << endl << "Data:" << n.data << endl;
    if (n.lchild == nullptr) {
        os << "DataLchild: The pointer is nullptr" << endl;
    }
    else {
        os << "DataLchild:" << n.lchild->data << endl;
    }
    if (n.rchild == nullptr) {
        os << "DataRchild: The pointer is nullptr" << endl;
    }
    else {
        os << "DataRchild:" << n.rchild->data << endl;
    }
    return os;
}

istream& operator>>(istream& is, node& n) {
    int d;
    is >> d;
    n.data = d;
    n.lchild = nullptr;
    n.rchild = nullptr;
    return is;
}