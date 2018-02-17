#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void postOrder(node *root) {
    if(root == nullptr)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << (*root).data << " ";
}