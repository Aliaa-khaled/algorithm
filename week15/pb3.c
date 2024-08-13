#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *NodeLink;
} node;

int length_node (node *List);
void Add_Node(node **List, int new_data);
void view_all_Nodes(node *List);
int middel_node(node *List);

int main()
{
    node *ListHead = NULL;

    Add_Node(&ListHead, 7);
    Add_Node(&ListHead, 1);
    Add_Node(&ListHead, 8);
    Add_Node(&ListHead, 3);
    Add_Node(&ListHead, 2);

    printf("Linked list : \n");
    view_all_Nodes(ListHead);
    printf("\n");

    printf("the data of the middle node: %d\n",middel_node(ListHead));


    return 0;
}

void Add_Node(node **List, int new_data)
{
    node *TempNode = (node *)malloc(sizeof(node));
    if (TempNode != NULL)
    {
        TempNode->data = new_data;
        TempNode->NodeLink = *List;
        *List = TempNode;
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
}

void view_all_Nodes(node *List)
{
    if (List == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        while (List != NULL)
        {
            printf("Data: %d\n", List->data);
            List = List->NodeLink;
        }
    }
}
int length_node (node *List)
{
    struct Node *TempNode = List;
    int i=0;
    while (TempNode != NULL)
    {
        i++;
        TempNode = TempNode->NodeLink;
    }
    return i;
}
int middel_node(node *List)
{
    for(int i=0;i<(length_node(List)/2);i++)
    {
        List = List->NodeLink;
    }
    return List->data;
}
