#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "registro.hpp"
#include "produto.hpp"
#include "carrinho.hpp"
#include "login.hpp"
#include <sstream>
#include <iostream>

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


TEST_CASE ("(login.hpp) autenticarCliente"){
    Login log;
    std::string text;
    text = "miguel"; 
        
        SUBCASE("Testando nome e senha que esteja no arquivo"){
            CHECK(log.autenticarCliente(text, "Miguel18") == true);
}

        SUBCASE("Testando nome e senha que não está no arquivo"){
            CHECK(log.autenticarCliente(text, "naotem") == false);
        }
}

TEST_CASE ("(login.hpp) autenticarLoja"){
    Login log;
    std::string text;
    text = "lacerda"; 
        
        SUBCASE("Testando nome e senha que esteja no arquivo"){
            CHECK(log.autenticarLoja(text, "Lacerda03") == true);
}

        SUBCASE("Testando nome e senha que não está no arquivo"){
            CHECK(log.autenticarLoja(text, "naotem") == false);
        }
}


TEST_CASE("(carrinho.hpp) adicao e remocao") {
    Carrinho_de_compra carrinho;
    Produto p1("pao", 5, "1234", 10, "Frances");
    Produto p2("agua", 3, "112", 5, "doce");
        carrinho.adicionar_item(p1.get_codigo(), 1);
        carrinho.adicionar_item(p2.get_codigo(), 1);

        carrinho.remover_item(p1.get_codigo(), 1);
        carrinho.remover_item(p2.get_codigo(), 1);
        CHECK(carrinho.calcular_valor() == 0.0);
    }


TEST_CASE("Teste da classe Estoque") {
    Estoque estoque;

    SUBCASE("Teste do método incluir_estoque") {
        std::istringstream iss("maca 3.50 4321 30 argentina");
        std::cin.rdbuf(iss.rdbuf());
        CHECK(estoque.incluir_estoque("Loja 1") == true);
    }
}


TEST_CASE("Teste da classe Estoque Vazia") {
    Estoque estoque;

    SUBCASE("Teste da exibicao do estoque vazio") {
        CHECK(estoque.exibir_estoque_nome() == false);
}

    SUBCASE("Teste da exibicao do estoque vazio") {
        CHECK(estoque.exibir_estoque_codigo() == false);
}

    SUBCASE("Teste da exibicao do estoque vazio") {
        CHECK(estoque.exibir_estoque_quantidade() == false);
}

    SUBCASE("Teste da exibicao do estoque vazio") {
        CHECK(estoque.exibir_estoque_valor() == false);
}
}

/*TEST_CASE("Teste da classe Estoque Vazia") { //protected
    Estoque estoque;
    Produto p1("pao", 5, "1234", 10, "Frances");
    std::string text = "teste";
    estoque_nome.push_back(std::make_pair(text, p1));

        CHECK(estoque.exibir_estoque_nome() == true);

}*/


/*TEST_CASE("(carrinho.cpp) verificar_cartao") { ////// privado, sem possbilidade de ser testado;
    Pagamento pagamento;
    std::string text;

        SUBCASE("Testando cartão válido"){
            text = "12345678";
            CHECK(pagamento.verificar_cartao(text) == 0);
        }

        SUBCASE("Testando cartão inválido com letra"){
            text = "1234567c";
            CHECK(pagamento.verificar_cartao(text) == 1);
        }

        SUBCASE("Testando cartão inválido com tamanho errado"){
            text = "123456";
            CHECK(pagamento.verificar_cartao(text) == 0);
        }

  }*/


/*TEST_CASE("(produto.hpp) Testando remoção produto") {
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
}*/