#include "produto.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cctype> 

void Produto::alterar_valor(float valor_novo){
   _valor = valor_novo;
}

void Produto::desconto(float porcentagem){
   _valor = _valor - _valor*porcentagem;
}

std::string Produto::get_codigo(){
    return _codigo_produto;
}

std::string Produto::get_nome(){
    return _nome_produto;
}

float Produto::get_valor(){
    return _valor;
}

std::string Produto::get_descricao(){
    return _descricao;
}

int Produto::get_quantidade(){
    return _quantidade;
}

Produto::Produto(std::string nome_produto, float valor, std::string descricao, std::string codigo_produto, int quantidade){
        _nome_produto = nome_produto;
        _valor = valor;
        _descricao = descricao;
        _codigo_produto = codigo_produto;
        _quantidade = quantidade;
    }
bool Estoque::incluir_estoque(Produto produto){
    if(estoque_nome.empty()){
        estoque_codigo.insert(it_codigo, std::pair<std::string, Produto>(produto._codigo_produto, produto));
        estoque_nome.insert(it_nome,std::pair<std::string, Produto>(produto._nome_produto, produto));
        estoque_quantidade.insert(it_quantidade,std::pair<int, Produto>(produto._quantidade,produto));
        estoque_valor.insert(it_valor, std::pair<int, Produto>(produto._valor, produto));
        return true;
    }

    return false;
}