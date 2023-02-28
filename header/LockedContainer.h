#define LOCKED_CONTAINER_H_INCLUDED
#ifndef LOCKED_CONTAINER_H_INCLUDED
#include <string>

using namespace std;

class LockedContainer {
public:
    LockedContainer(string password);
    bool unlock(string password);

private:
    bool locked;
    string password;

};
#endif