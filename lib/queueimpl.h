
#ifndef QUEUEIMPL_H
#define QUEUEIMPL_H

#include<iostream>

using namespace std;

template <class T>
Queue<T>::Queue()
{
	head=NULL;
	tail=NULL;

}

template <class T>
Queue<T>::~Queue()
{

}

template <class T>
void Queue<T>::enqueue (const T & item)
{
	QueueItem<T>* addQueue= new QueueItem<T>;
	addQueue->value=item;
	//cout<<"after addQueue->value=item;"<<endl;
     
    if(head==NULL)
    {
    	head=addQueue;
    	tail=addQueue;
    } 
    else
    {
    	//cout<<"in else"<<endl;
	    tail->next=addQueue;
		//cout<<"tail->next=addQueue;;"<<endl;
		addQueue->next=NULL;
		//cout<<"addQueue->next=NULL;item;"<<endl;
		tail=addQueue;
    }
	

}

  /* adds the item to the end of the queue.
     The same item may be added many times. */

template <class T>
void Queue<T>::dequeue ()
{
	if(head==NULL)
   {
   	throw EmptyQueueException();                 
   }

   else
   {
   	QueueItem<T> *temp1=head;
   	head=head->next;
   	delete temp1;
   }


  /* removes the front element of the queue. 
     Throws an EmptyQueueException when called on an empty queue.
     EmptyQueueException should inherit from std::exception. */
}
template <class T>
const T & Queue<T>::peekFront ()
{
   if(head==NULL)
   {
   	throw EmptyQueueException();                 
   }

   else
   {
    return head->value;
   }
  /* returns the front element of the queue. 
     Throws an EmptyQueueException when called on an empty queue.
     EmptyQueueException should inherit from std::exception. */
}
template <class T>
bool Queue<T>::isEmpty ()
{
  return head==NULL;
  /*
     if(head==NULL)
      {
        return true;
      }
      else
      {
        return false;
      }
    */

  /* returns whether the queue is empty. */
 }

#endif