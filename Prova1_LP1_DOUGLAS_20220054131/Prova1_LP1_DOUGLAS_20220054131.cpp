/**
 * @file Prova 1 - LP1.cpp
 * @brief Implementação da classe Funcionário, ordenação de funcionários por salário e aumento de salário
 * @author Douglas Felipe de Lima Silva (20220054131)
 * @since 09/05/2023
 * @date 10/05/2023
*/


//Incluindo as bibliotecas necessárias
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; // P/ evitar repetições do sts 

 /**
     * @brief Construtor da classe Aluno
      *@param nome Nome do funcionário
    *@param salario Salário do funcionário
    */
class Funcionario 
{
public:
    string nome;
    double salario;

    Funcionario(string nome, double salario)
    {
        this->nome = nome;
        this->salario = salario;
    }


 /**
     * @brief Função para aumentar o salário do funcionário
     */
    void aumentarSalario(int percAumento) 
    {
        salario *= (1 + percAumento/100.0);
    }
/**
     * @brief Sobrecarga do operador de incremento
     */
    Funcionario& operator++() 
    { 
        salario *= 1.1; // incrementa 10% fixos
        return *this;
    }
};

/**
     * @brief Função para imprimir os funcionários e seus salários 
     */
void printFuncionarios(vector<Funcionario>& funcionarios) 
{
    for (auto& f : funcionarios) 
    {
        cout << "Nome: " << f.nome << " | Salario: " << f.salario << endl;
    }
    cout << endl;
}

/**
     * @brief Função para ordenar os funcionários por salário (maior para menor)
     */
void bubblesort_maior(vector<Funcionario>& funcionarios) 
{
    int n = funcionarios.size();
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (funcionarios[j].salario < funcionarios[j+1].salario) 
            {
                swap(funcionarios[j], funcionarios[j+1]);
            }
        }
    }
}

/**
     * @brief Função para ordenar os funcionários por salário (menor para maior)
     */
void bubblesort_menor(vector<Funcionario>& funcionarios) 
{
    int n = funcionarios.size();
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (funcionarios[j].salario > funcionarios[j+1].salario) 
            {
                swap(funcionarios[j], funcionarios[j+1]);
            }
        }
    }
}

/**
     * @brief Função principal
     */
int main() 
{
    vector<Funcionario> funcionarios;
    string nome;
    double salario;

    /**
     * @brief Loop para adicionar funcionários e seus salários 
     */

    while (true) {
        cout << "Informe o nome do funcionario ou 'X' para finalizar: ";
        cin >> nome;

        if (nome == "X") 
        {
            break;
        }

        cout << "Informe o salario do funcionario: ";
        cin >> salario;

        /**
     * @brief Adicionando funcionários e seus salários ao vetor 
     */
        Funcionario novoFuncionario(nome, salario);
        funcionarios.push_back(novoFuncionario);

        cout << "Funcionarios: " << endl;
        printFuncionarios(funcionarios);

        cout << "Deseja aumentar o salario de algum funcionario? (Y/N): ";
        char resposta;
        cin >> resposta;

        /**
     * @brief Loop para aumentar o salário de algum funcionário
     */
        if (resposta == 'Y') 
        {
            cout << "Informe o i do funcionário: ";
            int indice;
            cin >> indice;

            if (indice >= 0 && indice < funcionarios.size()) 
            {
                cout << "Informe: ";
                int percAumento;
                cin >> percAumento;

                funcionarios[indice].aumentarSalario(percAumento);
            }
        }
    }

/**
     * @brief Função para ordenar os funcionários por salário (maior para menor)
     */
    bubblesort_maior(funcionarios);
    cout << "Ordenado por maior salario:" << endl;
    printFuncionarios(funcionarios);


/**
     * @brief Função para ordenar os funcionários por salário (menor para maior)
     */
    bubblesort_menor(funcionarios);
    cout << "Ordenado por menor salario:" << endl;
    printFuncionarios(funcionarios);

    return 0;
}
