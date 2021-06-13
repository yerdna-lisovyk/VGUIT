
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

int main()
{

    const int m = 5;
    const int n = 8;
    const int V[n][m] = { 5, 2, 3, 8, 9,
                           5, 8, 9, 9, 3,
                           6, 8, 6, 3, 8,
                           3, 2, 3, 7, 9,
                           2, 4, 9, 3, 5,
                           5, 6, 3, 7, 8,
                           4, 4, 5, 8, 5,
                           6, 8, 6, 9, 8
    };

    int GJ[n];
    int minJob=-1;
    int T[n][m];
    int T_min[n][m];
    std::vector<int> Job(n);
    for (int i = 0; i < n; i++)
    {
        Job[i] = i + 1;
    }

    do
    {
        T[0][0] = V[Job[0] - 1][0];
        for (int j = 1; j < m; j++)
        {
            T[0][j] = T[0][j - 1] + V[Job[0] - 1][j];
        }
        int k = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int max_i = 0, max_j = T[i - 1][j];
                if (j != 0)
                    max_i = T[i][j - 1];
                T[i][j] = V[Job[k] - 1][j] + std::max(max_i, max_j);
            }
            k++;
        }

        if (T[n - 1][m - 1] < minJob|| minJob==-1)
        {
            minJob = T[n - 1][m - 1];
            for (int i = 0; i < n; i++)
            {
                GJ[i] = Job[i];
                
            }
            for (int i = 1; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    T_min[i][j] = T[i][j];
                }
        }
    } while (next_permutation(Job.begin(), Job.end()));
        

    for (int i = 0; i < n; i++)
    {
        std::cout << GJ[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "minJob = " << minJob << std::endl;
    std::cout << "T = " << std::endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout.width(3);
            std::cout << T_min[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}


