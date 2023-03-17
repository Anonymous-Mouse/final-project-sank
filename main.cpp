#include "../header/Story.h"
#include "../header/Level.h"
#include "../header/Room.h"
#include "../header/Item.h"
#include "../header/Enemy.h"


#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
Enemy* ruthlessRat = new Enemy("Ruthless Rat", 45, 15, 13, 1);
Enemy* causticRoach = new Enemy("Caustic Cockroach", 35, 17, 20, 1);
Enemy* heinoushornet = new Enemy("Heinous Hornet", 42, 14, 7, 1 );

vector<vector<Room*>> Asylum = {
   { nullptr,                           nullptr,                            new Room("Exit"),       nullptr},
   { nullptr,                           new Room("Hallway"),                new Room("Reception"),  new Room("Broom Closet")},
   { nullptr,                           new Room("Hallway", causticRoach, 90),  nullptr,          nullptr},
   { new Room("Cell2", heinoushornet, 100), new Room("Hallway"),                nullptr,          nullptr},
   {    nullptr,                        new Room("Hallway", ruthlessRat, 100), new Room("Hallway"),  nullptr},
   {    nullptr,                        nullptr,                            new Room("Cell"),      nullptr}

};

Level* level = new Level(1, Asylum, {5,2});
StoryIO io(cin,cout);

Story MurderMenagerie("Murder Menagerie", level);

MurderMenagerie.start(io);

}