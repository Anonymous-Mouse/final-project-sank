#include <iostream>
#include <string>
#include "../header/StoryIO.h"


int StoryIO::getInt(){
    std::string in = getString();
    if(in.length()==1 && isdigit(in.at(0))){
        return static_cast<int>(in.at(0));
    }else{
        *this << "Please enter a valid number!" << this->endl;
        return getInt();
    }
}
        
std::string StoryIO::getString(){
    std::string in;
    std::cin >> in;
    return in;
}
        

    


