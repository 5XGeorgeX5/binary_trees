#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

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
        Node(const T &value)
        {
            data = value;
            parent = nullptr;
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
        node->height = std::max(leftHeight, rightHeight) + 1;
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

        if (node->parent == nullptr)
            root = newRoot;
        else if (node->parent->left == node)
            node->parent->left = newRoot;
        else
            node->parent->right = newRoot;
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

        if (node->parent == nullptr)
            root = newRoot;
        else if (node->parent->left == node)
            node->parent->left = newRoot;
        else
            node->parent->right = newRoot;
        newRoot->right = node;
        newRoot->parent = node->parent;
        node->left = newLeft;
        node->parent = newRoot;
        setHeight(node);
        setHeight(newRoot);
        node = newRoot;
    }

    Node *findNode(Node *node, const T &value)
    {
        if (value < node->data)
        {
            if (node->left == nullptr)
                return node;
            return findNode(node->left, value);
        }
        if (node->data < value)
        {
            if (node->right == nullptr)
                return node;
            return findNode(node->right, value);
        }
        return node;
    }

    Node *insertNode(const T &value)
    {
        Node *newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            return root;
        }
        Node *parent = findNode(root, value);
        newNode->parent = parent;
        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
        return newNode;
    }

    Node *deleteNode(Node *node)
    {
        Node *replacement = nullptr;
        if (node->right)
        {
            replacement = node->right;
            while (replacement->left)
                replacement = replacement->left;
        }
        else if (node->left)
        {
            replacement = node->left;
            while (replacement->right)
                replacement = replacement->right;
        }
        if (replacement)
        {
            node->data = replacement->data;
        }
        else if (node->parent == nullptr)
        {
            delete node;
            root = nullptr;
            return nullptr;
        }
        else if (node->parent->left == node)
        {
            node->parent->left = nullptr;
            return node->parent;
        }
        else
        {
            node->parent->right = nullptr;
            return node->parent;
        }

        if (replacement->parent->left == replacement)
        {
            replacement->parent->left = nullptr;
        }
        else
        {
            replacement->parent->right = nullptr;
        }
        delete replacement;
        return node;
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

    void printInOrder(Node *node)
    {
        if (node == nullptr)
            return;
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
    int printNode(Node *node, int offset, int depth, std::vector<std::string> &output)
    {
        if (!node)
            return 0;

        bool is_left = (node->parent && node->parent->left == node);
        std::stringstream ss;
        ss << "(" << std::setw(3) << std::setfill('0') << node->data << ")";

        std::string data_str = ss.str();
        int width = data_str.length();

        int left = printNode(node->left, offset, depth + 1, output);
        int right = printNode(node->right, offset + left + width, depth + 1, output);

        for (int i = 0; i < width; i++)
            output[depth][offset + left + i] = data_str[i];

        if (depth && is_left)
        {
            for (int i = 0; i < width + right; i++)
                output[depth - 1][offset + left + width / 2 + i] = '-';
            output[depth - 1][offset + left + width / 2] = '.';
        }
        else if (depth && !is_left)
        {
            for (int i = 0; i < left + width; i++)
                output[depth - 1][offset - width / 2 + i] = '-';
            output[depth - 1][offset + left + width / 2] = '.';
        }

        return left + width + right;
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
            if (balance > 1 || balance < -1)
            {
                balanceNode(newNode, balance);
                return;
            }
            newNode = newNode->parent;
        }
    }

    void remove(const T &value)
    {
        Node *node = findNode(root, value);
        if (node->data != value)
            return;
        Node *replacement = deleteNode(node);
        int balance;
        while (replacement)
        {
            setHeight(replacement);
            balance = getBalance(replacement);
            if (balance > 1 || balance < -1)
            {
                balanceNode(replacement, balance);
            }
            replacement = replacement->parent;
        }
    }

    void print()
    {
        printInOrder(root);
        std::cout << std::endl;
    }

    void printTree()
    {
        if (!root)
        {
            std::cout << "Empty tree" << std::endl;
            return;
        }

        int height = root->height;
        std::vector<std::string> output(height, std::string(255, ' '));
        printNode(root, 0, 0, output);

        for (const std::string &line : output)
        {
            std::cout << line.substr(0, line.find_last_not_of(' ') + 1) << std::endl;
        }
        cout << endl;
    }
};

int main()
{
    AVLTree<int> tree;
    tree.insert(10);
    tree.printTree();
    tree.insert(20);
    tree.printTree();
    tree.insert(30);
    tree.printTree();
    tree.insert(15);
    tree.printTree();
    tree.insert(25);
    tree.printTree();
    tree.insert(5);
    tree.printTree();
    tree.insert(35);
    tree.printTree();
    tree.insert(40);
    tree.printTree();
    tree.insert(45);
    tree.printTree();
    tree.insert(50);
    tree.printTree();
    tree.insert(37);
    tree.printTree();
    return 0;
}