#include "LockedContainer.h"
#include <string>

LockedContainer::LockedContainer(string password) {
    this->password = password;
    this->locked = true;
}

bool LockedContainer::unlock(string password) {
    if (locked && password == this->password) {
        locked = false;
        return true;
    }
    else {
        return false;
    }
}

bool LockedContainer::isLocked() {
    return locked;
}