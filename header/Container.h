#define CONTAINER_H_INCLUDED
#ifndef CONTAINER_H_INCLUDED
#include <string>

using namespace std;

class Container {
public:
    container(Item contents[], string name, int contentsAmmount);
    void getItemIndex(int);
    void removeItemIndex(int);
    void getName(int);

private:
    Item contents[];
    string name;
    int contentsAmount;
};
#endif