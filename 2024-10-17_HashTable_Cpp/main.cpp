/*
 * Name: Kaci Craycraft
 * South Hills Username: kcraycraft45
 */

#include <algorithm>
#include <iostream>

#include "MyHashtable.h"

int main()
{
    Hashtable::MyHashtable<std::string, float> menu;

    menu.add("Pizza", 9.99f);
    menu.add("Burger", 5.99f);
    menu.add("Fries", 2.99f);
    menu.add("Soda", 1.99f);
    menu.add("Salad", 4.99f);
    menu.add("Steak", 12.99f);

    std::cout<<menu.toString()<<std::endl;


    std::cout<<"Count: "<<menu.getCount()<<std::endl;
    std::cout<<"Buckets: "<<menu.getCapacity()<<std::endl;
    std::cout<<"Price of burger: " << menu["Burger"] <<std::endl;

    return 0;
}
