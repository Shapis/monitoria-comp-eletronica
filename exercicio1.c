#include <stdio.h>

/*
Juquinha conseguiu seu primeiro emprego numa firma de advocacia, e a primeira tarefa que lhe foi atribuída foi contar quantas palavras havia em cada página de um certo processo. Sendo o rapaz com inclinação a programação que ele é, e que entende que tarefas tediosas podem, e devem ser automatizadas. Ele resolveu escrever um programa para fazer isso por ele.
 
Escreva um programa que receba um certo número de strings, e imprima em ordem quantas palavras havia em cada uma delas.
 
Os dados que serão inseridos serão da seguinte forma: Primeiro o número de páginas, e depois o conteúdo de cada página. As páginas terão no máximo 100 caracteres, e todas palavras serão separadas por um espaço, todas páginas terão pelo menos uma palavra.
 
Por exemplo:
 
3
"Eu não sei quem roubou aquela bolsa. Mas sei que não fui eu."
"Claro meu amigo, essa ponte pode ser sua por meros cinquenta reais."
"Sinta-se à vontade para deixar as chaves do seu carro comigo. Sou de confiança."
 
 
Este exemplo deve imprimir em ordem e exatamente neste formato: 13, 12, 14.
 
 
Sugestões/Dicas:
 
Utilize um vetor para guardar as strings recebidas pelo programa.
 
Crie uma função que receba um string e retorne um inteiro correspondendo a  quantas palavras havia naquele string.
 
Lembre-se que vetores quando são passados para funções são passados por referência, e não por cópia: Logo use ponteiros!
 
Guarde seus resultados em um vetor de resultados.
 
Crie uma condição if-else para formatar o seu resultado corretamente com vírgulas e ponto final.
 
Itere sobre este vetor para imprimir os resultados.
*/

int quantasPalavrasNaFrase(char *frase)
{
    int temp = 1;
    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] == ' ' && frase[i + 1] != ' ' && frase[i + 1] != '\0')

            temp++;
    }
    return temp;
}

int main()
{
    // A variável que guardará quantas frases serão inseridas no programa.
    int n;

    // Recebendo do usuário a quantidade de frases que serão inseridas no programa.
    scanf("%d", &n);

    // Criando um vetor para guardar quantas palavras há em cada frase que o usuário inserirá.
    int resultados[n];

    // Criando um vetor de vetores char(strings) com tamanho 1 a mais do que o tamanho máximo de cada frase para incluir o caracter \0, que demarca o final da frase.
    char minhaFrases[n][101];

    // Iterando o número de vezes que o usuário indicou, e que guardamos como variável n, e atribuindo iterativamente ao nosso vetor que guardará as strings.
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", minhaFrases[i]);
    }

    //  Passamos cada string para a função que conta quantas palavras há na devida string, e retornamos esse valor guardando iterativamente no vetor resultados. detalhe: Poderíamos juntar esse passo ao passo anterior sem problemas.
    for (int i = 0; i < n; i++)
    {
        resultados[i] = quantasPalavrasNaFrase(minhaFrases[i]);
    }

    // Iterando o número de vezes que o usuário indicou. Imprimimos os resultados, utilizando vírgula se não for o último dígito do problema, e ponto final se for.
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            printf("%d, ", resultados[i]);
        }
        else
        {
            printf("%d.\n", resultados[i]);
        }
    }
}