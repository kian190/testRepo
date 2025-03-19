//
// Created by user on 11/20/2024.
//

#ifndef GESCHWINDIKEIT_H
#define GESCHWINDIKEIT_H
#include <string>

struct Planet
{
    std::string name;
    double GM;
    double radius;
};

double HohmannTransferGeschwindigkeit(const Planet& planet, double height1, double height2);
double Treibstoffbedardf (double DeltaGeschwindigkeit, double austrittsgeschwindigkeit, double Masse);

#endif //GESCHWINDIKEIT_H
