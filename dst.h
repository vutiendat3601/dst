struct TreeNode
{
    int value;
    ::TreeNode *left;
    ::TreeNode *right;
};

::TreeNode *loadBinaryTree();
void preOrderTraversal(::TreeNode *root);

void insertNode(::TreeNode **root, int value);
::TreeNode *searchNode(::TreeNode *root, int key);
void deleteNode(::TreeNode **root, int key);