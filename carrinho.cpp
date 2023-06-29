#include "carrinho.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cctype> 
#include <sstream>

void Carrinho_de_compra::adicionar_item(std::string codigo, int quantidade, Estoque aux){
    Produto escolha = aux.estoque_codigo[codigo];
    int j = escolha.get_quantidade();
    if( j <= quantidade){
        _sacola.push_back(std::make_pair(escolha, quantidade));
    }
    else{
        std::cout << "Poxa, não temos essa quantidade no estoque!" << std::endl;
    }
}

void Carrinho_de_compra::remover_item(std::string codigo, int quantidade){
    int i = 0;
do{
  if(_sacola[i].first.get_codigo() == codigo){
    _sacola[i].second = _sacola[i].second - quantidade;
    i = -1;
  }  
    else{
        i++;
    }
}while(i != -1);


}

void Carrinho_de_compra::exibir_carrinho(){
for (const auto& par : _sacola) {
        Produto produto = par.first;
        int quantidade = par.second;

        std::cout << "Nome: " << produto.get_nome() << ", Preço: " << produto.get_valor() << ", Quantidade: " << quantidade << std::endl;
    }
}

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
    else if(forma_pagamento == "Crédito" || forma_pagamento == "Credito" || forma_pagamento == "credito" || forma_pagamento == "crédito"){
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
     }while(x==0);
}

void Pagamento::pagar(){
     if(_modo_pagamento == "Credito" || _modo_pagamento == "Debito"){
        //int cardNumber[16];
        std::string numero;
        do{
            std::cout << "Digite os números do seu cartão: ";
            //for(int j=0; j!=16; j++){
            //std::cin >> cardNumber[j];}
            std::getline(std::cin, numero);
            if(Pagamento::verificar_cartao(numero) == 1){
              std::cout << "Erro! Digite apenas números!" << std::endl;
            }
            else if(Pagamento::verificar_cartao(numero) == 2){
              std::cout << "Erro! Digite todos os 16 números do cartão!" << std::endl;
            }
        }while(Pagamento::verificar_cartao(numero) != 0);
        std::cout << "Parabéns! Compra realizada com sucesso!" << std::endl;
    }
     if(_modo_pagamento == "Pix"){
        std::cout << "O codigo de PIX é: " << gerar_codigo_PIX() << std::endl;
        char aux1;
        std::cout << "Digite 's' quando finalizar o pix. " << std::endl;
        do{ 
        std::cin >> aux1;
        std::cin.ignore();
        }while(aux1!= 's');

        std::cout << "Parabéns! Compra realizada com sucesso" << std::endl;
 }
}


 //bool Pagamento::eValido(int cardNumber[16]) {
    /*int cardNumber[16];
    std::cout << "Digite os números com um espaçamento entre eles:" << std::endl;
    for(int j=0; j!=16; j++){
        std::cin >> cardNumber[j];
    }*/
    //int length = 16;
    //int sum = 0;
    //int parity = length % 2;
    //for (int i = 0; i < length; i++) {
        //if (i % 2 != parity) {
            //sum += cardNumber[i];
        //} else {
            //if (cardNumber[i] > 4) {
                //sum += 2 * cardNumber[i] - 9;
            //} else {
                //sum += 2 * cardNumber[i];
            //}
        //}
    //}
    //return (sum % 10) == 0;
//}

std::string Pagamento::gerar_codigo_PIX(){
    int x = rand() % 10 + 1;
    switch(x){
        case 1:
          return "123A#&906YL0";
          break;
        case 2:
          return "432Ua$876Op%";
          break;
        case 3:
          return "@#456dE&90YY";
          break;
        case 4:
          return "087LPa5&@k99";
          break;
        case 5:
          return "27MAR6Tn2023";
          break;
        case 6:
          return "Ma546&&#ok21";
          break;
        case 7:
          return "LU44I87GI0@#";
          break;
        case 8:
          return "Y4N7@99&mm03";
          break;
        case 9:
          return "AABB0987Aur3";
          break;
        case 10:
          return "125A#&906YL0";
          break;
        default:
          return "ABC4457Mr007";
          break;
    }
}
int Pagamento::verificar_cartao(std::string numeroCartao){
  std::stringstream x;
  for(char c : numeroCartao){
    if(c != ' '){
      x << c;
    }
  }
  numeroCartao = x.str();
  for(char c : numeroCartao){
    if(!std::isdigit(c)){
      return 1;
    }
  }
  int tamanho = numeroCartao.length();
  if(tamanho != 16){
    return 2;
  }
  return 0;
}