#pragma once

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

    void exibir() override;
    void atualizar() override;

    std::string getTipo() override { return "Produto Alimenticio"; }

    std::string getDataValidade() const { return dataValidade; }
    void setDataValidade(const std::string &d) { dataValidade = d; }
    bool isOrganico() const { return organico; }
    void setOrganico(bool o) { organico = o; }
};

