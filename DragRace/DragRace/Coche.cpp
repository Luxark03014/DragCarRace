#include "Coches.h"
#include <chrono>
#include <thread>

COCHE::COCHE(int pSpeed, int pDistance, int pNitro, string pName) {
	speed = pSpeed;
	distance = pDistance;
	nitro = pNitro;
	name = pName;
}

int COCHE::tirarDado() {
	int dado;

	cout << "Tirando el dado . . .\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
	dado = 1 + rand() % 6;
	cout << "DADO TIRADO: " << dado << "\n";
	return dado;

}
void COCHE::setSpeed(int pSpeed, int dado, int nitro, string pNitroResp) {
	
	speed += dado;
	if (pNitroResp =="s")
	{
		if (nitro == 1)
		{
			cout << "HAS UTILIZADO CORRECTAMENTE EL NITRO! Doblas tu velocidad\n";
			speed *= 2;
		}
		else if (nitro == 0)
		{
			cout << "VAYA! HAS FALLADO EL NITRO! Tu velocidad se reduce a la mitad\n";
			speed /= 2;

		}

	}
	
}
int COCHE::getSpeed() {
	return speed;
}
string COCHE::getName() {
	return name;
}
void COCHE::setDistance(int pDistance, int pSpeed) {
	distance =  pDistance + pSpeed * 100;

}
int COCHE::getDistance() {
	return distance;
}
int COCHE::getNitro() {
	return nitro;
}
void COCHE::setNitro() {
	
	nitro = rand() % 2;
}
void COCHE::getParameters() {
	cout << "Nombre: " << name << " DISTANCIA: " << distance << " Nitro " << nitro << "\n";
}