#include "usuario.hpp"
#include "produto.hpp"
#include "carrinho.hpp"
#include "registro.hpp"
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

Registro r;
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
    Estoque aux;
    Carrinho_de_compra carrinho;
    std::string comando_secundario;
    std::vector<std::string> lines;
    std::vector<std::string> linhas;
    std::vector<Produto> product;
    std::string linha = "";
    std::string line;
    std::string aux1;
    int indice_secundario;
    unsigned i = 0;
    int quant = 0;
    pagina_principal:
    std::cout << "==============MENU================" << std::endl;
    std::cout << "1: Produtos \n2: Usuario \n3: Carrinho \nsair\n"<< std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Digite o numero referente ao que gostaria de prosseguir ou digite sair." << std::endl;
    std::cin >> comando_secundario;
    std::cout << std::string(15, '\n');
    if (comando_secundario == "sair" || comando_secundario == "Sair"){
        exit(0);
    }
    if(comando_secundario == "1"){
        product.clear();
        linhas.clear();
        //std::cout << "tamanho vector: " << product.size() << '\n';
        std::string nome_loja, nome_produto, valor, codigo_produto, quantidade, descricao;
        
        std::ifstream arquivo_produto("produto.txt");
        if(arquivo_produto.is_open()){
            while(std::getline(arquivo_produto, linha)){
                linhas.push_back(linha);
            }
            for(unsigned l = 0; l < linhas.size(); l += 6){
                nome_produto = linhas[l + 1];
                Produto nome_produtos(linhas[l + 1], std::stof(linhas[l + 2]), linhas [l + 3], std::stoi(linhas[l + 4]), linhas[l + 5]);
                product.push_back(nome_produtos);
            }
        visualizacao_produtos:

            for(unsigned m = 0; m < (linhas.size()/5); m ++){
                std::cout << "Para comprar um produto digite o numero que corresponde ao produto desejado ou digite 'sair'.\n\n";
                for(unsigned n = 0; n < product.size() ; n++){
                    std::cout << n << ": ";
                    Produto aux = product[n]; 
                    aux.exibir_produto();
                    std::cout << '\n';
                }
                std::cin >> aux1;
                if(aux1 != "sair"){
                produto_1:
                    indice_secundario = std::stoi(aux1);
                    std::cout << product[indice_secundario].get_nome() << std::endl;
                    std::cout << product[indice_secundario].get_valor() << std::endl;
                    std::cout << product[indice_secundario].get_codigo() << std::endl;
                    std::cout << product[indice_secundario].get_quantidade()<< std::endl;
                    std::cout << product[indice_secundario].get_descricao() << std::endl;
                    std::cout << "\n\n Digite 'adicionar' para adicionar ao carrinho" << std::endl;
                    std::cin >> comando_secundario;
                    if(comando_secundario == "adicionar"){
                        std::cout << "Quantos gostaria?\n";
                        std::cin >> quant;
                        carrinho.adicionar_item(product[indice_secundario].get_codigo(), quant);
                        goto visualizacao_produtos;
                    }
                    if(comando_secundario == "voltar"){
                        goto visualizacao_produtos;
                    }
                    else {
                    std::cout << "Comando invalido" << std::endl;
                    goto produto_1;}
                }
                if(aux1 == "sair") {
                        goto pagina_principal;
                    }
            }    
        }
        arquivo_produto.close();
        if (std::remove("produto.txt") != 0){
            std::cout << "Erro no arquivo de usuario" << std::endl;
            exit(1);
        }
        std::ofstream file_product("produto.txt");       //add ao arquivo
        for (const std::string &element : linhas){
            file_product << element << std::endl;
        }
        file_product.close();
        linhas.clear();
        goto pagina_principal;
    }
    if(comando_secundario == "2"){
        std::ifstream arquivo("usuariosClientes.txt", std::ios::in | std::ios::out);
        if (arquivo.is_open()){
            std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo;
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
            std::cout << '\n';
            std::cout << "Usuario:\n" << nomeArquivo << "\n\nSenha:\n" << "**" << "\n\nEmail:\n" << emailArquivo <<  "\n\nCpf:\n" 
                      << cpfArquivo << std::endl;
            std::cout << "\nDigite o que deseja mudar ou digite voltar: usuario, senha, email: " << std::endl;
            std::cin >> comando_secundario;
            comando_secundario = trata_string(comando_secundario);
            std::cout << std::string(15, '\n');

            if(comando_secundario == "usuario"){
                alterar_nome:
                std::cout << "Nome: " << nomeArquivo;
                std::cout << " " << "Gostaria de alterar o nome de usuario? \n" << "S/N" << std::endl;
                std::cin >> comando_secundario;
                if(comando_secundario == "s"){
                    verificar_nome:
                    std::cout << "Qual nome você gostaria?" << std::endl;
                    nomeArquivo = r.validar_usuario();
                    std::cout << "\nO novo nome sera " << nomeArquivo << "?" << std::endl;
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
                        std::cout << "Comando invalido" << std::endl;
                        goto verificar_nome;
                    }
                }
                if(comando_secundario == "n"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando invalido" << std::endl;
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
                    std::cout << "Qual sera a nova senha?" << std::endl;
                    senhaArquivo = r.validar_senha();
                    std::cout << "\nA nova senha sera " << senhaArquivo << "?" << std::endl;
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
                        std::cout << "Comando invalido" << std::endl;
                        goto verificar_senha;
                    }
                }
                if (comando_secundario == "n"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando invalido" << std::endl;
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
                    std::cout << "\nO novo email sera " << emailArquivo << "?" << std::endl;
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
                        std::cout << "Comando invalido" << std::endl;
                        goto verificar_email;
                    }
                }
                if (comando_secundario == "n"){
                    goto visualizacao_perfil;
                }
                else{
                    std::cout << "Comando invalido" << std::endl;
                    goto alterar_email;
                }
            } 
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
        goto  pagina_principal;
    }
    if(comando_secundario == "3"){
        carrinho_usuario:
        carrinho.exibir_carrinho();
        Pagamento aux_pagamento;
        Entrega entrega;

        std::cout << "Gostaria de finalizar a compra?\n" << "S|N" << std::endl;
        std::cin >> comando_secundario;
        comando_secundario = trata_string(comando_secundario);

        if (comando_secundario == "sim" || comando_secundario == "s"){
            aux_pagamento.pagar();
            std::cout << '\n';
            std::cout << "Voce ira receber a entrega..." << std::endl;
            entrega.entregar();
            std::cout << '\n';
            carrinho.limpar_sacola();
            goto pagina_principal;
        }
        if (comando_secundario == "nao" || comando_secundario == "não" || comando_secundario == "n"){
            goto pagina_principal;
        }
        else{
            std::cout<< "Comando nao reconhecido" << std::endl;
            goto carrinho_usuario;
        }

        std::cout << "Voce ira receber a entrega..." << std::endl;
        entrega.entregar();
        
        goto pagina_principal;
    }
}

