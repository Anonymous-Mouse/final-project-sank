#include <string>
#include "../header/Item.h"
#include "../header/Entity.h"

using namespace std;


string Item::getName(){
    return this->Name;
}

Item::Item(string Name){
    this->Name = Name;
}

bool Item::use(Entity*){
    return false;
}

virtual ItemTypes getType(){
    return ItemTypes::ITEM;
}

std::string Item::getTypeString(){
    return "Item";
}