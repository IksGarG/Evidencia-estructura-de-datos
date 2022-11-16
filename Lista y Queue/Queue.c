/*
   Iker Garcia German, A01782767
   Rodrigo Nuñez Magallanes, A01028310
   Rafael Blanga Hanono, A01781442
   Segundo Codigo Evidencia 1
   Cola (queue) con prioridades
*/

#include <stdio.h>
#include <stdlib.h>

/* cada nodo de la estructura contiene un valor, una prioridad y un apuntador al
nodo que va después del mismo en la cola*/
struct node
{
   int value;
   int priority;
   struct node *next;
};

struct node *front = NULL;
struct node *back = NULL;

// 1. Añadir un nodo a la cola con prioridades
void enqueue(int newValue, int newPriority)
{
   printf("Agregando %d con prioridad %d\n", newValue, newPriority);
   struct node *element = malloc(sizeof(struct node));
   if (element == NULL)
   {
      printf("Error: No se puede crear un elemento en la cola\n");
      return;
   }
   element->value = newValue;
   element->priority = newPriority;
   element->next = NULL;
   if (queueIsEmpty() == 1)
   {
      front = element;
      back = element;
      printQueue();
      return;
   }
   struct node *currentNode = front;
   while (currentNode != NULL)
   {
      // prioridad del que entra es mayor, se inserta
      if (currentNode->priority > newPriority)
      {
         if (currentNode == front)
         {
            element->next = front;
            front = element;
         }
         else
         {
            currentNode->next = currentNode->next->next;
            element->next = currentNode;
         }
         break;
      }
      // prioridades son iguales, va al final de la "sub-cola" e inserta
      else if (currentNode->priority == newPriority)
      {
         while (currentNode->next != NULL && currentNode->next->priority == newPriority)
         {
            currentNode = currentNode->next;
         }
         element->next = currentNode->next;
         currentNode->next = element;
         break;
      }
      // llego hasta atras
      else if (currentNode->next == NULL)
      {
         currentNode->next = element;
         back = element;
         break;
      }
      currentNode = currentNode->next;
   }
   printQueue();
}

// 2. Añadir múltiples nodos consecutivos a la cola con prioridades
void enqueueMultiple()
{
   int newValue, newPriority;
   printf("Ingresa el valor del nuevo elemento: ");
   scanf("%d", &newValue);
   printf("Ingresa la prioridad del nuevo elemento: ");
   scanf("%d", &newPriority);
   enqueue(newValue, newPriority);
   char answer;
   do
   {
      printf("¿Deseas agregar otro elemento? (s/n): ");
      scanf(" %c", &answer);
      if (answer == 's')
      {
         printf("Ingresa el valor del elemento: ");
         scanf("%d", &newValue);
         printf("Ingresa la prioridad del elemento: ");
         scanf("%d", &newPriority);
         enqueue(newValue, newPriority);
      }
   } while (answer == 's');
}

// 3. Eliminar un nodo de la cola con prioridades
void dequeue()
{
   if (queueIsEmpty() == 1)
   {
      printf("Error: La cola esta vacia\n");
      return;
   }
   else
   {
      struct node *temp;
      temp = front;
      if (front == back)
      {
         front = NULL;
         back = NULL;
      }
      else
      {
         front = front->next;
      }
      printf("Eliminando el elemento (%d, %d) \n", temp->value, temp->priority);
      free(temp);
   }
}

// 4. Eliminar toda la cola
void deleteQueue()
{
   while (queueIsEmpty() == 0)
   {
      dequeue();
   }
}

// 5. Buscar un nodo en la cola con prioridades
void findNode(int value, int priority)
{
   int index = 0;
   int notFound = 1;
   if (queueIsEmpty() == 1)
   {
      printf("Error: La cola esta vacia\n");
      return;
   }
   struct node *currentNode = front;
   while (currentNode != NULL)
   {
      if (currentNode->value == value && currentNode->priority == priority)
      {
         notFound = 0;
         printf("El elemento (%d, %d) se encuentra en la posicion %d de la cola.\n", value, priority, index);
         printf("Es decir, tiene %d elementos antes de el.\n", index);
         return;
      }
      currentNode = currentNode->next;
      index++;
   }
   if (notFound == 1)
   {
      printf("El elemento (%d, %d) no se encuentra en la cola.\n", value, priority);
   }
}

// 6. Saber si la cola está vacía
int queueIsEmpty()
{
   return (front == NULL) ? 1 : 0;
}

// 7. Encontrar el número de nodos en la cola con prioridades
int queueSize()
{
   if (queueIsEmpty() == 1)
   {
      printf("Error: La cola esta vacia\n");
      return 0;
   }
   int size = 0;
   struct node *currentNode = front;
   while (currentNode != NULL)
   {
      size++;
      currentNode = currentNode->next;
   }
   return size;
}

// 8. MISC. Imprimir la cola con prioridades
void printQueue()
{
   if (queueIsEmpty() == 1)
   {
      printf("La cola esta vacia\n");
      return;
   }
   printf("Elementos de la cola: \n");
   int i = 0;
   struct node *currentNode = front;
   while (currentNode != NULL)
   {
      printf("Elemento[%d] = (%d, %d) \n", i, currentNode->value, currentNode->priority);
      currentNode = currentNode->next;
      i++;
   }
   printf("\n");
}

void main()
{
   /* la funcion de imprimir la cola se llama en varias de las funciones, asi como
   la de checar que esta vacia, por lo que no se muestran explicitamente aqui*/

   // agregar elementos estaticamente
   enqueue(1, 2);
   enqueue(1, 1);
   enqueue(1, 3);
   enqueue(2, 2);
   enqueue(8, 1);
   enqueue(9, 4);
   enqueue(2, 1);
   enqueue(3, 3);
   enqueue(1, 4);
   enqueue(2, 4);
   // agregando varios elementos consecutivos
   printf("Agregar varios elementos consecutivos: \n");
   enqueueMultiple();
   // obteniendo el tamaño de la cola
   printf("Tamaño de la cola: %d\n", queueSize());
   // buscando un elemento en la cola
   printf("Buscando un elemento en la cola\n");
   findNode(3, 3);
   // eliminando al elemento de hasta adelante en la cola
   printf("Eliminando el elemento de hasta adelante\n");
   dequeue();
   printQueue();
   // eliminando la cola
   printf("Eliminando la cola\n");
   deleteQueue();
   printQueue();
}