#include "DeepCleaner.h"

#include <stdexcept>
#include <iostream>
#include <nlohmann/json.hpp>
#include <regex>
#include <map>
#include <fstream>
using json = nlohmann::json;
int writeToJson(const json& data, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return -1; // Indicate failure
    }
    file << data.dump(4); // Pretty print with 4 spaces
    file.close();
    return 0; // Indicate success
}





std::string CardomomCleaner::Cleaner() {
    int pos = 0;

    std::transform(marquee_data.begin(), marquee_data.end(), marquee_data.begin(), ::tolower);
 
    marquee_data= std::regex_replace(marquee_data, std::regex("<a[^>]*>", std::regex::icase), ""); // Remove HTML tags
    marquee_data = std::regex_replace(marquee_data, std::regex("</a>", std::regex::icase), ""); // Remove remaining HTML tag


    marquee_data=marquee_data.substr(325,-1);
   
    return marquee_data; // Placeholder, replace with actual cleaning logic
}   
void CardomomCleaner::ToJson() {
     json result = json::array(); // store multiple <b> blocks

    std::regex bTagRegex("<b>(.*?)</b>", std::regex::icase);
    auto bBegin = std::sregex_iterator(marquee_data.begin(), marquee_data.end(), bTagRegex);
    auto bEnd   = std::sregex_iterator();

    size_t lastPos = 0;

    for (auto it = bBegin; it != bEnd; ++it) {
        std::smatch match = *it;
        std::string parent = match[1]; // text inside <b>...</b>
        
        // Find the section after </b> until next <b> (or end)
        size_t start = match.position() + match.length();
        size_t stop  = (std::next(it) != bEnd) ? (*std::next(it)).position() : marquee_data.size();
        std::string block = marquee_data.substr(start, stop - start);

        // Parse key:value pairs inside block
        std::regex kvRegex("([a-zA-Z0-9 ()./-]+):\\s*([^,]+)", std::regex::icase);
        auto kvBegin = std::sregex_iterator(block.begin(), block.end(), kvRegex);
        auto kvEnd   = std::sregex_iterator();

        json child;
        for (auto kv = kvBegin; kv != kvEnd; ++kv) {
            std::string key   = (*kv)[1];
            std::string value = (*kv)[2];
            // trim spaces
            key.erase(0, key.find_first_not_of(" \n\r\t"));
            key.erase(key.find_last_not_of(" \n\r\t")+1);
            value.erase(0, value.find_first_not_of(" \n\r\t"));
            value.erase(value.find_last_not_of(" \n\r\t")+1);
            child[key] = value;
        }

        result.push_back({ { parent, child } });
    }
  
  data = result; // Store the JSON data in the class member
  writeToJson(data, "cardomom_data.json"); // Write to file
  
  return void();
}