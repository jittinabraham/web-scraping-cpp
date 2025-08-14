#include "HtmlResponds.h"
#include "DeepCleaner.h"
#include <iostream>
#include <memory>

int main() {
    HtmlResponds fetcher;
    const std::string html = fetcher.fetch("https://www.indianspices.com/marketing/price/domestic/daily-price.html"); // replace with your URL
    //ssstd::cout << html << std::endl;
    //auto cleandata_for_small = createCleaner("cardamom","small cardamom",html);
    auto cleandata_for_large = createCleaner("cardamom","spice: large cardamom",html);
    cleandata_for_large->Cleaner();
    //cleandata_for_small->Cleaner(); 
    

    return 0;
}
