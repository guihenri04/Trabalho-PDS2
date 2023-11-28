#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <sstream>
#include "../Filmes/filme.hpp"
#include "../Cliente/cliente.hpp"

using namespace std;
enum Metodo {ler_filme, ser_alugado, ser_avaliado  };

#include "../Filmes/Subclasses/DVDestoque.hpp"

    dvdEstoque dvdE(1, "Divergente", 0);
    Filme* filme1=&dvdE;
    dvdEstoque dvdE2(1, "Divergente", 2);
    Filme* filme2=&dvdE2;

string saida_filme(Filme* filme, Metodo metodo){
stringstream saida;
auto cout_saida = cout.rdbuf();
cout.rdbuf(saida.rdbuf());
if( metodo == ler_filme){
filme->lerFilme();
}else if(metodo == ser_alugado){
filme->serAlugado();
}else if (metodo == ser_avaliado){
filme->serAvaliado(6);
}
cout.rdbuf(cout_saida);
return saida.str();
}

TEST_CASE("Filmes-lerFilme"){
    CHECK(saida_filme(filme1, ler_filme) == "1 Divergente 0 DVD\n");
}

TEST_CASE("Filmes-serAlugado"){
    filme2->serAlugado();
    CHECK(filme2->unidades == 1); 
    CHECK(saida_filme(filme1, ser_alugado) == "ERRO: filme indisponivel\n");  
}

TEST_CASE ("Filmes-serDevolvido"){
    filme2->serDevolvido();
    CHECK(filme2->unidades == 2);
}

TEST_CASE("Filmes-serAvaliado"){
    filme2->serAvaliado(2);
    CHECK(filme2->avaliacao == 3.5);
    filme2->serAvaliado(2);
    CHECK(filme2->avaliacao == 3);
    // test de avaliação superior a 5
    CHECK(saida_filme(filme2, ser_avaliado) == "ERRO: O filme pode ser avaliado em no máximo 5\n");

    
}