#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED
#include "../header/Item.h"
#include <string>
#include <array>

using namespace std;

class Container {
private:
    vector<Item*> contents;
    string name;
    int maxItems;
    string password;
    bool locked;

public:
    Container(vector<Item*> contents, string name, int maxItems, string password = "0");
    bool isLocked();
    bool unlock(string password);
    int getContentsAmount();
    int getMaxItems();
    Item* getItemIndex(int index);
    void removeItemIndex(int index);
    string getName();
    ~Container();
    
};
#endif