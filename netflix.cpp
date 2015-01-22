
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm> 
#include <stdio.h>
#include <ctype.h>
#include <cctype> 
#include "netflix.h"
#include <vector>



#include "lib/map.h"
#include "lib/mapimpl.h"
#include "lib/set.h"
#include "lib/setimpl.h"
#include "lib/hash.h"
#include "movie.h"
#include "movie.cpp"
#include "user.h"
#include "user.cpp" 



NetFlix::NetFlix()
{
	userfile="data/user.txt";
    moviefile="data/movie.txt";
    current_user=NULL;
    vector_pos=0;
}

Hash<Movie*> NetFlix::getMovieHash()
{
	return MovieHash;
}

string NetFlix::getMovieVector(int i)
{
	return MoviesList_search_by_keyword[i];
}

vector<string> NetFlix::getMovieVector()
{
	return MoviesList_search_by_keyword;
}


void NetFlix::read_user_info()
{
		   
		   string line;
		   stringstream ss;
		   string a;
		   string f_username;
		   string f_realname;
		   string f_realname1;
		   string f_realname2;
		   User* addUser=new User("temp1","temp2");
    	   string checkedOut_movie;

    	   string temp3;
    	   string temp4;

    	   string temp5;
    	   string temp6;
          
           string temp7;
    	   string temp8;

    	   string temp9;
    	   string temp10;


		   ifstream userinfo;
		   userinfo.open(userfile.c_str());
		  
		    //getline function to read the userfile
			   	while(getline(userinfo,line))
			   	{

                   ss.str("");
	    	       ss.clear();

		            ss<<line;
	                getline(ss,temp3,' ');
	                getline(ss,temp4);
	                //Identify user info by key words
			   	
			   		if(temp3=="BEGIN" && temp4=="QUEUE")
			   		{   
			   		   getline(userinfo,line);
			   		   string line1;
			   		   line1= line;
			   		   ss<<line;

			   		   getline(ss,temp5,' ');
			   		   getline(ss,temp6);

			   		   //start reading the queue movie
			   		   while(temp5!="END" && temp6!="QUEUE")
			   		   {	
			   		   	   cout<<line1<<endl;

		                   Movie* newMovie=new Movie(line1);
		                   addUser->movieQueue()->enqueue(newMovie);
		                   
		                   ss.str("");
			    	       ss.clear();
		                  
		                   getline(userinfo,line); 
		                  
		                   line1=line;

		                   ss<<line;
			   		       ss>>temp5;
			   		       ss>>temp6;   
			   		          
		               } 
			   		}
			   		else if(temp3=="NAME:")
			   		{	
						f_realname=temp4;

			   			ss.str("");
			    	    ss.clear();

				   		addUser=new User(f_username,f_realname);
				
			   		}

			   		else if(temp3=="MOVIE:")
			   		{
			   		   
	                   checkedOut_movie=temp4;
	                   Movie* checkout_new_movie=new Movie(checkedOut_movie);
				   	   addUser->rentMovie(checkout_new_movie);
	
			   		}

			   		else if(temp3=="BEGIN" && temp4!="QUEUE" && temp4!= "RATINGS")
			   		{
			   			f_username=temp4;
			   			ss.str("");
			    	    ss.clear();
			   		}
			   		
			   		else if(temp3=="BEGIN" && temp4=="RATINGS")
			   		{
			   		   cout<<"here in the begin and ratings"<<endl;
 
			   		   getline(userinfo,line);
			   		   string line2;
			   		   line2= line;
			   		   
			   		   ss<<line;

			   		   cout<<line2;
                       
			   		   ss>>temp9;
			   		   ss>>temp10;
         
			   		   cout<<temp9<<endl;
			   		   cout<<temp10<<endl;


			   		   	ss.str("");
			    	    ss.clear();


			   	
			   		   while(temp9!="END" && temp10!="RATINGS")
			   		   {	
			   		   	   cout<<"here in the end ratings"<<endl;
			   		   	   cout<<line2<<endl;

			   		   	   ss.str("");
			    	       ss.clear();

			   		   	   int rate_n;
			   		   	   string line3;
			   		   	   string temp_3;

			   		   	   ss<<line2;
			   		   	   ss>>rate_n;
			 
			   		   	   cout<<rate_n<<endl;
			   		   	 
			   		   	   getline(ss,temp_3);
			   		   	   line3=temp_3.substr(1,temp_3.size()-2);
			   		   	   cout<<line3<<endl;
			  
                           Movie_rate_info* addMovie_rate_info=new Movie_rate_info(line3,rate_n);
			   		   	   addUser->getMovieRatingMap().add(line3,addMovie_rate_info);

		                   cout<<"after add"<<endl;
		                   ss.str("");
			    	       ss.clear();
		                  
		                   getline(userinfo,line); 
		                  
		                   line2=line;

		                   ss<<line;
			   		       ss>>temp9;
			   		       ss>>temp10;   
			   		          
		               }

			   		}
			   		else if(temp3=="END")
			   		{
			   			UserHash.add(f_username,addUser);

			   			//test to see if the use has been successfully added to the hash table
			   		}
		   		}
		   		cout<<line<<endl;
		   	
		   userinfo.close();//return user;			
}

