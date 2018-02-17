#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void topViewL(node* root) {
    if(!root)
        return;
    topViewL(root -> left);
    cout << (*root).data << " ";
}

void topViewR(node *root) {
    if(!root)
        return;
    cout << (*root).data << " ";
    topViewR(root -> right);
}

void topView(node * root) {
    topViewL(root -> left);
    cout << (*root).data << " ";
    topViewR(root -> right);
}