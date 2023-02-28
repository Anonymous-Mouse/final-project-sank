#include "Container.h"
#include "LockedContainer.h"
#include <string>
#include <vector>

using namespace std;

Container::Container(vector<Item> contents, string name) {
    this->contents = contents;
    this->name = name;
    this->locked = false;
}

Container::Container(vector<Item> contents, string name, string key) {
    this->contents = contents;
    this->name = name;
    this->key = key; 
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