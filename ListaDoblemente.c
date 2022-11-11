/*
   Iker Garcia German
   Rodrigo Nuñez Magallanes
   Rafael Blanga Hanono
   Primera Codigo Evidencia 1
*/

#include <stdio.h>
#include <stdlib.h>
void beg_insert(int);

/* Esta es una definición de estructura en C para un nodo de una lista doblemente enlazada. 
    El nodo tiene un campo de datos entero y dos punteros a otros nodos. 
    El puntero next apunta al siguiente nodo de la lista, y el puntero prev apunta al nodo anterior de la lista. 
    El puntero head apunta al primer nodo de la lista. */

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

/* Esta es una función para insertar un nuevo nodo al principio de una lista doblemente enlazada. 
    La función toma un parámetro entero, que es el dato a almacenar en el nuevo nodo. 
    La función primero asigna memoria para el nuevo nodo usando malloc, y luego comprueba si la asignación fue exitosa. 
    Si no es así, imprime un mensaje de error y regresa. En caso contrario, almacena los datos en el nuevo nodo, y luego comprueba si la lista está vacía. 
    Si es así, establece el puntero de la cabeza para que apunte al nuevo nodo y establece los punteros next y prev del nuevo nodo para que apunten a sí mismo.
    Si la lista no está vacía, la función encuentra el último nodo de la lista y establece su puntero siguiente para que apunte al nuevo nodo. 
    También establece el puntero prev del nuevo nodo para que apunte al último nodo, y establece el puntero prev del nodo principal para que apunte al nuevo nodo. 
    Por último, establece el puntero de la cabeza para que apunte al nuevo nodo. */

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
// La función está iterando a través de una lista enlazada e imprimiendo los datos de cada nodo.

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
// La toma un número entero de entrada n e inserta n elementos en una lista enlazada, empezando por el principio de la lista.

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

/*  La función borra un nodo de una lista enlazada. Si el nodo a eliminar es el primer nodo, entonces la función establece que el siguiente nodo sea la cabeza. 
    En caso contrario, la función establece que el siguiente nodo del nodo anterior sea el siguiente nodo del nodo a eliminar. */

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
// La funcion borra múltiples nodos de una lista enlazada. 
// Se pide al usuario que introduzca el elemento a eliminar, y se llama a la función delete_node para cada elemento.

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
// La función borra una lista circular enlazada. El bucle while itera a través de toda la lista, borrando cada nodo uno a uno hasta llegar de nuevo al nodo cabeza. 
// El nodo cabeza es entonces borrado y el puntero cabeza es puesto a NULL.

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
// Esta función busca un nodo en una lista enlazada. Si se encuentra el elemento, imprime la posición del mismo. 
// Si no se encuentra el elemento, imprime "Objeto no encontrado".
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
                printf("\n\nObjeto encontrado en la posicion %d\n\n", i + 1);
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
// Esta función indica al usuario si la lista se encuentra vacía o no. Apuntando el puntero head a NULL, se indica que la lista está vacía.
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
// La función cuenta el número de nodos de una lista. Si la lista está vacía, imprime "Lista vacía".
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

// Esta función muestra los nodos de la lista enlazada en orden inverso.
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
// Esta función elimina los valores de los nodos duplicados en una lista enlazada circular.
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
// Se trata de un programa basado en menús. El usuario puede elegir entre las diferentes opciones que se le muestran en pantalla.
// El bucle do-while se utiliza para que el menú se muestre al menos una vez aunque la condición del bucle while falle.
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
