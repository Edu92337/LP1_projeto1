#pragma once

#include <iostream>
#include <string>

#include "Produto.hpp"

class ProdutoDeLimpeza : public Produto {
private:
    std::string tipoQuimico; 
public:
    ProdutoDeLimpeza(std::string nome, float valor, int quantidade, int tipo, std::string tipoQuimico = "")
        : Produto(nome, valor, quantidade, tipo), tipoQuimico(tipoQuimico) {}

    float calcularImposto() override {
        return valor * 0.1f; 
    }

    void exibir() override {
        std::cout << "[Limpeza] " << nome
                  << " | Tipo Quimico: " << (tipoQuimico.empty() ? "N/A" : tipoQuimico)
                  << " | Valor: R$" << valor
                  << " | Qtd: " << quantidade
                  << " | Imposto: R$" << calcularImposto()
                  << std::endl;
    }


    std::string getTipo() override { return "Produto de Limpeza"; }

    std::string getTipoQuimico() const { return tipoQuimico; }
    void setTipoQuimico(std::string tq) { tipoQuimico = tq; }
};
