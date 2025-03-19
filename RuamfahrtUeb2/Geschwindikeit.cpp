//
// Created by user on 11/20/2024.
//

#include "Geschwindikeit.h"
#include <valarray>
#include <cstdio>
using namespace std;

double HohmannTransferGeschwindigkeit(const Planet& planet, double height1, double height2)
{
    double r1 = planet.radius * 1000 + height1 * 1000;
    double r2 = planet.radius * 1000 + height2 * 1000;

    double a = 0.5 * (r1 + r2);

    double VisVisaGeschwidikeit1 = sqrt(planet.GM * (2.0 / r1 - 1.0 / a));//visVisa
    double VisVisaGeschwindikeit2 = sqrt(planet.GM * (2.0 / r2 - 1.0 / a));

    double VisVisaKreisOrbit1 = sqrt(planet.GM / r1);
    double VisVisaKreisOrbit2 = sqrt(planet.GM / r2);

    double Geschwidikeit1 =VisVisaGeschwidikeit1 - VisVisaKreisOrbit1;//Hohmantransfer
    double Geschwidikeit2 =VisVisaKreisOrbit2 - VisVisaGeschwindikeit2;
    printf("Geschwindikgkeit1%f %f",Geschwidikeit1, Geschwidikeit2);
    double gesamtGeschwindikeit =(Geschwidikeit1) +(Geschwidikeit2);//Warum haben wir hier den Absolute Wert
    /*Debugging
    printf("r1: %.f m, r2: %.f m\n", r1, r2);
    printf("VisVisaGeschwindigkeit: %.f m/s , VisVisaGeschwindigkeit: %.f m/s\n", VisVisaGeschwidikeit1, VisVisaGeschwindikeit2);
    printf("VisVisaKreisOrbit1: %.f m/s, VisVisaKreisOrbit2: %.f m/s \n", VisVisaKreisOrbit1, VisVisaKreisOrbit2);
    printf("Geschwindigkeit1: %.f m/s, Geschwindigkeit2: %.2f \n", Geschwidikeit1, Geschwidikeit2);
    */
    return gesamtGeschwindikeit;
}
double Treibstoffbedardf (double DeltaGeschwindigkeit, double austrittsgeschwindigkeit, double Masse)
{
    return Masse * (1 - exp(-DeltaGeschwindigkeit / austrittsgeschwindigkeit));
}

/*
double Geschwindikeit(double x1, double x2, double m, double Re, double G, double M)
{
    x1 *= 1000;
    x2 *= 1000;
    double a = 0.5 * (x1 + x2);
    double V1Vp = std::sqrt((G * M) * ((2 / x1) - (1 / a)));
    double V1Vi = std::sqrt(m / x1);
   double V1 = V1Vp - V1Vi;
   printf("a ist %f \n", a);
printf("V1Vp: %f, V1Vi: %f, V1: %f\n", V1Vp, V1Vi, V1);


    double V2Vf = std::sqrt(m/Re + x2);
    double V2Va = std::sqrt((G * M) * (2/Re +x2) - 1/a);
    double V2 = V2Vf - V2Va;
    double V = V1 - V2;
printf("V2Vf: %f, V2Va: %f, V2: %f\n", V2Vf, V2Va, V2);
    return V;






}
*/