#include "usuario.hpp"
#include "produto.hpp"
#include "carrinho.hpp"
#include <fstream>

std::string trata_string(std::string &str){
    for (char c : str) {
        if (!std::isalpha(c)) {
            return str;
        }
        c = std::tolower(c);
    }
    return str;
}

void cliente_main(){
    std::string comando_secundario;
    pagina_principal:
    std::cout << "1: Produtos \n2: Usuário \n3: Carrinho \n"<< std::endl;
    //std::cout<<"4: Compras" << std::endl;
    std::cout << "Digite o número referente ao que gostaria de prosseguir" << std::endl;
    std::cin >> comando_secundario;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if(comando_secundario == "sair"){
        exit(0);
    }    
    if(comando_secundario == "1"){
        //adicionar arquivo dos produtos
        std::ifstream arquivo();
    }
    if(comando_secundario == "2"){
        std::ifstream arquivo("usuariosCliente.txt", std::ios::binary | std::ios::in);
        if (arquivo.is_open()){
            visualizacao_perfil:
            std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo, cepArquivo;
            std::cout << "Usuario:\n" << nomeArquivo << "\n\nEmail:\n" << emailArquivo <<  "\n\nCpf:\n" << cpfArquivo << "\n\nCep\n" << cepArquivo << std::endl;
            std::cout << "\nVoltar" << std::endl;
            std::cin >> comando_secundario;
            if (comando_secundario == "sair"){
                exit(0);
            }
            comando_secundario = trata_string(comando_secundario);
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            if(comando_secundario == "usuario"){
                alterar_nome:
                std::cout << "Nome: " << nomeArquivo;
                std::cout << "Gostaria de alterar o nome de usuario? \n" << "S/N" << std::endl;
                std::cin >> comando_secundario;
                if(comando_secundario == "s" || comando_secundario == "S"){
                    //adicionar função trocar_nome
                }
                if(comando_secundario == "n" || comando_secundario == "N"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando inválido" << std::endl;
                    goto alterar_nome;
                }
            }
            if(comando_secundario == "email"){
                alterar_email:
                std::cout << "Email: " << emailArquivo;
                std::cout << "Gostaria de alterar o email? \n" << "S/N" << std::endl;
                std::cin >> comando_secundario;
                if(comando_secundario == "sair"){
                    exit(0);
                }   
                if (comando_secundario == "s" || comando_secundario == "S"){
                    // adicionar função trocar_email
                }
                if (comando_secundario == "n" || comando_secundario == "N"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando inválido" << std::endl;
                    goto alterar_email;
                }
            }
            if(comando_secundario == "cep"){
                alterar_cep:
                std::cout << "Cep: " << cepArquivo;
                std::cout << "Gostaria de alterar o seu CEP? \n" << "S/N" << std::endl;
                std::cin >> comando_secundario;
                if(comando_secundario == "sair"){
                    exit(0);
                }   
                if (comando_secundario == "s" || comando_secundario == "S"){
                    // adicionar função trocar_cep
                }
                if (comando_secundario == "n" || comando_secundario == "N"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando inválido." << std::endl;
                    goto alterar_cep;
                }
            }
            if(comando_secundario == "voltar"){
                goto pagina_principal;
            }
        }
        arquivo.close();
    }
    if(comando_secundario == "3"){
        //adicionar arquivo do carrinho
        Carrinho_de_compra::exibir_carrinho;
    }
    /*if(comando_secundario == "4"){
        //adicionar historico de compras
    }*/
}

void loja_main(){
    std::string comando_secundario;
    pagina_principal:
    std::cout << "1: Produtos \n2: Usuário \n"<<std::endl;
    //std::cout<<"3: Vendas" << std::endl;  //função ianda não desenvolvida
    std::cout << "Digite o número referente ao que gostaria de prosseguir." << std::endl;
    std::cin >> comando_secundario;
    comando_secundario = trata_string(comando_secundario);
    if (comando_secundario == "sair"){
        exit(0);
    }
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if(comando_secundario == "1"){
    //adicionar arquivo dos produtos
        std::ifstream arquivo();
    }
    if(comando_secundario == "2"){
        std::ifstream arquivo("usuariosLojas.txt", std::ios::binary | std::ios::in);
        if (arquivo.is_open()){
            std::string nomeArquivo, senhaArquivo, emailArquivo, cnpjArquivo, cepArquivo;
            visualizacao_perfil:
            std::cout << "Usuario:\n" << nomeArquivo<< "\n\nEmail:\n" << emailArquivo <<  "\n\nCnpj:\n" <<
            cnpjArquivo << "\n\nCep\n" << cepArquivo << std::endl;
            std::cout << "\nVoltar" << std::endl;
            std::cin >> comando_secundario;            
            comando_secundario = trata_string(comando_secundario);
            if (comando_secundario == "sair"){
                exit(0);
            }
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                if(comando_secundario == "usuario"){
                    alterar_nome:
                    std::cout << "Loja: " << nomeArquivo;
                    std::cout << "Gostaria de alterar o nome da loja? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if(comando_secundario == "s" || comando_secundario == "S"){
                        //adicionar função trocar_nome
                    }
                    if(comando_secundario == "n" || comando_secundario == "N"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto alterar_nome;
                    }
                }
                if(comando_secundario == "email"){
                    alterar_email:
                    std::cout << "Email: " << emailArquivo;
                    std::cout << "Gostaria de alterar o email? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if (comando_secundario == "sair"){
                        exit(0);
                    }                    
                    if(comando_secundario == "s" || comando_secundario == "S"){
                        // adicionar função trocar_email
                    }
                    if(comando_secundario == "n" || comando_secundario == "N"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto alterar_email;
                    }
                }
                if(comando_secundario == "cep"){
                    alterar_cep:
                    std::cout << "Cep: " << cepArquivo;
                    std::cout << "Gostaria de alterar o seu CEP? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if (comando_secundario == "sair"){
                        exit(0);
                    }                    
                    if (comando_secundario == "s" || comando_secundario == "S"){
                        // adicionar função trocar_cep
                    }
                    if(comando_secundario == "n" || comando_secundario == "N"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido." << std::endl;
                        goto alterar_cep;
                    }
                }
                if(comando_secundario == "cnpj"){
                    alterar_cnpj:
                    std::cout << "Cnpj: " << cnpjArquivo;
                    std::cout << "Gostaria de alterar o seu Cnpj? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if (comando_secundario == "sair"){
                        exit(0);
                    }                    
                    if(comando_secundario == "s" || comando_secundario == "S")
                    {
                        // adicionar função trocar_cnpj
                    }
                    if(comando_secundario == "n" || comando_secundario == "N")
                    {
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido." << std::endl;
                        goto alterar_cnpj;
                    }
                }
                if(comando_secundario == "voltar"){
                    goto pagina_principal;
                }
                std::cout << "Comando inválido." << std::endl;
                goto visualizacao_perfil;
            }
            arquivo.close();
        }
    /*if(comando_secundario == "3"){
        //adicionar arquivo do carrinho    
    }                                           //funções não definidas ainda
    if(comando_secundario == "4"){
        //adicionar historico de compras
    }*/
    else{
        std::cout << "Comando inválido\n" << "Tente novamente" << std::endl;
        goto pagina_principal;
    }
    
}