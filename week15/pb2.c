#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *NodeLink;
} node;

void reverse_node (node **List);
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


    reverse_node(&ListHead);
    printf("Linked list after reverse nodes: \n");
    view_all_Nodes(ListHead);


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

void reverse_node (node **List)
{

    node *previous = NULL;
    node *current = *List;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->NodeLink;   // حفظ العنوان للعقدة التالية
        current->NodeLink = previous; // عكس الاتجاه
        previous = current; // الانتقال للعقدة الحالية
        current = next;     // الانتقال للعقدة التالية
    }
    *List = previous;

}
