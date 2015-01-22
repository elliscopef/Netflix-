  //movie.h


  #ifndef MOVIE_H
  #define MOVIE_H

  using namespace std;

  #include <iostream>
  #include <string>
  #include <cstring>
  #include "lib/set.h"
  #include "lib/setimpl.h"
  #include "lib/hash.h"



  class Movie {
    public: 
    
      Movie();
      Movie (string title);       // constructor for a movie with the given title

      Movie (const Movie & other);  // copy constructor

      ~Movie ();                  // destructor

      string getTitle() const;   // returns the title of the movie

      void addKeyword (string keyword); 
        /* Adds the (free-form) keyword to this movie.
           If the exact same keyword (up to capitalization) was already
           associated with the movie, then the keyword is not added again. */
      void addActor (string keyword);
      Hash<string> getAllKeywords () const;
      Hash<string> getAllActors() const;

      
    private:
    	string movie_name;
      Hash<string> keywords;
      Hash<string> actors;

  };


  #endif
