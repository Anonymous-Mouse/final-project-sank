#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED
#include <string>
#include <array>

using namespace std;

class Container {
public:
    Container(vector<Item*> contents, string name, int maxItems, string password);
    bool isLocked();
    bool unlock(string password;)
    int getContentsAmount();
    void getItemIndex(int);
    void removeItemIndex(int);
    void getName(int);

private:
    vector<Item*> contents;
    string name;
    int maxItems;
    string password;
    bool locked;

};
#endif