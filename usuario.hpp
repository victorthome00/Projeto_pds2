#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <iostream>

/// @brief Inicia uma série de processos que integra as funções dos demais arquivos.
///
///  Ela integra o arquivo produto e carrinho fazendo manipulação das classes:
/// Estoque, Produto, Carrinho, Pagamento, Entrega e Autenticações. É possível 
/// visualizar os produtos disponibilizados pelas lojas, adicioná-los ao carrinho,
/// realizar o pagamento e definindo um CEP de entrega. Além disso, é possível
/// ver e alterar as informações pessoais do usuário.
/// 
/// @param nome Nome do Usuário.
void cliente_main(std::string nome);

/// @brief Gerencia o estoque da loja.
///
///  Intrega as funções do estoque fazendo a inserção de novos produtos no arquivo 
/// produtos.txt. É possível ver e alterar os dados da loja.
///
/// @param nome Nome da loja.
void loja_main(std::string nome);

#endif