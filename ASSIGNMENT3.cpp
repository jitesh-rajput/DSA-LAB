#include <iostream>
using namespace std;

struct Bnode
{
    string name;
    int ch;
    struct Bnode *table[10];
} * root;

class Tree
{
public:
    void create()
    {
        root = new Bnode();
        cout << "Enter The Name Of The Book :- ";
        cin >> root->name;
        cout << "\nEnter The Number of Chapter :- ";
        cin >> root->ch;
        for (int i = 0; i < root->ch; ++i)
        {
            root->table[i] = new Bnode();
            cout << "Enter The Name Of The Chapter " << i + 1 << ":-";
            cin >> root->table[i]->name;
            cout << "\nEnter The Number of Section  :- ";
            cin >> root->table[i]->ch;

            for (int j = 0; j < root->table[i]->ch; ++j)
            {
                root->table[i]->table[j] = new Bnode();
                cout << "Enter The Name Of The Section " << j + 1 << ":-";
                cin >> root->table[i]->table[j]->name;
                cout << "\nEnter The Number of Subsection :- ";
                cin >> root->table[i]->table[j]->ch;

                for (int k = 0; k < root->table[i]->table[j]->ch; ++k)
                {
                    root->table[i]->table[j]->table[k] = new Bnode();
                    cout << "\nEnter The Name Of The SubSection " << k + 1 << ":-";
                    cin >> root->table[i]->table[j]->table[k]->name;
                }
            }
        }
    }

    void display(Bnode *root)
    {
        cout << "\nName of Book :- " << root->name;
        for (int i = 0; i < root->ch; ++i)
        {
            cout << "\n\t Chapter " << i + 1 << ":-" << root->table[i]->name;
            for (int j = 0; j < root->table[i]->ch; ++j)
            {
                cout << "\n\t\tSection " << j + 1 << " :- " << root->table[i]->table[j]->name;
                for (int k = 0; i < root->table[i]->table[j]->ch; ++k)
                {
                    root->table[i]->table[j]->table[k] = new Bnode();
                    cout << "\n\t\t\t SubSection :- " << k + 1 << " :- " << root->table[i]->table[j]->table[k]->name;
                }
            }
        }
    }
};
int main()
{
    Tree t1;
    t1.create();
    t1.display(root);
    return 0;
}