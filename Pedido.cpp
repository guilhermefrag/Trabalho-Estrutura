#include <iostream>
#include <queue>
using namespace std;

class Pedido{
   private:
        int codPedido;
        int codLanche;
        float valor;
        string descricao;
        string nomeCliente;
   public:
      Pedido(int codLanche,float valor,string descricao,string nomeCliente ){
          this->codLanche = codLanche;
          this->descricao = descricao;
          this->nomeCliente = nomeCliente;
          this->valor = 0;
      }
      

      ~Pedido() {
        cout << "Object Destroyed" << endl;
      }

      void print() {
         cout << (codLanche ) << endl;
      }
};

void imprimeMenu(string cardapio[]){
    cout << "---------Escolha um lanche---------" << endl;
    for(int i = 0; i < 10; i++){
        cout << i << "-" << cardapio[i] << endl;
    }
}

int main() {
   // FIFO
   string cardapio[10] = {"Sair","X-Burguer", "X-Bacon", "X-Egg", "X-Galinha", "X-GalinhaBacon", "X-Tudo", "X-Casa","X-Calabresa", "X-Coração"};
   queue<Pedido> pedidos;
   pedidos.push(Pedido(2, 3.8,"X-Burguer", "Pankaj"));

   int opcao;

    do{
        imprimeMenu(cardapio);
        cin >> opcao;
        switch(opcao){
            case 0:
                cout << "Saindo..." << endl;
                break;
            case 1:
                pedidos.push(Pedido(opcao,3.8,cardapio[opcao],"Jefersson"));
                break;
        }
    }while(opcao != 0);

   // Traverse over queue
   while(pedidos.size()) {
      pedidos.front().print();
      pedidos.pop();
   }

   return 0;
}