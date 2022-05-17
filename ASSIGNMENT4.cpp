/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a
binary tree -
i. Insert new node,
ii. Find number of nodes in longest path from root,
iii. Minimum data value found in the tree,
iv. Changea tree so that the roles of the left and right pointers are swapped at every node,
 v. Search a value
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};

class Tree
{
public:
    node *insert(node *temp, int data)
    {
        if (temp == NULL)
        {
            node *n = new node();
            n->data = data;
            temp = n;
        }
        else if (temp->data > data)
        {
            temp->left = insert(temp->left, data);
        }
        else
        {
            temp->right = insert(temp->right, data);
        }
        return temp;
    }
    int search(node *temp, int key)
    {
        if (temp != NULL)
        {
            search(temp->left, key);
            if (key == temp->data)
            {
                return 1;
            }
            search(temp->right, key);
        }
        return 0;
    }
    void display(node *root)
    {
        if (root == NULL)
        {
            cout << "Tree is Empty";
        }
        else
        {
            cout << "\n Inorder :- ";
            inorder(root);
            cout << "\n PreOrder :- ";
            preorder(root);
            cout << "\n Posorder :- ";
            postorder(root);
        }
    }
    void inorder(node *temp)
    {
        if (temp != NULL)
        {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }
    void preorder(node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    void postorder(node *temp)
    {
        if (temp != NULL)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }
    void getMin(node *temp)
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        cout << "\nMinimum Data :- " << temp->data;
    }
    void swap(node *temp)
    {
        if (temp == NULL)
            return;
        node *temp2;
        swap(temp->left);
        swap(temp->right);
        temp2 = temp->left;
        temp->left = temp->right;
        temp->right = temp2;
    }
};

int main()
{
    node *root = NULL;
    Tree t1;
    int ch;
    while (1)
    {
        cout << "\n\n 1. Insert Data ";
        cout << "\n 2. Display Tree ";
        cout << "\n 3. Search ";
        cout << "\n 4. Minimum Data ";
        cout << "\n 5. Swap ";
        cout << "\n 6.Exit \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int data;
            cout << "\nEnter Data :- ";
            cin >> data;
            root = t1.insert(root, data);
            break;
        case 2:
            t1.display(root);
            break;
        case 3:
            int key;
            cout << "\nEnter Element to Search :- ";
            cin >> key;
            if (t1.search(root, key) == 1)
                cout << "\nKey Found..";
            else
                cout << "\nData Not Found..";
            break;
        case 4:
            t1.getMin(root);
            break;
        case 5:
            t1.swap(root);
            cout << "\nElement Swaped...!";
            cout << "\n Data :- ";
            t1.inorder(root);
            break;
        default:
            return 0;
        }
    }
}