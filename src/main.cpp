#include <iostream>
#include <iomanip>
#include<fstream>
#include "Estoque.hpp"
#include "Produto.hpp"

int main() {
    std::cout << std::setprecision(2) << std::fixed;

    Estoque estoque;
    estoque.carregarDados();
    estoque.exibirMensagemDeBoasVindas();

    std::string produtoPesquisado;
    int opt = 1;
    do {
        estoque.exibirMenu();
        std::cin >> opt;
        std::cin.ignore();

        switch (opt) {
        case 0:
            std::cout << "Fechando o sistema...\nAte a proxima!\n";
            break;

        case 1: {
            Produto::exibirTipos();
            Produto* novoProduto = Produto::criar();
            if (novoProduto != nullptr) {
                estoque.inserirProduto(novoProduto);
                std::cout << "Produto adicionado com sucesso!\n";
            }
            else std::cout << "Erro ao inserir produto.\n";
            Estoque::pausarExecucao();
            break;
        }

        case 2:
            estoque.listarProdutos();
            Estoque::pausarExecucao();
            break;
        
        case 3:
            std::cout << "Digite o nome do produto desejado: ";
            std::getline(std::cin, produtoPesquisado);
            estoque.exibirProduto(produtoPesquisado);
            Estoque::pausarExecucao();
            break;

        case 4:
            std::cout << "Digite o nome do produto desejado: ";
            std::getline(std::cin, produtoPesquisado);
            estoque.atualizarProduto(produtoPesquisado);
            Estoque::pausarExecucao();
            break;

        case 5:
            std::cout << "Digite o nome do produto desejado: ";
            std::getline(std::cin, produtoPesquisado);
            estoque.removerProduto(produtoPesquisado);
            Estoque::pausarExecucao();
            break;

        case 6:
            estoque.gerarRelatorio();
            Estoque::pausarExecucao();
            break;
        
        case 7:
            estoque.limparEstoque();
            std::cout << "Estoque limpo com sucesso!\n";
            Estoque::pausarExecucao();
            break;
        
        default:
            std::cout << "Opcao invalida!\n";
            Estoque::pausarExecucao();
            break;
        }
    } while (opt > 0);

    estoque.salvarDados();
    return 0;
}