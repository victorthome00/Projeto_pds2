#include "registro.hpp"
#include "login.hpp"
#include <iostream>

/*int main() {
    Registro registro;
    Login login;

    int opcao;
    std::cout << "1 - Cadastrar Cliente" << std::endl;
    std::cout << "2 - Cadastrar Loja" << std::endl;
    std::cout << "3 - Fazer login do Cliente" << std::endl;
    std::cout << "4 - Fazer login da Loja" << std::endl;
    std::cout << "Escolha uma opção: "<<std::endl;
    std::cin >> opcao;

    if (opcao == 1) {
        registro.cadastrarCliente();
    } else if(opcao == 2) {
        registro.cadastrarLoja();
    }
    else if (opcao == 3) {
        if (login.autenticarCliente()) {
            std::cout << "Login realizado com sucesso!" << std::endl;
        } else {
            std::cout << "Falha na autenticação." << std::endl;
        }
    }
    else if (opcao == 4) {
        if (login.autenticarLoja()) {
            std::cout << "Login realizado com sucesso!" << std::endl;
        } else {
            std::cout << "Falha na autenticação." << std::endl;
        }
    } else {
        std::cout << "Opção inválida." << std::endl;
    }

    return 0;
}
*/



int main(){
    std::string comando;
    std::cout<<"Digite 'encerrar' a qualquer momento para encerrar a sessão"<<est::endl;
    do{
        std::cout<<"Digite 1 para cliente"<<"\n"<<"Digite 2 para Gerente"<<std::endl;
        std::cin>>comando;
        std::cout<<'\n'<<std::endl;
        if(comando == "1"){
            //fazer login
            Login::autenticarCliente();
            //fazer cadastro
            //chamar página cliente
        }
        if(comando == "2"){
            //fazer login
            Login::autenticarLoja();
            //fazer cadastro
            //chamar página loja
        }
        else{
            std::cout<<"ERRO\ncomando não reconhecido"<<std::endl;
        }
    } while (comando != "encerrar");
    
}
