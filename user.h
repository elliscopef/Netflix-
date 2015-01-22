      //user.h

    #ifndef USER_H
    #define USER_H

    using namespace std;

    #include<iostream>
    #include<string>
    #include<cstring>
    #include"lib/queue.h"
    #include "hash.h"


    class  Movie_rate_info  
    {  
    public:
        Movie_rate_info(string a,int b)
        {
          movie_name=a;
          rate_int=b;
        }
        ~Movie_rate_info()
        {

        }
        string getMovieRating_title()
        {
          return movie_name;
        }
        int getMovieRating_rate()
        {
          return rate_int;
        }
        void setMovieRating(int temp)
        {
          rate_int=temp;
        }
        

      private:
        int rate_int;      //rating
        string movie_name;   //movie name 
    };


    class User {
      public:
        User (string ID, string name);  
        /* constructor that generates a user with the given name and ID.
           While multiple users may have the same name, the ID should be unique
           (e.g., an e-mail address), so that users can log in with it. */

        User (const User & other); // copy constructor

        ~User ();            // destructor

        string getID () const;    // returns the ID associated with this user

        string getName () const;  // returns the name associated with this user

        Queue<Movie*> * movieQueue (); 
        /* returns a pointer to the user's movie queue.
           This is the easiest way to ensure that you can modify the queue.
           (If you return by reference, that's also possible, but you'd need
           to be very careful not to invoke any deep copy constructors or
           assignments. A pointer is thus safer.) */

        void rentMovie (Movie *m);
        /* sets the user's currently rented movie to m.
           If the user already has a movie checked out, then it does nothing.
           (So no overwriting the current movie.) */

        void returnMovie (int movie_rate_num);
        /* returns the movie that the user currently has checked out.
           Does nothing if the user doesn't currently have a movie. */

        Movie* currentMovie ();
        /* returns the user's current checked out movie.
           Returns NULL if the user has no movie checked out. */
         Hash<Movie_rate_info*> getMovieRatingMap();
        

        bool rent_movie_rated();
    
       

        private:
        	string id;
        	string fullname;
          Movie* checkedOutMovie;
          Hash<Movie_rate_info*> MovieRating1;
          //Map<string,int>* MovieRating;
          Queue<Movie*>* moviesQueue;
        // you get to decide what goes here.
    };
    //User samir;
    //samir.rentMovie(movies.get("NAME OF MOVIE"));

    #endif