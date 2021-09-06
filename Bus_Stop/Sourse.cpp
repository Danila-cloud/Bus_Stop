
#include"Bus.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    BusStop bs(1, 6);
    bs.addBus(Bus("№1"));
    bs.addBus(Bus("№2"));
    bs.addBus(Bus("№3"));
    bs.addBus(Bus("№4"));
    bs.addBus(Bus("№5"));

    bs.logic();
}

