// bst.cpp
#include "bst.h"

using namespace std;

int BST::sumOfTree = 0;

BST::BST() {
    root = nullptr;
}

BST::BST(int n) {
    root = new node(n);
}

BST::~BST() {
    burnTree(root);
}

BST::node *BST::insert(node *parent, int n) {
    if (parent == nullptr) {
        return new node(n);
    }
    if (parent->value > n) {
        parent->Lchild = insert(parent->Lchild, n);
    } else if (parent->value < n) {
        parent->Rchild = insert(parent->Rchild, n);
    } else {
        cout << "ERROR: Duplicate value." << endl;
        return nullptr;
    }
    return parent;
}

void BST::insert(int n) {
    node *tmp = insert(root, n);
    if (tmp == nullptr) {
        cout << "The element already exists in the tree!" << endl;
    } else {
        root = tmp;
    }
}

void BST::preOrder(node *nd) {
    if (nd == nullptr) return;
    cout << nd->value << " ";
    preOrder(nd->Lchild);
    preOrder(nd->Rchild);
}

void BST::inOrder(node *nd) {
    if (nd == nullptr) return;
    inOrder(nd->Lchild);
    cout << nd->value << " ";
    inOrder(nd->Rchild);
}

void BST::postOrder(node *nd) {
    if (nd == nullptr) return;
    postOrder(nd->Lchild);
    postOrder(nd->Rchild);
    cout << nd->value << " ";
}

void BST::printTree() {
    cout << "Preorder: " << endl;
    preOrder(root);
    cout << endl;
    cout << "Inorder: " << endl;
    inOrder(root);
    cout << endl;
    cout << "Postorder: " << endl;
    postOrder(root);
    cout << endl;
}

void BST::sumTree(node *nd) {
    if (nd->Lchild != nullptr) {
        sumTree(nd->Lchild);
    }
    if (nd->Rchild != nullptr) {
        sumTree(nd->Rchild);
    }
    if (nd->Lchild == nullptr && nd->Rchild == nullptr) {
        sumOfTree += nd->value;
    }
}

int BST::sumTree() {
    sumOfTree = 0;
    sumTree(root);
    return sumOfTree;
}

int BST::treeHeight(node *nd, int h) {
    if (nd == nullptr) {
        return h;
    }
    return std::max(treeHeight(nd->Lchild, h + 1), treeHeight(nd->Rchild, h + 1));
}

int BST::treeHeight() {
    return treeHeight(root, -1);
}

bool BST::searchIf(node *nd, int n) {
    if (nd == nullptr) return false;
    if (nd->value < n) {
        return searchIf(nd->Rchild, n);
    } else if (nd->value > n) {
        return searchIf(nd->Lchild, n);
    }
    return true;
}

void BST::closestCommonAncestor(node *nd, int n, int m) {
    if (nd->value < n && nd->value < m) {
        closestCommonAncestor(nd->Rchild, n, m);
    } else if (nd->value > n && nd->value > m) {
        closestCommonAncestor(nd->Lchild, n, m);
    } else {
        cout << "Closest common ancestor (if both elements exist): " << nd->value << endl;
        if (!searchIf(nd, n)) cout << n << " is not in the tree!" << endl;
        if (!searchIf(nd, m)) cout << m << " is not in the tree!" << endl;
    }
}

void BST::closestCommonAncestor(int n, int m) {
    closestCommonAncestor(root, n, m);
}

BST::node *BST::deleteNode(node *nd, int n) {
    if (nd == nullptr) return nullptr;

    if (nd->value < n) {
        nd->Rchild = deleteNode(nd->Rchild, n);
    } else if (nd->value > n) {
        nd->Lchild = deleteNode(nd->Lchild, n);
    } else {
        if (nd->Lchild == nullptr && nd->Rchild == nullptr) {
            delete nd;
            return nullptr;
        } else if (nd->Rchild == nullptr) {
            node *tmp = nd->Lchild;
            delete nd;
            return tmp;
        } else if (nd->Lchild == nullptr) {
            node *tmp = nd->Rchild;
            delete nd;
            return tmp;
        } else {
            node *succ = nd->Rchild;
            while (succ != nullptr && succ->Lchild != nullptr)
                succ = succ->Lchild;

            nd->value = succ->value;
            nd->Rchild = deleteNode(nd->Rchild, succ->value);
        }
    }
    return nd;
}

bool BST::deleteNode(int n) {
    node *tmp_root = deleteNode(root, n);
    if (tmp_root == nullptr) {
        cout << "ERR: nullptr returned" << endl;
        root = nullptr;
        return false;
    } else {
        root = tmp_root;
    }
    return true;
}

void BST::burnTree(node *nd) {
    if (nd == nullptr) return;
    burnTree(nd->Lchild);
    burnTree(nd->Rchild);
    delete nd;
}

int BST::min(node *nd) {
    if (nd->Lchild != nullptr) {
        return min(nd->Lchild);
    }
    return nd->value;
}

int BST::min() {
    return min(root);
}

int BST::max(node *nd) {
    if (nd->Rchild != nullptr) {
        return max(nd->Rchild);
    }
    return nd->value;
}

int BST::max() {
    return max(root);
}
