#include <iostream>
#include <string>

#include "Produto.hpp"
#include "ProdutoAlimenticio.hpp"
#include "ProdutoDeLimpeza.hpp"
#include "ProdutoEletronico.hpp"
#include "ProdutoVestuario.hpp"

void Produto::exibirTipos() {
    std::cout << "\n=== TIPOS DE PRODUTOS ===\n";
    std::cout << "1. Produto Alimenticio\n";
    std::cout << "2. Produto Eletronico\n";
    std::cout << "3. Produto de Limpeza\n";
    std::cout << "4. Produto de Vestuario\n";
    std::cout << "Escolha o tipo: ";
}

void Produto::exibir() {
    std::cout << "[ " << this->getTipo() << " ] " << nome
            << " | Valor: R$ " << valor
            << " | Qtd: " << quantidade;
}

void ProdutoAlimenticio::exibir() {
    Produto::exibir();
    std::cout << " | Validade: " << (dataValidade.empty() ? "N/A" : dataValidade)
            << " | Organico: " << (organico ? "Sim" : "Nao")
            << " | Imposto: R$" << calcularImposto()
            << std::endl;
}

void ProdutoDeLimpeza::exibir() {
    Produto::exibir();
    std::cout << " | Tipo Quimico: " << (tipoQuimico.empty() ? "N/A" : tipoQuimico)
            << " | Imposto: R$ " << calcularImposto()
            << std::endl;
}

void ProdutoEletronico::exibir() {
    Produto::exibir();
    std::cout << " | Marca: " << (marca.empty() ? "N/A" : marca)
            << " | Garantia: " << garantiaMeses << " meses"
            << " | Imposto: R$ " << calcularImposto()
            << std::endl;
}

void ProdutoVestuario::exibir() {
    Produto::exibir();
    std::cout << " | Tamanho: " << (tamanho.empty() ? "N/A" : tamanho)
            << " | Material: " << (material.empty() ? "N/A" : material)
            << " | Imposto: R$ " << calcularImposto()
            << std::endl;
}

void Produto::atualizar() {
    // Mostrar os atributos atuais
    // e abrir o terminal para receber as atualizações
}

Produto* Produto::criar() {
    int tipo;
    std::cin >> tipo;
    std::cin.ignore();

    if (tipo < 1 || tipo > 4) {
        std::cout << "Tipo invalido!\n";
        return nullptr;
    }

    std::string nome;
    float valor;
    int quantidade;

    std::cout << "\nNome do produto: ";
    std::getline(std::cin, nome);
    std::cout << "Valor: R$ ";
    std::cin >> valor;
    std::cout << "Quantidade: ";
    std::cin >> quantidade;
    std::cin.ignore();

    switch (tipo) {
    case 1: { // Alimenticio
        std::string dataValidade;
        int organicoOpt;
        std::cout << "Data de validade (DD/MM/AAAA): ";
        std::getline(std::cin, dataValidade);
        std::cout << "E organico? (1-Sim/0-Nao): ";
        std::cin >> organicoOpt;
        std::cin.ignore();
        return new ProdutoAlimenticio(nome, valor, quantidade, tipo, dataValidade, organicoOpt == 1);
    }
    case 2: { // Eletronico
        std::string marca;
        int garantia;
        std::cout << "Marca: ";
        std::getline(std::cin, marca);
        std::cout << "Garantia (meses): ";
        std::cin >> garantia;
        std::cin.ignore();
        return new ProdutoEletronico(nome, valor, quantidade, tipo, marca, garantia);
    }
    case 3: { // Limpeza
        std::string tipoQuimico;
        std::cout << "Tipo quimico: ";
        std::getline(std::cin, tipoQuimico);
        return new ProdutoDeLimpeza(nome, valor, quantidade, tipo, tipoQuimico);
    }
    case 4: { // Vestuario
        std::string tamanho, material;
        std::cout << "Tamanho: ";
        std::getline(std::cin, tamanho);
        std::cout << "Material: ";
        std::getline(std::cin, material);
        return new ProdutoVestuario(nome, valor, quantidade, tipo, tamanho, material);
    }
    default:
        return nullptr;
    }
}

void Produto::exibeRelatorio() {
    std::fstream file;
    file.open("relatorios.txt",std::ios_base::in | std::ios_base::out);
    file << "==== RELATÓRIO DO PRODUTO "<<this->nome<<" ===="<<std::endl;
    file << "Valor : "<<this->valor<<std::endl;
    file << "Quantidade : "<<this->quantidade<<std::endl;
    file << "Tipo : "<<getTipo()<<std::endl;
}