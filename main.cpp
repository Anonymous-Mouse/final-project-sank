#include "../header/Story.h"
#include "../header/Level.h"
#include "../header/Room.h"
#include "../header/Item.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){

vector<vector<Room*>> Asylum = {
   { nullptr,           nullptr,            new Room("Exit"),       nullptr},
   { nullptr,           new Room("Hallway"), new Room("Reception"),       new Room("Broom Closet")},
   { nullptr,           new Room("Hallway"),        nullptr,          nullptr},
   { new Room("Cell2"), new Room("Hallway"),        nullptr,          nullptr},
   {    nullptr,        new Room("Hallway"), new Room("Hallway"),     nullptr},
   {    nullptr,          nullptr,           new Room("Cell"),         nullptr}

};

Level level(1, Asylum, {5,2});
StoryIO io(cin,cout);

Story MurderMenagerie("Murder Menagerie", &level);

MurderMenagerie.start(io);

}