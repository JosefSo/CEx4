#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char choice, c;
    int src, v;
    src = 0;
    v = src;
    p_node temp = NULL;
    p_node *head = &temp;
    while (scanf("%c", &choice) != EOF)
    {
        if (choice == 'A')
        {
            deleteGraph(head);
            scanf("%d", &v);
            *head = createGraph(v);

            scanf("%c", &c);

            while (scanf("%c", &c) != 0)
            {
                if (c == 'n')
                {
                    scanf("%d", &src);
                    addNode(head, src);
                }
                else
                {
                    break;
                }
            }
            choice = c;
        }
        if (choice == 'B')
        {

            addNode_B(head);

            continue;
        }
        if (choice == 'D')
        {
            deleteNode(head);

            continue;
        }
        if (choice == 'S')
        {
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortestPath(*head, src, dest);
            printf("Dijsktra shortest path: %d \n", dis);
            continue;
        }
        if (choice == 'T')
        {
            TSP(*head);
            continue;
        }
    }
    deleteGraph(head);
}