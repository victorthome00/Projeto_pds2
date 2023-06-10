#include "classes.hpp"
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
/*void Carrinho_de_compra::adicionar_item(std::string codigo, int quantidade, std::vector <Produto> &vetor){
    for (Produto aux : vetor) {
        if (aux.get_codigo() == codigo) {
            std::pair <Produto, int> aux1(aux, quantidade);
            _sacola.push_back(aux1);
            return;
        }
    }
}
void Carrinho_de_compra::remover_item(std::string codigo, int quantidade, std::vector <Produto> &vetor){
    for (Produto aux : vetor) {
        if (aux.get_codigo() == codigo) {
            std::pair <Produto, int> aux1(aux, quantidade);
            _sacola.push_back(aux1);
            return;
        }
    }
} */

void Pagamento::get_modo_pagamento(){
    std::cout << "Escreva seu modo de pagamento(Débito, Crédito ou PIX):" << std::endl;
    std::string forma_pagamento;
    ;
    int x = 0;
    std::getline (std::cin, forma_pagamento);
    do{if(forma_pagamento == "Débito" || forma_pagamento == "Debito" || forma_pagamento == "debito" || forma_pagamento == "débito"){
        x = 1;
        _modo_pagamento = "Debito";
    }
    else if(forma_pagamento == "Crédito" || forma_pagamento == "Credito" || forma_pagamento == "credito" || forma_pagamento == "débito"){
        x = 1;
        _modo_pagamento = "Credito";
    }
    else if(forma_pagamento == "PIX" || forma_pagamento == "Pix" || forma_pagamento == "pix"){
        x = 1;
        _modo_pagamento = "PIX";
    }
    else{
        std::cout << "Erro! Digite um método de pagamento válido!" << std::endl;
     }
     }while(x=0);
}

void Pagamento::pagar(){
     if(_modo_pagamento == "Credito" || _modo_pagamento == "Debito"){
        int cardNumber[16];
        do{
            std::cout << "Digite os números do seu cartão com um espaçamento entre eles: ";
            for(int j=0; j!=16; j++){
            std::cin >> cardNumber[j];}
        }while(!Pagamento::eValido(cardNumber));
        std::cout << "Parabéns! Compra realizada com sucesso!" << std::endl;
    }
    if(_modo_pagamento == "Pix"){
        //gerar código pix
        char aux1;
        std::cout << "Digite 's' quando finalizar o pix. " << std::endl;
        do{ 
        std::cin >> aux1;
        std::cin.ignore();
        }while(aux1!= 's');

        std::cout << "Parabéns! Compra realizada com sucsso" << std::endl;
 }
}


 bool Pagamento::eValido(int *cardNumber) {
    /*int cardNumber[16];
    std::cout << "Digite os números com um espaçamento entre eles:" << std::endl;
    for(int j=0; j!=16; j++){
        std::cin >> cardNumber[j];
    }*/
    int length = 16;
    int sum = 0;
    int parity = length % 2;
    for (int i = 0; i < length; i++) {
        if (i % 2 != parity) {
            sum += cardNumber[i];
        } else {
            if (cardNumber[i] > 4) {
                sum += 2 * cardNumber[i] - 9;
            } else {
                sum += 2 * cardNumber[i];
            }
        }
    }
    return (sum % 10) == 0;
}

std::string Pagamento::gerar_codigo_PIX(){
    int x = rand() % 10 + 1;
    //fazer o codigo para gerar chave
}