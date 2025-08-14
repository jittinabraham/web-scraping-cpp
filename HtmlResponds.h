#ifndef HTMLRESPONDS_H
#define HTMLRESPONDS_H

#include <string>
#include<iostream>
class HtmlResponds {
public:
    HtmlResponds() = default;
    ~HtmlResponds() = default;

    // Fetches the webpage and returns HTML as a string
    std::string fetch(std::string url);

private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
    std::string marquess_cleaner(std::string html) {
        // extract text in the <marquess> tag
  
        int start = html.find("<marquee");
        int end = html.find("</marquee>", start);
    
        
        return html.substr(start + 10, end - start - 10);
        
      
        
    }   
};
#endif
