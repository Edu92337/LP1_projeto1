#include <iostream>
#include <string>

#include "Produto.hpp"

void Produto::exibeRelatorio() {
    std::fstream file;
    file.open("relatorios.txt",std::ios_base::in | std::ios_base::out);
    file << "==== RELATÓRIO DO PRODUTO "<<this->nome<<" ===="<<std::endl;
    file << "Valor : "<<this->valor<<std::endl;
    file << "Quantidade : "<<this->quantidade<<std::endl;
    file << "Tipo : "<<getTipo()<<std::endl;
}