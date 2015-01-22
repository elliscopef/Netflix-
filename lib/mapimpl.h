
  #ifndef MAPIMPL_H
  #define MAPIMPL_H

  using namespace std;


  #include <stdlib.h> 
  #include<iostream>







template <class KeyType, class ValueType>
Map<KeyType,ValueType>::Iterator::Iterator()
{
}


template <class KeyType, class ValueType>
 Map<KeyType,ValueType>::Iterator::Iterator(const Map<KeyType, ValueType> *s, MapItem<KeyType, ValueType> *p)
 {
  whoIBelongTo = s; current = p;
 }



template <class KeyType, class ValueType>
typename Map<KeyType,ValueType>::Iterator  Map<KeyType,ValueType>::begin () const
 {
    return Map<KeyType,ValueType>::Iterator(this, head); 
 }


template <class KeyType, class ValueType>
typename Map<KeyType,ValueType>::Iterator  Map<KeyType,ValueType>::end () const
{
    return Map<KeyType,ValueType>::Iterator(this, NULL); 
}


template <class KeyType, class ValueType>
Pair<KeyType, ValueType>  Map<KeyType,ValueType>::Iterator::operator* () const
{

   return Pair<KeyType, ValueType> (current->key,current->value);
}

template <class KeyType, class ValueType>
typename Map<KeyType,ValueType>::Iterator  Map<KeyType,ValueType>::Iterator::operator++ () 
{
current = current->next;
return *this;

}

template <class KeyType, class ValueType>
typename Map<KeyType,ValueType>::Iterator Map<KeyType,ValueType>::Iterator::operator= (const Map<KeyType,ValueType>::Iterator & other) 

{
   current = other.current;
   whoIBelongTo = other.whoIBelongTo;
   return *this;
}

template <class KeyType, class ValueType>
bool Map<KeyType,ValueType>::Iterator::operator== (const Map<KeyType,ValueType>::Iterator & other) const
{
  return (current == other.current && whoIBelongTo == other.whoIBelongTo);
}

