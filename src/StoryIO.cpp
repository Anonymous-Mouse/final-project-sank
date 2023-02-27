#include <iostream>
#include <string>
#include "../header/StoryIO.h"


int StoryIO::getInt(){
    std::string in = getString();
    if(in.length()==1 && isdigit(in.at(0))){
        return (static_cast<int>(in.at(0))-48);
    }else{
        *this << "Please enter a valid number!" << this->endl;
        return getInt();
    }
}
        
std::string StoryIO::getString(){
    std::string in;
    *(this->input) >> in;
    return in;
}


StoryIO::StoryIO(std::istream& input, std::ostream& output){
    this->input = &input;
    this->output = &output;
}




