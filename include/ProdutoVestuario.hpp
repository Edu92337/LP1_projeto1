#pragma once

#include <string>

#include "Produto.hpp"

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

    void exibir() override;
    void atualizar() override;
    
    std::string getTipo() override { return "Produto de Vestuario"; }

    std::string getTamanho() const { return tamanho; }
    void setTamanho(std::string t) { tamanho = t; }
    std::string getMaterial() const { return material; }
    void setMaterial(std::string m) { material = m; }
};