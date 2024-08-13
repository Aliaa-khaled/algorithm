#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *NodeLink;
} node;

void Delete_Node(node **List, int deleted_data);
void Add_Node(node **List, int new_data);
void view_all_Nodes(node *List);

int main()
{
    node *ListHead = NULL;

    Add_Node(&ListHead, 7);
    Add_Node(&ListHead, 1);
    Add_Node(&ListHead, 3);
    Add_Node(&ListHead, 2);

    printf("Linked list : \n");
    view_all_Nodes(ListHead);
    printf("\n");

    Delete_Node(&ListHead, 7);
    printf("Linked list after deleting first node: \n");
    view_all_Nodes(ListHead);
    printf("\n");

    Delete_Node(&ListHead, 3);
    printf("Linked list after deleting a node : \n");
    view_all_Nodes(ListHead);
    printf("\n");

    Delete_Node(&ListHead, 2);
    printf("Linked list after deleting last node: \n");
    view_all_Nodes(ListHead);
    printf("\n");

    printf("when try to delete node out of linked list: \n");
    Delete_Node(&ListHead, 4);
    printf("\n");

    Delete_Node(&ListHead, 1);
    printf("Linked list after deleting the only node: \n");
    view_all_Nodes(ListHead);


    return 0;
}

void Delete_Node(node **List, int deleted_data)
{
    if (*List == NULL)
    {
        printf("List is empty. No node to delete.\n");
        return;
    }

    node *current = *List;
    node *previous = NULL;

    while (current != NULL)
    {
        if (current->data == deleted_data)
        {
            if (previous == NULL)
            {
                *List = current->NodeLink;
            }
            else
            {
                previous->NodeLink = current->NodeLink;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->NodeLink;
    }
    printf("Node with data %d not found.\n", deleted_data);
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
