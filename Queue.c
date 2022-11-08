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

int queueIsEmpty()
{
   return (front == NULL) ? 1 : 0;
}