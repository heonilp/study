#include <iostream>
using namespace std;
class TreeNode {
    int data;
    TreeNode *left, *right;
public:
    TreeNode(int data=1) {
        this->data = data; this->left = NULL; this->right = NULL;
    }
    ~TreeNode() { delete left; delete right; }
    int getData() { return data; }
    TreeNode* getLeft() { return left; }
    TreeNode* getRight() { return right; }
    void setLeft(TreeNode *left) { this->left = left; }
    void setRight(TreeNode *right) { this->right = right; }
};
class Tree {
    TreeNode *root;
public:
    Tree() {
        root = NULL;
    }
    ~Tree() { delete root; }
    TreeNode* getRoot() { return root; }
    void insert_node(int key);
    void postorder(TreeNode* root);
};
void Tree::insert_node(int key) {
    TreeNode *p, *t;
    TreeNode *z;
    p = NULL;
    t = this->root;
    while (t != NULL) {
        p = t;
        if (key < p->getData())
            t = p->getLeft();
        else
            t = p->getRight();          
    }
    z = new TreeNode(key);
    if (p == NULL) this->root = z;
    else if (key < p->getData())
        p->setLeft(z);
    else
        p->setRight(z);
}
void Tree::postorder(TreeNode* root) {
    if (root) {
        postorder(root->getLeft());
        postorder(root->getRight());
        cout << root->getData() << endl;
    }
}
int main() {
    int num;
    Tree *t = new Tree;
    while (scanf("%d", &num) != EOF) {
        t->insert_node(num);
    }
    t->postorder(t->getRoot());
    delete t;
}