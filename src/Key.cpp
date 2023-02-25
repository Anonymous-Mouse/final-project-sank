#include "../header/Key.h"

bool Key::use(Entity) override{
    throw "Invalid usage of Key"
}


Key::Key(std::string Name): Item(Name){}