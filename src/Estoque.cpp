#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

#include "Estoque.hpp"
#include "Produto.hpp"
#include "ProdutoAlimenticio.hpp"
#include "ProdutoDeLimpeza.hpp"
#include "ProdutoEletronico.hpp"
#include "ProdutoVestuario.hpp"

void Estoque::exibirMensagemDeBoasVindas() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::cout << "Bem-vindo ao Sistema de Gerenciamento de Estoque!\n";
    pausarExecucao();
    
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

void Estoque::pausarExecucao() {
    std::cout << "( Pressione para prosseguir )";
    getchar();
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
    std::cout << "=== SISTEMA DE GERENCIAMENTO DE ESTOQUE ===\n";
    std::cout << "================= RELATORIO ===============\n";
    std::cout << "Administrador: " << administrador << '\n';
    std::cout << "Endereco: " << endereco << '\n';
    std::cout << "Quantidade de produtos: " << quantidadeProdutos << '\n';
    std::cout << "Valor total do estoque: R$ " << valorEstoque << "\n\n";
    pausarExecucao();
    
    // Tipos:
    // 0. Produto Alimenticio
    // 1. Produto Eletronico
    // 2. Produto de Limpeza
    // 3. Produto de Vestuario
    std::array<int,4> quantidadeProdutosTipo = {0, 0, 0, 0};
    for (auto p : produtos) {
        if (p->getTipo() == "Produto Alimenticio") quantidadeProdutosTipo[0]++;
        else if (p->getTipo() == "Produto Eletronico") quantidadeProdutosTipo[1]++;
        else if (p->getTipo() == "Produto de Limpeza") quantidadeProdutosTipo[2]++;
        else if (p->getTipo() == "Produto de Vestuario") quantidadeProdutosTipo[3]++;
    }

    std::cout << "Quantidade de produtos de cada tipo:\n";
    std::cout << "Produtos Alimenticios: " << quantidadeProdutosTipo[0] << '\n';
    std::cout << "Produtos Eletronico: " << quantidadeProdutosTipo[1] << '\n';
    std::cout << "Produtos de Limpeza: " << quantidadeProdutosTipo[2] << '\n';
    std::cout << "Produtos de Vestuario: " << quantidadeProdutosTipo[3] << "\n\n";
    pausarExecucao();
    
    std::cout << "Informações dos produtos:\n";
    if (quantidadeProdutos == 0) {
        std::cout << "Nenhum produto no estoque.\n";
    }

    float valorImpostos = 0.0f;
    for (int i = 0; i < quantidadeProdutos; i++) {
        std::cout << "Produto " << i+1 << ":\n";
        produtos[i]->exibirRelatorio();
        std::cout << '\n';
        valorImpostos += produtos[i]->calcularImposto();
    }
    std::cout << "Impostos acumulados: R$ " << valorImpostos << '\n';
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

void Estoque::salvarDados() {
    std::ofstream f("dados.txt", std::ios_base::in | std::ios_base::out);
    if (!f.is_open()) return;

    f << "ESTOQUE\n" << administrador << "\n" << endereco << "\n";

    for (auto p : produtos) {
        p->salvarEmArquivo(f);
    }
}

void Estoque::carregarDados() {
    std::ifstream f("dados.txt");
    if (!f.is_open()) return;

    std::string tag;
    if (!std::getline(f, tag) || tag != "ESTOQUE") return;

    std::getline(f, administrador);
    std::getline(f, endereco);

    while (std::getline(f, tag)) {
        if (tag != "PRODUTO") continue;

        std::string tipoStr, nome, valorStr, qtdStr;
        std::getline(f, tipoStr);
        std::getline(f, nome);
        std::getline(f, valorStr);
        std::getline(f, qtdStr);

        int tipo = std::stoi(tipoStr);
        float valor = std::stof(valorStr);
        int qtd = std::stoi(qtdStr);

        Produto* p = nullptr;
        switch (tipo) {
        case 1: {
            std::string dataValidade, orgStr;
            std::getline(f, dataValidade);
            std::getline(f, orgStr);
            p = new ProdutoAlimenticio(nome, valor, qtd, tipo, dataValidade, orgStr == "1");
            break;
        }
        case 2: {
            std::string marca, garStr;
            std::getline(f, marca);
            std::getline(f, garStr);
            p = new ProdutoEletronico(nome, valor, qtd, tipo, marca, std::stoi(garStr));
            break;
        }
        case 3: {
            std::string tipoQuimico;
            std::getline(f, tipoQuimico);
            p = new ProdutoDeLimpeza(nome, valor, qtd, tipo, tipoQuimico);
            break;
        }
        case 4: {
            std::string tamanho, material;
            std::getline(f, tamanho);
            std::getline(f, material);
            p = new ProdutoVestuario(nome, valor, qtd, tipo, tamanho, material);
            break;
        }
        }
        if (p) inserirProduto(p);
    }
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