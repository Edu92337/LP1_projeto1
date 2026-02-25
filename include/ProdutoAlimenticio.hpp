#pragma once

#include <iostream>
#include <string>

#include "Produto.hpp"

class ProdutoAlimenticio : public Produto {
private:
    std::string dataValidade; 
    bool organico;
public:
    ProdutoAlimenticio(std::string nome, float valor, int quantidade, int tipo,
                       std::string dataValidade = "", bool organico = false)
        : Produto(nome, valor, quantidade, tipo), dataValidade(dataValidade), organico(organico) {}

        
    float calcularImposto() override {
        return  valor * 0.03f;
    }

    void exibir() override {
        std::cout << "[Alimenticio] " << nome
                  << " | Validade: " << (dataValidade.empty() ? "N/A" : dataValidade)
                  << " | Organico: " << (organico ? "Sim" : "Nao")
                  << " | Valor: R$" << valor
                  << " | Qtd: " << quantidade
                  << " | Imposto: R$" << calcularImposto()
                  << std::endl;
    }

    std::string getTipo() override { return "Produto Alimenticio"; }

    std::string getDataValidade() const { return dataValidade; }
    void setDataValidade(std::string d) { dataValidade = d; }
    bool isOrganico() const { return organico; }
    void setOrganico(bool o) { organico = o; }
};

