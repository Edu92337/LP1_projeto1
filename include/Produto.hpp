#pragma once
#include <string>
#include <iostream>

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

    virtual float calcularImposto() = 0;
    virtual std::string getTipo() = 0;

    std::string getNome() const { return nome; }
    float getValor() const { return valor; }
    void setValor(float v) { this->valor = v; }
    void setQuantidade(int qnt) { this->quantidade = qnt; }
    int getQuantidade() { return this->quantidade; }

    virtual ~Produto() = default;
};

class ProdutoDeLimpeza : public Produto {
private:
    std::string tipoQuimico; 
public:
    ProdutoDeLimpeza(std::string nome, float valor, int quantidade, int tipo, std::string tipoQuimico = "")
        : Produto(nome, valor, quantidade, tipo), tipoQuimico(tipoQuimico) {}

    void exibir() override {
        std::cout << "[Limpeza] " << nome
                  << " | Tipo Quimico: " << (tipoQuimico.empty() ? "N/A" : tipoQuimico)
                  << " | Valor: R$" << valor
                  << " | Qtd: " << quantidade
                  << " | Imposto: R$" << calcularImposto()
                  << std::endl;
    }

    float calcularImposto() override {
        return valor * 0.1f; 
    }

    std::string getTipo() override { return "Produto de Limpeza"; }

    std::string getTipoQuimico() const { return tipoQuimico; }
    void setTipoQuimico(std::string tq) { tipoQuimico = tq; }
};

class ProdutoEletronico : public Produto {
private:
    std::string marca;
    int garantiaMeses;
public:
    ProdutoEletronico(std::string nome, float valor, int quantidade, int tipo,
                      std::string marca = "", int garantiaMeses = 12)
        : Produto(nome, valor, quantidade, tipo), marca(marca), garantiaMeses(garantiaMeses) {}

    void exibir() override {
        std::cout << "[Eletronico] " << nome
                  << " | Marca: " << (marca.empty() ? "N/A" : marca)
                  << " | Garantia: " << garantiaMeses << " meses"
                  << " | Valor: R$" << valor
                  << " | Qtd: " << quantidade
                  << " | Imposto: R$" << calcularImposto()
                  << std::endl;
    }

    float calcularImposto() override {
        return valor * 0.15f; 
    }

    std::string getTipo() override { return "Produto Eletronico"; }

    std::string getMarca() const { return marca; }
    void setMarca(std::string m) { marca = m; }
    int getGarantiaMeses() const { return garantiaMeses; }
    void setGarantiaMeses(int g) { garantiaMeses = g; }
};

class ProdutoAlimenticio : public Produto {
private:
    std::string dataValidade; 
    bool organico;
public:
    ProdutoAlimenticio(std::string nome, float valor, int quantidade, int tipo,
                       std::string dataValidade = "", bool organico = false)
        : Produto(nome, valor, quantidade, tipo), dataValidade(dataValidade), organico(organico) {}

    void exibir() override {
        std::cout << "[Alimenticio] " << nome
                  << " | Validade: " << (dataValidade.empty() ? "N/A" : dataValidade)
                  << " | Organico: " << (organico ? "Sim" : "Nao")
                  << " | Valor: R$" << valor
                  << " | Qtd: " << quantidade
                  << " | Imposto: R$" << calcularImposto()
                  << std::endl;
    }

    float calcularImposto() override {
        return  valor * 0.03f;
    }

    std::string getTipo() override { return "Produto Alimenticio"; }

    std::string getDataValidade() const { return dataValidade; }
    void setDataValidade(std::string d) { dataValidade = d; }
    bool isOrganico() const { return organico; }
    void setOrganico(bool o) { organico = o; }
};


class ProdutoVestuario : public Produto {
private:
    std::string tamanho; 
    std::string material; 
public:
    ProdutoVestuario(std::string nome, float valor, int quantidade, int tipo,
                     std::string tamanho = "", std::string material = "")
        : Produto(nome, valor, quantidade, tipo), tamanho(tamanho), material(material) {}

    void exibir() override {
        std::cout << "[Vestuario] " << nome
                  << " | Tamanho: " << (tamanho.empty() ? "N/A" : tamanho)
                  << " | Material: " << (material.empty() ? "N/A" : material)
                  << " | Valor: R$" << valor
                  << " | Qtd: " << quantidade
                  << " | Imposto: R$" << calcularImposto()
                  << std::endl;
    }

    float calcularImposto() override {
        return valor * 0.12f; 
    }

    std::string getTipo() override { return "Produto de Vestuario"; }

    std::string getTamanho() const { return tamanho; }
    void setTamanho(std::string t) { tamanho = t; }
    std::string getMaterial() const { return material; }
    void setMaterial(std::string m) { material = m; }
};