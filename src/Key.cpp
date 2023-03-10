#include "../header/Key.h"
#include "../header/Entity.h"
#include <cassert>

bool Key::use(Entity*){
    assert(false && "Key should not be used this way.");
    return false;
}


Key::Key(std::string Name): Item(Name){}