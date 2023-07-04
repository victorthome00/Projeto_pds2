#include "carrinho.cpp"
#include "login.cpp"
#include "produto.cpp"
#include "registro.cpp"
#include "usuario.cpp"
#include <iostream>

std::string trata_string(std::string &str){
    for (char c : str) {
        if (!std::isalpha(c)) {
            return str;
        }
        c = std::tolower(c);
    }
    return str;
}

int main(){
    std::string comando,comando_auxiliar;
    std::cout<<"Digite 'encerrar' a qualquer momento para encerrar a sessão"<<std::endl;
    do{

        std::cout<<"Digite 'cliente' caso deseje entrar como cliente"<<"\n"<<"Digite 'gerente' para gerenciar seus produtos disponiveis"<<std::endl;
        std::cout<<"Digite 1 para cliente"<<"\n"<<"Digite 2 para Lojista"<<std::endl;

        std::cin>>comando;
        std::cout<<'\n'<<std::endl;
        comando = trata_string(comando); // apenas para padronizar eventuais desvios de letras maiúsculas ou minúsculas
        if(comando == "cliente"){
            std::cout<<"já possui cadastro?"<<std::endl;
            std::cin>>comando_auxiliar;
            comando_auxiliar = trata_string(comando_auxiliar);
            if (comando_auxiliar == "sim" || comando_auxiliar == "s"){
                Login log;
                do{
                    log.autenticarCliente();
                } while (!log.autenticarCliente());
                
            }
            if(comando_auxiliar == "não" || comando_auxiliar == "n" || comando_auxiliar == "nao"){
                Registro novo_cliente;
                novo_cliente.cadastrarCliente();
            }
            void cliente_main();
        }
        if(comando == "gerente"){
            std::cout<<"já possui cadastro?"<<std::endl;
            std::cin>>comando_auxiliar;
            comando_auxiliar = trata_string(comando_auxiliar);
            if (comando_auxiliar == "sim" || comando_auxiliar == "s"){
                Login log;
                do{
                    log.autenticarLoja();
                } while (!log.autenticarLoja());
                
            }
            if(comando_auxiliar == "não" || comando_auxiliar == "n" || comando_auxiliar == "nao"){
                Registro novo_cliente;
                novo_cliente.cadastrarLoja();
            }
            void loja_main();
        }
        else{
            std::cout<<"ERRO\ncomando não reconhecido"<<std::endl;
        }
    } while (comando != "encerrar");
}