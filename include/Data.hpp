#pragma once

#include <iostream>

class Data {
private:
    int dia, mes, ano;
    int getDiasDoMes(int mes, int ano);

public:
    Data() {}
    Data(int dia, int mes, int ano) {
        // Validação do mês
        if (mes < 1 || mes > 12) {
            std::cout << "Atributo mês inválido\n";
            mes = 1;
        }

        // Validação do dia
        if (dia < 1 || dia > getDiasDoMes(mes, ano)) {
            std::cout << "Atributo dia inválido\n";
            dia = 1;
        }

        setDia(dia);
        setMes(mes);
        setAno(ano);
    }

    Data(const std::string &data) {
        dia = std::stoi(data.substr(0, 2));
        mes = std::stoi(data.substr(3, 2));
        ano = std::stoi(data.substr(6, 4));

        // Validação do mês
        if (mes < 1 || mes > 12) {
            std::cout << "Atributo mês inválido\n";
            mes = 1;
        }

        // Validação do dia
        if (dia < 1 || dia > getDiasDoMes(mes, ano)) {
            std::cout << "Atributo dia inválido\n";
            dia = 1;
        }
    }

    std::string getDia();
    std::string getMes();
    std::string getAno();
    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }

    std::string toString();
};
