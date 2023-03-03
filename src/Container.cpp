#include "Container.h"
#include "LockedContainer.h"
#include "LockedRoom.h"
#include <string>
#include <vector>

using namespace std;

Container::Container(vector<Item> contents, string name, int maxItems) {
    this->contents = contents;
    this->name = name; 
    this->maxItems = maxItems;
    this->locked = true;
}

bool Container::isLocked() {
    return locked;
}

bool Container::unlock(string key) {
    if (locked && key == this->key) {
        locked = false;
        return true;
    }
    else {
        return false;
    }
}

int Container::getContentsAmount() {
    return contents.size();
}

Item Container::getItemIndex(int index) {
    return contents[index];
}

void Container::removeItemIndex(int index) {
    contents.erase(contents.begin() + index);
}

string Container::getName() {
    return name;
}