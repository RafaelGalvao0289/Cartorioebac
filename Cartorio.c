#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
    //Inicio da cria��o de vari�veis/strings
 	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n"); //Coletando informa��o do Usu�rio
	scanf("%s", &cpf); //l� o CPF � ser cadastrado (%s refere-se � strings)
	
	strcpy(arquivo, cpf); //Responsavel por copiar a variavel no nome do arquivo
	FILE *file; // cria o arquivo
	
	file = fopen(arquivo, "w"); //abre o arquivo, com a fun��o W = Write = escrever
	fprintf(file, "CPF: "); //escreve CPF: antes da entrada da variavel
    fprintf(file,cpf); //salva o valor da variavel CPF
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,"\nNOME: "); //acrescenta a virgula NOME ap�s o valor escrito
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //pergunta o nome � ser cadastrado
	scanf("%s", &nome); //l� o nome � ser cadastrado
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,nome); //acrescenta o nome ao arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,"\nSOBRENOME: "); //acrescenta a virgula SOBRENOME ap�s o valor escrito
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: \n");  //pergunta o sobrenome � ser cadastrado
	scanf("%s", &sobrenome); //l� o sobrenome � ser cadastrado
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,sobrenome); //acrescenta o sobrenome ao arquivo
	fclose(file); //fecha o arquivo
	 
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = adicionar
	fprintf(file,"\nCARGO: "); //acrescenta a virgula CARGO ap�s o valor escrito
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: \n");  //pergunta o cargo � ser cadastrado
	scanf("%s", &cargo); //acrescenta o cargo ao arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para "a" = alterar
	fprintf(file,cargo);  //acrescenta o cargo ao arquivo
	fprintf(file,"\n\n"); //acrescenta duas linhas abaixo do virgula CARGO
	fclose(file); //fecha o arquivo
    	
    system("pause");
    
}

int consulta() //Fun��o responsavel por consultar os usu�rios no sistema
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40]; //traz a variavel CPF para fun��o
    char conteudo[200]; //traz a variavel Conte�do para fun��o
    	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf); //armazenando a variavel "cpf" utilizado a fun��o string "%s"
      	
    FILE *file;
    file = fopen(cpf,"r"); //Abre o arquivo CPF, com a fun��o "R" de Read(Ler) a informa��o
      	
    if(file == NULL) //Se a informa��o n�o existir traz a seguinte informa��o.
    {
    	printf("\nN�o foi possivel abrir o arquivo, registro n�o localizado!.\n");
    }
    	
    printf("\nEssas s�o as informa��es do usu�rio: \n\n"); //Informa��o para aparecer antes dos dados
    
    while(fgets(conteudo, 200, file)!= NULL) //While (enquanto) tiver informa��o, armazene a informa��o em conteudo se for diferente de NULL (nulo)
    {
    	printf("%s", conteudo); //Traz as informa��es salvas (%s) como string e apresenta ao usu�rio
    }
    
    fclose(file);
    system ("pause");

}

int deletar() //Fun��o responsavel por deletar os usu�rios do sistema
{
	char cpf[40]; //traz a variavel CPF para fun��o
	 
	printf("Digite o CPF do usu�rio � ser deletado: "); //pergunta o CPF � ser deletado
	scanf("%s",cpf); //l� o CPF � ser deletado
	
	FILE *file;
    file = fopen(cpf,"r"); //Abre o arquivo CPF, com a fun��o "R" de Read(Ler) a informa��o
                    
	if(file == NULL) //se o arquivo nao existir
    {
       printf("\nO usu�rio n�o se encontra registrado no sistema.\n\n");
	   system("pause");	
	}
	
	else
	{
	    printf("\nRegistro deletado com sucesso!.\n\n"); //mensagem de confirma��o de exclus�o
        system("pause");
        fclose(file); //fecha o arquivo para que possa ser excluido
    }
    
    remove(cpf); //determina que o registro seja deletado
 
}

int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //respons�vel por limpar � tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar � tela
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
			
	}	
}
