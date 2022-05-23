/*
A Dictionary stores keywords and its meanings. Provide facility for
adding new keywords, deleting keywords, updating values of any
entry. Provide facility to display whole data sorted in ascending/
Descending order. Also find how many maximum comparisons may
require for finding any keyword. Use Height balance tree and find the
complexity for finding a keyword
*/

#include <iostream>
using namespace std;

struct node
{
    string keyword;
    string meaning;
    int height = 0;
    node *left = NULL;
    node *right = NULL;
};

class Tree
{

public:
    int height(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return root->height;
    }
    int getBalance(node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    // A utility function to right rotate subtree rooted with y See the diagram given above.
    node *rightRotate(node *y)
    {
        node *x = y->left;
        node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left),
                        height(y->right)) +
                    1;
        x->height = max(height(x->left),
                        height(x->right)) +
                    1;

        // Return new root
        return x;
    }

    // A utility function to left rotate subtree rooted with x See the diagram given above.
    node *leftRotate(node *x)
    {
        node *y = x->right;
        node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left),
                        height(x->right)) +
                    1;
        y->height = max(height(y->left),
                        height(y->right)) +
                    1;

        // Return new root
        return y;
    }
    node *insert(node *temp, string k, string m)
    {
        if (temp == NULL)
        {
            node *n = new node();
            n->keyword = k;
            n->meaning = m;
            temp = n;
        }
        else if (temp->keyword > k)
        {
            temp->left = insert(temp->left, k, m);
        }
        else
        {
            temp->right = insert(temp->right, k, m);
        }
        temp->height = 1 + max(height(temp->left),
                               height(temp->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance(temp);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && k < temp->left->keyword)
            return rightRotate(temp);

        // Right Right Case
        if (balance < -1 && k > temp->right->keyword)
            return leftRotate(temp);

        // Left Right Case
        if (balance > 1 && k > temp->left->keyword)
        {
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }
        // Right Left Case
        if (balance < -1 && k < temp->right->keyword)
        {
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }

        /* return the (unchanged) node pointer */
        return temp;
    }

    void display(node *root)
    {
        if (root != NULL)
        {
            display(root->left);
            cout << "\nKeyword :-" << root->keyword << "\t Meaning:- " << root->meaning << "Height :-" << root->height << endl;
            display(root->right);
        }
    }

    void update(node *root, string k)
    {
        if (root != NULL)
        {
            if (root->keyword == k)
            {
                cout << "\nEnter New Meaning Of Keyword " << root->keyword << ":- ";
                cin >> root->meaning;
                cout << "\nMeaning Updated ...";
                return;
            }
            else if (root->keyword > k)
            {
                update(root->left, k);
            }
            else if (root->keyword < k)
            {
                update(root->right, k);
            }
            else
            {
                cout << "Keyword Not Found ...:";
            }
        }
        else
        {
            cout << "Keyword Not Found ...:";
        }
    }

    void search(node *root, string k)
    {
        if (root != NULL)
        {
            if (root->keyword == k)
            {
                cout << "\n Keyword found :" << root->keyword << "Meaning :- " << root->meaning;
            }
            else if (root->keyword > k)
            {
                update(root->left, k);
            }
            else if (root->keyword < k)
            {
                update(root->right, k);
            }
            else
            {
                cout << "Keyword Not Found ...:";
            }
        }
        else
        {
            cout << "Keyword Not Found ...:";
        }
    }
};

int main()
{
    node *root = NULL;
    Tree t1;
    int ch;
    while (1)
    {
        cout << "\n 1. Insert ";
        cout << " \n 2. Display";
        cout << "\n 3. Update ";
        cout << "\n 4. Search ";
        cout << "\n 5 . Exit \n";
        cin >> ch;
        string k, m;
        switch (ch)
        {
        case 1:
            cout << "Enter Keyword :- ";
            cin >> k;
            cout << "Enter Meaning :-";
            cin >> m;
            root = t1.insert(root, k, m);
            break;
        case 2:
            cout << "Ascending Order :- \n";
            t1.display(root);
            break;
        case 3:
            cout << "\n Enter Keyword to Update :-";
            cin >> k;
            t1.update(root, k);
            break;
        case 4:
            cout << "\n Enter Keyword to Search :-";
            cin >> k;
            t1.search(root, k);
            break;
        default:
            return 0;
        }
    }
}