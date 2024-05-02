#pragma once
#include <iostream>
using namespace std;
class COCHE
{
	private:
		int speed;
		int distance;
		int nitro;
		string name;
	
	public:
		COCHE(int pSpeed, int pDistance, int pNitro, string pName);
		int tirarDado();
		void setSpeed(int pSpeed, int dado, int nitro, string pNitroResp);
		int getSpeed();
		string getName();
		void setDistance(int distance, int speed);
		int getDistance();
		int getNitro();
		void setNitro();
		void getParameters();

		
};