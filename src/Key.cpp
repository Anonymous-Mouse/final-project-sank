#include "../header/Key.h"
#include "../header/Entity.h"
#include <cassert>
#include <string>

bool Key::use(Entity*){
    assert(false && "Key should not be used this way.");
    return false;
}

ItemTypes Key::getType(){
    return ItemTypes::KEY;
}

std::string Key::getTypeString(){
    return "Key";
}

std::string Key::getDescription(){
    return this->getTypeString() + " - Name: " + this->getName();
 }

Key::Key(std::string Name): Item(Name){}