#ifndef __LAB2_H__
#define __LAB2_H__
#include <iostream>
const int TAMANHO = 16;
struct Queue
{  
  char fila[TAMANHO];
  int count;
  int inicio;
  int fim;
};

Queue Create()
{
  Queue queue = {{},0,0,0};
  return queue;
}

bool Enqueue(Queue &queue, char value)
{  
  if (queue.count == TAMANHO)
  {
    return false;
  }
  else
  {
    queue.fila[queue.fim] = value;
    queue.count++;
    queue.fim++;
    if (queue.fim > TAMANHO-1)
    {
      queue.fim = queue.fim % TAMANHO;
    }
  }
  
  
  return true;
}

char Dequeue(Queue &queue)
{
  //muda o inicio
  if (queue.count == 0)
  {
    return '/0';
  }
  char obj = queue.fila[queue.inicio];
  queue.inicio++;
  if (queue.inicio > TAMANHO-1)
    {
      queue.inicio = queue.inicio % TAMANHO;
    }
  queue.count = queue.count-1;
  return obj;
}

char Front(Queue const queue)
{
  if (queue.count != 0)
  {
    return queue.fila[queue.inicio];
  }
  else
  {
    return '\0';
  }
}

int Size(Queue const queue)
{
  return TAMANHO;
}

int Count(Queue const queue)
{
  return queue.count;
}

bool IsEmpty(Queue const queue)
{
  if (queue.count==0)
  {
    return true;
  }
  else
  {
    return false;  
  }
}

void Clear(Queue &queue)
{
  queue = {{},0,0,0};
}
#endif
