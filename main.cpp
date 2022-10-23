#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;

void Jogo(int tentativas, int tamanho, int arrayValores[]);
void Menu();


int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    Menu();
    return 0;
}


void Jogo(int tamanho, int tentativas, int arrayValores[])
{
    int iguais = 0, controleTentativas = 0, controleTamanho, controleLugar = 0, controleQTD = 0;
    int *TentantivaResposta = new int [tentativas];

    do
    {
        iguais = 0;

        for(int i = 0 ; i < tamanho; i++)
        {
            arrayValores[i] = rand() % 7 + 1;
        }


        for(int i = 0 ; i < tamanho; i ++)
        {
            for(int j = i + 1; j < tamanho; j++)
            {
                if (arrayValores[i] == arrayValores[j])
                    iguais++;
            }
        }


    } while(iguais != 0);

    //PROVA REAL
    for(int i = 0 ; i < tamanho; i++){
        cout << arrayValores[i] << "\t";
    }


    while( controleTentativas < tentativas){
        cout << "Tentativa " << controleTentativas <<  " de " << tentativas << " possíveis!" << endl;
        cout << "Aguardando os " << tamanho << " valores da tentativa: ";
        for(int i = 0 ; i < tamanho ; i++)
        {
            cout << "..." << endl;
            cin >> TentantivaResposta[i];
        }

        //LAÇOS E CONDIÇÕES PARA VERIFICAR A QUANTIDADE  NÚMEROS CORRETOS E NOS LOCAIS CORRETOS
        for(int i = 0 ; i < tamanho ; i++)
        {
            if(TentantivaResposta[i] == arrayValores[i])
                controleLugar++;
            for (int j = 0 ; j< tamanho; j++)
            {
            if(TentantivaResposta[i] == arrayValores[j])
                controleQTD++;
            }
        }

        cout << controleQTD << "(s) acertos de número" << endl;
        cout << controleLugar << "(s) No lugar correto" << endl;

        controleTentativas += 1;

        if(controleTentativas == tentativas){
            cout << "Você perdeu! Os valores eram: ";
            for (int i = 0 ; i < tamanho; i ++){
                cout << arrayValores[i] << "\t";
            }
        }

        for(int i = 0 ; i < tamanho; i++)
        {
            if(TentantivaResposta[i] == arrayValores[i])
                controleTamanho ++;
            if(controleTamanho == tamanho - 1){
                cout << endl << "Você Venceu com "<< tentativas - controleTentativas << " tentativas restando";
                controleTentativas = tentativas;
            }
        }

        delete[] TentantivaResposta;
        TentantivaResposta = NULL;
    }

    delete[] TentantivaResposta;
    TentantivaResposta = NULL;
}

void Menu(){
    int escolha, facilValores[3] = {0}, medioValores[4] = {0}, dificilValores[5] = {0};
    
    do{
    cout << "\t___________________________________________" << endl;
    cout << "\t|-----------------------------------------|" << endl;;
    cout << "\t|--------------Fácil - 1------------------|" << endl;;
    cout << "\t|--------------Médio - 2------------------|" << endl;;
    cout << "\t|-------------Dificil - 3-----------------|" << endl;;
    cout << "\t|------------Créditos - 4-----------------|" << endl;;
    cout << "\t|-----------------------------------------|" << endl;;
    cout << "\t|_________________________________________|" << endl;;
    cin >> escolha;
    } while (5 > escolha < 0);


    switch (escolha)
    {
    case 1:
        Jogo(3, 1, facilValores);
        break;

    case 2:
        Jogo(4, 10, medioValores);
        break;
    
    case 3:
        Jogo(5, 12, dificilValores);
        break;
    
    default:
        cout << endl << 
                "\tProduzido por João Pedro Gubertt, para ajuda" << endl << 
                "\tde um amigo e para treinar aspectos tanto de" << endl << 
                "\tprimeiro módulo de Algoritmo e Programação" << endl;
        cout << "\tquanto do segundo";
        break;
    }
    return;
}
