#include "usuario.hpp"
#include "produto.hpp"
#include "carrinho.cpp"
#include <fstream>
#include <vector>

std::string trata_string(std::string &str){
    for (char c : str) {
        if (!std::isalpha(c)) {
            return str;
        }
        c = std::tolower(c);
    }
    return str;
}

void cliente_main(std::string nome){
    Carrinho_de_compra carrinho;
    std::string comando_secundario;
    std::vector<std::string> lines;
    std::string line;
    unsigned i = 0;
    //pagina_principal:
    std::cout << "1: Produtos \n2: Usuário \n3: Carrinho \n"<< std::endl;
    std::cout << "Digite o número referente ao que gostaria de prosseguir" << std::endl;
    std::cin >> comando_secundario;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if (comando_secundario == "sair" || comando_secundario == "Sair"){
        exit(0);
    }
    if(comando_secundario == "1"){
        //adicionar arquivo dos produtos
    }
    if(comando_secundario == "2"){
        std::ifstream arquivo("usuariosClientes.txt", std::ios::in | std::ios::out);
        if (arquivo.is_open()){
            std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo, cepArquivo;
            while(std::getline(arquivo, line)){
                lines.push_back(line);
            }
            for(; i < lines.size(); i++){
                if(lines[i] == nome){
                    nomeArquivo = lines[i];
                    senhaArquivo = lines[i + 1];
                    emailArquivo = lines[i + 2];
                    cpfArquivo = lines[i + 3];
                }
            }
        visualizacao_perfil:
            std::cout << "Usuario:\n" << nomeArquivo << "\n\nSenha:\n" << "******" << "\n\nEmail:\n" << emailArquivo <<  "\n\nCpf:\n" 
                      << cpfArquivo << "\n\nCep\n" << cepArquivo << std::endl;
            std::cout << "\nVoltar" << std::endl;
            std::cin >> comando_secundario;
            comando_secundario = trata_string(comando_secundario);
            std::cout << std::string(15, '\n');

            if(comando_secundario == "usuario"){
                alterar_nome:
                std::cout << "Nome: " << nomeArquivo;
                std::cout << "Gostaria de alterar o nome de usuario? \n" << "S/N" << std::endl;
                std::cin >> comando_secundario;
                if(comando_secundario == "s"){
                    verificar_nome:
                    std::cout << "Qual nome você gostaria?" << std::endl;
                    std::cin >> nomeArquivo;
                    std::cout << "\nO novo nome será " << nomeArquivo << "?" << std::endl;
                    std::cout << "S/N?\n";
                    std::cin >> comando_secundario;
                    if (comando_secundario == "s"){
                        lines[i] = nomeArquivo;
                        goto visualizacao_perfil;
                    } 
                    if (comando_secundario == "n"){ 
                        goto verificar_nome;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto verificar_nome;
                    }
                }
                if(comando_secundario == "n"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando inválido" << std::endl;
                    goto alterar_nome;
                }
            }
            if (comando_secundario == "senha"){
            alterar_senha:
                std::cout << "Senha: " << senhaArquivo;
                std::cout << "Gostaria de alterar a sua senha? \n" << "S/N" << std::endl;
                std::cin >> comando_secundario;
                if (comando_secundario == "s"){
                verificar_senha:
                    std::cout << "Qual será a nova senha?" << std::endl;
                    std::cin >> senhaArquivo;
                    std::cout << "\nA nova senha será " << senhaArquivo << "?" << std::endl;
                    std::cout << "S/N?\n";
                    std::cin >> comando_secundario;
                    if (comando_secundario == "s"){
                        lines[i + 1] = senhaArquivo;
                        goto visualizacao_perfil;
                    }
                    if (comando_secundario == "n"){
                        goto verificar_senha;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto verificar_senha;
                    }
                }
                if (comando_secundario == "n"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando inválido" << std::endl;
                    goto alterar_senha;
                }
            }
            if (comando_secundario == "email"){
            alterar_email:
                std::cout << "Email: " << emailArquivo;
                std::cout << "Gostaria de alterar o email? \n" << "S/N" << std::endl;
                std::cin >> comando_secundario;
                if (comando_secundario == "s"){
                    verificar_email:
                    std::cout << "Qual o novo email?" << std::endl;
                    std::cin >> emailArquivo;
                    std::cout << "\nO novo email será " << emailArquivo << "?" << std::endl;
                    std::cout << "S/N?\n";
                    std::cin >> comando_secundario;
                    if (comando_secundario == "s"){
                        lines[i + 2] = emailArquivo;
                        goto visualizacao_perfil;
                    }
                    if (comando_secundario == "n"){
                        goto verificar_email;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto verificar_email;
                    }
                }
                if (comando_secundario == "n"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando inválido" << std::endl;
                    goto alterar_email;
                }
            } 
            /*if (comando_secundario == "cep" || comando_secundario == "Cep" || comando_secundario == "CEP"){
            alterar_cep:
                std::cout << "Cep: " << cepArquivo;
                std::cout << "Gostaria de alterar o seu CEP? \n" << "S/N" << std::endl;
                std::cin >> comando_secundario;
                if (comando_secundario == "s" || comando_secundario == "S"){
                    verificar_cep:
                    std::cout << "Qual será o novo cep?" << std::endl;
                    std::cin >> cepArquivo >> std::endl;
                    if(cepArquivo
                    )
                    std::cout << "O novo cep será " << cepArquivo << "?" << std::endl;
                    std::cout << "S/N?\n";
                    std::cin >> comando_secundario;
                    if (comando_secundario == "s" || comando_secundario == "S"){
                        lines[i + 4] = cepArquivo;
                        goto visualizacao_perfil;
                    }
                    if (comando_secundario == "n" || comando_secundario == "N"){
                        goto verificar_cep;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto verificar_cep;
                    }
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
            }*/
        }
        arquivo.close();
        if (std::remove("usuariosClientes.txt") != 0){
            std::cout << "Erro no arquivo de usuario" << std::endl;
            exit(1);
        }
        std::ofstream file("usuariosClientes.txt");
        for (const std::string &element : lines){
            file << element << std::endl;
        }
        file.close();
    }
    if(comando_secundario == "3"){
        carrinho.exibir_carrinho();

    }
}
void loja_main(std::string nome){
    std::string comando_secundario;
    std::vector<std::string> lines;
    std::vector<std::string> produtos; 
    std::string line;
    unsigned i = 0;
    pagina_principal:
    std::cout << "1: Produtos \n2: Usuário \n"<<std::endl;
    //std::cout<<"3: Vendas" << std::endl;  //função ianda não desenvolvida
    std::cout << "Digite o número referente ao que gostaria de prosseguir." << std::endl;
    std::cin >> comando_secundario;
    comando_secundario = trata_string(comando_secundario);
    if (comando_secundario == "sair"){
        exit(0);
    }
    std::cout << std::string(15, '\n');
    if(comando_secundario == "1"){
    
    }
    if(comando_secundario == "2"){
        std::ifstream arquivo("usuariosLoja.txt", std::ios::in | std::ios::out);
        if (arquivo.is_open()){
            std::string nomeArquivo, senhaArquivo, emailArquivo, cnpjArquivo, cepArquivo;
            while (std::getline(arquivo, line)){
                lines.push_back(line);
            }
            for (; i < lines.size(); i++){
                if (lines[i] == nome){
                    nomeArquivo = lines[i];
                    senhaArquivo = lines[i + 1];
                    emailArquivo = lines[i + 2];
                    cnpjArquivo = lines[i + 3];
                    cepArquivo = lines[i + 4];
                }
            }
            visualizacao_perfil:
            std::cout << "Usuario:\n" << nomeArquivo<< "\n\nSenha:\n" << "******" << "\n\nEmail:\n" << emailArquivo 
                      << "\n\nCnpj:\n" << cnpjArquivo << "\n\nCep\n" << cepArquivo << std::endl;
            std::cout << "\nVoltar" << std::endl;
            std::cin >> comando_secundario;            
            comando_secundario = trata_string(comando_secundario);
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                if(comando_secundario == "usuario"){
                    alterar_nome:
                    std::cout << "Loja: " << nomeArquivo;
                    std::cout << "Gostaria de alterar o nome da loja? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if(comando_secundario == "s"){
                        verificar_nome:
                        std::cout << "Qual o novo nome da loja?" << std::endl;
                        std::cin >> nomeArquivo;
                        std::cout << "\nO novo nome será " << nomeArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                        lines[i] = nomeArquivo;
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_nome;
                        }
                        else{
                            std::cout << "Comando inválido" << std::endl;
                            goto verificar_nome;
                        }
                    if(comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto alterar_nome;
                    }
                }
                if (comando_secundario == "senha"){
                alterar_senha:
                    std::cout << "Senha: " << senhaArquivo;
                    std::cout << "Gostaria de alterar a sua senha? \n"
                              << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if (comando_secundario == "s"){
                    verificar_senha:
                        std::cout << "Qual será a nova senha?" << std::endl;
                        std::cin >> senhaArquivo;
                        std::cout << "\nA nova senha será " << senhaArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                            lines[i + 1] = senhaArquivo;
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_senha;
                        }
                        else{
                            std::cout << "Comando inválido" << std::endl;
                            goto verificar_senha;
                        }
                    }
                    if (comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto alterar_senha;
                    }
                }
                if(comando_secundario == "email"){
                    alterar_email:
                    std::cout << "Email: " << emailArquivo;
                    std::cout << "Gostaria de alterar o email? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;             
                    if(comando_secundario == "s"){
                    verificar_email:
                        std::cout << "Qual o novo email?" << std::endl;
                        std::cin >> emailArquivo;
                        std::cout << "\nO novo email será " << emailArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                            lines[i + 2] = emailArquivo;
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_email;
                        }
                        else{
                            std::cout << "Comando inválido" << std::endl;
                            goto verificar_email;
                        }
                    }
                    if(comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido" << std::endl;
                        goto alterar_email;
                    }
                }
                if (comando_secundario == "cnpj"){
                alterar_cnpj:
                    std::cout << "Cnpj: " << cnpjArquivo;
                    std::cout << "Gostaria de alterar o seu Cnpj? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if (comando_secundario == "s"){
                    verificar_cnpj:
                        std::cout << "Qual o novo cnpj?" << std::endl;
                        std::cin >> cnpjArquivo;
                        std::cout << "\nO novo cnpj será " << cnpjArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                            lines[i + 3] = cnpjArquivo;
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_cnpj;
                        }
                        else{
                            std::cout << "Comando inválido" << std::endl;
                            goto verificar_cnpj;
                        }
                    }
                    if (comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido." << std::endl;
                        goto alterar_cnpj;
                    }
                }
                if(comando_secundario == "cep"){
                    alterar_cep:
                    std::cout << "Cep: " << cepArquivo;
                    std::cout << "Gostaria de alterar o seu Cep? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;                
                    if (comando_secundario == "s"){
                    verificar_cep:
                        std::cout << "Qual será o novo cep?" << std::endl;
                        std::cin >> cepArquivo;
                        std::cout << "\nO novo cep será " << cepArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                            lines[i + 4] = cepArquivo;
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_cep;
                        }
                        else{
                            std::cout << "Comando inválido" << std::endl;
                            goto verificar_cep;
                        }
                    }
                    if(comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando inválido." << std::endl;
                        goto alterar_cep;
                    }
                }
                if(comando_secundario == "voltar"){
                    goto pagina_principal;
                } else{
                std::cout << "Comando inválido." << std::endl;
                goto visualizacao_perfil;
                }
            }
            arquivo.close();
            if(std::remove("usuariosLoja.txt") != 0){
               std::cout << "Erro no arquivo de usuario" << std::endl;
               exit(1);
            }
            std::ofstream file("usuariosLoja.txt");
            for (const std::string &element : lines){
                file << element << std::endl;
            }
            file.close();
        }
    /*if(comando_secundario == "3"){
        //adicionar arquivo do carrinho    
    }         //funções não definidas ainda
    if(comando_secundario == "4"){
        //adicionar historico de compras
    */
    }
    else{
        std::cout << "Comando inválido\n" << "Tente novamente" << std::endl;
        goto pagina_principal;
    }
    }