#ifndef NETFLIX_H
#define NETFLIX_H

#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm> 
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <cctype> 
#include <vector>
//#include <map>


#include"lib/map.h"
#include "lib/set.h"
#include "movie.h"
#include "user.h"
#include "lib/hash.h"

class NetFlix
{


private:
string userfile;
string moviefile;

Hash<Movie*> key_querySet;
vector<string> MoviesList_search_by_keyword;


User* current_user;

Hash<User*> UserHash;

Hash<Movie*> MovieHash;

public:

NetFlix();

int vector_pos;
Hash<Movie*> getKey_QuerySet();
User* getCurrentUser();
Hash<Movie*> getMovieHash();
string getMovieVector(int i);
vector<string> getMovieVector();

void read_user_info();
void read_movie_info();


bool user_exist(string username);

void login();

void new_user(string a, string b);

string FrontOfQueue();
void return_movie(int movie_rate_num);

void rent_movie();
void delete_from_queue();
void movie_to_back();

bool if_movie_exist(string e);
int if_keyword_exist(string t);
Movie* search_by_title(string f);
void search_by_keywords(string keyword);
bool keyword_find_in_movie(string moviename,string keyword);

void next_movie();
void add_to_queue();
void return_to_main();

void writeout_file();

};

#endif
