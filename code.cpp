#include<stdio.h>
#include<queue>
#include<iostream>
#include <array>
#include <string>
#include <locale.h>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using namespace std;

struct Pedido{
    int codPedido;
    int codLanche;
    float valor;
    string descricao;
    string nomeCliente;
};

Pedido criaPedido(Pedido *pedido,int codLanche,float valor, string cardapio[],string nomeCliente){
    pedido->codLanche = codLanche;
    pedido->valor = valor;
    pedido->descricao = cardapio[codLanche];
    pedido->nomeCliente = nomeCliente;

    return *pedido;
}



void imprimeMenu(string cardapio[]){
    for(int i = 1; i < 10; i++){
        cout << i << "-" << cardapio[i] << endl;
    }
}

int main(){
    string cardapio[10] = {"Não existe","X-Burguer", "X-Bacon", "X-Egg", "X-Galinha", "X-GalinhaBacon", "X-Tudo", "X-Casa","X-Calabresa", "X-Coração"};
    imprimeMenu(cardapio);
    queue<Pedido> pedidos;

}