void NetFlix::read_movie_info()                  //function that reads the movie data from the file
{

	string line;
	string a;

	string title;
	string keyword;
	string actor;

	ifstream movieinfo;

	movieinfo.open(moviefile.c_str());

			Movie* addMovie=new Movie("temp");
			//getline function to read the userfile
			while(getline(movieinfo,line))
				{   

				int begin = line.find("N");                           //Identify user info by key words
				int middle = line.find("D");
				int final = line.find("D");
				int actor=line.find("R");

				if(begin==4)
				{

				int space=line.find("          ");
				title=line.substr(6,space);
			
				addMovie=new Movie(title);

				}

				else if(middle==6)
				{

				int temp1=line.find("          ");
				keyword=line.substr(9,temp1);
				addMovie->addKeyword(keyword);

				}
				else if(actor==4)
				{
				int temp1=line.find("          ");
				keyword=line.substr(6,temp1);
				addMovie->addActor(keyword);
				}

				else if(final==2)
				{

				
				//add to the movie hash table right now
				MovieHash.add(title,addMovie);
				continue;
				}
			}
		
				movieinfo.close();
				
}


Hash<Movie*> NetFlix::getKey_QuerySet()
{
   return key_querySet;
}


User* NetFlix::getCurrentUser()
{
	return current_user;
}

bool NetFlix::user_exist(string username)
{
	cout<<"Checking User: "<<username<<endl;
	current_user=UserHash.get(username);

	return UserHash.find(username);
}

void NetFlix::return_movie(int movie_rate_num)
{
	current_user->returnMovie(movie_rate_num);
}


void NetFlix::new_user(string a, string b)
{

    User* addUser1=new User(a,b);
    
    UserHash.add(a,addUser1);
}

bool NetFlix::if_movie_exist(string e)
{
	if(MovieHash.find(e))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Movie* NetFlix::search_by_title(string f)
{
	
   if(MovieHash.find(f))
   {
   	 return MovieHash.get(f);
   }
   else 
   {
   	return NULL;
   }

}

bool NetFlix::keyword_find_in_movie(string moviename,string keyword)
{
	if(MovieHash.get(moviename)->getAllKeywords().find(keyword))
		{
			return true;
		}
	else if(MovieHash.get(moviename)->getAllActors().find(keyword))
		{
			return true;
		}
	else
		{
			return false;
		}
}

int NetFlix::if_keyword_exist(string keyword)
{
	int a=0;
	if(MovieHash.find(keyword))
	{
		a=1;
		return a;
	}
	else
	{
		
		for(int g=0; g<MovieHash.getM();g++)
	   {
	   	
	 
	   	if(!MovieHash.isEmpty(g))
	   	{
	   		if(keyword_find_in_movie(MovieHash.getHashList(g).value->getTitle(),keyword))
			{
				
				a=2;
				return 2;
			}
	   	}		
	   }
	}
	return a;
	        //if a==0; Not exist;
			//   a==1;  is title
			//   a==2; is keyword
		    
}


void NetFlix::search_by_keywords(string keyword)
{
	MoviesList_search_by_keyword.clear();
	key_querySet.clear();
	//condition that the keyword is title
	if(MovieHash.find(keyword))
	{	
		//MovieHash.get(keyword)
		key_querySet.add(keyword,MovieHash.get(keyword));
		MoviesList_search_by_keyword.push_back(keyword);
	}
	else
	{
     
     //condition that the keyword is in the movie's keyword
		for(int g=0; g<MovieHash.getM();g++)
	   {
	   		if(!MovieHash.isEmpty(g))
	   	{
			if(keyword_find_in_movie(MovieHash.getHashList(g).value->getTitle(),keyword))
			{
				key_querySet.add(MovieHash.getHashList(g).value->getTitle(),MovieHash.getHashList(g).value);
				MoviesList_search_by_keyword.push_back(MovieHash.getHashList(g).value->getTitle());
			}
		}
	   }
	}
	
}



string NetFlix::FrontOfQueue()
{  
	string temp6;
   try{temp6=current_user->movieQueue()->peekFront()->getTitle();}
		catch(EmptyQueueException){
		   			temp6="No Movie";
		   		}
   return temp6;
}

void NetFlix::delete_from_queue()
{
	try{current_user->movieQueue()->dequeue();}
	    catch(EmptyQueueException)
	    {	
	    }
}

void NetFlix::writeout_file()
{
	ofstream ofile;
    
    string filename = "data/user.txt";
    ofile.open(filename.c_str());

    for(int num=0; num<UserHash.getM();num++)
    {
    	  if(!UserHash.isEmpty(num))
    	  {
    	  	User* user_w = UserHash.getHashList(num).value;

    	   ofile<<"BEGIN "<<user_w->getID()<<endl;
           ofile<<"NAME:"<<user_w->getName()<<endl;
           Movie* tempMov = user_w->currentMovie();
           Queue<Movie*>* tempQue = user_w->movieQueue();

		    ofile<<"MOVIE: ";
		    if (tempMov!=NULL) {
		        ofile<<tempMov->getTitle();
		    }
		    ofile<<endl;
		    ofile<<"BEGIN QUEUE"<<endl;
		    while (tempQue->isEmpty()!=true) {
		        ofile<<tempQue->peekFront()->getTitle()<<endl;
		        tempQue->dequeue();
		    }
		    ofile<<"END QUEUE"<<endl;
		    
		    ofile<<"BEGIN RATINGS"<<endl;
		    for(int p=0; p<getMovieHash().getM();p++)
		    {
		    	if(!getCurrentUser()->getMovieRatingMap().isEmpty(p))
		    	{
		    		ofile<<getCurrentUser()->getMovieRatingMap().getHashList(p).value->getMovieRating_rate()<<" "<<getCurrentUser()->getMovieRatingMap().getHashList(p).value->getMovieRating_title()<<endl;
		    	}
		    }
		    ofile<<"END RATINGS"<<endl;
		    ofile<<"END"<<endl;
    	  }
    }
 
    ofile.close();
}