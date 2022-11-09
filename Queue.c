/*
   Iker Garcia German
   Rodrigo Nuñez Magallanes
   Segundo Codigo Evidencia 1
*/

#include <stdio.h>
#include <stdlib.h>

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
      return;
   }
   struct node *currentNode = front;
   struct node *previousNode = NULL;
   while (currentNode != NULL)
   {
      // las prioridades son iguales, vemos cuantos hay de la misma prioridad para mandarlo al final los que ya estaban
      if (currentNode->priority == newPriority)
      {
         printf("Nuevo elemento tiene la misma prioridad\n");
         // avanzamos para ir hasta el final de los elementos que tienen la misma prioridad, si hay más de uno, y ahi insertar el nuevo
         if (currentNode->next != NULL && currentNode->next->priority == newPriority)
         {
            do
            {
               currentNode = currentNode->next;
            } while (currentNode->priority == newPriority);
         }
         /*
         aqui no se revisa si es el de hasta en frente, porque si estamos en el caso en el que
         el elemento que entra tiene la misma prioridad que otro que ya existe en la cola, forzosamente
         deberá ir detrás de él y por tanto nunca será en el frente
         */
         // el elemento va a ir hasta atras
         if (currentNode == back)
         {
            back->next = element;
            back = element;
         }
         // el elemento va a ir en medio de dos elementos
         else
         {
            element->next = currentNode->next;
            currentNode->next = element;
         }
         break;
      }
      // el nuevo elemento es más importante que el actual, entonces inserta
      else if (currentNode->priority > newPriority)
      {
         printf("Nuevo elemento tiene mayor prioridad\n");
         // el elemento va a ir hasta el frente
         if (currentNode == front)
         {
            element->next = front;
            front = element;
         }
         // el elemento va a ir hasta atras
         else if (currentNode == back)
         {

            back->next = element;
            back = element;
         }
         // el elemento va a ir en medio de dos elementos
         else
         {
            element->next = currentNode->next;
            currentNode->next = element;
         }
         break;
      }
      else if (currentNode->priority < newPriority)
      {
         printf("Nuevo elemento tiene menor prioridad\n");
         // el elemento va a ir hasta atras
         if (currentNode == back)
         {
            back->next = element;
            back = element;
         }
         // el elemento va a ir en medio de dos elementos
         else
         {
            element->next = currentNode->next;
            currentNode->next = element;
         }
         break;
      }
      // si no se cumple ninguna de las condiciones y por tanto se rompe el ciclo, avanzo
      currentNode = currentNode->next;
   }
}

// 2. Añadir múltiples nodos consecutivos a la cola con prioridades

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
}

void main()
{
   // enqueueing
   enqueue(1, 1);
   enqueue(2, 2);
   enqueue(3, 3);
   enqueue(4, 2);
   enqueue(5, 1);
   // printing
   printQueue();
   // getting queue size
   printf("Tamaño de la cola: %d\n", queueSize());
   // searching for an element in the queue
   printf("Buscando un elemento en la cola\n");
   findNode(3, 3);
   // dequeueing
   printf("Eliminando el elemento de hasta adelante\n");
   dequeue();
   printQueue();
   // deleting queue
   printf("Eliminando la cola\n");
   deleteQueue();
   printQueue();
}