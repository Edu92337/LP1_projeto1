#pragma once

class Produto {
private:
    std::string nome;
    float valor;
public:
    Produto() {
        valor = 0.0f;
    }

    void exibir();
    void atualizar();

    std::string getNome() const { return nome; }
    float getValor() const { return valor; }
};