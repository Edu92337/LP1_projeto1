#pragma once
#include <string>
#include <iostream>
using namespace std;
class Produto {
protected:
    std::string nome;
    float valor;
    int quantidade;
    int tipo;
    int idContribuinte;
public:
    Produto() : valor(0.0f), quantidade(0), tipo(0), idContribuinte(0) {}

    Produto(std::string nome, float valor, int quantidade, int tipo)
        : nome(nome), valor(valor), quantidade(quantidade), tipo(tipo), idContribuinte(0) {}

    virtual void exibir() {
        std::cout << "Produto: " << nome << ", Valor: R$" << valor << ", Quantidade: " << quantidade << std::endl;
    }

    virtual void atualizar(int qnt) {
        this->quantidade += qnt;
    }
    virtual void atualizarNome(string nome){
        this->nome = nome;
    }

    virtual float calcularImposto() = 0;
    virtual std::string getTipo() = 0;

    std::string getNome() const { return nome; }
    float getValor() const { return valor; }
    void setValor(float v) { this->valor = v; }
    void setQuantidade(int qnt) { this->quantidade = qnt; }
    int getQuantidade() { return this->quantidade; }

    virtual ~Produto() = default;
};
