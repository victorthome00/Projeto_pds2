#include "carrinho.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cctype> 
#include <sstream>
#include <chrono>
#include <thread>


void Carrinho_de_compra::adicionar_item(std::string codigo, int quantidade, Estoque aux){
    Produto escolha = aux.estoque_codigo[codigo];
    int j = escolha.get_quantidade();
    if( j >= quantidade){
        _sacola.push_back(std::make_pair(escolha, quantidade));
    }
    else{
        std::cout << "Poxa, não temos essa quantidade no estoque!" << std::endl;
    }
}

void Carrinho_de_compra::remover_item(std::string codigo, int quantidade){
  for (auto it = _sacola.begin(); it != _sacola.end(); ++it) {
        if (it->first.get_codigo() == codigo) {
            it->second -= quantidade;
            if (it->second <= 0) {
                _sacola.erase(it);
                break;
            }
        }
    }


}

void Carrinho_de_compra::exibir_carrinho(){
for (const auto& par : _sacola) {
        Produto produto = par.first;    
        int quantidade = par.second;

        std::cout << "Nome: " << produto.get_nome() << ", Preço: " << produto.get_valor() << ", Quantidade: " << quantidade << std::endl;
    }
    std::cout << std::endl << std::endl;
    std::cout << "Preço total: " << calcular_valor() << std::endl;
}

float Carrinho_de_compra::calcular_valor(){
float aux = 0;
for(const auto& par : _sacola){
    Produto atual = par.first;
    int quantidade = par.second;
    aux = aux + atual.get_valor()*quantidade;
}
    return aux;
}

void Pagamento::get_modo_pagamento(){
    
    std::string forma_pagamento;
    int x = 0;
    std::getline (std::cin, forma_pagamento);
    do{
      std::cout << "Escreva seu modo de pagamento(Débito, Crédito ou PIX):" << std::endl;
      if(forma_pagamento == "Débito" || forma_pagamento == "Debito" || forma_pagamento == "debito" || forma_pagamento == "débito"){
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
//seleciona o metodo escolhido
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
    do{ 
    std::cout << "Digite 's' quando finalizar o pix. " << std::endl;
    std::cin >> aux1;
    std::cin.ignore();
    }while(aux1!= 's');
     if(_modo_pagamento == "Credito" || _modo_pagamento == "Debito"){
        std::string numero;
        do{
            std::cout << "Digite os números do seu cartão: ";
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
        do{ 
        std::cout << "Digite 's' quando finalizar o pix. " << std::endl;
        std::cin >> aux1;
        std::cin.ignore();
        }while(aux1!= 's');

    std::cout << "Parabéns! Compra realizada com sucesso" << std::endl;
  }
}
//principal metodo da classe

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
//gera PIX aleatorios (podem ser adicionados mais a vontade - so aumentar o rand)
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
//verifica se o numero colocado contem letras e se tem 16 digitos.
void Entrega::coletar_endereco(){
  int i, j;
  std::string cep;

  while (true) {
    i = 0;
    j = 0;
    std::cout << "Digite um CEP válido: ";
    std::cin >> cep;

    for(char c : cep){
        i++;

        if(std::isdigit(c)){
         j++;
        }
    }

    if (i == 8 && j == i) {
        
       // return 0;
        break;
    }
    std::cout << "CEP inválido, necessário ter 8 dígitos" << std::endl;
 }
}

void Entrega::entregar(){
  std::cout << "Preparando o seu pedido!" << std::endl;
    std::chrono::seconds duracao(3);
    std::this_thread::sleep_for(duracao);
    std::cout << "Pedido a caminho!" << std::endl;
    std::this_thread::sleep_for(duracao);
    std::cout << "Pedido entregue no cep " << _cep << std::endl;
}

void Entrega::set_cep(std::string cep){
    _cep = cep;
}

/*void Entrega::coletar_endereco(){
  int i = 0, j = 0;
  do{
    std::cout << "Digite o seu cep: " << std::endl;
    std::getline(std::cin, _cep);
    for(char c : _cep){
      j++;
      if(std::isdigit(c)){
        i = -1;
        _cep = nullptr;
        std::cout << "Cep invalido! " << std::endl;
      }
    }
    if(j != 8){
      std::cout << "Cep invalido! " << std::endl;
      i = -1;
      j = 0;
    }
  }while(i = -1);

}*/