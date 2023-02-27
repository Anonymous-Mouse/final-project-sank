#ifndef STORYIO_H
#define STORYIO_H

#include <iostream>
#include <string>

class StoryIO{

    private:
        std::istream* input;
        std::ostream* output;

    public:
        const std::string endl = "\n";
        
        int getInt();
        
        std::string getString();
        
        template <typename T>
		StoryIO operator<<(T in){
    		*(this->output) << in;
    		return *this;
		}

        StoryIO(std::istream& input, std::ostream& output);

};

#endif
