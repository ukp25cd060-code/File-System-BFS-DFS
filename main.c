#include <stdio.h>
#include <string.h>

#define MAX 20
#define NAME_LEN 50

int graph[MAX][MAX];
int visited[MAX];
char files[MAX][NAME_LEN];
int n;

void BFS(int start, const char target[])
{
    int queue[MAX];
    int front = 0, rear = 0, found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");
    while (front < rear)
    {
        int current = queue[front++];
        printf("%s ", files[current]);

        if (strcmp(files[current], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n%s using BFS.\n", found ? "File found" : "File not found");
}

void DFS(int current, const char target[], int *found)
{
    visited[current] = 1;
    printf("%s ", files[current]);

    if (strcmp(files[current], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
            DFS(i, target, found);
    }
}

int main(void)
{
    int start;
    char target[NAME_LEN];

    printf("Enter number of files/directories: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Invalid number of nodes. Enter a value from 1 to %d.\n", MAX);
        return 1;
    }

    printf("\nEnter file/directory names (one word each):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i + 1);
        scanf("%49s", files[i]);
    }

    printf("\nEnter the %d x %d adjacency matrix (0 or 1):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (scanf("%d", &graph[i][j]) != 1 ||
                (graph[i][j] != 0 && graph[i][j] != 1))
            {
                printf("Invalid matrix. Enter only 0 or 1.\n");
                return 1;
            }
        }
    }

    printf("\nEnter starting node (1 to %d): ", n);
    if (scanf("%d", &start) != 1 || start < 1 || start > n)
    {
        printf("Invalid starting node.\n");
        return 1;
    }

    printf("Enter file name to search: ");
    scanf("%49s", target);

    BFS(start - 1, target);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int found = 0;
    printf("\nDFS Traversal: ");
    DFS(start - 1, target, &found);
    printf("\n%s using DFS.\n", found ? "File found" : "File not found");

    return 0;
}
