#include <iostream>
#include <array>
using namespace std;

void shuchu(char a[12][12])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}
void crossing(char a[12][12])
{
    char *p = 0;
    int count = 0;
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if (a[i][j] == '.')
            {
                p = &a[i][j];
                if (*(p + 1) == 'T')
                    count++;
                if (*(p - 1) == 'T')
                    count++;
                if (*(p - 12) == 'T')
                    count++;
                if (*(p + 12) == 'T')
                    count++;
                if (count == 2)
                    *p = 'T';
                count = 0;
            }
        }
    }
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if (a[i][j] == 'T')
            {
                p = &a[i][j];
                if (*(p + 1) == 'T')
                    count++;
                if (*(p - 1) == 'T')
                    count++;
                if (*(p - 12) == 'T')
                    count++;
                if (*(p + 12) == 'T')
                    count++;
                if (count != 2)
                    *p = '.';
                count = 0;
            }
        }
    }
}
void mazeTraverse(char a[12][12], char *p, int site)
{
    if (*p == 'T')
        *p = '.';
    else
        *p = 'T';
    int flag = 0;
    for (int i = 0; i < 12; i++)
    {
        if (a[i][11] == '.')
            flag = 1;
    }
    if (flag == 0)
    {
        crossing(a);
        return;
    }
    flag = 0;
    switch (site)
    {
    case 1:
        if (*(p + 12) != '#')
            mazeTraverse(a, p + 12, 2);
        else if (*(p + 1) != '#')
            mazeTraverse(a, p + 1, 1);
        else if (*(p - 12) != '#')
            mazeTraverse(a, p - 12, 4);
        else if (*(p - 1) != '#')
        {
            *p = '.';
            mazeTraverse(a, p - 1, 3);
        }
        break;
    case 2:
        if (*(p - 1) != '#')
            mazeTraverse(a, p - 1, 3);
        else if (*(p + 12) != '#')
            mazeTraverse(a, p + 12, 2);
        else if (*(p + 1) != '#')
            mazeTraverse(a, p + 1, 1);
        else if (*(p - 12) != '#')
        {
            *p = '.';
            mazeTraverse(a, p - 12, 4);
        }
        break;
    case 3:
        if (*(p - 12) != '#')
            mazeTraverse(a, p - 12, 4);
        else if (*(p - 1) != '#')
            mazeTraverse(a, p - 1, 3);
        else if (*(p + 12) != '#')
            mazeTraverse(a, p + 12, 2);
        else if (*(p + 1) != '#')
        {
            *p = '.';
            mazeTraverse(a, p + 1, 1);
        }
        break;
    case 4:
        if (*(p + 1) != '#')
            mazeTraverse(a, p + 1, 1);
        else if (*(p - 12) != '#')
            mazeTraverse(a, p - 12, 4);
        else if (*(p - 1) != '#')
            mazeTraverse(a, p - 1, 3);
        else if (*(p + 12) != '#')
        {
            *p = '.';
            mazeTraverse(a, p + 12, 2);
        }
        break;
    }
}
int main()
{
    char migong[12][12] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                           {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
                           {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
                           {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
                           {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
                           {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                           {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                           {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                           {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
                           {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
                           {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
                           {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};
    cout << "迷宫！迷宫！" << '\n';
    shuchu(migong);
    mazeTraverse(migong, &migong[2][0], 1);
    cout << "出路！出路！" << '\n';
    shuchu(migong);
}
