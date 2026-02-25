#include <iostream>
#include <string>
#include <vector>

#include "Estoque.hpp"
#include "Produto.hpp"

void Estoque::limparEstoque() {
    for (auto p : produtos) {
        delete p;
    }
    produtos.clear();
    valorEstoque = 0.0f;
    quantidadeProdutos = 0;
}

void Estoque::listarProdutos() {
    std::cout << "Listagem de produtos:\n";
    for (int i = 0; i < quantidadeProdutos; i++) {
        std::cout << i+1 << ": ";
        produtos[i]->exibir();
    }
}

void Estoque::gerarRelatorio() {
    for (auto p : this->produtos){
        p->exibeRelatorio();
    }
}

void Estoque::inserirProduto(Produto &p) {
    // Criar ponteiro de acordo com o tipo
    // do produto e inserir na lista.

    valorEstoque += p.getValor();
    quantidadeProdutos++;
}

void Estoque::atualizarProduto(std::string nomeProduto) {
    int indiceEscolhido = Estoque::pesquisarProduto(nomeProduto);
    if (indiceEscolhido == -1) {
        return;
    }
    produtos[indiceEscolhido]->atualizar();
}

void Estoque::exibirProduto(std::string nomeProduto) {
    int indiceEscolhido = Estoque::pesquisarProduto(nomeProduto);
    if (indiceEscolhido == -1) {
        return;
    }
    produtos[indiceEscolhido]->exibir();
}

void Estoque::removerProduto(std::string nomeProduto) {
    int indiceEscolhido = Estoque::pesquisarProduto(nomeProduto);
    if (indiceEscolhido == -1) {
        return;
    }
    valorEstoque -= produtos[indiceEscolhido]->getValor();
    quantidadeProdutos--;
    delete produtos[indiceEscolhido];
    produtos.erase(produtos.begin() + indiceEscolhido);
}

int Estoque::pesquisarProduto(std::string nomeProduto) {
    std::vector<int> indices;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (produtos[i]->getNome().find(nomeProduto) != std::string::npos)
            indices.push_back(i);
    }

    if (indices.size() == 0) {
        std::cout << "Nenhum produto com o nome \"" << nomeProduto << "\" encontrado.\n";
        return -1;
    }

    int indiceEscolhido = indices[0];
    if (indices.size() > 1) {
        std::cout << "Mais de um produto com o nome pesquisado encontrado.\n";
        std::cout << "Escolha o produto desejado: ";
        for (size_t i = 0; i < indices.size(); i++) {
            std::cout << i+1 << ": ";
            produtos[indices[i]]->exibir();
        }
        std::cin >> indiceEscolhido;
        indiceEscolhido--;
        if (indiceEscolhido < 0 || indiceEscolhido >= (int)indices.size()) {
            std::cout << "Indice invalido!\n";
            return -1;
        }
        indiceEscolhido = indices[indiceEscolhido];
    }

    return indiceEscolhido;
}