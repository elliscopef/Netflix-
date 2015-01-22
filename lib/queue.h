//Queue.h

#ifndef QUEUE_H
#define QUEUE_H



class EmptyQueueException{};
class WrongInputException{};

template <class T>
struct QueueItem
{
  T value;
  QueueItem<T>* next;
};

template <class T>
class Queue {
  public:
    

    Queue();
    ~Queue();

    void enqueue (const T & item);
      /* adds the item to the end of the queue.
         The same item may be added many times. */

    void dequeue (); 
      /* removes the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */

    const T & peekFront ();
      /* returns the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */

    bool isEmpty ();
      /* returns whether the queue is empty. */
  private:
    QueueItem<T>* head,*tail;
};

#include"queueimpl.h"
#endif
