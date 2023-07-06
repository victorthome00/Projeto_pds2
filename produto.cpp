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
void Produto::adicionar_quantidade(int a){
    _quantidade += a;
}

void Produto::remover_quantidade(int a){
    if(a >= _quantidade){
        _quantidade = 0;
}
    else{
        _quantidade -= a;
    }
}
void Produto::exibir_produto(){
    std::cout<< _nome_produto << "\n" << _valor << "\n" << _codigo_produto<< "\n"<< _descricao << "\n" << _quantidade << std::endl;
}
bool Estoque::incluir_estoque(Produto produto){
    if (estoque_codigo.find(produto._codigo_produto) != estoque_codigo.end()) {
        std::cout<<"Produto ja existe"<<std::endl;
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
    return true;
}
bool Estoque::remover_produto(const std::string& codigo) {
    // Verificar se o produto existe no estoque pelo código
    auto it = estoque_codigo.find(codigo);
    if (it == estoque_codigo.end()) {
        std::cout << "Produto nao existe" << std::endl;
        return false; // Produto não encontrado no estoque
    }
    
    // Remover o produto de todos os mapas
    estoque_nome.erase(it->second._nome_produto);
    estoque_valor.erase(it->second._valor);
    estoque_quantidade.erase(it->second._quantidade);
    
    estoque_codigo.erase(it);
    
    std::cout << "Produto removido com sucesso do estoque" << std::endl;
    return true; // Produto removido com sucesso do estoque
}
bool Estoque::exibir_estoque_nome() {
    if (estoque_nome.empty()) {
        std::cout << "Estoque vazio." << std::endl;
        return false;
    }

    std::cout << "Estoque por nome:" << std::endl;
    for (const auto& item : estoque_nome) {
        std::cout << "Nome: " << item.first << std::endl;
        std::cout << "Valor: R$" << item.second._valor << std::endl;
        std::cout << "Descrição: " << item.second._descricao << std::endl;
        std::cout << "Codigo: " << item.second._codigo_produto << std::endl;
        std::cout << "Quantidade: " << item.second._quantidade << std::endl;
        std::cout << "---------------------" << std::endl;
    }

    return true;
}

bool Estoque::exibir_estoque_valor() {
    if (estoque_valor.empty()) {
        std::cout << "Estoque vazio." << std::endl;
        return false;
    }

    std::cout << "Estoque por valor:" << std::endl;
    for (const auto& item : estoque_valor) {
        std::cout << "Valor: R$" << item.first << std::endl;
        std::cout << "Nome: " << item.second._nome_produto << std::endl;
        std::cout << "Descricao: " << item.second._descricao << std::endl;
        std::cout << "Codigo: " << item.second._codigo_produto << std::endl;
        std::cout << "Quantidade: " << item.second._quantidade << std::endl;
        std::cout << "---------------------" << std::endl;
    }

    return true;
}

bool Estoque::exibir_estoque_codigo() {
    if (estoque_codigo.empty()) {
        std::cout << "Estoque vazio." << std::endl;
        return false;
    }

    std::cout << "Estoque por codigo:" << std::endl;
    for (const auto& item : estoque_codigo) {
        std::cout << "Codigo: " << item.first << std::endl;
        std::cout << "Nome: " << item.second._nome_produto << std::endl;
        std::cout << "Valor: R$" << item.second._valor << std::endl;
        std::cout << "Descricao: " << item.second._descricao << std::endl;
        std::cout << "Quantidade: " << item.second._quantidade << std::endl;
        std::cout << "---------------------" << std::endl;
    }

    return true;
}

bool Estoque::exibir_estoque_quantidade() {
    if (estoque_quantidade.empty()) {
        std::cout << "Estoque vazio." << std::endl;
        return false;
    }

    std::cout << "Estoque por quantidade:" << std::endl;
    for (const auto& item : estoque_quantidade) {
        std::cout << "Quantidade: " << item.first << std::endl;
        std::cout << "Nome: " << item.second._nome_produto << std::endl;
        std::cout << "Valor: R$" << item.second._valor << std::endl;
        std::cout << "Descricao: " << item.second._descricao << std::endl;
        std::cout << "Codigo: " << item.second._codigo_produto << std::endl;
        std::cout << "---------------------" << std::endl;
    }

    return true;
}
bool Estoque::exibir_produto_nome(std::string nome) {
    bool encontrado = false; //boleano criado para verifiação se o produto existe no estoque

    std::cout << "Produtos com o nome \"" << nome << "\":" << std::endl;
    for (const auto& item : estoque_nome) {
        if (item.second._nome_produto == nome) {
            std::cout << "Nome: " << item.first << std::endl;
            std::cout << "Valor: R$" << item.second._valor << std::endl;
            std::cout << "Descricao: " << item.second._descricao << std::endl;
            std::cout << "Codigo: " << item.second._codigo_produto << std::endl;
            std::cout << "Quantidade: " << item.second._quantidade << std::endl;
            std::cout << "---------------------" << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "Produto nao encontrado." << std::endl;
    }

    return encontrado;
}

bool Estoque::exibir_produto_codigo(std::string codigo) {
    auto it = estoque_codigo.find(codigo);
    if (it == estoque_codigo.end()) {
        std::cout << "Produto com codigo \"" << codigo << "\" nao encontrado." << std::endl;
        return false;
    }

    std::cout << "Produto com codigo \"" << codigo << "\":" << std::endl;
    std::cout << "Nome: " << it->second._nome_produto << std::endl;
    std::cout << "Valor: R$" << it->second._valor << std::endl;
    std::cout << "Descricao: " << it->second._descricao << std::endl;
    std::cout << "Quantidade: " << it->second._quantidade << std::endl;

    return true;
}

