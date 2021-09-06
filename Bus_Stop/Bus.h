#pragma once
#include<string>
#include<iostream>
#include<queue>
#include<Windows.h>

using namespace std;


class Bus
{
	int free;
	string numBus;
public:
	Bus(string n) :numBus(n) { free = rand() % 10; }
	void print()
	{
		cout << "Автобус          : " << numBus << endl;
		cout << "Свободных мест   : " << free << endl;
	}

	int getFree()const { return free; }
	void setFree(int f) { free = f; }

};


class Passenger
{
	int time = 0;

public:
	Passenger() {}
	int getTime()const { return time; }
	void setTime(int t) { time = t; }
};



class BusStop
{
	queue<Passenger> pass;
	queue<Bus> bus;
	int time_pass;
	int time_bus;

public:
	BusStop(int tp, int tb) :time_pass(tp), time_bus(tb) {}
	void logic();
	void addBus(Bus b) { bus.push(b); }

};

void BusStop::logic()
{
	int t = 0;
	while (true)
	{

		if (t % time_pass == 0)
		{
			pass.push(Passenger());
			cout << " Пассажиров на остановке : " << pass.size() << endl;
		}
		if (t % time_bus == 0)
		{
			cout << "Пассажиров на остановке : " << pass.size() << endl;
			bus.front().print();
			int free = bus.front().getFree();
			if (pass.size() <= free)
				free = pass.size();
			for (size_t i = 0; i < free; i++)
			{
				pass.pop();
			}
			cout << "Увезено пассажиров - " << free << endl;
			bus.front().setFree(rand() % 10);
			Bus b = bus.front();
			bus.pop();
			bus.push(b);
		}

		t++;
		Sleep(1000);
	}
}