#define CONTAINER_H_INCLUDED
#ifndef CONTAINER_H_INCLUDED
#include <string>
#include <array>

using namespace std;

class Container {
public:
    Container(vector<Item> contents, string name);
    Container(vector<Item> contents, string name, string key);
    bool isLocked();
    int getContentsAmount();
    void getItemIndex(int);
    void removeItemIndex(int);
    void getName(int);

private:
    vector<Item> contents;
    string name;
    string key;
};
#endif