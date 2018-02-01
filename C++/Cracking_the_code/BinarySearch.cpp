/*class Node{
    int data;
    Node* right;
    Node* left;
}*/
bool checkBST(Node* right, int min, int max){
    if(right -> data <= min || right -> data >= max) {
        return false;
    }
    bool isLeft = right -> left == NULL ? true : checkBST(right -> left, min, right -> data);
    bool isRight = right -> right == NULL ? true : checkBST(right -> right, right  -> data, max);
    return isLeft && isRight;
}

bool checkBST(Node* root){
    return checkBST(root -> left, 0, root -> data) && checkBST(root -> right, root -> data, INT32_MAX);
}