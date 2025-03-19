#include <iostream>
#include "Geschwindikeit.h"
using namespace std;

Planet planets[] =
{
    {"Erde", 3.986e14, 6378.1},
   {"Venus", 3.24859e14, 6051.8},
    {"Mars", 4.28283e13, 3389.5},
    {"Jupiter", 1.26687e17, 69911},
    {"Saturn", 3.793e16, 58232},
};

int main()
{
    for(const auto& Planet : planets)
    {
       double HoffmanV = HohmannTransferGeschwindigkeit(Planet, 830, 690);
        //double HoffmanV = HohmannTransferGeschwindigkeit(Planet, 690, 830);
        std::cout << "Planet: " << Planet.name <<"\n";
        (cout << "Die HohmannTransferGeschwindigkeit ist: " << HoffmanV << " m/s\n\n");
    }

    double Masse = 400;
    double austrittsgeschwindigkeit = 2200;
    double DeltaEintritt = HohmannTransferGeschwindigkeit(planets[1], 585, 50);
    double Treibstoff = Treibstoffbedardf(DeltaEintritt, austrittsgeschwindigkeit, Masse); //wo ist hier das Problem?

    cout << "\n\nWiedereintritt bei der Erde: " << DeltaEintritt << "m/s\n";
    cout << "Treibstoffbedarf: " << Treibstoff << "kg\n";
    return 0;
}





