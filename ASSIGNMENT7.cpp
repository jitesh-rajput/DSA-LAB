/*
You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company
charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a
minimum total cost. Solve the problem by suggesting appropriate data structures.
*/
#include <iostream>
using namespace std;

int main()
{
    int office[20][20] = {9999, 9999}, size;
    string cities[10];
    cout << "\nEnter the Number of Cities :- ";
    cin >> size;

    for (int i = 0; i < size; ++i)
    {
        cout << "\nEnter the name of citie :-" << i + 1 << " :- ";
        cin >> cities[i];
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            cout << "\nEnter the distance between " << cities[i] << " to " << cities[j] << ":-";
            cin >> office[i][j];
            office[j][i] = office[i][j];
        }
    }
    int min, selected[size] = {0}, x, y, count = 0, ch = 0;
    selected[0] = 1;
    while (ch < size - 1)
    {
        min = 9999;
        for (int i = 0; i < size; ++i)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < size; ++j)
                {
                    if (selected[j] == 0)
                    {
                        if (min > office[i][j])
                        {
                            min = office[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = 1;
        cout << "  " << cities[x] << " - " << cities[y] << " := " << min << endl;
        count += min;
        ch++;
    }
    cout << "Total MST := " << count;
}
