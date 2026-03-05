#pragma once

#include <string>

#include "Produto.hpp"
#include "Data.hpp"

class ProdutoAlimenticio : public Produto {
private:
    Data dataValidade; 
    bool organico;
public:
    ProdutoAlimenticio(std::string nome, float valor, int quantidade, int tipo,
                       std::string dataValidade, bool organico = false)
        : Produto(nome, valor, quantidade, tipo), dataValidade(dataValidade), organico(organico) {}
        
    float calcularImposto() override {
        return  valor * 0.03f;
    }

    void exibir() override;
    void atualizar() override;
    void salvarEmArquivo(std::ofstream& f) override;
    void exibirRelatorio() override;

    std::string getTipo() override { return "Produto Alimenticio"; }

    std::string getDataValidade() { return dataValidade.toString(); }
    void setDataValidade(const std::string &d) { dataValidade = Data(d); }
    bool isOrganico() const { return organico; }
    void setOrganico(bool o) { organico = o; }
};

