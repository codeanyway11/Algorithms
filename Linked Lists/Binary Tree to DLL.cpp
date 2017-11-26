/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Structure for tree and linked list
struct Node
{
    int data;
    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; */
// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list

Node* binTreetoDLLUtil(struct Node* root){
    if(root->left){
        Node* left= binTreetoDLLUtil(root->left);
       while(left->right){
           left= left->right;
       }
       left->right= root;
       root->left = left;
    }

    if(root->right){
        Node* right = binTreetoDLLUtil(root->right);
        while(right->left){
            right= right->left;
        }
        right->left = root;
        root->right = right;
    }
    return root;
}

void BToDLL(Node *root, Node **head_ref)
{
    if(!root){
        return;
    }

    Node* rootOfDLL= binTreetoDLLUtil(root);

    while(rootOfDLL->left){
        rootOfDLL= rootOfDLL->left;
    }
    *head_ref= rootOfDLL;
}
