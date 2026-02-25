#include <iostream>

#include "Estoque.hpp"
#include "Produto.hpp"
#include "ProdutoAlimenticio.hpp"
#include "ProdutoDeLimpeza.hpp"
#include "ProdutoEletronico.hpp"
#include "ProdutoVestuario.hpp"

int main() {
    Estoque estoque;
    std::cout << estoque.getQuantidadeProdutos() << '\n';

    return 0;
}