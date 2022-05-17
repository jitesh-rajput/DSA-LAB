/*
A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any
entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may
require for finding any keyword. Use Binary Search Tree for implementation
*/
#include <iostream>
using namespace std;

struct node
{
    string keyword;
    string meaning;
    node *left = NULL;
    node *right = NULL;
};

class Tree
{

public:
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
        return temp;
    }

    void display(node *root)
    {
        if (root != NULL)
        {
            display(root->left);
            cout << "\nKeyword :-" << root->keyword << "\t Meaning:- " << root->meaning << endl;
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