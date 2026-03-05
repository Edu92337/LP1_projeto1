#include <string>

#include "Data.hpp"

std::string Data::getDia() {
    std::string newDia = std::to_string(dia);
    if (dia < 10) 
        newDia = '0' + newDia;
    return newDia;
}

std::string Data::getMes() {
    std::string newMes = std::to_string(mes);
    if (mes < 10)
        newMes = '0' + newMes;
    return newMes;
}

std::string Data::getAno() {
    std::string newAno = std::to_string(ano);
    return newAno;
}

int Data::getDiasDoMes(int mes, int ano) {
    switch (mes){
    case 1:
        return 31;
    case 2:
        if ((ano%4==0 && ano%100!=0) || ano%400==0)
            return 29;
        return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return -1;
    }
}

std::string Data::toString() {
    return getDia() + "/" + getMes() + "/" + getAno();
}