void loja_main(std::string nome){
    std::string comando_secundario;
    std::vector<std::string> lines;
    std::vector<std::string> produtos;
    std::vector<std::string> linhas;
    std::vector<std::string> produto_loja;
    produto_loja.resize(0);
    std::string linha;
    std::string line;
    unsigned i = 0;
    std::size_t p = 0;
    pagina_principal:
    std::cout << "==============MENU===============" << std::endl;
    std::cout << "1: Produtos \n2: Usuario \n3: Adicionar novo produto \nsair\n" <<std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "Digite o numero referente ao que gostaria de prosseguir ou digite sair." << std::endl;
    std::cin >> comando_secundario;
    comando_secundario = trata_string(comando_secundario);
    if (comando_secundario == "sair"){
        exit(0);
    }
    std::cout << std::string(15, '\n');
    if(comando_secundario == "1"){
        std::string nome_loja, nome_produto, valor, codigo_produto, quantidade, descricao;
        std::ifstream arquivo_produto("produto.txt", std::ios::in | std::ios::out);
        if (arquivo_produto.is_open()){
            while (std::getline(arquivo_produto, linha)){
                linhas.push_back(linha);
            }
            for(std::size_t o = 0; o < linhas.size(); o++){
                if(nome == linhas[o]){
                    unsigned tamanho = produto_loja.size() + 6;
                    produto_loja.resize(tamanho);
                    for(int q = 0; q < 6; q++){
                        produto_loja[p] = linhas[o];
                        p++;
                        o++;
                    } 
                    --o;
                }
            }
            int num_prod = 1;
            for(unsigned r = 0; r < produto_loja.size(); r+=6){
                std::cout<<"Produto "<<num_prod<<":"<<std::endl;
                std::cout << produto_loja[r + 1] << std::endl;
                std::cout << produto_loja[r + 2] << std::endl;
                std::cout << produto_loja[r + 3] << std::endl;
                std::cout << produto_loja[r + 4] << std::endl;
                std::cout << produto_loja[r + 5] << std::endl;
                num_prod++;
                std::cout << '\n';
            }
            visualizacao_produtos:
            std::cout << "Digite o nome do produto que voce gostaria de vizualizar ou digite sair" << std::endl;
            std::cin >> comando_secundario;
            for(unsigned s = 0; s < produto_loja.size(); s++){
                if(comando_secundario == produto_loja[s]){
                produto_escolhido:
                    std::cout << '\n';
                    std::cout << "Nome: " << produto_loja[s] << std::endl;
                    std::cout << "Valor: " << produto_loja[s + 1] << std::endl;
                    std::cout << "Codigo: " << produto_loja[s + 2] << std::endl;
                    std::cout << "Quantidade: " << produto_loja[s + 3] << std::endl;
                    std::cout << "Descricao: " << produto_loja[s + 4] << std::endl;
                    std::cout << '\n';
                    std::cout << "Digite o que deseja alterar: nome, valor, codigo, quantidade ou descricao ou digite sair ";
                    std::cout << '\n';
                    std::cin >> comando_secundario;
                    if(comando_secundario == "sair"){
                        goto pagina_principal;
                    }
                    if(comando_secundario == "nome"){
                    alterar_nome_produto:
                        std::cout << '\n';
                        std::cout << "Gostaria de alterar o nome?\nS/N" << std::endl;
                        std::cin >> comando_secundario;
                        if(comando_secundario == "s"){
                            std::cout << "Digite o novo nome para o produto?" << std::endl;
                            std::cin >> produto_loja[s];
                            std::cout << '\n';
                            goto produto_escolhido;
                        }
                        if(comando_secundario == "n"){
                            goto produto_escolhido;
                        }else 
                        std::cout << "Comando invalido." << std::endl;
                        goto alterar_nome_produto;
                    }
                    if(comando_secundario == "valor"){
                    alterar_valor_produto:
                        std::cout << '\n';
                        std::cout << "Gostaria de alterar o valor do produto?\nS/N" << std::endl;
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                        std::cout << "Digite o novo valor para o produto?" << std::endl;
                        std::cin >> produto_loja[s + 1];
                        std::cout << '\n';
                        goto produto_escolhido;
                        }
                        if (comando_secundario == "n"){
                        goto produto_escolhido;
                        }
                        else
                        std::cout << "Comando invalido." << std::endl;
                        goto alterar_valor_produto;
                    }
                    if(comando_secundario == "codigo"){
                    alterar_codigo_produto:
                        std::cout << '\n';
                        std::cout << "Gostaria de alterar o codigo?\nS/N" << std::endl;
                        std::cin >> comando_secundario;
                        if(comando_secundario == "s"){
                        std::cout << "Digite o novo codigo para o produto?" << std::endl;
                        std::cin >> produto_loja[s + 2];
                        std::cout << '\n';
                        goto produto_escolhido;
                        }
                        if (comando_secundario == "n"){
                        goto produto_escolhido;
                        }
                        else
                        std::cout << "Comando invalido." << std::endl;
                        goto alterar_codigo_produto;
                    }
                    if (comando_secundario == "quantidade"){
                    alterar_quantidade_produto:
                        std::cout << '\n';
                        std::cout << "Gostaria de alterar a quantidade do produto?\nS/N" << std::endl;
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                        std::cout << "Digite a nova quantidade para o produto?" << std::endl;
                        std::cin >> produto_loja[s + 3];
                        std::cout << '\n';
                        goto produto_escolhido;
                        }
                        if (comando_secundario == "n"){
                        goto produto_escolhido;
                        }
                        else
                        std::cout << "Comando invalido." << std::endl;
                        goto alterar_quantidade_produto;
                    }
                    if (comando_secundario == "descricao"){
                    alterar_descricao_produto:
                        std::cout << '\n';
                        std::cout << "Gostaria de alterar a descricao?\nS/N" << std::endl;
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                        std::cout << "Digite a nova descricao para o produto?" << std::endl;
                        std::cin >> produto_loja[s + 4];
                        std::cout << '\n';
                        goto produto_escolhido;
                        }
                        if (comando_secundario == "n"){
                        goto produto_escolhido;
                        }
                        else
                        std::cout << "Comando invalido." << std::endl;
                        goto alterar_descricao_produto;
                    }
                    if(comando_secundario == "sair"){
                            goto pagina_principal;
                        }
                    else{
                        std::cout << "Comando invalido" << std::endl;
                        goto produto_escolhido;
                    }
                }
            }
            if(comando_secundario == "sair"){
                goto pagina_principal;
            }
            else {
                std::cout << "Produto inexistente" << std::endl;
                goto visualizacao_produtos;
            }
        }
        arquivo_produto.close();
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
            std::cout << "Loja:\n" << nomeArquivo<< "\n\nSenha:\n" << "**" << "\n\nEmail:\n" << emailArquivo 
                      << "\n\nCnpj:\n" << cnpjArquivo << "\n\nCep\n" << cepArquivo << std::endl;
            std::cout << "\nDigite o que deseja mudar ou digite voltar: loja, senha, email, cnpj, cep: " << std::endl;
            std::cin >> comando_secundario;            
            comando_secundario = trata_string(comando_secundario);
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                if(comando_secundario == "loja"){
                    alterar_nome:
                    std::cout << "Nome da loja é: " << nomeArquivo;
                    std::cout << ", gostaria de alterar o nome da loja? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if(comando_secundario == "s"){
                        verificar_nome:
                        std::cout << "Qual o novo nome da loja?" << std::endl;
                        nomeArquivo = r.validar_loja();
                        std::cout << "\nO novo nome sera " << nomeArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                        lines[i] = nomeArquivo;
                        std::cout << "\n\n";
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_nome;
                        }
                        else{
                            std::cout << "Comando invalido" << std::endl;
                            goto verificar_nome;
                        }
                    }    
                    if(comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando invalido" << std::endl;
                        goto alterar_nome;
                    }
                }
                
                if (comando_secundario == "senha"){
                alterar_senha:
                    std::cout << "A senha a: " << senhaArquivo;
                    std::cout << ", gostaria de alterar a sua senha? \n"
                              << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if (comando_secundario == "s"){
                    verificar_senha:
                        std::cout << "Qual sera a nova senha?" << std::endl;
                        senhaArquivo = r.validar_senha();
                        std::cout << "\nA nova senha sera " << senhaArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                            lines[i + 1] = senhaArquivo;
                            std::cout << "\n\n";
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_senha;
                        }
                        else{
                            std::cout << "Comando invalido" << std::endl;
                            goto verificar_senha;
                        }
                    }
                    if (comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando invalido" << std::endl;
                        goto alterar_senha;
                    }
                }
                if(comando_secundario == "email"){
                    alterar_email:
                    std::cout << "O email e: " << emailArquivo;
                    std::cout << ", gostaria de alterar o email? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;             
                    if(comando_secundario == "s"){
                    verificar_email:
                        std::cout << "Qual o novo email?" << std::endl;
                        std::cin >> emailArquivo;
                        std::cout << "\nO novo email sera " << emailArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                            lines[i + 2] = emailArquivo;
                            std::cout << "\n\n";
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_email;
                        }
                        else{
                            std::cout << "Comando invalido" << std::endl;
                            goto verificar_email;
                        }
                    }
                    if(comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando invalido" << std::endl;
                        goto alterar_email;
                    }
                }
                if (comando_secundario == "cnpj"){
                alterar_cnpj:
                    std::cout << "O cnpj e: " << cnpjArquivo;
                    std::cout << ", gostaria de alterar o seu Cnpj? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;
                    if (comando_secundario == "s"){
                    verificar_cnpj:
                        std::cout << "Qual o novo cnpj?" << std::endl;
                        cnpjArquivo = r.validar_cnpj();
                        std::cout << "\nO novo cnpj sera " << cnpjArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                            lines[i + 3] = cnpjArquivo;
                            std::cout << "\n\n";
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_cnpj;
                        }
                        else{
                            std::cout << "Comando invalido" << std::endl;
                            goto verificar_cnpj;
                        }
                    }
                    if (comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando invalido." << std::endl;
                        goto alterar_cnpj;
                    }
                }
                if(comando_secundario == "cep"){
                    alterar_cep:
                    std::cout << "O cep e: " << cepArquivo;
                    std::cout << ", gostaria de alterar o seu Cep? \n" << "S/N" << std::endl;
                    std::cin >> comando_secundario;                
                    if (comando_secundario == "s"){
                    verificar_cep:
                        std::cout << "Qual sera o novo cep?" << std::endl;
                        cepArquivo = r.validar_cep();
                        std::cout << "\nO novo cep sera " << cepArquivo << "?" << std::endl;
                        std::cout << "S/N?\n";
                        std::cin >> comando_secundario;
                        if (comando_secundario == "s"){
                            lines[i + 4] = cepArquivo;
                            std::cout << "\n\n";
                            goto visualizacao_perfil;
                        }
                        if (comando_secundario == "n"){
                            goto verificar_cep;
                        }
                        else{
                            std::cout << "Comando invalido" << std::endl;
                            goto verificar_cep;
                        }
                    }
                    if(comando_secundario == "n"){
                        goto visualizacao_perfil;
                    }
                    else{
                        std::cout << "Comando invalido." << std::endl;
                        goto alterar_cep;
                    }
                }
                if(comando_secundario == "voltar"){
                    goto pagina_principal;
                } else{
                std::cout << "Comando invalido." << std::endl;
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
    if(comando_secundario == "3"){
        add_estoque:
        Estoque estoque_aux;
        estoque_aux.incluir_estoque(nome);
        std::cout<<"Gostaria de adicionar outro produto?" << "\n S/N" << std::endl;
        std::cin >> comando_secundario;
        comando_secundario = trata_string(comando_secundario);
        if (comando_secundario == "sim" || comando_secundario == "s"){
            goto add_estoque;
        }
        if (comando_secundario == "nao" || comando_secundario == "não" || comando_secundario == "n"){
            goto pagina_principal;
        }
        else{
            std::cout<< "Comando nao reconhecido" << std::endl;
            goto add_estoque;
        }
    }
    else{
        std::cout << "Comando invalido\n" << "Tente novamente" << std::endl;
        goto pagina_principal;
    }
}