#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Produto.hpp"

class Estoque {
private:
    std::vector<Produto*> produtos;
    std::string endereco, administrador;
    int quantidadeProdutos;
    float valorEstoque;
public:
    Estoque() {
        quantidadeProdutos = 0;
        valorEstoque = 0.0f;
    }
    Estoque(std::string end, std::string admin) : Estoque() {
        endereco = end;
        administrador = admin;
    }

    ~Estoque() {
        limparEstoque();
    }

    void limparEstoque();
    void listarProdutos();
    void gerarRelatorio();
    void inserirProduto(Produto &p);
    void atualizarProduto(std::string nomeProduto);
    void exibirProduto(std::string nomeProduto);
    void removerProduto(std::string nomeProduto);
    int pesquisarProduto(std::string nomeProduto);

    std::string getEndereco() const { return endereco; }
    std::string getAdministrador() const { return administrador; }
    int getQuantidadeProdutos() const { return quantidadeProdutos; }
    float getValorEstoque() const { return valorEstoque; }

    void setProdutos(const std::vector<Produto*> &p) { produtos = p; }
    void setEndereco(const std::string &end) { endereco = end; }
    void setAdministrador(const std::string &admin) { administrador = admin; }
    void setQuantidadeProdutos(int qtd) { quantidadeProdutos = qtd; }
    void setValorEstoque(float valor) { valorEstoque = valor; }
};