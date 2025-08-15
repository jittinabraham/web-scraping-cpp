#ifndef DEEPCLEARNER_H
#define DEEPCLEARNER_H
#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
class DeepCleaner {

    
public:
    std::string marquee_data;
    DeepCleaner(const std::string& marqueeContent) : marquee_data(marqueeContent) {}
    virtual ~DeepCleaner() = default;

    virtual std::string Cleaner() =0;
    virtual void ToJson() = 0;

};
class CardomomCleaner : public DeepCleaner {
    private:
    json data; //defines what data to be extracted small cardomom or large 
public:
    CardomomCleaner(const std::string& marqueeContent) 
            : DeepCleaner(marqueeContent){}
        
    std::string Cleaner() override;
    void ToJson() override ;
    

};



inline std::unique_ptr<DeepCleaner> createCleaner(const std::string& type,const std::string& cardtype) {
    if (type == "cardamom") {
        return std::make_unique<CardomomCleaner>(cardtype);
    } 
    else {
        throw std::invalid_argument("Unknown type! Note the program is now only configured for cardomom data: " + type);
    }
}
#endif

