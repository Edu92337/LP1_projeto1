#pragma once

#include <fstream>
#include <string>
#include <iostream>

class Produto {
protected:
    std::string nome;
    float valor;
    int quantidade;
    int tipo;
    std::fstream file;
public:
    Produto() : valor(0.0f), quantidade(0), tipo(0) {    
        file.open("dados.txt", std::ios::in | std::ios::out);
    }

    Produto(std::string nome, float valor, int quantidade, int tipo)
        : nome(nome), valor(valor), quantidade(quantidade), tipo(tipo) {
                file.open("dados.txt", std::ios::in | std::ios::out);
        }

    void exibeRelatorio();
    static void exibirTipos();
    static Produto* criar();
    virtual void exibir();
    virtual void atualizar();
    virtual float calcularImposto() = 0;
    virtual std::string getTipo() = 0;

    std::string getNome() const { return nome; }
    float getValor() const { return valor; }
    int getQuantidade() { return this->quantidade; }

    void setNome(const std::string &nome) { this->nome = nome; }
    void setValor(float v) { this->valor = v; }
    void setQuantidade(int qnt) { this->quantidade = qnt; }

    virtual ~Produto() = default;
};
