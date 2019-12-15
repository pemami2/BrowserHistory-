
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
    BrowserHistory();

    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();

    void readFile(string fileName);

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();

private:
    std::list<Site> mylist;
    list<Site>:: iterator nullnode = mylist.begin();
    list<Site>:: iterator iter1 = mylist.begin();
    list<Site>:: iterator iter2 = mylist.end();

};

BrowserHistory::BrowserHistory()
    {
    Site *i = new Site;
    i->setUrl("");
    i->setFilesize (0);
    mylist.push_front(*i);
    iter1++;
    nullnode++;

    }

void BrowserHistory::visitSite(string url, size_t filesize){
    if (iter1 !=iter2){
        mylist.erase(std::next(iter1),iter2);
    }

    Site *w= new Site;
    w->setUrl(url);
    w->setFilesize (filesize);
    mylist.push_back(*w);
    iter1++;
}

void BrowserHistory::backButton(){

    if (iter1 != std::next(nullnode)){
        iter1 --;
    }


    }



void BrowserHistory::forwardButton(){
    if (iter1!= std::prev(iter2)){
        iter1++;
    }
}

void BrowserHistory::readFile(string fileName)
{
    string var = "";
    ifstream inFile;
    string url_from_file = "";
    size_t filesize_from_file;
    inFile.open(fileName);
    while (inFile>>var){
            if (var == "visit")
            {
                inFile>> url_from_file;
                inFile>>filesize_from_file;
                visitSite(url_from_file,filesize_from_file);
            }
            else if(var == "back")
            {
                backButton();
            }
            else if (var =="forward")
            {
                forwardButton();

            }
    }
}

string BrowserHistory::currentUrl(){
    string urlReturn = iter1->getUrl();
    return urlReturn;
}

size_t BrowserHistory::currentPageSize(){
    size_t pageSizeReturn = iter1->getFilesize();
    return pageSizeReturn;
}

size_t BrowserHistory::getHistoryLength(){
    int sz = mylist.size() - 1;
    return sz;
}
