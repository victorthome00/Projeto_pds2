#include "usuario.hpp"
#include <fstream>

void cliente_main(){
    std::string comando_secundario;
    while(comando_secundario != "Sair" || comando_secundario != "sair"){
        std::cout << "1: Produtos \n2: Usuário \n3: Carrinho \n4: Compras" << std::endl;
        std::cout << "Digite o número referente ao que gostaria de prosseguir" << std::endl;
        std::cin >> comando_secundario;
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        switch(comando_secundario){
            case 1:
            //adicionar arquivo dos produtos
                std::ifstream arquivo();
                break;
            case 2:
                std::ifstream arquivo("usuariosCliente.txt", std::ios::binary | std::ios::in);
                if (arquivo.is_open())
                {
                    std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo, cepArquivo;
                    std::cout << "Usuario:\n" << nomeArquivo\n\n << "Email:\n" << emailArquivo\n\n <<  "Cpf:\n" <<
                    cpfArquivo\n\n << "Cep\n" << cepArquivo << std::endl;
                    std::cout << "\nVoltar" << std::endl;
                    std::cin >> comando_secundario;
                    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    switch(comando_secundario){
                        case "Usuario"  || "usuario":
                            std::cout << "Gostaria de alterar o nome de usuario? \n" << "S/N" << std::endl;
                            std::cin >> comando_secundario;
                            if(comando_secundario ==)
                            break;
                    }   
                }
                break;
            case 3:
            //adicionar arquivo do carrinho    
                break;
            case 4:
            //adicionar historico de compras
                break;
            default:
                std::cout << "Comando inválido\n" << "Tente novamente" << std::endl;
                break;
        }
    } 
}