#include <iostream>
#include <string>
#include <sstream>
#include "../StartGameMenu/header/Story.h"
#include "../StartGameMenu/header/StoryIO.h"

void Story::StartGameMenu() {
    std::ostringstream ostr;
    std::istringstream istr;
    StoryIO io(istr, ostr);

    io << "Mystery Menagerie" << io.endl;
    io << "1. New game" << io.endl;
    io << "2. Load game" << io.endl;
    io << "3. Options" << io.endl;

    int input = io.getDigit(3);

    if (input == 1) {
        //It would call a function to start a new game
    }

    if (input == 2) {
        //It would call some function that loads in a game from a previous save (saving this for the end because we might not implement it)
    }

    if (input == 3) {

        io << "Options: " << io.endl;
        io << "1. Change difficulty" << io.endl;
        io << "2. Instructions" << io.endl;
        io << "3. Back" << io.endl;

        io.getDigit(3);

        if (io.getDigit(3) == 1) {
            io << "Change Difficulty" << io.endl;
            io << "1. Easy mode" << io.endl;
            io << "2. Normal mode" << io.endl;
            io << "3. Hard mode" << io.endl;
            io << "4. Back" << io.endl;

            io.getDigit(4);

            if (io.getDigit(4) == 1) {
                //calls function to change difficulty accordingly
            }

            if (io.getDigit(4) == 2) {
                //calls function to change difficulty accordingly
            }

            if (io.getDigit(4) == 3) {
                //calls function to change difficulty accordingly
            }

            if (io.getDigit(4) == 4) {
                //this will bring the player back to the options menu
            }
        }

        if (io.getDigit(3) == 2) {
            //this will display the instructions to the game
        }

        if (io.getDigit(3) == 3) {
            //this will take the player back to the start menu
        }
    }
}