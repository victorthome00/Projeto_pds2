#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <iostream>

class Estoque;
class Carrinho; 
class Usuario{
public:
    Usuario(const std::string login, const std::string senha, const std::string endereco,
            const std::string codigo_usuario, const std::string nome_usuario);
    void trocar_senha(std::string nova_senha);
    void trocar_end(std::string novo_end);
    void trocar_nome(std::string novo_nome);
    virtual std::string gerador_codigo() = 0;
    virtual ~Usuario();

protected:
    std::string login() const;
    std::string senha() const;
    std::string endereco() const;
    std::string nome_usuario() const;
};

class Cliente : public Usuario{
public:
    friend class Carrinho;
    Cliente(std::string login, std::string senha, std::string endereco, std::string codigo_usuario,
            std::string nome_usuario);
    void trocar_senha(std::string nova_senha);
    void trocar_end(std::string novo_end);
    void trocar_nome(std::string novo_nome);
    std::string gerador_codigo();

private:
    std::string login() const;
    std::string nome_usuario() const;
    std::string senha() const;
    std::string endereco() const;
};

class Loja : public Usuario{
public:
    friend class Estoque;
    Loja(std::string login, std::string senha, std::string endereco, std::string codigo_usuario, 
         std::string nome_usuario);
    void trocar_senha(std::string nova_senha);
    void trocar_end(std::string novo_end);
    void trocar_nome(std::string novo_nome);
    vstd::string gerador_cogido();

private:
    std::string login() const;
    std::string nome_usuario() const;
    std::string senha() const;
    std::string endereco() const;
};

struct TreeNode {
  int value;
  TreeNode* left;
  TreeNode* right;
};

struct TreeType {
  TreeNode* root;

  void insert(TreeNode* tree, int item);

  void insertItem(int value) {
    insert(root, value);
  }
};

void TreeType::insert(TreeNode* tree, int number) {
  if (tree == NULL) {
    tree = new TreeNode;
    tree->left = NULL;
    tree->right = NULL;
    tree->value = number;
    cout << "DONE";
  } else if (number < tree->value) {
    insert(tree->left, number);
  } else {
    insert(tree->right, number);
  }
}

#endif
