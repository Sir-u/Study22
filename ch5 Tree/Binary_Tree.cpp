#include <iostream>
using namespace std;
#define endl "\n";

template <typename T>
struct Node
{
public:
    T value;
    struct Node *left;
    struct Node *right;
};

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;
    int size = 0;

public:
    BinaryTree() : root(nullptr){};
    ~BinaryTree(){};

    Node<T>* FindMax(Node<T> *node)
    {
        if (node == NULL)
            return NULL;

        while (node->right != NULL)
        {
            node = node->right;
        }
        return node;
    }

    void AddNode()
    {
        T data;
        cin >> data;

        Add(data);
    }

    void Add(T data)
    {
        Node<T> *node = new Node<T>();
        Node<T> *tmpRoot = nullptr;

        node->value = data;

        if (root == nullptr)
            root = node;
        else
        {
            Node<T> *ptr = root;

            while (ptr != nullptr)
            {
                tmpRoot = ptr;
                if (node->value < ptr->value)
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
            }

            if (node->value < tmpRoot->value)
                tmpRoot->left = node;
            else
                tmpRoot->right = node;
        }
    }

    void RemoveNode()
    {
        T data;
        cin >> data;

        Node<T> *ptr = root;
        Remove(ptr, data);
    }

    Node<T>* Remove(Node<T> *node, T data)
    {
        if (node == nullptr)
            return node;
        else if (node->value > data)
            node->left = Remove(node->left, data);
        else if (node->value < data)
            node->right = Remove(node->right, data);
        else
        {
            Node<T> *ptr = node;

            if (node->right == nullptr && node->left == nullptr) ////////////////////////////////////
            {
                if(node->value == root->value) root = nullptr;
                delete node;
                node = nullptr;
            }
            else if (node->right == nullptr)
            {
                if (node == root)
                    root = node->left;
                node = node->left;
                delete ptr;
            }
            else if (node->left == nullptr)
            {
                if (node == root)
                    root = node->right;
                node = node->right;
                delete ptr;
            }
            else
            {
                ptr = FindMax(node->left);
                node->value = ptr->value;
                node->left = Remove(node->left, ptr->value);
            }
        }
        return node;
    }

    void SearchValue()
    {
        T data;
        cin >> data;

        Search(data);
    }

    void Search(T data)
    {
        Node<T> *ptr = root;
        Node<T> *tmpRoot = nullptr;

        while (ptr != nullptr)
        {
            if (ptr->value == data)
            {
                cout << data << " exists" << endl;
                break;
            }
            else if (ptr->value < data)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        cout << "Can't find " << data << endl;
    }

    void Display(Node<T> *n, int mode)
    {
        if (mode == 1)
        {
            if (n != nullptr)
            {
                cout << n->value << "; ";
                Display(n->left, mode);
                Display(n->right, mode);
            }
            else if(root == nullptr)
            {
                cout << "Tree is empty";
            }
        }
        if (mode == 2)
        {
            if (n != nullptr)
            {
                Display(n->left, mode);
                cout << n->value << "; ";
                Display(n->right, mode);
            }
            else if(root == nullptr)
            {
                cout << "Tree is empty";
            }
        }

        if (mode == 3)
        {
            if (n != nullptr)
            {
                Display(n->left, mode);
                Display(n->right, mode);
                cout << n->value << "; ";
            }
            else if(root == nullptr)
            {
                cout << "Tree is empty";
            }
        }
    }

    void Show()
    {
        int mode;
        cin >> mode;

        Display(root, mode);
        cout << endl;
    }
};

int main(void)
{
    BinaryTree<int> Tree;
    string order;

    do
    {
        cin >> order;

        if (order == "add")
            Tree.AddNode();
        if (order == "remove")
            Tree.RemoveNode();
        if (order == "search")
            Tree.SearchValue();
        if (order == "show")
            Tree.Show();

    } while (order != "end");
}