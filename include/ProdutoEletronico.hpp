#pragma once

#include <string>

#include "Produto.hpp"

class ProdutoEletronico : public Produto {
private:
    std::string marca;
    int garantiaMeses;
public:
    ProdutoEletronico(std::string nome, float valor, int quantidade, int tipo,
                      std::string marca = "", int garantiaMeses = 12)
        : Produto(nome, valor, quantidade, tipo), marca(marca), garantiaMeses(garantiaMeses) {}


    float calcularImposto() override {
        return valor * 0.15f; 
    }

    void exibir() override;
    void atualizar() override;
    void salvarEmArquivo(std::ofstream& f) override;

    std::string getTipo() override { return "Produto Eletronico"; }

    std::string getMarca() const { return marca; }
    void setMarca(std::string m) { marca = m; }
    int getGarantiaMeses() const { return garantiaMeses; }
    void setGarantiaMeses(int g) { garantiaMeses = g; }
};
