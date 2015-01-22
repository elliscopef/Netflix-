    //movieimpl.cpp



    #ifndef MOVIEIMPL_H
    #define MOVIEIMPL_H

    using namespace std;

    #include<algorithm>
    #include<iostream>
    #include<string>   
    #include<cstring>
    #include"lib/set.h"
    #include"movie.h"


        Movie::Movie()      // constructor for a movie with the given title
        {
        }

        Movie::Movie(string title)      // constructor for a movie with the given title
        {
        	movie_name=title;
        }
     
        Movie::Movie (const Movie & other)  // copy constructor
        {
            
        	this->movie_name=other.movie_name;
        	this->keywords=other.keywords;

        }

        Movie::~Movie ()                 // destructor
        {

        }

        string Movie::getTitle () const   // returns the title of the movie
        {
        	return movie_name;
        }

        void Movie::addKeyword (string keyword)
        {
      
            this->keywords.add(keyword,keyword);
         
        }
        /* Adds the (free-form) keyword to this movie.
             If the exact same keyword (up to capitalization) was already
             associated with the movie, then the keyword is not added again. */
        void Movie::addActor (string keyword)
        {
            this->actors.add(keyword,keyword);
        }

        Hash<string> Movie::getAllKeywords () const
        {
           // cout<<"in the getAllKeywords functions"<<endl;
            return this->keywords;

        }
        Hash<string> Movie::getAllActors() const
        {
            return this->actors;
        }
        
        //we can use this one to reture the keywords by value 
       

          /* Returns a set of all keywords associated with the movie. */




    #endif