#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void inOrder(node *root) {
    if(root == nullptr)
        return;
    inOrder(root -> left);
    cout << (*root).data << " ";
    inOrder(root -> right);
}