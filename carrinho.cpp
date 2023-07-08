#include "carrinho.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cctype> 
#include <sstream>
#include <unistd.h>


void Carrinho_de_compra::adicionar_item(std::string codigo, int quantidade){
  std::ifstream produtos("produto.txt", std::ios::in | std::ios::out);
  std::vector<std::string> linhas;
  std::string linha;
  std::string line;
  while (std::getline(produtos, linha)){
    linhas.push_back(linha);
  }
  for(std::size_t o = 0; o < linhas.size(); o++){
    if(codigo == linhas[o]){
      //std::cout << "entro" << std::endl;
      std::string nome, codigo, descricao;
      float valor;
      int quanti;
      nome = linhas[o - 2];
      codigo = linhas[o];
      descricao = linhas[o + 2];
      valor = std::stof(linhas[o - 1]);
      quanti = std::stoi(linhas[o + 1]);
      Produto produto_aux(nome,valor,codigo,quanti,descricao);
      std::pair<Produto, int> par(produto_aux,quantidade);
      _sacola.push_back(par);
    }
  }
  produtos.close();
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
  for (const auto& par : _sacola){
    Produto produto = par.first;    
    int quantidade = par.second;

    std::cout << "Nome: " << produto.get_nome() << ", Preco: " << produto.get_valor() << ", Quantidade: " << quantidade << std::endl;
  }
  std::cout << std::endl << std::endl;
  std::cout << "Preco total: " << calcular_valor() << std::endl;
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

void Carrinho_de_compra::limpar_sacola(){
  _sacola.clear();
}

std::string Pagamento::get_modo_pagamento(){
    std::string _modo_pagamento;
    std::string forma_pagamento;
    int x = 1;
    do{
      std::cout << "Escreva seu modo de pagamento(Debito, Credito ou PIX):" << std::endl;
      std::cin >> forma_pagamento;
      std::cin.ignore();
      if(forma_pagamento == "PIX" || forma_pagamento == "Pix" || forma_pagamento == "pix"){
         x = 1;
         _modo_pagamento = "PIX";
    }
      else if(forma_pagamento == "Débito" || forma_pagamento == "Debito" || forma_pagamento == "debito" || forma_pagamento == "débito"){
        x = 1;
        _modo_pagamento = "Debito";
    } else if(forma_pagamento == "Crédito" || forma_pagamento == "Credito" || forma_pagamento == "credito" || forma_pagamento == "crédito"){
        x = 1;
        _modo_pagamento = "Credito";
    } else{
        std::cout << "Erro! Digite um metodo de pagamento valido!" << std::endl;
        x = 0;
     }
     }while(x==0);
     return _modo_pagamento;
}

void Pagamento::pagar(){
  std::string modo;
  modo = get_modo_pagamento();
  if(modo == "Credito" || modo == "Debito"){
    if(modo == "Credito"){
      std::cout << "O modo de pagamento escolhido foi Credito!!" << std::endl;
    }
    else if(modo == "Debito"){
      std::cout << "O modo de pagamento escolhido foi Debito!!" << std::endl;
    }
    sleep(1);
    std::string numero;
    do{
      char c;
      do{
      std::cout << "Digite os primeiros 8 numeros do seu cartao: ";
      std::getline(std::cin, numero);
      std::cout << "Os numeros do seu cartao sao: " << numero << std::endl;
      std::cout << "Digite 's' para confirmar, para reescrever o numero digite qualquer botao diferente de 's': " << std::endl;
      std::cin >> c;
      std::cin.ignore();
      std::cout << std::endl;
      if(c == 's' || c == 'S'){
        c = 's';
      }
      }while(c != 's');
      std::cout << "verificando cartao..." << std::endl;
      sleep(3);
      if(Pagamento::verificar_cartao(numero) == 1){
        std::cout << "Erro! Digite apenas numeros!" << std::endl;
      }
      else if(Pagamento::verificar_cartao(numero) == 2){
        std::cout << "Erro! Digite os primeiros 8 numeros do seu cartao!" << std::endl;
      }
    }while(Pagamento::verificar_cartao(numero) != 0);
    std::cout << "Parabens! Compra realizada com sucesso!" << std::endl;
    sleep(1);
  }
  else if(modo == "PIX"){
    std::cout << "O modo de pagamento escolhido foi PIX!!" << std::endl;
    std::cout << "O codigo de PIX e: " << Pagamento::gerar_codigo_PIX() << std::endl;
    char aux1;
    do{ 
    std::cout << "Digite 's' quando confirmar o pix. " << std::endl;
    std::cin >> aux1;
    std::cin.ignore(); 
    }while(aux1!= 's');
    std::cout << "Confirmando PIX..." << std::endl;
    sleep(3);
    std::cout << "Parabens! Compra realizada com sucesso" << std::endl;
    sleep(1);
  }
}


//principal metodo da classe

std::string Pagamento::gerar_codigo_PIX(){
  srand(time(NULL));
  int x = rand() % 20 + 1;
  int y = x;
    if(y == 10 || y == 20 || y == 7){
      std::cout << "Oh nao! A geracao do codigo PIX encontrou um problema!\n";
      sleep(2);
      std::cout << "Jogue esse jogo da velha enquanto nossos programadores corrigem isso!\n";
      sleep(2);
      std::cout << "========================================\n";
      std::cout << "============ Jogo da Velha =============\n";
      std::cout << "========================================\n";
      std::cout << "Digite somente numeros de 1 a 9, correspondentes a posicao que deseja jogar!" << std::endl;
      Jogo_espera a;
      a.Jogo_da_velha();
      std::cout << "\n=====Problema corrigido!=====\n";
      std::cout << "Voltando ao codigo..." << std::endl;
      sleep(2);
    }
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
      case 11:
        return "1LiPa6YaL0ve";
        break;
      case 12:
        return "0623tes2tot4";
        break;
      case 13:
        return "133Li$$de%L0";
        break;
      case 14:
        return "G4v1AAo33%$0";
        break;
      case 15:
        return "Ph1nn**8F39m";
        break;
      case 16:
        return "L]V1c7&&rhH0";
        break;
      case 17:
        return "J3+0j$))0021";
        break;
      case 18:
        return "A1V1cAo33%$0";
        break;
      case 19:
        return "T0ppG88nM4vi";
        break;
      case 20:
        return "LpG88n&&rhH0";
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
  if(tamanho != 8){
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
    std::cout << "Digite um CEP valido: ";
    std::cin >> cep;

    for(char c : cep){
        i++;

        if(std::isdigit(c)){
         j++;
        }
    }

    if (i == 8 && j == i) {
        
        set_cep(cep);
        break;
    }
    std::cout << "CEP invalido, necessario ter 8 digitos" << std::endl;
 }
}

void Entrega::entregar(){
  coletar_endereco();
  std::cout << "Preparando o seu pedido!" << std::endl;
    sleep(3);
    std::cout << "Pedido a caminho!" << std::endl;
    sleep(3);
    std::cout << "Pedido entregue no cep " << _cep << std::endl;
}

void Entrega::set_cep(std::string cep){
    this->_cep = cep;
}


void Jogo_espera::drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void Jogo_espera::playerMove(char* spaces, char player) {
    int num;
    do {
        std::string number;
        std::cout << "Escolha uma posicao para o marcador (1-9): ";
        std::getline(std::cin, number);

        if (number.length() == 1 && std::isdigit(number[0])) {
            num = number[0] - '0';
            num--;
            if (num >= 0 && num <= 8 && spaces[num] == ' ') {
                spaces[num] = player;
                break;
            }
        }
        std::cout << "Entrada invalida. Tente novamente." << std::endl;
    } while (true);
}

void Jogo_espera::computerMove(char *spaces, char computer){
    int number;
    srand(time(NULL));
    sleep(1);
    while(true){
      number = rand() % 9;
      if(spaces[number] == ' '){
        spaces[number] = computer;
        break;
      }
    }
}

bool Jogo_espera::checkWinner(char *spaces, char player){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << "VOCE GANHOU!\n" : std::cout << "VOCE PERDEU!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << "VOCE GANHOU!\n" : std::cout << "VOCE PERDEU!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << "VOCE GANHOU!\n" : std::cout << "VOCE PERDEU!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "VOCE GANHOU!\n" : std::cout << "VOCE PERDEU!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "VOCE GANHOU!\n" : std::cout << "VOCE PERDEU!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "VOCE GANHOU!\n" : std::cout << "VOCE PERDEU!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << "VOCE GANHOU!\n" : std::cout << "VOCE PERDEU!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << "VOCE GANHOU!\n" : std::cout << "VOCE PERDEU!\n";
    }
    else{
      return false;
    }
    return true;
}

bool Jogo_espera::checkTie(char *spaces){

  for(int i = 0; i < 9; i++){
    if(spaces[i] == ' '){
      return false;
    }
  }
    std::cout << "EMPATE!!" << std::endl;
    return true;
}

void Jogo_espera::Jogo_da_velha(){
  char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
      char player = 'X';
      char computer = 'O';
      bool running = true;

      drawBoard(spaces);

      while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player)){
          running = false;
          break;
        }
        else if(checkTie(spaces)){
          running = false;
          break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player)){
          running = false;
          break;
        }
        else if(checkTie(spaces)){
          running = false;
          break;
        }

      }
}