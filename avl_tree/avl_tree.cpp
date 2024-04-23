#include <iostream>

template <typename T>
class AVLTree
{
private:
    struct Node
    {
        T data;
        Node *parent;
        Node *left;
        Node *right;
        int height;
        TreeNode(const T &value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    Node *root;

    void setHeight(Node *&node)
    {
        int leftHeight = node->left ? node->left->height : 0;
        int rightHeight = node->right ? node->right->height : 0;
        node->height = max(leftHeight, rightHeight) + 1;
    }

    int getBalance(Node *node)
    {
        int leftHeight = node->left ? node->left->height : 0;
        int rightHeight = node->right ? node->right->height : 0;
        return leftHeight - rightHeight;
    }

    void leftRotate(Node *&node)
    {
        Node *newRoot = node->right;
        Node *newRight = newRoot->left;

        newRoot->left = node;
        newRoot->parent = node->parent;
        node->right = newRight;
        node->parent = newRoot;
        setHeight(node);
        setHeight(newRoot);
        node = newRoot;
    }

    void rightRotate(Node *&node)
    {
        Node *newRoot = node->left;
        Node *newLeft = newRoot->right;

        newRoot->right = node;
        newRoot->parent = node->parent;
        node->left = newLeft;
        node->parent = newRoot;
        setHeight(node);
        setHeight(newRoot);
        node = newRoot;
    }

    Node *insertNode(const T &value)
    {
        Node *newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            return root;
        }
        Node *temp = root;
        while (true)
        {
            if (value < temp->data)
            {
                if (temp->left)
                    temp = temp->left;
                else
                {
                    temp->left = newNode;
                    newNode->parent = temp;
                    break;
                }
            }
            else
            {
                if (temp->right)
                    temp = temp->right;
                else
                {
                    temp->right = newNode;
                    newNode->parent = temp;
                    break;
                }
            }
        }
        return newNode;
    }

    void balanceNode(Node *&node, int &balance)
    {
        if (balance > 1)
        {
            if (getBalance(node->left) < 0)
                leftRotate(node->left);
            rightRotate(node);
        }
        else if (balance < -1)
        {
            if (getBalance(node->right) > 0)
                rightRotate(node->right);
            leftRotate(node);
        }
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(const T &value)
    {
        Node *newNode = insertNode(value);
        int balance;
        while (newNode)
        {
            setHeight(newNode);
            balance = getBalance(newNode);
            if (balance > 1 || balance < -1) {
                balanceNode(newNode, balance);
                return;
            }
            newNode = newNode->parent;
        }
    }

    void remove(const T &value)
    {
        root = remove(root, value);
    }

    void print()
    {
        print(root);
    }
};