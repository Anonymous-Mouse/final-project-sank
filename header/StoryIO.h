#ifndef STORYIO_H
#define STORYIO_H

#include <iostream>
#include <string>

class StoryIO{
    public:
        const std::string endl = "\n";
        
        int getInt();
        
        std::string getString();
        
        template <typename T>
		StoryIO operator<<(T in){
    		std::cout << in;
    		return *this;
		}
    
};

#endif
