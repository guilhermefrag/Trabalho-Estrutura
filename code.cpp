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

Pedido criaPedido(string cardapio[],int codLanche){
    Pedido pedido;
    cout << "Digite o codigo do lanche: ";
    cin >> pedido.codLanche;
    cout << "Digite o valor do pedido: ";
    cin >> pedido.valor;
    pedido.descricao = cardapio[codLanche];
    cout << "Digite o nome do cliente: ";
    cin >> pedido.nomeCliente;

    return pedido;
}


void imprimeMenu(string cardapio[]){
    cout << "---------Escolha um lanche---------" << endl;
    for(int i = 0; i < 10; i++){
        cout << i << "-" << cardapio[i] << endl;
    }
}

int main(){
    string cardapio[10] = {"Sair","X-Burguer", "X-Bacon", "X-Egg", "X-Galinha", "X-GalinhaBacon", "X-Tudo", "X-Casa","X-Calabresa", "X-Coração"};
    queue<Pedido> pedidos;
    int opcao;

    do{
        imprimeMenu(cardapio);
        cin >> opcao;
        switch(opcao){
            case 0:
                cout << "Saindo..." << endl;
                break;
            case 1:
                Pedido pedido =  criaPedido(cardapio,opcao); 
                pedido.codPedido = pedidos.size()+1;
                pedidos.push(pedido);
                break;
        }
    }while(opcao != 0);
    
    

}