template <class KeyType, class ValueType>
bool Map<KeyType,ValueType>::Iterator::operator!= (const Map<KeyType,ValueType>::Iterator & other) const
{
   //return (!(this->operator== (other)));
   return !(*this == other);
   /*
   this == 0x537833;
   *this == an instance of the Iterator
   *(iterator) == pair
   */
}


 template <class KeyType, class ValueType>
    Map<KeyType, ValueType>::Map()
    { 
    head = NULL;
    tail = NULL; 
    }


  //deep copy
  template <class KeyType, class ValueType>
  Map<KeyType,ValueType>::Map (const Map<KeyType, ValueType> & other)
  {
    
    this->head=NULL;
    this->tail=NULL;
   //Create a pointer to loop through the item 
    MapItem<KeyType,ValueType>* temp;
    temp=other.head; 

    if(temp==NULL)
    {
      this->head=NULL;
      this->tail=NULL;
    }
    
    else
    { 
       while(temp!=NULL)
        {
        this->add(temp->key,temp->value);
        temp=temp->next;
       }
    }
   
  }


  template <class KeyType, class ValueType>
    Map<KeyType, ValueType>::~Map() // destructor
      { //initiliztion 
         MapItem<KeyType, ValueType> *a=head; 
         MapItem<KeyType, ValueType> *b=NULL;

        while(a!=tail)
        {
        	b=a->next;
        	delete a;
        	a=b;
        }
      }

  template <class KeyType, class ValueType>
  int Map<KeyType, ValueType>::size () const // returns the number of key-value pairs
      {   
        int size_counter=0;
        MapItem<KeyType, ValueType> *p=head;
        if(p==NULL)
        {
          return 0;
        }
        else
        {
          while(p!=NULL)
          {
            size_counter++;
            p=p->next;
          }
        }    
       	return size_counter;  
      }

  template <class KeyType, class ValueType>
  void Map<KeyType, ValueType>::add (const KeyType & key, ValueType & value)
     
      {        
      	  MapItem<KeyType, ValueType> *newItem=new MapItem<KeyType, ValueType>;
          newItem->key=key;
          newItem->value=value;
        
      	if(head==NULL)
      	{ 
      		head=newItem;                                                                                                                                         tail=newItem;
          newItem->prev=NULL;
          newItem->next=NULL;
     	}

      	else
      	{//check if the element has already existed in the Map
        try{get(key);}

        catch(NoSuchElementException)
         {      
            newItem->prev=tail;
      	    tail->next=newItem;
            newItem->next=NULL;
            tail=newItem;	    
      	 }
        }

  	}
    
        

  template <class KeyType, class ValueType>
  void Map<KeyType, ValueType>::remove (KeyType & key)
      {
        MapItem<KeyType,ValueType> *e;
        
        if(head==NULL)
        {
          return;
        }

        e=head;

        while(e!=NULL)
        {
       
          if(e->key==key)
          {
            //if the wanted key is at the last
            if(e->next==NULL)
            {
              e->prev->next=NULL;
              tail=e->prev;
              delete e;
            }
            //if the wanted key is in the beginning 
            else if(e-> prev ==NULL)
            {
              head=e->next;
              e->next->prev=NULL;

              delete e;
            }
            //when the wanted key is in the middle
            else
            {
              e->prev->next=e->next;
              e->next->prev=e->prev;
              delete e;
            }
	           return ;
          }
          e=e->next;
        }
        
        cout<<endl;

      }
       

  template <class KeyType, class ValueType>
   ValueType &  Map<KeyType,ValueType>::  get(const KeyType & key) const
      {
        
        MapItem<KeyType,ValueType> * temp;
      
          if (head == NULL) {
          
          cout<<"The head is NULL"<<endl;
          throw NoSuchElementException();
        }
        temp=head; 
        //When there is info in the map
        //Loop over the map to find the key

     
        while(temp!=NULL)
        {
            
          if(temp->key==key)
          {
            cout<<"The value attached to the key is ";
            cout<<temp->value<<endl;
            return temp->value;
          }
          else
          {
            temp=temp->next;
          }
         
        }
        throw NoSuchElementException() ;
      }





      //The function that merges "other" map with "map"
     template <class KeyType, class ValueType>
  void Map<KeyType, ValueType>::merge (const Map<KeyType, ValueType> & other)
      {
        //Initiate a pointer
        MapItem<KeyType,ValueType> * c;
        
        c=other.head;
        //loop through the elements in the other map and add the elements to the map
        while(c!=NULL)
        {
        
          add(c->key,c->value);
          //have already added the test existance functionality in the add function 
          c=c->next;
        }


      }
       /* Adds all the key-value associations of other to the current map.
          If both maps (this and other) contain an association for the same
          key, then the one of this is used. */
      

      //first function that resets the traversal to a "first" element of your data structure. 
     /* template <class KeyType, class ValueType>
       void Map<KeyType, ValueType>:: first()
      {
        track=head;
        if(track==NULL)
        {
          throw NoSuchElementException();
        }
       
      }
     */

      /*

      template <class KeyType, class ValueType>
      void Map<KeyType, ValueType>:: next()
      {
        if(track==NULL)
        {
          throw LastElementException();
        }

        track=track->next;
     
      }

      
      template <class KeyType, class ValueType>
      const ValueType & Map<KeyType, ValueType>:: getCurrentValue ()
      {
       
        if(track==NULL)
        {
          cout<<"track is NULL"<<endl;
        }
        return track->value;
      }
      
      template <class KeyType, class ValueType>
      const KeyType & Map<KeyType, ValueType>::getCurrentKey ()
      {
        
        return track->key;
      }
     */
    
     template <class KeyType, class ValueType>
     Map<KeyType, ValueType>& Map<KeyType, ValueType>::operator=(const Map<KeyType, ValueType> &other)
      {

        if(this == &other)
        {
          return *this;
        }

     

      MapItem<KeyType,ValueType>* temp;
       temp=other.head; 
       if(temp==NULL)
     {
       this->head=NULL;
       this->tail=NULL;
       return *this;
     }
     else
     {
       while(temp!=NULL)
     
     {
       this->add(temp->key,temp->value);
       temp=temp->next;
     }

     }
     
     return *this;
      }

    template <class KeyType, class ValueType> void Map<KeyType, ValueType>::printAll() const
  {
    MapItem<KeyType, ValueType> *iter = this->head;
    
    while (iter != NULL)
    {
      // if(iter->key!=iter->value)
      // {
        cout << iter->key << " : " << iter->value << endl;
        iter = iter->next;
      // }

      // else
      // {
      //   cout<<iter->key<<endl; 
      //   iter=iter->next;
      // }

    }
  }



#endif