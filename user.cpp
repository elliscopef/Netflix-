    //user.cpp


    using namespace std;

    #include<iostream>
    #include<string>
    #include<cstring>
    #include"user.h"




        User::User (string ID, string name)
        {
        	id=ID;
        	fullname=name;
          moviesQueue=new Queue<Movie*>();
           
          checkedOutMovie=NULL;
        } 
        /* constructor that generates a user with the given name and ID.
           While multiple users may have the same name, the ID should be unique
           (e.g., an e-mail address), so that users can log in with it. */

        User::User (const User & other) // copy constructor
        {
        	this->fullname=other.fullname;
        	this->id=other.id;

        }

        User::~User ()       // destructor
        {

        }

        string User::getID () const    // returns the ID associated with this user
        {
        	return id;

        }

        string User::getName () const  // returns the name associated with this user
        {
        	return fullname;

        }

        Queue<Movie*> * User::movieQueue ()
        {
            return moviesQueue;
        } 

         void User::rentMovie (Movie *m)
         {
            this->checkedOutMovie=m;
         }
        /* sets the user's currently rented movie to m.
           If the user already has a movie checked out, then it does nothing.
           (So no overwriting the current movie.) */

        void User::returnMovie (int movie_rate_num)
        {
            cout<<"in user return Movie"<<endl;
    
            cout<<movie_rate_num<<endl;
            if(checkedOutMovie!=NULL)
            {
                //MovieRating->get(checkedOutMovie->getTitle());
              if(!MovieRating1.find(checkedOutMovie->getTitle()))
              { 
                 if(movie_rate_num!=0)
                 {
                   Movie_rate_info* addMovie_rate_info= new Movie_rate_info(checkedOutMovie->getTitle(),movie_rate_num);
                   MovieRating1.add(checkedOutMovie->getTitle(),addMovie_rate_info);
                 }
               
              }

            
                checkedOutMovie=NULL;
            }
                        
        }
        /* returns the movie that the user currently has checked out.
           Does nothing if the user doesn't currently have a movie. */

        //bool to test if the rental movie has already been rated by the user
           bool User::rent_movie_rated()
        {
          if(checkedOutMovie!=NULL)
          {

            if(MovieRating1.find(checkedOutMovie->getTitle()))
            {
              return true;
            }
          }
           return false;
          
        }



         Hash<Movie_rate_info*> User::getMovieRatingMap()
         {
          return MovieRating1;
         }


        Movie* User::currentMovie ()
        {
            if(checkedOutMovie==NULL)
                {
      
                    return checkedOutMovie;
                }
            else
                {
                    return checkedOutMovie;
                }
        }
        /* returns the user's current checked out movie.
           Returns NULL if the user has no movie checked out. */
      