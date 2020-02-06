#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>

using std::string;
using std::list;

class Site {                                               // creating a site object containing a string for url as well as a file size variable 
private:
    string url_ = "";
    size_t filesize_ = 0;


public:
    Site() = default;
    Site(string url, size_t filesize) : url_(url), filesize_(filesize){};

    void setUrl ( string url )  {url_ = url; }
    void setFilesize( size_t filesize ) {filesize_=filesize; }

    string getUrl() const {return url_;}
    size_t getFilesize () const {return filesize_;}

};
