#include <iostream>
#include "Coches.h"
#include <chrono>
#include <thread>

using namespace std;


void finalTurno(COCHE& coche1, COCHE& coche2) {
	system("cls");
	cout << "RESULTADOS\n";
	cout << "===================================================\n";
	if (coche1.getDistance() > coche2.getDistance())
	{
		cout << "ENHORABUENA! HAS GANADO LA CARRERA!\n";
	}
	else if (coche1.getDistance() < coche2.getDistance())
	{
		cout << "VAYA, HAS PERDIDO!\n";
	}
	else if (coche1.getDistance() == coche2.getDistance())
	{
		cout << "BUENO, HABEIS EMPATADO!\n";
	}
	cout << "DISTANCIA TOTAL: \n";
	cout << "\n";
	cout << coche1.getName() << ": " << coche1.getDistance() << "\n";
	cout << "\n";
	cout << coche2.getName() << ": " << coche2.getDistance() << "\n";
	cout << "\n";
	system("pause");
	system("cls");





}
void turno(COCHE& coche1, COCHE& coche2) {
	int contadorTurno = 1;
	int contadorNitro = 0;
	string nitroResp;
	while (contadorTurno <= 5)
	{
		system("cls");
		cout << "TURNO " << contadorTurno << "\n";
		cout << "===================================================\n";


		if (contadorNitro == 0)
		{
			cout << "Quieres utilizar el nitro? (s/n) \n";
			cin >> nitroResp;
			if (nitroResp == "s")
			{

				coche1.setNitro();
				contadorNitro++;
			}
		}


		//COCHE1

		coche1.setSpeed(coche1.getSpeed(), coche1.tirarDado(), coche1.getNitro(), nitroResp);
		cout << "Velocidad actual de " << coche1.getName() << ": " << coche1.getSpeed() << "\n";
		coche1.setDistance(coche1.getDistance(), coche1.getSpeed());
		cout << "La distancia de " << coche1.getName() << " es de " << coche1.getDistance() << "\n";
		cout << "\n";
		system("pause");


		//COCHE2
		//desactivamos el nitro (dandole un valor de 3) para que el enemigo ni acierto ni falle el nitro ya que no lo puede utilizar
		nitroResp = "n";
		coche2.setSpeed(coche2.getSpeed(), coche2.tirarDado(), 3, nitroResp);
		cout << "Velocidad actual de " << coche2.getName() << ": " << coche2.getSpeed() << "\n";
		coche2.setDistance(coche2.getDistance(), coche2.getSpeed());
		cout << "La distancia de " << coche2.getName() << " es de " << coche2.getDistance() << "\n";
		cout << "\n";
		system("pause");
		contadorTurno++;

	}
	finalTurno(coche1, coche2);


}

int main()
{
	srand(time(NULL));
	int dado;
	int speed;
	
	string pName;
	cout << "BIENVENIDO A LA DRAG RACE!\n";
	cout << "===================================================\n";
	cout << "Cual es tu nombre?\n";
	cin >> pName;
	cout << "El coche contra quien compites es Max Verstappen\n";
	
	COCHE coche1 = COCHE(0, 0, 0, pName);
	//coche1.getParameters();
	pName = "Max Verstappen";
	COCHE coche2 = COCHE(0, 0, 0, pName);
	//coche2.getParameters();
	system("pause");
	this_thread::sleep_for(chrono::milliseconds(1000));
	turno(coche1, coche2);
}


