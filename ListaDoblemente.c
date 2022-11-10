/*
   Iker Garcia German
   Rodrigo Nuñez Magallanes
   Primera Codigo Evidencia 1
*/

#include <stdio.h>
#include <stdlib.h>
void beg_insert(int);
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
void beg_insert(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
            head = ptr;
        }
        printf("Node Inserted");
    }
}
void display()
{
    struct node *ptr;
    printf("\n printing values...");
    ptr = head;
    while (ptr->next != head)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n%d", ptr->data);
    printf("\n");
}
// Function to eliminate a exact value
void delete (int item)
{
    struct node *ptr, *temp;
    if (head->data == item)
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
    }
    else if (head->data != item)
    {
        ptr = head;
        while (ptr->next->data != item)
        {
            ptr = ptr->next;
        }
        if (ptr->next->next == head)
        {
            ptr->next = head;
            head->prev = ptr;
            free(ptr->next);
        }
        else
        {
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            free(temp);
        }
    }
    else
    {
        printf("\n Item not found\n");
    }
}
<<<<<<< Updated upstream
int main()
{
    int choice, item;
    do
    {
        printf("\n1.Insert in begining\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item?\n");
            scanf("%d", &item);
            beg_insert(item);
            break;
        case 2:
            printf("\nEnter the item which you want to delete?\n");
            scanf("%d", &item);
            delete (item);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nPlease enter valid choice..");
        }
    } while (choice != 4);
    return 0;
=======
// Function to eliminate repeated nodes
void delete_repeated()  
{  
    struct node *ptr1, *ptr2, *dup;  
    ptr1 = head;  
    while(ptr1 != NULL && ptr1 -> next != head)  
    {  
        ptr2 = ptr1;  
        while(ptr2 -> next != head)  
        {  
            if(ptr1 -> data == ptr2 -> next -> data)  
            {  
                dup = ptr2 -> next;  
                ptr2 -> next = ptr2 -> next -> next;  
                dup -> next -> prev = ptr2;  
                free(dup);  
            }  
            else  
            {  
                ptr2 = ptr2 -> next;  
            }  
        }  
        ptr1 = ptr1 -> next;  
    }  
}
int main ()  
{  
    int choice,item;  
    do   
    {  
        printf("\n1.Insert in begining\n2.Delete\n3.Delete Repeated\n4.Display\n5.Exit\n");  
        printf("\nEnter your choice?\n");        
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            printf("\nEnter the item?\n");  
            scanf("%d",&item);  
            beg_insert(item);  
            break;  
            case 2:  
            printf("\nEnter the item which you want to delete?\n");  
            scanf("%d",&item);  
            delete(item);  
            break;  
            case 3:  
            printf("\nEnter the item which you want to delete?\n");
            scanf("%d",&item);
            delete_repeated(item);  
            break;  
            case 4:  
            display();
            break;  
            case 5:
            exit(0);
            break;
            default:
            printf("\nPlease enter valid choice..");  
        }  
    }while(choice!=5);
    return 0;  
>>>>>>> Stashed changes
}