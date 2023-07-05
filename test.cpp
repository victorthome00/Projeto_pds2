#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "registro.hpp"
#include "produto.hpp"
#include "carrinho.hpp"

Registro r;

TEST_CASE ("(registro.hpp) Testando criptografia"){
    std::string text;
    text = "Senha18"; 
        CHECK(r.encrypit(text) == "Ugpjc3:");
    
    text = "Arr18";
        CHECK (r.encrypit(text) == "Ctt3:");

}

TEST_CASE ("(registro.hpp) Testando senha") {
//usando método encripty para testar senha, já que a senha tem que passar por essa função;
std::string text;

    SUBCASE("Senha com menos de 4 algarismos"){
        text = "A18";
        CHECK_THROWS_AS (r.encrypit(text), std::underflow_error); 
    }

    SUBCASE ("Senha com menos de 2 dígitos"){
        text = "Ar1";
        CHECK_THROWS_AS (r.encrypit(text), std::exception);
    }

    SUBCASE ("Senha sem ao menos 1 letra maiúscula"){
        text = "a18";
        CHECK_THROWS_AS (r.encrypit(text), std::exception);
    }
}

TEST_CASE("(produto.hpp) Incluir produto no estoque") {
    Estoque estoque;
    Produto produto("Produto 1", 10.0, "Descrição do Produto 1", "001", 5);
    estoque.incluir_estoque(produto);

        CHECK(estoque.incluir_estoque(produto) == false); 
}


TEST_CASE("(produto.hpp) Testando remoção produto") {
    Estoque estoque;
    Produto produto("Produto 2", 15.0, "Descrição do Produto 2", "002", 3);
    estoque.incluir_estoque(produto);

        SUBCASE("tem o produto no estoque"){
            CHECK(estoque.remover_produto("002") == true);
        }

        SUBCASE("Não tem o produto no estoque"){
            CHECK(estoque.remover_produto("003") == false);
        }
}

TEST_CASE("(produto.hpp) exibir_estoque_nome()") {
    Estoque estoque;
    Produto produto1("Produto 1", 10.0, "Descrição do Produto 1", "001", 1);
    Produto produto2("Produto 2", 15.0, "Descrição do Produto 2", "002", 1);
    estoque.incluir_estoque(produto1);
    estoque.incluir_estoque(produto2);

        SUBCASE ("Quando estoque não está vazio"){
          CHECK(estoque.exibir_estoque_nome() == true);
        }

        SUBCASE ("Quando estoque está vazio"){
        estoque.remover_produto("001");
        estoque.remover_produto("002");
            CHECK(estoque.exibir_estoque_nome() == false);
        }
}

TEST_CASE("(produto.hpp) exibir_produto_codigo") {
    Estoque estoque;
    Produto produto("Produto 1", 10.0, "Descrição do Produto 1", "001", 5);
    estoque.incluir_estoque(produto);

        SUBCASE("Tem o produto no estoque"){
            CHECK(estoque.exibir_produto_codigo("001") == true);
        }

        SUBCASE("Não tem o produto no estoque"){
            CHECK(estoque.exibir_produto_codigo("002") == false);  
    
        }
}

TEST_CASE("(produto.hpp) exibir_estoque_quantidade()") {
    Estoque estoque;
    Produto produto("Produto 1", 10.0, "Descrição do Produto 1", "001", 5);
    estoque.incluir_estoque(produto);

        SUBCASE("Tem o produto no estoque"){
            CHECK(estoque.exibir_estoque_quantidade() == true);
        }

        SUBCASE("Não tem o produto no estoque"){
        estoque.remover_produto("001");    
            CHECK(estoque.exibir_estoque_quantidade() == false);  
        }
}

TEST_CASE("(carrinho.hpp)calcular_valor") {     //usar construtor padrão de Produto
  Carrinho_de_compra carrinho;
  Estoque estoque;  // Criar objeto de estoque para fornecer itens ao carrinho
  estoque.incluir_estoque(Produto("Produto 1", 10.0, "Descrição do Produto 1", "001", 5)); //cointainer map<estoque_codigo> necessita de construtor padrão;
  estoque.incluir_estoque(Produto("Produto 2", 15.0, "Descrição do Produto 2", "002", 1));
  
  carrinho.adicionar_item("001", 3, estoque);
  carrinho.adicionar_item("002", 1, estoque);

    CHECK(carrinho.calcular_valor() == 45.0);
}


TEST_CASE("(carrinho.cpp) adicionar_item/remover_item") {
  Carrinho_de_compra carrinho;
  Estoque estoque; 
  estoque.incluir_estoque(Produto("Produto 1", 10.0, "Descrição do Produto 1", "001", 5));
  estoque.incluir_estoque(Produto("Produto 2", 5.0, "Descrição do Produto 2", "002", 3));

  carrinho.adicionar_item("001", 5, estoque);
  carrinho.adicionar_item("002", 2, estoque);

    SUBCASE("tem produto no carrinho"){
        CHECK(carrinho.calcular_valor() == 60.0);
    }

    SUBCASE("não tem produto no carrinho"){
    carrinho.remover_item("001", 5);
        CHECK(carrinho.calcular_valor() == 10.0);
    }
}