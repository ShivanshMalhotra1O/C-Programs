#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

int a[7][7] = {
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
};

void dfs(i)
{
    int j;
    printf("%d\t", i);
    visited[i] = 1;

    for (j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !visited[j])
        {
            dfs(j);
        }
    }
}

int main()
{
    dfs(2);

    return 0;
}