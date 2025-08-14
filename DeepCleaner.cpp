#include "DeepCleaner.h"
#include <memory>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
std::string CardomomCleaner::Cleaner() {
    int pos = 0;
    std::string result;
    std::transform(marquee_data.begin(), marquee_data.end(), marquee_data.begin(), ::tolower);
    std::vector<size_t> positions;
    while(pos!=std::string::npos) {
        positions.push_back(pos);
        pos = marquee_data.find(data, pos+1);
        std::cout<<pos<<std::endl;
        }
    
    for (int i = 0; i < positions.size()-1; ++i) {
        size_t start = positions[i]+data.length();
        size_t len =positions[i+1]-start ;
        result+= marquee_data.substr(start, len);
      
      }
    std::cout << result << std::endl;

    // Implement the cleaning logic for cardomom data
    return marquee_data; // Placeholder, replace with actual cleaning logic
}   