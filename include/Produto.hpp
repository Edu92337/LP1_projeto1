#pragma once

#include <string>
#include <iostream>
<<<<<<< Updated upstream
<<<<<<< Updated upstream

=======
=======
>>>>>>> Stashed changes
#include<fstream>

using namespace std;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    virtual void atualizarNome(std::string &nome){
=======
    virtual void atualizar(int qnt,string nome){
>>>>>>> Stashed changes
=======
    virtual void atualizar(int qnt,string nome){
>>>>>>> Stashed changes
        this->nome = nome;
        atualizar(qnt);
    }

    void exibeRelatorio(){
        fstream file;
        file << "==== RELATÓRIO DO PRODUTO "<<this->nome<<" ===="<<endl;
        file << "Valor : "<<this->valor<<endl;
    }

    virtual float calcularImposto() = 0;
    virtual std::string getTipo() = 0;

    std::string getNome() const { return nome; }
    float getValor() const { return valor; }
    int getQuantidade() { return this->quantidade; }
    int getIdContribuinte() { return this->idContribuinte; }

    void setNome(const std::string &nome) { this->nome = nome; }
    void setValor(float v) { this->valor = v; }
    void setQuantidade(int qnt) { this->quantidade = qnt; }
    void setIdContribuinte(int id) { this->idContribuinte = id; }

    virtual ~Produto() = default;
};
