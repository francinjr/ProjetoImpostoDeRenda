#include <iostream>
#include <string>
#include <cctype>
#include <locale>

using namespace std;

struct rendimentosTributaveis {
    float receita;
    float pensao;
    float aposentadoria;
    float aluguel;
};

void maiorOuIgualaZero(float valor);
void getDadosRT(rendimentosTributaveis* ptr);
void imprimirReceitaImposto(float* ptr, float* ptr2);
float getValor(string msg);

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    rendimentosTributaveis rT;
    float imposto = 0;
    string nome;
    char sn;
    int qnt_dependente;
    float pensao_alimenticia;
    float educacao;
    float saude;

    cout << "Insira o seu nome completo: ";
    getline(cin, nome);
    getDadosRT(&rT);

    if (rT.receita > 22847.76) {
        if (rT.receita >= 22847.77 && rT.receita <= 33919.80) {
            imposto = rT.receita * 0.075f;
            imprimirReceitaImposto(&rT.receita, &imposto);
        }
        else if (rT.receita >= 33919.81 && rT.receita <= 45012.60) {
            imposto = rT.receita * 0.15f;
            imprimirReceitaImposto(&rT.receita, &imposto);
        }
        else if (rT.receita >= 45012.61 && rT.receita <= 55976.16) {
            imposto = rT.receita * 0.225f;
            imprimirReceitaImposto(&rT.receita, &imposto);
        }
        else {
            imposto = rT.receita * 0.275f;
            imprimirReceitaImposto(&rT.receita, &imposto);
        }
    }
    else {
        imprimirReceitaImposto(&rT.receita, &imposto);

    }

    cout << "Deseja incluir dependente(s)? [S/N] " << endl;
    cin >> sn;
    sn = toupper(sn);
    if (sn == 'S') {
        cout << "Insira o número de dependentes: ";
        cin >> qnt_dependente;
        maiorOuIgualaZero(qnt_dependente);
    }
    cout << "Realiza pagamento de pensão alimentícia? [S/N] ";
    cin >> sn;
    sn = toupper(sn);
    if (sn == 'S') {
        cout << "Digite o valor do pagamento: ";
        cin >> pensao_alimenticia;
        maiorOuIgualaZero(pensao_alimenticia);
    }
    cout << "Possui gastos com educação? [S/N] ";
    cin >> sn;
    sn = toupper(sn);
    if (sn == 'S') {
        cout << "Digite o valor dos gastos: ";
        cin >> educacao;
        maiorOuIgualaZero(educacao);
    }
    cout << "Possui gastos com saúde? [S/N] ";
    cin >> sn;
    sn = toupper(sn);
    if (sn == 'S') {
        cout << "Digite o valor dos gastos: ";
        cin >> saude;
        maiorOuIgualaZero(saude);
    }
}

void imprimirReceitaImposto(float* ptr, float* ptr2) {
    cout << "Receita anual: " << *ptr << endl;
    cout << "Imposto a pagar: " << *ptr2 << endl << endl;
}

void getDadosRT(rendimentosTributaveis* ptr) {

    ptr->receita = getValor("receita");
    ptr->aposentadoria = getValor("aposentadoria");
    ptr->aluguel = getValor("aluguel");
    ptr->pensao = getValor("pensao");
}

float getValor(string msg)
{
    float valor;
    do {
        cout << "Digite " << msg << ": ";
        cin >> valor;
        if (valor < 0) {
            cout << "Valor inválido (deve ser um número maior ou igual a zero)." << endl;
        }
    } while (valor < 0);
    return valor;
}

void maiorOuIgualaZero(float valor) {
    while (valor < 0) {
        cout << "Valor inválido (deve ser um número maior ou igual a zero)." << endl;
        cin >> valor;
    }
}