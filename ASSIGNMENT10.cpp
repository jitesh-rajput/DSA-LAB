#include <iostream>
using namespace std;
int main()
{
    int minHeap[20], s, parent;
    cout << "Enter Number of Students :- ";
    cin >> s;

    for (int i = 1; i <= s; ++i)
    {
        cout << "Enter " << i << " Student Marks :- ";
        cin >> minHeap[i];
        int j = i;
        while (j > 1)
        {
            parent = j / 2;
            if (minHeap[parent] > minHeap[j])
            {
                int temp = minHeap[j];
                minHeap[j] = minHeap[parent];
                minHeap[parent] = temp;
                j = parent;
            }
            else
            {
                break;
            }
        }
    }
    cout << "Minimum marks are :- " << minHeap[1];
}