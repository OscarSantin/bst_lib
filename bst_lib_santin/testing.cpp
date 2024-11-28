#include "bst_lib_santin.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main() {
    srand(time(NULL));
    node* root = new node(5);
    for (int c{ 0 }; c < 15; c++) {
        root->insertI(rand() % 12);
    }
    root->inOrder();
    cout << endl << root->searchI(4);
    cout << endl << root->searchR(4);
    return 0;
}