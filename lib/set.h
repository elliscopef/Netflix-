
    #ifndef SET_H
    #define SET_H


#include<iostream>
#include"map.h"



template <class T>
class Set {
   // all the private and public stuff you had before, except first() and next()
   private:
      Map<T, T> internalStorage;
      

   public:

     Set ();  // constructor for a new empty set

      Set (const Set<T> & other);

      ~Set (); // destructor

      int size () const; // returns the number of elements in the set

      void add (T & item); 
        /* Adds the item to the set.
           If the item is already in the set, it should do nothing.
        */

      void remove (T item);
       /* Removes the item from the set.
          If the item was not in the set, it should do nothing. */

      bool contains (T item) const;
       /* Returns whether the item is in the set. */

      void merge (const Set<T> & other);
       /* Adds all elements of other to this set. 
          However, will not create duplicates, i.e., it ignores elements
          already in the set. */

          
      void printAll () const;


      Set<T> setUnion (const Set<T> & other) const;

      Set<T> setIntersection (const Set<T> & other) const;

     class Iterator {
         /* add any constructors that you feel will be helpful,
            and choose whether to make them public or private. */


        private:

        const Set<T> *whoIBelongTo;

        typename Map<T,T>::Iterator iterator1;

         public:
            Iterator();
           T operator* () const;
              // return the item the iterator is at

           typename Set<T>::Iterator operator++ ();
              // advances the iterator (pre-increment)

           //make it private
           //make it friend access to the Set
           Iterator(Set<T> *b,typename Map<T,T>::Iterator iter);

           typename Set<T>::Iterator operator= (const Set<T>::Iterator & other);
              // assigns the other iterator to this iterator and returns this

           bool operator== (const Set<T>::Iterator & other) const;
              // returns whether this iterator is equal to the other iterator

           bool operator!= (const Set<T>::Iterator & other) const;
              // returns whether this iterator is not equal to the other iterator

           /* Optionally, if you think that it makes your code easier to write,
              you may also overload other operators: */

           /* You may define a public copy constructor and/or default constructor
              if you think it would be helpful. */


     };

         Set<T>::Iterator begin () ;
       // returns an iterator initialized to the first element

         Set<T>::Iterator end () ;

         Set<T> & operator=(const Set<T> &other);
       /* returns an iterator initialized past the last element,
          to designate that the end of the map has been reached. */
};

 #endif
#include"setimpl.h"