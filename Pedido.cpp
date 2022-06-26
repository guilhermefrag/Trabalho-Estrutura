#include <iostream>
#include <queue>
using namespace std;

//LISTA DO TIPO FIFO

class Pedido{
   public:
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
      Pedido(){ //se precisar inicializar em branco
            this->codLanche = 0;
            this->descricao = "";
            this->nomeCliente = "";
            this->valor = 0;
      }
      
      ~Pedido() { //Destruidor ???????????? só deixar em branco
      }

      void print() { //isso a gente nem ta usando
         cout << (codLanche, valor, descricao, nomeCliente) << endl;
      }
};

void imprimeMenu(string cardapio[]){
    cout << "---------Escolha um lanche---------" << endl;
    for(int i = 0; i < 10; i++){
        cout << i << "-" << cardapio[i] << endl;
    }
    cout << "---------------Opções--------------" << endl;
    cout << "10 - Listar Pedidos" << endl;
    cout << "11 - Faturar Pedido" << endl;
    cout << "12 - Quantidade de Pedidos" << endl;
    cout << "13 - Ultimo Pedido Feito" << endl;
    cout << "14 - Primeiro Pedido Feito" << endl;
    cout << "15 - Insere no Fim da Lista" << endl;
    cout << "---------------------------------";
}

void imprimePedido(queue<Pedido> pedidos){
    cout << "---------Pedidos---------" << endl;
    int codigoPedido;
    int codigoLanche;
    float valorPedido;
    string descricaoPedido;
    string nomeClientePedido;

    while(!pedidos.empty()){
        codigoPedido = pedidos.front().codPedido;
        codigoLanche = pedidos.front().codLanche; 
        valorPedido = pedidos.front().valor; 
        descricaoPedido = pedidos.front().descricao; 
        nomeClientePedido = pedidos.front().nomeCliente; 
        cout << "Codigo do pedido: " << codigoPedido << endl;
        cout << "Codigo do lanche: " << codigoLanche << endl;
        cout << "Valor do pedido: " << valorPedido << endl;
        cout << "Descricao do pedido: " << descricaoPedido << endl;
        cout << "Nome do cliente: " << nomeClientePedido << endl;
        pedidos.pop();
        cout << "---------------------------------" << endl;
    }
}

void criaPedido(queue<Pedido> &pedidos,string cardapio[], int codLanche, float valor){
    Pedido pedido;
    pedido.descricao = cardapio[codLanche];
    cout << "Digite o nome do cliente: ";
    cin >> pedido.nomeCliente;
    pedido.codPedido = pedidos.size()+1;
    pedidos.push(pedido);
}

void quantiadePedido(queue<Pedido> &pedidos){
    cout << "Quantidade de pedidos: " << pedidos.size() << endl;
}

void faturaPedido(queue<Pedido> &pedido){
    pedido.pop();
}

void retornaUltimo(queue<Pedido> &pedidos){
    cout << "---------------------------------";
    cout << "Ultimo pedido: " << endl;
    cout << "Codigo do pedido: " << pedidos.back().codPedido << endl;
    cout << "Codigo do lanche: " << pedidos.back().codLanche << endl;
    cout << "Valor do pedido: " << pedidos.back().valor << endl;
    cout << "Descricao do pedido: " << pedidos.back().descricao << endl;
    cout << "Nome do cliente: " << pedidos.back().nomeCliente << endl;
    cout << "---------------------------------";
}

void retornaPrimeiro(queue<Pedido> &pedidos){
    cout << "---------------------------------";
    cout << "Primeiro pedido: " << endl;
    cout << "Codigo do pedido: " << pedidos.front().codPedido << endl;
    cout << "Codigo do lanche: " << pedidos.front().codLanche << endl;
    cout << "Valor do pedido: " << pedidos.front().valor << endl;
    cout << "Descricao do pedido: " << pedidos.front().descricao << endl;
    cout << "Nome do cliente: " << pedidos.front().nomeCliente << endl;
    cout << "---------------------------------";
}

void insereFinal(queue<Pedido> &pedidos, Pedido pedido){
    pedidos.push(pedido);
}

int main() {
   // FIFO
   string cardapio[10] = {"Sair","X-Burguer", "X-Bacon", "X-Egg", "X-Galinha", "X-Galinha Bacon", "X-Tudo", "X-Casa","X-Calabresa", "X-Coração"};
   queue<Pedido> pedidos;
   cout << cardapio[1] << endl;
   int opcao;

    do{
        imprimeMenu(cardapio);
        cin >> opcao;
        switch(opcao){
            //Sair
            case 0:
                cout << "Saindo..." << endl;
                break;
            //Burguer
            case 1:
                criaPedido(pedidos,cardapio, opcao, 10.0);
                break;
            //Bacon
            case 2:
                criaPedido(pedidos,cardapio, opcao, 13.0);
                break;
            //Egg
            case 3:
                criaPedido(pedidos,cardapio, opcao, 12.0);
                break;
            //Galinha
            case 4:
                criaPedido(pedidos,cardapio, opcao, 11.0);
                break;
            //GalinhaBacon
            case 5:
                criaPedido(pedidos,cardapio, opcao, 14.0);
                break;
            //Tudo
            case 6:
                criaPedido(pedidos,cardapio, opcao, 15.0);
                break;
            //Casa
            case 7:
                criaPedido(pedidos,cardapio, opcao, 20.0);
                break;
            //Calabresa
            case 8:
                criaPedido(pedidos,cardapio, opcao, 17.0);
                break;
            //Coração
            case 9:
                criaPedido(pedidos,cardapio, opcao, 18.0);
                break;
            //Listar Pedidos
            case 10:
                imprimePedido(pedidos);
                break;
            //Faturar Pedido(Primeiro da Lista)
            case 11:
                cout << "Faturando Pedido...." << endl;
                faturaPedido(pedidos);
                break;
            //Quantidade de Pedidos
            case 12:
                quantiadePedido(pedidos);
                break;
            //Ultimo Pedido Feito
            case 13:
                retornaUltimo(pedidos);
                break;
            //Primeiro Pedido Feito
            case 14:
                retornaPrimeiro(pedidos);
                break;
        }
    }while(opcao != 0);

    return 0;
}