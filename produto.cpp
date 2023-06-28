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
    // Verificar se o produto já existe no estoque pelo código
    if (estoque_codigo.find(produto._codigo_produto) != estoque_codigo.end()) {
        std::cout<<"Produto já existe"<<std::endl;
        return false; // Produto já existe no estoque
    }
    
    // Adicionar o produto ao estoque
    estoque_nome.insert(std::make_pair(produto._nome_produto, produto));
    estoque_valor.insert(std::make_pair(produto._valor, produto));
    estoque_codigo.insert(std::make_pair(produto._codigo_produto, produto));
    estoque_quantidade.insert(std::make_pair(produto._quantidade, produto));

    if (estoque_codigo.find(produto._codigo_produto) != estoque_codigo.end()) {
        std::cout<<"Produto inserido com sucesso"<<std::endl;
        return true; //Produto inserido com sucesso
    }
}
bool Estoque::remover_produto(const std::string& codigo) {
    // Verificar se o produto existe no estoque pelo código
    auto it = estoque_codigo.find(codigo);
    if (it == estoque_codigo.end()) {
        std::cout << "Produto não existe" << std::endl;
        return false; // Produto não encontrado no estoque
    }
    
    // Remover o produto de todos os mapas
    estoque_nome.erase(it->second.get_nome());
    estoque_valor.erase(it->second.get_valor());
    estoque_quantidade.erase(it->second.get_quantidade());
    
    estoque_codigo.erase(it);
    
    std::cout << "Produto removido com sucesso do estoque" << std::endl;
    return true; // Produto removido com sucesso do estoque
}
