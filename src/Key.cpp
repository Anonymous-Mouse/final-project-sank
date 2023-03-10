#include "../header/Key.h"
#include "../header/Entity.h"

bool Key::use(Entity*){
    throw "Invalid usage of Key";
}


Key::Key(std::string Name): Item(Name){}