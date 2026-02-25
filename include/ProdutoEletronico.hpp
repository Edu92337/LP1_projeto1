#pragma once;
#include"Produto.hpp"
#include<iostream>
#include<string>
using namespace std;


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

    void exibir() override {
        std::cout << "[Eletronico] " << nome
                  << " | Marca: " << (marca.empty() ? "N/A" : marca)
                  << " | Garantia: " << garantiaMeses << " meses"
                  << " | Valor: R$" << valor
                  << " | Qtd: " << quantidade
                  << " | Imposto: R$" << calcularImposto()
                  << std::endl;
    }

    std::string getTipo() override { return "Produto Eletronico"; }

    std::string getMarca() const { return marca; }
    void setMarca(std::string m) { marca = m; }
    int getGarantiaMeses() const { return garantiaMeses; }
    void setGarantiaMeses(int g) { garantiaMeses = g; }
};
