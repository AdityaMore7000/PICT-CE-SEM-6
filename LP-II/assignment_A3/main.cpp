#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
void printArray(vi &a)
{
    for (int i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';
}
void primsAlgorithm()
{
    cout << "Wukong is the greatest!!!\n";
    return;
}
void selectionSort()
{
    int n;
    cout << "Enter the number of elements:\n";
    cin >> n;
    vi a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Array before sorting:\n";
    printArray(a);
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(a[i], a[min]);
        }
    }
    cout << "Array after sorting:\n";
    printArray(a);
    return;
}
int main()
{
    int ch;
    while (1)
    {
        cout << "\nSelect one of the following options:\n1. Selection sort.\n2. Prims Algorithm.\n0. Exit\n\n";
        cin >> ch;
        switch (ch)
        {
        case 0:
            return 0;
        case 1:
            selectionSort();
            break;
        case 2:
            primsAlgorithm();
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}