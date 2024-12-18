#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {7, 5, 16, 8};

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    return 0;
}