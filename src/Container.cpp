#include "../header/Container.h"
#include "../header/Item.h"
#include <string>
#include <vector>

using namespace std;

Container::Container(vector<Item*> contents, string name, int maxItems, string password) {
    this->contents = contents;
    this->name = name; 
    this->maxItems = maxItems;
    this->password = password;
    if(password == "0"){
        this->locked = false;
    }else{
        this->locked = true;
    }

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

int Container::getMaxItems(){
    return this->maxItems;
}

Item* Container::getItemIndex(int index) {
    if (index < contents.size()) {
        return contents[index];
    }
    else {
        return nullptr;
    }
}

void Container::removeItemIndex(int index) {
    contents.erase(contents.begin() + index);
}

string Container::getName() {
    return name;
}