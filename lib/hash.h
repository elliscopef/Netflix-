//hash.h
    #ifndef HASH_H
    #define HASH_H

    using namespace std;

    #include<iostream>
    #include<string>
    #include<cstring>




    template <class T>
    struct  HashItem  
    {  
        int k;      //ASCII
        int si;     //0 empty;1 taken
        T value;
        string name;   //username
    };


   template <class T>
    class Hash {
      public:
        Hash();
        ~Hash();  
        bool find(string username);   
        T get(string username); 
        void add(string username,T value);
        void remove(string username);
        bool isEmpty(int temp);
        HashItem<T> getHashList(int index);
        int getM();
        void clear();

      private:
           int M;
           HashItem<T>* HashList;
           int getAscII(string input);
           int getIndex_add(string input);
           int getIndex_find(string input);
        
    };


    #endif
    #include "hashimpl.h"