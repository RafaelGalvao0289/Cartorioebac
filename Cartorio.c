#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro() //Função responsavel por cadastrar os usuários no sistema
{
    //Inicio da criação de variáveis/strings
 	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n"); //Coletando informação do Usuário
	scanf("%s", &cpf); //lê o CPF à ser cadastrado (%s refere-se à strings)
	
	strcpy(arquivo, cpf); //Responsavel por copiar a variavel no nome do arquivo
	FILE *file; // cria o arquivo
	
	file = fopen(arquivo, "w"); //abre o arquivo, com a função W = Write = escrever
	fprintf(file, "CPF: "); //escreve CPF: antes da entrada da variavel
    fprintf(file,cpf); //salva o valor da variavel CPF
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,"\nNOME: "); //acrescenta a virgula NOME após o valor escrito
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //pergunta o nome à ser cadastrado
	scanf("%s", &nome); //lê o nome à ser cadastrado
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,nome); //acrescenta o nome ao arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,"\nSOBRENOME: "); //acrescenta a virgula SOBRENOME após o valor escrito
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: \n");  //pergunta o sobrenome à ser cadastrado
	scanf("%s", &sobrenome); //lê o sobrenome à ser cadastrado
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,sobrenome); //acrescenta o sobrenome ao arquivo
	fclose(file); //fecha o arquivo
	 
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,"\nCARGO: "); //acrescenta a virgula CARGO após o valor escrito
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: \n");  //pergunta o cargo à ser cadastrado
	scanf("%s", &cargo); //acrescenta o cargo ao arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = alterar
	fprintf(file,cargo);  //acrescenta o cargo ao arquivo
	fprintf(file,"\n\n"); //acrescenta duas linhas abaixo do virgula CARGO
	fclose(file); //fecha o arquivo
    	
    system("pause");
    
}

int consulta() //Função responsavel por consultar os usuários no sistema
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40]; //traz a variavel CPF para função
    char conteudo[200]; //traz a variavel Conteúdo para função
    	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf); //armazenando a variavel "cpf" utilizado a função string "%s"
      	
    FILE *file;
    file = fopen(cpf,"r"); //Abre o arquivo CPF, com a função "R" de Read(Ler) a informação
      	
    if(file == NULL) //Se a informação não existir traz a seguinte informação.
    {
    	printf("\nNão foi possivel abrir o arquivo, registro não localizado!.\n");
    }
    	
    printf("\nEssas são as informações do usuário: \n\n"); //Informação para aparecer antes dos dados
    
    while(fgets(conteudo, 200, file)!= NULL) //While (enquanto) tiver informação, armazene a informação em conteudo se for diferente de NULL (nulo)
    {
    	printf("%s", conteudo); //Traz as informações salvas (%s) como string e apresenta ao usuário
    }
    
    fclose(file);
    system ("pause");

}

int deletar() //Função responsavel por deletar os usuários do sistema
{
	char cpf[40]; //traz a variavel CPF para função
	 
	printf("Digite o CPF do usuário à ser deletado: "); //pergunta o CPF à ser deletado
	scanf("%s",cpf); //lê o CPF à ser deletado
	
	FILE *file;
    file = fopen(cpf,"r"); //Abre o arquivo CPF, com a função "R" de Read(Ler) a informação
                    
	if(file == NULL) //se o arquivo nao existir
    {
       printf("\nO usuário não se encontra registrado no sistema.\n\n");
	   system("pause");	
	}
	
	else
	{
	    printf("\nRegistro deletado com sucesso!.\n\n"); //mensagem de confirmação de exclusão
        system("pause");
        fclose(file); //fecha o arquivo para que possa ser excluido
    }
    
    remove(cpf); //determina que o registro seja deletado
 
}

int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //responsável por limpar à tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar à tela
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
