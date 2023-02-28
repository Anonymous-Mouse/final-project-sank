#include "Container.h"
#include "LockedContainer.h"
#include <string>
#include <vector>

using namespace std;

Container(vector<Item> contents, string name) {
    this->contents = contents;
    this->name = name;
    this->locked = false;
}

Container(vector<Item> contents, string name, string key) {
    this->contents = contents;
    this->name = name;
    this->key = key; 
    this->locked = true;
}

bool isLocked() {
    return locked;
}

bool unlock(string key) {
    if (locked && key == this->key) {
        locked = false;
        return true;
    }
    else {
        return false;
    }
}

int getContentsAmount() {
    return contents.size();
}

Item getItemIndex(int index) {
    return contents[index];
}

void removeItemIndex(int index) {
    contents.erase(contents.begin() + index);
}

string getName() {
    return name;
}