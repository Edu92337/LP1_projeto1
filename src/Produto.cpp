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
            << " | Qtd: " << quantidade<<'\n';
}

void ProdutoAlimenticio::exibir() {
    Produto::exibir();
    std::cout << " | Validade: " << (dataValidade.empty() ? "N/A" : dataValidade)
            << " | Organico: " << (organico ? "Sim" : "Nao")
            << " | Imposto: R$ " << calcularImposto()
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
    std::cout << "\n=== ATUALIZAR PRODUTO ===\n";
    std::cout << "Nome atual: " << nome << "\n";
    std::cout << "Novo nome (Enter para manter): ";
    std::string novoNome;
    std::getline(std::cin, novoNome);
    if (!novoNome.empty()) {
        nome = novoNome;
    }

    std::cout << "Valor atual: R$ " << valor << "\n";
    std::cout << "Novo valor (0 para manter): ";
    float novoValor;
    std::cin >> novoValor;
    if (novoValor > 0) {
        valor = novoValor;
    }
    std::cout << "Quantidade atual: " << quantidade << "\n";
    std::cout << "Nova quantidade (-1 para manter): ";
    int novaQuantidade;
    std::cin >> novaQuantidade;
    if (novaQuantidade >= 0) {
        quantidade = novaQuantidade;
    }
    std::cin.ignore();

    std::cout << "Produto atualizado com sucesso!\n";
}

void ProdutoAlimenticio::atualizar() {
    Produto::atualizar();
    std::cout << "\n--- Atualizar dados especificos ---\n";
    std::cout << "Data de validade atual: " << (dataValidade.empty() ? "N/A" : dataValidade) << "\n";
    std::cout << "Nova data (Enter para manter): ";
    std::string novaData;
    std::getline(std::cin, novaData);
    if (!novaData.empty()) {
        dataValidade = novaData;
    }

    std::cout << "Organico atual: " << (organico ? "Sim" : "Nao") << "\n";
    std::cout << "E organico? (1-Sim/0-Nao, Enter para manter): ";
    std::string input;
    std::getline(std::cin, input);
    if (!input.empty()) {
        organico = (input == "1");
    }
}

void ProdutoDeLimpeza::atualizar() {
    Produto::atualizar();
    std::cout << "\n--- Atualizar dados especificos ---\n";
    std::cout << "Tipo quimico atual: " << (tipoQuimico.empty() ? "N/A" : tipoQuimico) << "\n";
    std::cout << "Novo tipo quimico (Enter para manter): ";
    std::string novoTipo;
    std::getline(std::cin, novoTipo);
    if (!novoTipo.empty()) {
        tipoQuimico = novoTipo;
    }
}

void ProdutoEletronico::atualizar() {
    Produto::atualizar();
    std::cout << "\n--- Atualizar dados especificos ---\n";
    std::cout << "Marca atual: " << (marca.empty() ? "N/A" : marca) << "\n";
    std::cout << "Nova marca (Enter para manter): ";
    std::string novaMarca;
    std::getline(std::cin, novaMarca);
    if (!novaMarca.empty()) {
        marca = novaMarca;
    }

    std::cout << "Garantia atual: " << garantiaMeses << " meses\n";
    std::cout << "Nova garantia em meses (0 para manter): ";
    int novaGarantia;
    std::cin >> novaGarantia;
    if (novaGarantia > 0) {
        garantiaMeses = novaGarantia;
    }
    std::cin.ignore();
}

void ProdutoVestuario::atualizar() {
    Produto::atualizar();
    std::cout << "\n--- Atualizar dados especificos ---\n";
    std::cout << "Tamanho atual: " << (tamanho.empty() ? "N/A" : tamanho) << "\n";
    std::cout << "Novo tamanho (Enter para manter): ";
    std::string novoTamanho;
    std::getline(std::cin, novoTamanho);
    if (!novoTamanho.empty()) {
        tamanho = novoTamanho;
    }

    std::cout << "Material atual: " << (material.empty() ? "N/A" : material) << "\n";
    std::cout << "Novo material (Enter para manter): ";
    std::string novoMaterial;
    std::getline(std::cin, novoMaterial);
    if (!novoMaterial.empty()) {
        material = novoMaterial;
    }
}

void Produto::salvarEmArquivo(std::ofstream& f) {
    f << "PRODUTO\n" << tipo << "\n" << nome << "\n" << valor << "\n" << quantidade << "\n";
}

void ProdutoAlimenticio::salvarEmArquivo(std::ofstream& f) {
    Produto::salvarEmArquivo(f);
    f << dataValidade << "\n" << (organico ? 1 : 0) << "\n";
}

void ProdutoEletronico::salvarEmArquivo(std::ofstream& f) {
    Produto::salvarEmArquivo(f);
    f << marca << "\n" << garantiaMeses << "\n";
}

void ProdutoDeLimpeza::salvarEmArquivo(std::ofstream& f) {
    Produto::salvarEmArquivo(f);
    f << tipoQuimico << "\n";
}

void ProdutoVestuario::salvarEmArquivo(std::ofstream& f) {
    Produto::salvarEmArquivo(f);
    f << tamanho << "\n" << material << "\n";
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
    std::cout << "==== RELATÓRIO DO PRODUTO "<<this->nome<<" ===="<<std::endl;
    std::cout << "Valor : "<<this->valor<<std::endl;
    std::cout << "Quantidade : "<<this->quantidade<<std::endl;
    std::cout << "Tipo : "<<getTipo()<<std::endl;
}
