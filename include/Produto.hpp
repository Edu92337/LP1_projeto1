#pragma once

class Produto {
protected:
    std::string nome;
    float valor;
    int quantidade;
    int tipo;
    int idCOntribuinte;
public:
    Produto() {
        this->valor = 0.0f;
    }
    Produto(std::string nome,float valor,int quantidade,int tipo){
        this->nome = nome;
        this->valor = valor;
        this->quantidade=quantidade;
        this->tipo=tipo;
    }
    virtual void exibir();
    virtual void atualizar(int qnt);
    virtual float calcularImposto();
    virtual std::string getTipo();

    std::string getNome() const { return nome; }
    float getValor() const { return valor; }
    void setValor(int v){this->valor = v;}
    void setQuantidade(int qnt) {this->quantidade = qnt;}
    int getQuantidade(){return this->quantidade;}

};

class ProdutoDeLimpeza : public Produto {
 

};

class ProdutosEletronicos : public Produto{

};

class ProdutoAlimenticio : public Produto{


};

class ProdutoVestuario : public Produto{



};