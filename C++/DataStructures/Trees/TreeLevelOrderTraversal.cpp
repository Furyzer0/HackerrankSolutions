#include <vector>
#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void levelOrder(vector<node*> nodes) {
    if(nodes.size() <= 0)
        return;

    vector<node*> next;
    
    for(node* n : nodes) {
        cout << (*n).data << " ";
        if(n -> left != nullptr)
            next.push_back(n -> left);
        if(n -> right != nullptr)
            next.push_back(n -> right);
    }
    
    levelOrder(next);
}

void levelOrder(node * root) {
    vector<node*> nodes;
    nodes.push_back(root);
    levelOrder(nodes);
}