#include "usuario.hpp"
#include <fstream>

void cliente_main(){
    std::string comando_secundario;
    while(comando_secundario != "Sair" || comando_secundario != "sair"){
        pagina_principal:
        std::cout << "1: Produtos \n2: Usuário \n3: Carrinho \n4: Compras" << std::endl;
        std::cout << "Digite o número referente ao que gostaria de prosseguir" << std::endl;
        std::cin >> comando_secundario;
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        switch(comando_secundario){
            case "1":
            //adicionar arquivo dos produtos
                std::ifstream arquivo();
                break;
            case "2":
                std::fstream arquivo("usuarioCliente.txt", std::ios::in | std::ios::out);
                if (arquivo.is_open())
                {
                    std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo, cepArquivo;
                    std::string currentItem;
                    while (file >> currentItem)
                    {
                        if (currentItem == searchItem)
                        {
                            
                            
                            break;
                        }
                    }
                    visualizacao_perfil:
                    std::cout << "Usuario:\n" << nomeArquivo\n\n << "Email:\n" << emailArquivo\n\n <<  "Cpf:\n" <<
                    cpfArquivo\n\n << "Cep\n" << cepArquivo << std::endl;
                    std::cout << "\nVoltar" << std::endl;
                    std::cin >> comando_secundario;
                    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    switch(comando_secundario){
                        case "Usuario"  || "usuario":
                            alterar_nome:
                            std::cout << "Nome: " << nomeArquivo;
                            std::cout << "Gostaria de alterar o nome de usuario? \n" << "S/N" << std::endl;
                            std::cin >> comando_secundario;
                            if(comando_secundario == ("s" || "S")){
                                //adicionar função trocar_nome
                            }
                            else if (comando_secundario == ("n" || "N")){
                                goto visualizacao_perfil;
                            }else std::cout << "Comando inválido" << std::endl;
                            goto alterar_nome;
                            break;
                        case "Email" || "email":
                            alterar_email:
                            std::cout << "Email: " << emailArquivo;
                            std::cout << "Gostaria de alterar o email? \n" << "S/N" << std::endl;
                            std::cin >> comando_secundario;
                            if (comando_secundario == ("s" || "S"))
                            {
                                // adicionar função trocar_email
                            }
                            else if (comando_secundario == ("n" || "N"))
                            {
                                goto visualizacao_perfil;
                            }
                            else
                                std::cout << "Comando inválido" << std::endl;
                            goto alterar_email;
                            break;
                        case "CEP" || "Cep" || "cep":
                            alterar_cep:
                            std::cout << "Cep: " << cepArquivo;
                            std::cout << "Gostaria de alterar o seu CEP? \n" << "S/N" << std::endl;
                            std::cin >> comando_secundario;
                            if (comando_secundario == ("s" || "S"))
                            {
                                // adicionar função trocar_cep
                            }
                            else if (comando_secundario == ("n" || "N"))
                            {
                                goto visualizacao_perfil;
                            }
                            else
                                std::cout << "Comando inválido." << std::endl;
                            goto alterar_cep;
                            break;
                        case "Voltar" || "voltar":
                            goto pagina_principal;
                        default:
                            std::cout << "Comando inválido." << std::endl;
                            goto visualizacao_perfil;
                    }
                    arquivo.close();
                }
                break;
            case "3":
            //adicionar arquivo do carrinho    
                break;
            case "4":
            //adicionar historico de compras
                break;
            default:
                std::cout << "Comando inválido\n" << "Tente novamente" << std::endl;
                goto pagina_principal;
    } 
}

void loja_main(){
    std::string comando_secundario;
    while (comando_secundario != "Sair" || comando_secundario != "sair"){
        pagina_principal:
        std::cout << "1: Produtos \n2: Usuário \n3: Vendas" << std::endl;
        std::cout << "Digite o número referente ao que gostaria de prosseguir." << std::endl;
        std::cin >> comando_secundario;
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        switch(comando_secundario){
            case "1":
            //adicionar arquivo dos produtos
                std::ifstream arquivo();
                break;
            case "2":
                std::ifstream arquivo("usuariosLojas.txt", std::ios::binary | std::ios::in);
                if (arquivo.is_open())
                {
                    std::string nomeArquivo, senhaArquivo, emailArquivo, cnpjArquivo, cepArquivo;
                    visualizacao_perfil:
                    std::cout << "Usuario:\n" << nomeArquivo\n\n << "Email:\n" << emailArquivo\n\n <<  "Cnpj:\n" <<
                    cnpjArquivo\n\n << "Cep\n" << cepArquivo << std::endl;
                    std::cout << "\nVoltar" << std::endl;
                    std::cin >> comando_secundario;
                    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    switch(comando_secundario){
                        case "Usuario"  || "usuario":
                            alterar_nome:
                            std::cout << "Loja: " << nomeArquivo;
                            std::cout << "Gostaria de alterar o nome da loja? \n" << "S/N" << std::endl;
                            std::cin >> comando_secundario;
                            if(comando_secundario == ("s" || "S")){
                                //adicionar função trocar_nome
                            }
                            else if (comando_secundario == ("n" || "N")){
                                goto visualizacao_perfil;
                            }else std::cout << "Comando inválido" << std::endl;
                            goto alterar_nome;
                            break;
                        case "Email" || "email":
                            alterar_email:
                            std::cout << "Email: " << emailArquivo;
                            std::cout << "Gostaria de alterar o email? \n" << "S/N" << std::endl;
                            std::cin >> comando_secundario;
                            if (comando_secundario == ("s" || "S"))
                            {
                                // adicionar função trocar_email
                            }
                            else if (comando_secundario == ("n" || "N"))
                            {
                                goto visualizacao_perfil;
                            }
                            else
                                std::cout << "Comando inválido" << std::endl;
                            goto alterar_email;
                            break;
                        case "CEP" || "Cep" || "cep":
                            alterar_cep:
                            std::cout << "Cep: " << cepArquivo;
                            std::cout << "Gostaria de alterar o seu CEP? \n" << "S/N" << std::endl;
                            std::cin >> comando_secundario;
                            if (comando_secundario == ("s" || "S"))
                            {
                                // adicionar função trocar_cep
                            }
                            else if (comando_secundario == ("n" || "N"))
                            {
                                goto visualizacao_perfil;
                            }
                            else
                                std::cout << "Comando inválido." << std::endl;
                            goto alterar_cep;
                        case "CNPJ" || "Cnpj" || "cnpj":
                            alterar_cnpj:
                            std::cout << "Cnpj: " << cnpjArquivo;
                            std::cout << "Gostaria de alterar o seu Cnpj? \n" << "S/N" << std::endl;
                            std::cin >> comando_secundario;
                            if (comando_secundario == ("s" || "S"))
                            {
                                // adicionar função trocar_cnpj
                            }
                            else if (comando_secundario == ("n" || "N"))
                            {
                                goto visualizacao_perfil;
                            }
                            else
                                std::cout << "Comando inválido." << std::endl;
                            goto alterar_cnpj;
                        case "Voltar" || "voltar":
                            goto pagina_principal;
                        default:
                            std::cout << "Comando inválido." << std::endl;
                            goto visualizacao_perfil;
                    }
                    arquivo.close();
                }
                break;
            case "3":
            //adicionar arquivo do carrinho    
                break;
            case "4":
            //adicionar historico de compras
                break;
            default:
                std::cout << "Comando inválido\n" << "Tente novamente" << std::endl;
                goto pagina_principal;

        } 
    }    
}