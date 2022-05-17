/*
There are flight paths between cities. If there is a flight between city  A and city B then there is an edge between the cities. The cost of the
edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The
node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix
C217.2 26 representation of the graph. Check whether the graph is connected or not. Justify the storage representation use
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[20][20] = {0, 0};
    int size;
    cout << "Enter the Number of cities [MAX 20 ]:- ";
    cin >> size;
    string cities[size];

    for (int i = 0; i < size; ++i)
    {
        cout << "\nEnter The Name of Citie " << i + 1 << ":- ";
        cin >> cities[i];
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            cout << "Enter The Distance from " << cities[i] << " To " << cities[j] << endl;
            cin >> arr[i][j];
            arr[j][i] = arr[i][j];
        }
    }
    cout << "Array Representation :- \n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << cities[i] << "\t";
    }
    for (int i = 0; i < size; ++i)
    {
        cout << "\n"
             << cities[i];
        for (int j = 0; j < size; ++j)
        {
            cout << "\t" << arr[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
