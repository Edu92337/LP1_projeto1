#include <iostream>
#include <string>
#include <vector>

#include "Estoque.hpp"
#include "Produto.hpp"

void Estoque::exibirMensagemDeBoasVindas() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::cout << "Bem-vindo ao Sistema de Gerenciamento de Estoque!\n";
    std::cout << "( Pressione para prosseguir )";
    getchar();
    
    if (this->administrador == "") // Primeira vez acessando o sistema
        realizarCadastro();
}

void Estoque::exibirMenu() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::cout << "\n=== MENU PRINCIPAL ===\n";
    std::cout << "1. Adicionar produto\n";
    std::cout << "2. Listar produtos\n";
    std::cout << "3. Exibir produto\n";
    std::cout << "4. Atualizar produto\n";
    std::cout << "5. Remover produto\n";
    std::cout << "6. Gerar relatorio\n";
    std::cout << "7. Limpar estoque\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opcao: ";
}

void Estoque::realizarCadastro() {
    // Mudar para classe Endereço depois
    std::string admin, end;
    std::cout << "Cadastro do Estoque\n";
    std::cout << "Digite o nome do administrador do sistema: ";
    std::getline(std::cin, admin);

    std::cout << "Digite o endereco do estoque: ";
    std::getline(std::cin, end);

    setAdministrador(admin);
    setEndereco(end);
}

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
    
    if (quantidadeProdutos == 0) {
        std::cout << "Estoque vazio.\n";
        return;
    }

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

void Estoque::inserirProduto(Produto* p) {
    produtos.push_back(p);
    valorEstoque += p->getValor();
    quantidadeProdutos++;
}

void Estoque::atualizarProduto(std::string nomeProduto) {
    int indiceEscolhido = Estoque::pesquisarProduto(nomeProduto);
    if (indiceEscolhido == -1) {
        return;
    }
    produtos[indiceEscolhido]->atualizar();
    std::cout << "Produto atualizado com sucesso!\n";
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
    std::cout << "Produto removido com sucesso!\n";
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
        std::cout << "Escolha o produto desejado:\n";
        for (size_t i = 0; i < indices.size(); i++) {
            std::cout << i+1 << ": ";
            produtos[indices[i]]->exibir();
        }
        std::cin >> indiceEscolhido;
        std::cin.ignore();
        indiceEscolhido--;
        if (indiceEscolhido < 0 || indiceEscolhido >= (int)indices.size()) {
            std::cout << "Indice invalido!\n";
            return -1;
        }
        indiceEscolhido = indices[indiceEscolhido];
    }

    return indiceEscolhido;
}