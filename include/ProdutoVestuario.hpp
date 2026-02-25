#pragma once;
#include"Produto.hpp"
#include<iostream>
#include<string>
using namespace std;
class ProdutoVestuario : public Produto {
private:
    std::string tamanho; 
    std::string material; 
public:
    ProdutoVestuario(std::string nome, float valor, int quantidade, int tipo,
                     std::string tamanho = "", std::string material = "")
        : Produto(nome, valor, quantidade, tipo), tamanho(tamanho), material(material) {}


    float calcularImposto() override {
        return valor * 0.12f; 
    }

    void exibir() override {
        std::cout << "[Vestuario] " << nome
                  << " | Tamanho: " << (tamanho.empty() ? "N/A" : tamanho)
                  << " | Material: " << (material.empty() ? "N/A" : material)
                  << " | Valor: R$" << valor
                  << " | Qtd: " << quantidade
                  << " | Imposto: R$" << calcularImposto()
                  << std::endl;
    }

    std::string getTipo() override { return "Produto de Vestuario"; }

    std::string getTamanho() const { return tamanho; }
    void setTamanho(std::string t) { tamanho = t; }
    std::string getMaterial() const { return material; }
    void setMaterial(std::string m) { material = m; }
};