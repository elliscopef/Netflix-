 #ifndef MAP_H
 #define MAP_H


  
class NoSuchElementException{};
class LastElementException{};

template <class KeyType, class ValueType>

struct MapItem
{
  KeyType key;
  ValueType value;
  MapItem<KeyType, ValueType> *prev, *next;
};



template <class FirstType, class SecondType> 
struct Pair {
   FirstType first;
   SecondType second;

   Pair (FirstType first, SecondType second)
      { this->first = first; this->second = second; }
   // we're very nice and give you this piece of difficult code for free :-P
};
template <class KeyType, class ValueType>
class Map {


  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */
   MapItem<KeyType,ValueType> *head, *tail;

    
     

   public:
    Map ();  // constructor for a new empty map

    Map (const Map<KeyType, ValueType> & other);

    ~Map (); // destructor

    int size () const ;// returns the number of key-value pairs
    
    void add (const KeyType & key, ValueType & value);
   

    void remove (KeyType & key);
  

    ValueType & get (const KeyType & key) const;

    //ValueType get Map (const Map<KeyType, ValueType> & other); 
    //(KeyType & key, bool & success) const;
    
    
     /* Returns the value associated with the given key.
        If the key existed in the map, success should be set to true.
        If the key has no association, it should set success to false. */

    void merge (const Map<KeyType, ValueType> & other);
    
     /* Adds all the key-valufe associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */


    //function from project part 1

    Map<KeyType, ValueType>& operator=(const Map<KeyType, ValueType> &other);

    void printAll () const;

     class Iterator {
         /* add any constructors that you feel will be helpful,
            and choose whether to make them public or private. */
    
        private:

        const Map<KeyType, ValueType> *whoIBelongTo;

        MapItem<KeyType, ValueType> *current;

      
       

        public:
           
           Iterator();
           //supposed to be in the private
           //make the friend access
           Iterator(const Map<KeyType, ValueType> *s,  MapItem<KeyType, ValueType> *p);

           Pair<KeyType, ValueType> operator* () const;
              // return the current (key, value) pair the iterator is at

           typename Map<KeyType,ValueType>::Iterator operator++ () ;
              // advances the iterator (pre-increment)

           Map<KeyType,ValueType>::Iterator operator= (const Map<KeyType,ValueType>::Iterator & other);
              // assigns the other iterator to this iterator and returns this

           bool operator== (const Map<KeyType,ValueType>::Iterator & other) const;
              // returns whether this iterator is equal to the other iterator

           bool operator!= (const Map<KeyType,ValueType>::Iterator & other) const;
              // returns whether this iterator is not equal to the other iterator

           /* Optionally, if you think that it makes your code easier to write,
              you may also overload other operators: */

           /* You may define a public copy constructor and/or default constructor
              if you think it would be helpful. */
     };

     Map<KeyType,ValueType>::Iterator begin () const;
       // returns an iterator initialized to the first element

     Map<KeyType,ValueType>::Iterator end () const;
       /* returns an iterator initialized past the last element,
          to designate that the end of the map has been reached. */
};
 #endif
#include"mapimpl.h"