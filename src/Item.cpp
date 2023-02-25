#include <string>
#include "../header/Item.h"

using namespace std;


string Item::getName(){
    return this->Name;
}

Item::Item(string Name){
    this->Name = Name;
}
