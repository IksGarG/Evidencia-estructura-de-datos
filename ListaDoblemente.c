/*
   Iker Garcia German
   Rodrigo Nuñez Magallanes
   Rafael Blanga Hanono
   Primera Codigo Evidencia 1
*/

#include <stdio.h>
#include <stdlib.h>

// I need a function to insert at the beginning of the list
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
        printf("\nMemoria LLena");
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
        printf("Node Insertado\n\n");
    }
}

void display()
{
    struct node *ptr;
    printf("\n Imprimiendo...");
    ptr = head;
    while (ptr->next != head)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n%d", ptr->data);
}

// Function to insert multiple nodes at the beginning of the list

void insert_multiple(int n)
{
    int i, item;
    for (i = 0; i < n; i++)
    {
        printf("Introduzca el elemento a insertar: ");
        scanf("%d", &item);
        beg_insert(item);
    }
}

// Function to delete a node

void delete_node(int item)
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
    else
    {
        ptr = head->next;
        while (ptr->next != head)
        {
            if (ptr->data == item)
            {
                temp = ptr;
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(temp);
                printf("Nodo Eliminado\n\n");
                return;
            }
            ptr = ptr->next;
        }
        if (ptr->data == item)
        {
            temp = ptr;
            ptr->prev->next = head;
            head->prev = ptr->prev;
            free(temp);
            printf("Node deleted\n");
            return;
        }
        printf("Objeto no encontrado\n\n");
    }
}

// Function to delete multiple nodes

void delete_multiple(int n)
{
    int i, item;
    for (i = 0; i < n; i++)
    {
        printf("Introduzca el objeto a ser eliminado: ");
        scanf("%d", &item);
        delete_node(item);
    }
}

// Function to delete the entire list

void delete_list()
{
    struct node *ptr, *temp;
    ptr = head;
    while (ptr->next != head)
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(ptr);
    head = NULL;
    printf("Lista eliminada\n\n");
}

// Function to search for a node

void search_node(int item)
{
    struct node *ptr;
    int i = 0, flag = 0;
    ptr = head;
    if (head != NULL)
    {
        do
        {
            if (ptr->data == item)
            {
                printf("\n\nObjeto encontrado en la posicion %d", i + 1);
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        } while (ptr != head);
        if (flag == 0)
        {
            printf("Objeto no encontrado");
        }
    }
    else
    {
        printf("Lista vacia");
    }
}

// Function to know if the list is empty

void is_empty()
{
    if (head == NULL)
    {
        printf("Lista vacia");
    }
    else
    {
        printf("Lista no vacia");
    }
}

// Function to count the number of nodes

void count_nodes()
{
    struct node *ptr;
    int i = 0;
    ptr = head;
    if (head != NULL)
    {
        do
        {
            i++;
            ptr = ptr->next;
        } while (ptr != head);
        printf("\nNumero de nodos en la lista = %d", i);
    }
    else
    {
        printf("Lista vacia");
    }
}

// Function to display the list in reverse order

void display_reverse()
{
    struct node *ptr;
    printf("\n Imprimiendo nodos al reves...");
    ptr = head->prev;
    while (ptr->prev != head->prev)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n%d", ptr->data);
}

// Function to delete duplicate nodes

void delete_duplicate()
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != head)
    {
        ptr2 = ptr1;
        while (ptr2->next != head)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                ptr2->next->prev = ptr2;
                free(dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

// Main function with the menu

int main()
{
    int choice, item, n;
    do
    {
        printf("\n1.Insertar al principio");
        printf("\n2.Insertar multiples nodos al principio");
        printf("\n3.Borrar un nodo");
        printf("\n4.Borrar multiples nodos");
        printf("\n5.Borrar la lista");
        printf("\n6.Buscar un nodo");
        printf("\n7.Verificar si la lista esta vacia");
        printf("\n8.Contar el numero de nodos");
        printf("\n9.Imprimir la lista al reves"); 
        printf("\n10.Elminar nodos duplicados");
        printf("\n11.Imprimir la lista");
        printf("\n12.Salir");
        printf("\n\nIngrese su opcion: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Introduzca el elemento a insertar: ");
            scanf("%d", &item);
            beg_insert(item);
            break;
        case 2:
            printf("Introduzca el número de nodos a insertar: ");
            scanf("%d", &n);
            insert_multiple(n);
            break;
        case 3:
            printf("Introduzca el elemento que desea eliminar: ");
            scanf("%d", &item);
            delete_node(item);
            break;
        case 4:
            printf("Introduzca el número de nodos a eliminar: ");
            scanf("%d", &n);
            delete_multiple(n);
            break;
        case 5:
            delete_list();
            break;
        case 6:
            printf("Introduzca el elemento a buscar: ");
            scanf("%d", &item);
            search_node(item);
            break;
        case 7:
            is_empty();
            break;
        case 8:
            count_nodes();
            break;
        case 9:
            display_reverse();
            break;
        case 10:
            delete_duplicate();
            printf("Nodos duplicados eliminados\n\n");
            break;
        case 11:
            display();
            break;
        case 12:
            exit(0);
            break;
        default:
            printf("Opcion invalida");
        }
    } while (choice != 12);
    return 0;
}
