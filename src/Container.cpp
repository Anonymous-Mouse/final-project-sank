#include "../header/Container.h"
#include "../header/Item.h"
#include <string>
#include <vector>

using namespace std;

Container::Container(vector<Item*> contents, string name, int maxItems, string password) {
    this->contents = contents;
    this->name = name; 
    this->maxItems = maxItems;
    this->locked = true;
    this->password = password;
}

bool Container::isLocked() {
    return locked;
}

bool Container::unlock(string password) {
    if (locked && password == this->password) {
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

Item* Container::getItemIndex(int index) {
    return &contents[index];
}

void Container::removeItemIndex(int index) {
    contents.erase(contents.begin() + index);
}

string Container::getName() {
    return name;
}