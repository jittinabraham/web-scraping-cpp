#ifndef DEEPCLEARNER_H
#define DEEPCLEARNER_H
#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>

class DeepCleaner {

    
public:
    std::string marquee_data;
    DeepCleaner(const std::string& marqueeContent) : marquee_data(marqueeContent) {}
    virtual ~DeepCleaner() = default;

    virtual std::string Cleaner() =0;

};
class CardomomCleaner : public DeepCleaner {
    private:
    std::string data; //defines what data to be extracted small cardomom or large 
public:
    CardomomCleaner(const std::string& marqueeContent,const std::string& cardomomtype) 
            : DeepCleaner(marqueeContent),data(cardomomtype){}
        
    std::string Cleaner() override;
};



inline std::unique_ptr<DeepCleaner> createCleaner(const std::string& type,const std::string& cardtype, const std::string& data) {
    if (type == "cardamom") {
        return std::make_unique<CardomomCleaner>(data,cardtype);
    } 
    else {
        throw std::invalid_argument("Unknown type! Note the program is now only configured for cardomom data: " + type);
    }
}
#endif

