#include "HtmlResponds.h"
#include <iostream>

int main() {
    HtmlResponds fetcher;
    std::string html = fetcher.fetch("https://www.indianspices.com/marketing/price/domestic/daily-price.html"); // replace with your URL
    //std::cout << html << std::endl;
    return 0;
}
