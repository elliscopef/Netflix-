//hashimpl.h
#ifndef HASHIMPL_H
#define HASHIMPL_H

#include "hash.h"
#include <stdlib.h> 
#include <iostream>


  using namespace std;


    template <class T>
    Hash<T>::Hash()
    {
      //manually assign the size is 50
      HashList=new HashItem<T>[50];

      //manually assign the Model is 49
      M= 49;
      for(int a=0; a< 50;a++)
      {
        HashList[a].k=0;
        HashList[a].si=0;
      }

    }

   template <class T>
    Hash<T>::~Hash()
    {

    } 

   template <class T>
    void  Hash<T>::clear()
    {
      delete [] HashList;
      HashList=new HashItem<T>[50];
      for(int a=0; a< 50;a++)
      {
        HashList[a].k=0;
        HashList[a].si=0;
      }


    }

   template <class T>
   bool Hash<T>::find(string username)
   {
    int temp=getIndex_find(username);
    if (temp!=-1)
    {
      return true;
    }
    else
    {
      return false;
    }
   }    


   template <class T>
   T Hash<T>::get(string username)
   {
    int temp1=getIndex_find(username);
    return HashList[temp1].value;
   }  

   template <class T>
   void Hash<T>::add(string username,T value)
   {
    //find the index using the index function 
    int index=getIndex_add(username);

    HashList[index].value=value;
    HashList[index].name=username;
    HashList[index].si=1;
    HashList[index].k=getAscII(username);
   }

   template <class T>
   void Hash<T>::remove(string username)
   {
    int temp3=getIndex_find(username);

    HashList[temp3].value=NULL;
    HashList[temp3].name.clear();
    HashList[temp3].si=0;
    HashList[temp3].k=0;
   }
   
   template <class T>
   int Hash<T>::getAscII(string input)
   {
    int s0=0;
    int input_size=input.size();
    for(int r=0;r<input_size-1;r++)
        {
          s0+=input[r]; 
        }
    return s0;
   }

   template <class T>
   int Hash<T>::getIndex_add(string input)
   {
    int s1=getAscII(input);
    // cout<<s1<<endl;
     int sum=0;
     int adr=s1%M;  

     int d=adr;
      if(HashList[adr].si==0)     //no conflicts
      {
        return adr;
      }
      else   //冲突 
      { 
       while (HashList[d].k!=0)
       {
        //ACII
        cout<<"test"<<endl;
        d=(d+s1%10+1)%M;   //Probing  
        sum=sum+1;                     
       };
        return d;
      }
    }


    template <class T>
    bool Hash<T>::isEmpty(int temp)
    {
      if(HashList[temp].si==1)
      {
        return false;
      }
      else
      {
        return true;
      }
    }

    template <class T>
    HashItem<T> Hash<T>::getHashList(int index)
    {
 
      return HashList[index];
    }

    template <class T>
     int Hash<T>::getM()
     {
      return M;
     }

    template <class T>
   int Hash<T>::getIndex_find(string input)
   {

    int e=-1;
    int s1=getAscII(input);

    int adr=s1%M;
  
    int d= adr;
    int sum=1;


    if(HashList[adr].k==s1)          //three conditions
     {
      
        return d;
     }
    else if (HashList[adr].k==0) 
     {
      return e;
     } 
    else
      {  
        //cout<<"get in else"
        int g=0;
        while(g==0)
        {
         d=(d+s1%10+1)%M;       //Probing                    
         sum=sum+1;
         if(HashList[d].k==0)
         {
          g=1;     
          return e;
         }
         if(HashList[d].k==s1)
         {
          g=1; 
          return d;
         }
        }   
      } 
     return d;
   }

#endif