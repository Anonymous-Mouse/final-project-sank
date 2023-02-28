#include "LockedContainer.h"
#include <string>

LockedContainer(string password) {
    this->password = password;
    this->locked = true;
}

bool unlock(string password) {
    if (locked && password == this->password) {
        locked = false;
        return true;
    }
    else {
        return false;
    }
}

bool isLocked() {
    return locked;
}