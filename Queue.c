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
      printf("Error: No se puede crear un elemento en la cola");
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
            element->next = currentNode;
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
      printf("Error: La cola esta vacia");
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
      printf("Eliminando %d", temp->value);
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
}

// 6. Saber si la cola está vacía
int queueIsEmpty()
{
   return (front == NULL) ? 1 : 0;
}

// 7. Encontrar el número de nodos en la cola con prioridades
int queueSize()
{
   int size = 0;
   struct node *currentNode = back;
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
      printf("La cola esta vacia");
      return;
   }
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
   enqueue(1, 1);
   enqueue(2, 2);
   enqueue(3, 3);
   enqueue(4, 2);
   enqueue(5, 1);
   printQueue();
}