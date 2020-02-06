
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include "Site.h"

using std::string;
using std::list;
using namespace std;

class BrowserHistory {
public:
    BrowserHistory();                                               //constructor
    void visitSite(string url, size_t filesize);                    // function to visit new site
    void backButton();                                              // function to move to previous site in linked list
    void forwardButton();                                           // function to move to next site in linked list
    void readFile(string fileName);                                 // functino to read in a text file containing site information

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();
private:
    std::list<Site> mylist;                                             // creating doubly linked list
    list<Site>:: iterator nullnode = mylist.begin();                    // iterator for front of linked list
    list<Site>:: iterator iter1 = mylist.begin();                       // current site iterator
    list<Site>:: iterator iter2 = mylist.end();                         // iterator for end of linked list
};

BrowserHistory::BrowserHistory(){                                       // constructor
    Site *i = new Site;                                                 // creating new object of type Site
    i->setUrl("");                                                      // initilizing url as empty string
    i->setFilesize (0);                                                 // initilizing file size as 0
    mylist.push_front(*i);                                              // inserting Site object into the linked list
    iter1++;                                                            // incrementing the current site iterator
    nullnode++;                                                         // incrementing front of list iterator
}

void BrowserHistory::visitSite(string url, size_t filesize){
    if (iter1 !=iter2){                                                 // erasing all sites after current site
        mylist.erase(std::next(iter1),iter2);
    }
    Site *w= new Site;                                                  // creating new object of type Site
    w->setUrl(url);                                                     // assigning given url to Site object
    w->setFilesize (filesize);                                          // assigning given file size to Site object
    mylist.push_back(*w);                                               // inserting Site object to the end of the linked list
    iter1++;                                                            // incrementing current site iterator
}

void BrowserHistory::backButton(){
    if (iter1 != std::next(nullnode)){                                  // checking to see if previous sites exist
        iter1 --;                                                       // moving current site iterator to previous site in linked list
    }
}

void BrowserHistory::forwardButton(){
    if (iter1!= std::prev(iter2)){                                      // checking to see if next sites exist
        iter1++;                                                        // moving current site iterator to next site in linked list                                                      
    }
}

void BrowserHistory::readFile(string fileName){
    string var = "";                                                    // initializing string variable to read in from text file
    string url_from_file = "";                                          // intitializing variable for assigning url string
    size_t filesize_from_file;                                          // intitializing variable for assigning file size
    
    ifstream inFile; 
    inFile.open(fileName);                                              // opening text file
    while (inFile>>var){                                                // reading text file by word (seperated by whitespace)
            if (var == "visit"){                                        // identifying "visit" command
                inFile>> url_from_file;                                 // saving url from text file
                inFile>>filesize_from_file;                             // saving file size from text file
                visitSite(url_from_file,filesize_from_file);            // passing url and file size to the visitSite function   
            }
            else if(var == "back"){                                     // identifying "back" command
                backButton();                                           // calling backButton function to move back in linked list
            }
            else if (var =="forward"){                                  // identifying "forward" command
                forwardButton();                                        // calling forwardButton function to move forward in linked list
            }
    }
}

string BrowserHistory::currentUrl(){
    string urlReturn = iter1->getUrl();                                 // using current site iterator to return the current url from Site object in linked list
    return urlReturn;
}

size_t BrowserHistory::currentPageSize(){
    size_t pageSizeReturn = iter1->getFilesize();                       // using current site iterator to return the current file size from Site object in linked list
    return pageSizeReturn;
}

size_t BrowserHistory::getHistoryLength(){
    int sz = mylist.size() - 1;                                         // returning size of linked list using .size() function minus one for empty Site at front 
    return sz;
}
