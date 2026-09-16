#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> data = {80, 60, 90, 70, 85};

    int min = data[0];
    int max = data[0];
    int sum = 0;

    cout << "Cumulative Min: ";
    for (int x : data)
    {
        if (x < min) min = x;
        cout << min << " ";
    }

    cout << "\nCumulative Max: ";
    for (int x : data)
    {
        if (x > max) max = x;
        cout << max << " ";
    }

    cout << "\nCumulative Mean: ";
    for (int i = 0; i < data.size(); i++)
    {
        sum += data[i];
        cout << (double)sum / (i + 1) << " ";
    }

    cout << "\nRolling Sum: ";
    for (int i = 0; i < data.size() - 1; i++)
        cout << data[i] + data[i + 1] << " ";

    cout << "\nRolling Mean: ";
    for (int i = 0; i < data.size() - 1; i++)
        cout << (data[i] + data[i + 1]) / 2.0 << " ";

    return 0;
}