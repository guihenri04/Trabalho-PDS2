#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include "filme.hpp"
#include "cliente.hpp"
#include "DVDestoque.hpp"
#include "DVDlancamento.hpp"
#include "DVDpromocao.hpp"
#include "fita.hpp"
#include <vector>
#include <algorithm>
using namespace std;

class Locadora {
private:
  vector<Filme*> filmes;
  vector<Cliente*> clientes;
public:
  Locadora();
  void cadastrarFilme(string tipo, int quantidade, int id, const string& titulo, const string& categoria);
  void removerFilme(int codigo);
  void listarFilmes(char opcao);
  void cadastrarCliente(int cpf, string nome);
  void removerCliente(int cpf);
  void listarClientes(char opcao);
  void aluguel(int cpf, int id);
  void devolucao(Filme* filme, Cliente* cliente);
};

#endif