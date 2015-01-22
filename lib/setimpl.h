
#ifndef SETIMPL_H
#define SETIMPL_H

using namespace std;

#include <stdlib.h> 
#include<iostream>
#include<string>
#include<cstring>

#include"set.h"
#include"map.h"
#include"mapimpl.h"




	

template <class T>
Set<T>::Iterator::Iterator()
{

}

template <class T>
 T Set<T>::Iterator::operator* () const
{
//put ()
  return (*iterator1).first;

}

template <class T>
Set<T>::Iterator::Iterator(Set<T> *b,typename Map<T,T>::Iterator iter)
{
whoIBelongTo=b;
iterator1=iter;
}


template <class T>
typename Set<T>::Iterator Set<T>::begin () 
  {
 return (Set<T>::Iterator(this,internalStorage.begin()));
  }

template <class T>
typename Set<T>::Iterator Set<T>::end () 
  {
 return (Set<T>::Iterator(this,internalStorage.end()));
  }


template <class T>
typename Set<T>::Iterator Set<T>::Iterator::operator++ ()
{
   ++iterator1;
   return *this;
}


template <class T>
typename Set<T>::Iterator Set<T>::Iterator::operator= (const Set<T>::Iterator & other)
{
  this->iterator1=other.iterator1;
  return *this;
}
// assigns the other iterator to this iterator and returns this

template <class T>
bool Set<T>::Iterator::operator== (const Set<T>::Iterator & other) const
{
	return (iterator1==other.iterator1);

}
              // returns whether this iterator is equal to the other iterator
template <class T>
bool Set<T>::Iterator::operator!= (const Set<T>::Iterator & other) const
{
	return (iterator1!= (other.iterator1));
  //simplify
	//return (!(this->operator== (other)));
}
//implement the function

template <class T>
Set<T>::Set()
{
	
}

//deep copy of the Set
//Wait for check
template <class T>
 Set<T>::Set (const Set<T> & other)
 {

 this->internalStorage = other.internalStorage;
 
 }



template <class T>
Set<T>::~Set()
{
}

//use the size function in map
template <class T>
int Set<T>::size() const{

     return this->internalStorage.size();
}



//use the add function in map
template <class T>
void Set<T>:: add (T &item){
	
	this->internalStorage.add(item,item);
}


//use the remove function in map
template <class T>
void Set<T>::remove(T item)
{
	this->internalStorage.remove(item);
}

//use the get function in map
template <class T>
bool Set<T>:: contains(T item) const{

	try{
		this->internalStorage.get(item);
 	   }

    catch( NoSuchElementException & e )

       {
        return false;

       }
	
	return true;
}


 



template <class T>
void Set<T>::merge(const Set<T> & other)
{
	internalStorage.merge(other.internalStorage);
}

template <class T>
Set<T> Set<T>::setUnion (const Set<T> & other) const
{
	//Inialize a new Set and then merge Set<T> this and Set<T> other to that new set
	Set<T> unionSet;
	unionSet.merge(other);
	unionSet.merge(*this);
	return unionSet;
}

//Intersectin Function
template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const
{
	//initialize a Set to store the difference between Set this and the intersection between Set this and Set other.
	Set<T> Counter_IntersecSet;
	Counter_IntersecSet.merge(*this);
     
    MapItem<T,T> *intersec_tracker=other.internalStorage.first();
	while(intersec_tracker!=NULL)
	{
		Counter_IntersecSet.remove(intersec_tracker->key);
		intersec_tracker=intersec_tracker->next;
	}


    //initialize another Set to store the intersection of Set this and Set other.
    //By merge Set this and then remove the components from IntersecSet
    Set<T> IntersecSet1;
	IntersecSet1.merge(*this);


    MapItem<T,T> *intersec_tracker1=Counter_IntersecSet.internalStorage.first();
	while(intersec_tracker1!=NULL)
	{
		IntersecSet1.remove(intersec_tracker1->key);
		intersec_tracker1=intersec_tracker1->next;
	}

	return IntersecSet1;




}


template <class T>
Set<T> & Set<T>::operator=(const Set<T> &other)
 {
 	if(this == &other)
 	{
 		return *this;
 	}

 	this->internalStorage=other.internalStorage;
 	return *this;
 }



 template <class T> void Set<T>::printAll () const
{
	this->internalStorage.printAll();
}



#endif