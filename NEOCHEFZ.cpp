#include <iostream>
#include <cstring>
#include <cstdio>
#include <locale>
#include <cstdlib>
#include <conio.h>
#include <cctype>
#include <fstream>
#include <ctime>
#include <windows.h>
using namespace std;


//ESTRUTURA PARA CADASTRAR CLIENTES
struct clientes
{
	string nomecliente;
	string telefonecliente;
	string CPFcliente;
	string enderecocliente;
	string datacliente;
	int codigocliente;
	int clienteativo;
};
struct clientes Cliente[5000]; //VETOR PARA RECEBER OS CLIENTES QUANDO CADASTRADOS


//ESTRUTURA PARA GUARDAR AS PIZZAS
struct pizzas
{
	string nomepizza;
	string tamanhopizza;
	string ingredientes;
	float precopizza;
	int codigopizza;
	
	//FUNÇÃO DENTRO DA ESTRUTURA DE PIZZAS PARA PASSAR OS DADOS DAS PIZZAS PARA O VETOR DA ESTRUTURA DE PIZZAS
	void inserirdadosPiz(string idnomepizza, string idtamanhopizza, string idingredientes, float idprecopizza, int idcodigopizza)
	{
		nomepizza = idnomepizza;
		tamanhopizza = idtamanhopizza;
		ingredientes = idingredientes;
		precopizza = idprecopizza;
		codigopizza = idcodigopizza;
	}
	
	//FUNÇÃO PARA VISUALIZAR AS PIZZAS DISPONÍVEIS DENTRO DA ESTRUTURA DE PIZZAS
	void visualizapizzas()
	{
		cout << "\t\t\t\t\t\t|NOME: " << nomepizza << "............." << ingredientes << endl;
		cout << "\t\t\t\t\t\t|TAMANHO: " << tamanhopizza << endl;
		cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << precopizza << endl;
		cout << "\t\t\t\t\t\t|CÓDIGO: " << codigopizza << endl;
	}
};

//VETOR DA ESTRUTURA PIZZAS PARA ARMAZENAR TODOS OS DADOS DAS OPÇÕES DE PIZZAS PRÉ-DEFINIDAS LOGO ABAIXO
pizzas vPizzas[13]; 

//VARIÁVEIS DO TIPO STRUCT CRIADAS PARA CADA PIZZA
pizzas Americana, Atum, Brocolis, Calabresa, CincoQueijos, FrangCat, Marguerita, Portuguesa, Rucula, Siciliana, Banana, Passione, RomeuJulieta;


//ESTRUTURA PARA GUARDAR AS BEBIDAS
struct bebidas
{
	string nomebebida;
	float precobebida;
	int codigobebida;
	
	//FUNÇÃO PARA PASSAR OS DADOS DAS PIZZAS PARA O VETOR DA ESTRUTURA DE BEBIDAS
	void inserirdadosBeb(string idnomebebida, float idprecobebida, int idcodigobebida)
	{
		nomebebida = idnomebebida;
		precobebida = idprecobebida;
		codigobebida = idcodigobebida;
	}
	
	//FUNÇÃO PARA VISUALIZAR AS BEBIDAS DISPONÍVEIS DENTRO DA ESTRUTURA DE BEBIDAS
	void visualizabebidas()
	{
		cout << "\t\t\t\t\t\t|NOME: " << nomebebida << endl;
		cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << precobebida << endl;
		cout << "\t\t\t\t\t\t|CÓDIGO: " << codigobebida << endl;
	}
};

//VETOR DA ESTRUTURA BEBIDAS PARA ARMAZENAR TODOS OS DADOS DAS OPÇÕES DE BEBIDAS PRÉ-DEFINIDAS LOGO ABAIXO
bebidas vBebidas[9];

//VARIÁVEIS DO TIPO STRUCT CRIADAS PARA CADA BEBIDA
bebidas CocaCola, CocaColaZero, CocaCola2, Guarana, FantaUva, Sprite, Brahma, Skol, Eisenbahn;


//ESTRUTURA PARA GUARDAR O ESTOQUE DOS PRODUTOS
struct estoque
{
	string nomeproduto;
	string tipoestoque;
	long quantidadeproduto;
	int codigoproduto;
	
	//FUNÇÃO PARA PASSAR OS DADOS DO ESTOQUE PARA O VETOR DA ESTRUTURA DE ESTOQUE
	void inserirdadosEst(string idnomeproduto, string idtipoestoque, float idquantidadeproduto, int idcodigoproduto)
	{
		nomeproduto = idnomeproduto;
		tipoestoque = idtipoestoque;
		quantidadeproduto = idquantidadeproduto;
		codigoproduto = idcodigoproduto;
	}
	
	//FUNÇÃO PARA VISUALIZAR OS PRODUTOS DISPONÍVEIS NA ESTRUTURA DE ESTOQUE
	void visualizestoque()
	{
		cout << "\n";
		cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|NOME: " << nomeproduto << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|ESTOQUE EM: " << tipoestoque << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|QUANTIDADE: " << quantidadeproduto << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|CÓDIGO: " << codigoproduto << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|________________________________" << endl;
		
	}
};

//VETOR DA ESTRUTURA ESTOQUE CRIADO PARA RECEBER TODOS OS PRODUTOS QUE SERÃO ARMAZENADOS NO ESTOQUE
estoque vEstoque[50];

//VARIÁVEIS DO TIPO STRUCT CRIADAS PARA CADA PRODUTO QUE SERÁ GUARDADO NO ESTOQUE
estoque MOLHOTOMATE, MUSSARELA, PALMITO, ERVILHA, PRESUNTO, BACON, ATUM, TOMATE, CEBOLA, CATUPIRY, BROCOLIS, PEPPERONI, ALHO, CALABRESA, OREGANO, AZEITONA, PARMESAO;
estoque PROVOLONE, GORGONZOLA, FRANGO, MANJERICAO, MILHO, OVO, RUCULA, CHAMPIGNON;
estoque DOCELEITE, BANANA, CANELA, CHOCOLATE, MORANGO, SORVETECREME, GOIABADA;
estoque COCACOLA, COCACOLAZERO, COCACOLA2, GUARANA, FANTAUVA, SPRITE, BRAHMA, SKOL, EISENBAHN;
estoque MASSA, FARINHA, ACUCAR, FERMENTO, SAL, OLEO, MANTEIGA;


//ESTRUTURA DE PEDIDOS PARA ARMAZENAR OS PEDIDOS
struct pedidos
{
	//VARIÁVEIS PARA IDENTIFICAR O CLIENTE
	string nome_clientepedido;
	string CPF_clientepedido;
	string telefone_clientepedido;
	string endereco_clientepedido;
	int codigo_clientepedido; 
	
	//VARIÁVEIS PARA IDENTIFICAR AS PIZZAS
	string nome_pizzapedido;
	string tamanho_pizzapedido;
	string ingredientes_pizzapedido;
	double preco_pizzapedido;
	int codigo_pizzapedido;
	int quantidade_pizzapedido;
	string obs_pizzapedido;
	
	//VARIÁVEIS PARA IDENTIFICAR AS BEBIDAS
	string nome_bebidapedido;
	double preco_bebidapedido;
	int codigo_bebidapedido;
	int quantidade_bebidapedido;
	
};
struct pedidos Pedido[1000]; //VETOR DA ESTRUTURA PEDIDOS PARA RECEBER OS PEDIDOS REALIZADOS

int contadorpedido = 0; //CONTADOR UTILIZADO EM UM LAÇO DE REPETIÇÃO PARA GUARDAR O PEDIDO E TAMBÉM EXIBÍ-LO DEPOIS QUE FINALIZAR

//ESTRUTURA DA UNIDADE PARA GUARDAR VALORES
struct unidade1
{
	double faturamento_bruto1;
	double lucro1;
};
struct unidade1 Unidade1;


struct unidade2
{
	double faturamento_bruto2;
	double lucro2;
};
struct unidade2 Unidade2;


struct unidade3
{
	double faturamento_bruto3;
	double lucro3;
};
struct unidade3 Unidade3;

struct funcionarios
{
	string nomefuncionario;
	string CPFfuncionario;
	string funcaofuncionario;
	string unidadefuncionario;
	string datafuncionario;
	int codigofuncionario;
	int funcionarioativo;
};
struct funcionarios Funcionario[300];

fstream arquivo; //VARIÁVEL PARA MANIPULAR ARQUIVO, TANTO LEITURA COMO ESCRITA

//VARIÁVEIS
int i = 0; //CONTADOR PARA GUARDAR E VISUALIZAR DADOS
int contador = 0; //CONTADOR PARA GUARDAR E VISUALIZAR DADOS
int menu = 0; //VARIÁVEL PARA RECEBER O CASE DO MENU
char op; // VARIÁVEL PARA RECEBER DECISÕES (S|N)
int listcadastro = 0; //VARIÁVEL PARA ESCOLHER DENTRO DO MENU CASE (3)
int opcaoexcliente = 0; //VARIÁVEL PARA ESCOLHER DENTRO DO MENU CASE (2)
int opcadastro = 0; //VARIÁVEL PARA ESCOLHER DENTRO DO MENU CASE (1)
int digitofinal = 0; //VARIÁVEL UTILIZADA NA FUNÇÃO DE RECEBER SÓ NUMEROS, GUARDANDO O RETORNO DELA
int geracodigo = 1; //VARIÁVEL UTILIZADA PARA DAR CÓDIGO AO CLIENTE NO CADASTRO, SOMANDO +1 A CADA CADASTRO
int geracodigofun = 1;
double valortotal; //VARIÁVEL PARA GUARDAR O VALOR TOTAL DO PEDIDO NO FINAL DO PEDIDO
int unidadepizzaria = 0;
int contadorfuncionario = 0;


//FUNÇÕES UTILIZADAS
void cadastrar_cliente(); //FUNÇÃO PARA CADASTRAR CLIENTES
void list_cliente(); //FUNÇÃO PARA LISTAR OS CLIENTES DO ARQUIVO
void consulta_cliente(); //FUNÇÃO PARA CONSULTAR CLIENTES
void excluir_cliente(); //FUNÇÃO PARA EXCLUIR CLIENTES
void realiza_login(); //FUNÇÃO PARA REALIZAR O PRIMEIRO LOGIN DO SISTEMA
void adm_login(); //FUNÇÃO PARA REALIZAR O LOGIN ADMINISTRATIVO
void ped_pizza(); //FUNÇÃO PARA REALIZAR PEDIDO DE PIZZA
void ped_bebida(); //FUNÇÃO PARA REALIZAR PEDIDO DE BEBIDA
void sonumeros(); //FUNÇÃO PARA RECEBER SÓ NUMEROS EM MENUS
void realiza_pedido(); //FUNÇÃO PARA REALIZAR O PEDIDO DO CLIENTE
int validanumerico(string campo);
int validaletra(string campo);
int validacampobranco(string campo);
void cadastrar_funcionario();
void excluir_funcionario();
void excluir_pedido();
void consulta_funcionarios();
void list_funcionarios();
void realizapagamento();
void contabil();
void gerenciaestoque();
void pizzasmaispedidas();
void estoqueinsere();
void pizzainsere();
void bebidainsere();
void carregarfuncionarios();
void carregarclientes();
void backupcliente();
void backupfuncionario();

int logado; //VARIÁVEL PARA SETAR SE O LOGIN FOI SUCEDIDO OU NÃO
int adm_logado; //VARIÁVEL PARA SETAR SE O LOGIN ADM FOI SUCEDIDO OU NÃO
int verificador = 0;

//INICIO DA FUNÇÃO PRINCIPAL QUE EXECUTARÁ O PROGRAMA
int main(void)
{
	system("title NEOCHEFZ");
	system("Color 0F");
	system("MODE con cols=168 lines=10000");
	setlocale(LC_ALL, "portuguese"); //ALTERANDO IDIOMA DO SISTEMA PARA PORTUGUÊS
	
	//STRUCT DE PIZZAS RECEBENDO SEUS DADOS NAS VARIÁVEIS UTILIZANDO A FUNÇÃO MOSTRADA ANTERIORMENTE NA ESTRUTURA
	pizzainsere();
	 
	//STRUCT DE BEBIDAS RECEBENDO SEUS DADOS NAS VARIÁVEIS UTILIZANDO A FUNÇÃO MOSTRADA ANTERIORMENTE NA ESTRUTURA
	bebidainsere();
	 
	//STRUCT DE ESTOQUE RECEBENDO SEUS DADOS NAS VARIÁVEIS UTILIZANDO A FUNÇÃO MOSTRADA ANTERIORMENTE NA ESTRUTURA
	estoqueinsere();	 				
	
	carregarfuncionarios();
	
	carregarclientes();	

	realiza_login(); //CHAMANDO A FUNÇÃO PARA REALIZAR O PRIMEIRO LOGIN E LIBERAR O SISTEMA
	
	if(logado == 1) //VALIDAÇÃO, SE FOR 1 O LOGIN NÃO FOI SUCEDIDO
	{
		fflush(stdin);
		return main();
	}
	else if(logado == 2) //VALIDAÇÃO, SE FOR 2 O LOGIN FOI SUCEDIDO E LIBERA O SISTEMA
	{
	//LOOP PARA RODAR O MENU DO SISTEMA
	do{ 
	
	system("cls");
	cout << "\n" << endl; //MENU PRINCIPAL COM TODAS AS OPÇÕES DISPONÍVEIS DO SISTEMA
	cout << "\t\t\t\t\t\t\t\t ________________________________________________________ " << endl;
	cout << "\t\t\t\t\t\t\t\t|                                                        |" << endl;
	cout << "\t\t\t\t\t\t\t\t|             S Y S T E M    N E O C H E F Z             |" << endl;
	cout << "\t\t\t\t\t\t\t\t|________________________________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t\t|                      MENU DE OPÇÕES                    |" << endl;
	cout << "\t\t\t\t\t\t\t\t|========================================================|" << endl;
	cout << "\t\t\t\t\t\t\t\t|                            |                           |" << endl;
	cout << "\t\t\t\t\t\t\t\t|[1] - CADASTRAR CLIENTE     | [4] - REALIZAR PEDIDO     |" << endl;
	cout << "\t\t\t\t\t\t\t\t|____________________________|___________________________|" << endl;
	cout << "\t\t\t\t\t\t\t\t|                            |                           |" << endl;
	cout << "\t\t\t\t\t\t\t\t|[2] - EXCLUIR CLIENTE       | [5] - EXCLUIR PEDIDO      |" << endl;
	cout << "\t\t\t\t\t\t\t\t|____________________________|___________________________|" << endl;
	cout << "\t\t\t\t\t\t\t\t|                            |                           |" << endl;
	cout << "\t\t\t\t\t\t\t\t|[3] - CLIENTES CADASTRADOS  | [6] - PEDIDOS REALIZADOS  |" << endl;
	cout << "\t\t\t\t\t\t\t\t|____________________________|___________________________|" << endl;
	cout << "\t\t\t\t\t\t\t\t|                                                        |" << endl;
	cout << "\t\t\t\t\t\t\t\t|                   [7] - GERENCIAMENTO                  |" << endl;
	cout << "\t\t\t\t\t\t\t\t|________________________________________________________|" << endl;
	cout << "\n\t\t\t\t\t\t\t\t -> O QUE DESEJA REALIZAR: "; //PEDINDO A OPÇÃO DO MENU
	fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
	sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
	menu = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
	
	while(menu < 0 || menu > 7 || menu == 13) //VALIDAÇÃO DA OPÇÃO DIGITADA, PARA EVITAR ERROS
	{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t _______________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t|              **OPÇÃO INVÁLIDA!!!**            |" << endl;
			cout << "\t\t\t\t\t\t\t\t|____-> DIGITE UMA OPÇÃO APRESENTADA NO MENU____|" << endl;
			cout << "\n\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";
			fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
			sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
			menu = digitofinal; //NOVAMENTE, PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
	}

	system("cls");
	
	while(menu == 1) //<INICIO DO (1)PRIMEIRO CASE DO MENU> CADASTRAR CLIENTE******************
	{
		cout << "\n" << endl; //DANDO AS OPÇÕES DENTRO DA OPÇÃO (1) DO MENU PRINCIPAL
		cout << "\t\t\t\t\t\t\t\t\t\t _____________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|    <<CADASTRAR CLIENTE>>    |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|=============================|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[1] - RETORNAR AO MENU       |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[2] - CADASTRAR CLIENTE      |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";
		fflush(stdin);//LIMPANDO O BUFFER DE ENTRADA DE DADOS
		sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
		opcadastro = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
		
		while(opcadastro != 1 && opcadastro != 2) //VALIDAÇÃO DA OPÇÃO DIGITADA, PARA EVITAR ERROS
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (1|2)_____|" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";	
			fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
			sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
			opcadastro = digitofinal; //NOVAMENTE, PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
		}
	
		switch(opcadastro)
		{
		case 1: //<OPÇÃO (1) DENTRO DO MENU CASE (1)
				break; //RETORNA AO MENU PRINCIPAL
			
			case 2: //<OPÇÃO (2) DENTRO DO MENU CASE (1)
				cadastrar_cliente(); //FUNÇÃO CADASTRAR NOVOS CLIENTES
				break;
		}
		break;
	}

	while(menu == 2) //<INICIO DO (2)SEGUNDO CASE DO MENU> EXCLUIR CADASTRO***************
	{
		cout << "\n" << endl; //DANDO AS OPÇÕES DENTRO DA OPÇÃO (2) DO MENU PRINCIPAL
		cout << "\t\t\t\t\t\t\t\t\t\t _____________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|     <<EXCLUIR CLIENTE>>     |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|=============================|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[1] - RETORNAR AO MENU       |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[2] - EXCLUIR CLIENTE        |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t -> O QUE DESEJA REALIZAR: ";
		fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
		sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
		opcaoexcliente = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
			
		while(opcaoexcliente != 1 && opcaoexcliente != 2) //VALIDAÇÃO DA OPÇÃO DIGITADA, PARA EVITAR ERROS
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (1|2)_____|" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";
			fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
			sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
			opcaoexcliente = digitofinal; //NOVAMENTE, PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
		}
		
		switch(opcaoexcliente)
		{
			case 1: //<OPÇÃO (1) DENTRO DO MENU CASE (2)
				break; //RETORNA AO MENU PRINCIPAL
				
			case 2: //<OPÇÃO (2) DENTRO DO MENU CASE (2)
				excluir_cliente(); //FUNÇÃO PARA EXCLUIR CLIENTES
				break;
		}
	break;
	}

	while(menu == 3)//<INICIO DO (3)TERCEIRO CASE DO MENU> CLIENTES CADASTRADOS**************
	{	
		cout << "\n" << endl; //DANDO AS OPÇÕES DENTRO DA OPÇÃO (3) DO MENU PRINCIPAL
		cout << "\t\t\t\t\t\t\t\t\t\t _____________________________" << endl;	
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|   <<CLIENTES CADASTRADOS>>  |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|=============================|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[1] - RETORNAR AO MENU       |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[2] - CONSULTAR CLIENTE      |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                             |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[3] - LISTAR CLIENTES        |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";
		fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
		sonumeros(); //FUNÇÃO PARA RECEBER SÓ NUMEROS, EVITANDO ERROS
		listcadastro = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU
		
		while(listcadastro != 1 && listcadastro != 2 && listcadastro != 3) //VALIDAÇÃO DA OPÇÃO DIGITADA, PARA EVITAR ERROS 
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|____-> DIGITE UMA OPÇÃO VÁLIDA (1|2|3)____|" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";
			fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
			sonumeros(); //FUNÇÃO PARA RECEBER SÓ NUMEROS, EVITANDO ERROS
			listcadastro = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU
		}
		
		
		switch(listcadastro)
		{
			case 1: //<OPÇÃO (1) DENTRO DO MENU CASE (2)			
				break; //RETORNA AO MENU PRINCIPAL
			
			case 2: //<OPÇÃO (2) DENTRO DO MENU CASE (2)
				consulta_cliente();	//FUNÇÃO PARA CONSULTA POR CÓDIGO DO CLIENTE
				break;
			
			case 3: //<OPÇÃO (3) DENTRO DO MENU CASE (2)
				list_cliente(); //FUNÇÃO PARA LISTAR CLIENTES CADASTRADOS
				break;
		}
	break;
	}

	while(menu == 4) //<INICIO DO (4)QUARTO CASE DO MENU> PREALIZAR PEDIDO**************
	{
		realiza_pedido();

		break;
	}
	
	while(menu == 5) //<INICIO DO (5)QUINTO CASE DO MENU> EXCLUIR PEDIDO**************
	{
		excluir_pedido();
		break;
	}
	
	while(menu == 6)
	{
		string linha;
			
		arquivo.open("arquivopedidos.txt", ios::in); //ABRINDO ARQUIVO SOMENTE PARA LEITURA
		
		if(arquivo.is_open()) //SE O ARQUIVO ESTIVER ABERTO
		{
			cout << "\n " << endl; //EXIBINDO NA TELA TODOS OS PEDIDOS REALIZADOS
			cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
			cout << "\t\t\t\t\t\t|                                             <<PEDIDOS REALIZADOS>>                                        |" << endl;
			cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
			cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
			cout << "\n" << endl;
		
			while(getline(arquivo,linha))
			{
				cout << "\t\t\t\t\t\t" << linha << endl;
			}
			
			arquivo.close();
		
			cout << "\n";
			cout << "\t\t\t\t\t\t ____________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t|            -> PRESSIONE ENTER PARA RETORNAR AO MENU!               |" << endl;
			cout << "\t\t\t\t\t\t|____________________________________________________________________|";
			getch();
			break;
		}
		else //SENÃO, SE NÃO TIVER ARQUIVO PARA ABRIR
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t _________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t|                                                         |" << endl;
			cout << "\t\t\t\t\t\t|  NÃO HÁ PEDIDOS OU NÃO FOI POSSÍVEL ABRIR O ARQUIVO!!!  |" << endl;
			cout << "\t\t\t\t\t\t|       -> PRESSIONE ENTER PARA RETORNAR AO MENU!         |" << endl;
			cout << "\t\t\t\t\t\t|_________________________________________________________|";
			getch();
			break;
		}
		
	}
	
	while(menu == 7)
	{
		adm_login(); //CHAMADA DA FUNÇÃO PARA REALIZAR LOGIN ADMINISTRATIVO
		int menuadm = 0;
		int opcaofuncionarios = 0;
		int opcaoestoque = 0;
		int opcaopromocao = 0;
		int opcaofaturamento = 0;
		int opcaolucro = 0;
		int opcaodespesas = 0;
		
		if(adm_logado == 2) //SE ADM LOGADO FOR (2), LOGIN REALIZADO
		{			
									
			do{
			
			system("cls");
			cout << "\n" << endl; //MENU PRINCIPAL COM TODAS AS OPÇÕES DISPONÍVEIS DO SISTEMA
			cout << "\t\t\t\t\t\t\t\t ________________________________________________________ " << endl;
			cout << "\t\t\t\t\t\t\t\t|                                                        |" << endl;
			cout << "\t\t\t\t\t\t\t\t|             S Y S T E M    N E O C H E F Z             |" << endl;
			cout << "\t\t\t\t\t\t\t\t|________________________________________________________|" << endl;
			cout << "\t\t\t\t\t\t\t\t|                 MENU DE GERENCIAMENTO                  |" << endl;
			cout << "\t\t\t\t\t\t\t\t|========================================================|" << endl;
			cout << "\t\t\t\t\t\t\t\t|                            |                           |" << endl;
			cout << "\t\t\t\t\t\t\t\t|[1] - FUNCIONÁRIOS          | [4] - PIZZAS + PEDIDAS    |" << endl;
			cout << "\t\t\t\t\t\t\t\t|____________________________|___________________________|" << endl;
			cout << "\t\t\t\t\t\t\t\t|                            |                           |" << endl;
			cout << "\t\t\t\t\t\t\t\t|[2] - ESTOQUE               | [5] - FATURAMENTO & LUCRO |" << endl;
			cout << "\t\t\t\t\t\t\t\t|____________________________|___________________________|" << endl;
			cout << "\t\t\t\t\t\t\t\t|                            |                           |" << endl;
			cout << "\t\t\t\t\t\t\t\t|[3] - PROMOÇÕES             | [6] - DESPESAS            |" << endl;
			cout << "\t\t\t\t\t\t\t\t|____________________________|___________________________|" << endl;
			cout << "\t\t\t\t\t\t\t\t|                                                        |" << endl;
			cout << "\t\t\t\t\t\t\t\t|              [7] - SAIR DO GERENCIAMENTO               |" << endl;
			cout << "\t\t\t\t\t\t\t\t|________________________________________________________|" << endl;
			cout << "\n\t\t\t\t\t\t\t\t -> O QUE DESEJA REALIZAR: "; //PEDINDO A OPÇÃO DO MENU ADM
			fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
			sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
			menuadm = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
			
			while(menuadm < 0 || menu > 7 || menu == 13) //VALIDAÇÃO DA OPÇÃO DIGITADA, PARA EVITAR ERROS
			{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t _______________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t|              **OPÇÃO INVÁLIDA!!!**            |" << endl;
					cout << "\t\t\t\t\t\t\t\t|____-> DIGITE UMA OPÇÃO APRESENTADA NO MENU____|" << endl;
					cout << "\n\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";
					fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
					sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
					menuadm = digitofinal; //NOVAMENTE, PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
			}

			system("cls");
			
			while(menuadm == 1)
			{
				cout << "\n" << endl; //DANDO AS OPÇÕES DENTRO DA OPÇÃO (3) DO MENU PRINCIPAL
				cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;	
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|        <<FUNCIONÁRIOS>>        |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|================================|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|[1] - RETORNAR AO MENU          |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|[2] - CADASTRAR FUNCIONÁRIOS    |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|[3] - EXCLUIR FUNCIONÁRIOS      |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|[4] - FUNCIONÁRIOS CADASTRADOS  |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
				cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";	
				fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
				sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
				opcaofuncionarios = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
				
				while(opcaofuncionarios == 1)
				{
					break;
				}
				
				while(opcaofuncionarios == 2)
				{
					cadastrar_funcionario();
					break;
				}
				
				while(opcaofuncionarios == 3)
				{
					excluir_funcionario();
					break;
				}
				
				while(opcaofuncionarios == 4)
				{
					int listafun = 0;
					
					system("cls");
					cout << "\n" << endl; //DANDO AS OPÇÕES DENTRO DA OPÇÃO (3) DO MENU PRINCIPAL
					cout << "\t\t\t\t\t\t\t\t\t\t ____________________________________________" << endl;	
					cout << "\t\t\t\t\t\t\t\t\t\t|                                            |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|        <<FUNCIONÁRIOS CADASTRADOS>>        |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|                                            |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|============================================|" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|                                            |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|[1] - CONSULTAR FUNCIONÁRIO                 |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|____________________________________________|" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|                                            |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|[2] - LISTAR FUNCIONÁRIOS                   |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|____________________________________________|" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";	
					fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
					sonumeros(); //UTILIZANDO DA FUNÇÃO DE SÓ ACEITAR NÚMEROS PARA NÃO OCORRER ERROS
					listafun = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE RECEBE A OPÇÃO DO MENU.
					
					
					while(listafun == 1)
					{
						consulta_funcionarios();
						break;
					}
					
					while(listafun == 2)
					{
						list_funcionarios();
						break;
					}
					
					break;
				}
			
			break;
			}
			
			while(menuadm == 2)
			{
				gerenciaestoque();
				break;
			}
			
			/*while(menu adm == 3)
			{
				promocoes();
				break;
			}*/
			
			while(menuadm == 4)
			{
				pizzasmaispedidas();
				break;
			}
			
			while(menuadm == 5)
			{
				contabil();
				break;
			}
			
			/*while(menuadm == 6)
			{
				despesas();
				break;
			}*/
			
			while(menuadm == 7)
			{
				break;
			}
			
			}while(menuadm != 7 || menu < 7);
		}
		
		break;	
	}

		
  	}while(menu != 8 || menu < 8); //VALIDAÇÃO DO LOOP DO MENU PRINCIPAL, PARA CONTINUAR RODANDO DENTRO DAS OPÇÕES
}
} //FIM DA FUNÇÃO MAIN()<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//FUNÇÃO PARA CADASTRO DE CLIENTES
void cadastrar_cliente()
{
    time_t agora;
    char datahora[100];

    /* Recupera a quantidade de segundos desde 01/01/1970 */
    agora = time(NULL);

    /* Formata a data e a hora da forma desejada */
    strftime( datahora, sizeof(datahora), "%d.%m.%Y - %H:%M:%S", localtime( &agora ) );
    
    Cliente[contador].datacliente = (std::string) datahora;
    		
	do{ //LAÇO DE REPETIÇÃO PARA REALIZAR CADASTROS DE CLIENTES
				
		Cliente[contador].codigocliente = geracodigo; //PASSANDO PARA O CLIENTE NA POSIÇÃO [] DO VETOR, O CÓDIGO GERADO PELA VARIÁVEL GERACODIGO
		
		system("cls"); //LIMPANDO A TELA
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t\t|                     <<NOVO CADASTRO DE CLIENTE>>                   |" << endl;
		cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
		
		do{
			cout << "\t\t\t\t\t\t\t|             NOME: ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			getline(cin,Cliente[contador].nomecliente); //PEGANDO A LINHA DIGITADA PELO USUÁRIO NA POSIÇÃO [] DO VETOR
			validacampobranco(Cliente[contador].nomecliente);
			
				if(verificador == 1)
				{
					validaletra(Cliente[contador].nomecliente);	
				}
		}while(verificador == 0);
		
		do{
			cout << "\t\t\t\t\t\t\t|              CPF: ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			getline(cin,Cliente[contador].CPFcliente); //PEGANDO A LINHA DIGITADA PELO USUÁRIO NA POSIÇÃO [] DO VETOR
			validacampobranco(Cliente[contador].CPFcliente);
			
				if(verificador == 1)
				{
					validanumerico(Cliente[contador].CPFcliente);	
				}
		}while(verificador == 0);		
		
		do{
			cout << "\t\t\t\t\t\t\t|         TELEFONE: ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			getline(cin,Cliente[contador].telefonecliente); //PEGANDO A LINHA DIGITADA PELO USUÁRIO NA POSIÇÃO [] DO VETOR
			validacampobranco(Cliente[contador].telefonecliente);
			
			if(verificador == 1)
				{
					validanumerico(Cliente[contador].telefonecliente);
				}
		}while(verificador == 0);
		
		do{
			cout << "\t\t\t\t\t\t\t|         ENDEREÇO: ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			getline(cin,Cliente[contador].enderecocliente); //PEGANDO A LINHA DIGITADA PELO USUÁRIO NA POSIÇÃO [] DO VETOR
			
			validacampobranco(Cliente[contador].enderecocliente);
		}while(verificador == 0);
		
		//MOSTRANDO A DATA QUE O CLIENTE ESTÁ CADASTRADO, DE ACORDO COM A DATA QUE ESTÁ NA MÁQUINA QUE ESTÁ EXECUTANDO O PROGRAMA
		cout << "\t\t\t\t\t\t\t| DATA DE CADASTRO: " << Cliente[contador].datacliente << endl;
		
		//MOSTRANDO O CÓDIGO DO CLIENTE QUE ESTÁ SENDO CADASTRADO
		cout << "\t\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << Cliente[contador].codigocliente; 
		
		Cliente[contador].clienteativo = 1; //PASSANDO O VALOR (1), SIGNIFICANDO QUE O CLIENTE ESTÁ ATIVO
		
		cout << "\n\t\t\t\t\t\t\t -> CONFIRMA CADASTRO DE CLIENTE? (S|N): ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
		op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		
		while(op != 'S' && op !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\n\t\t\t\t\t\t\t -> CONFIRMA CADASTRO DE CLIENTE? (S|N): ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
			op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		}
		
		if(op == 'S')
		{			
			contador++; //INCREMENTANDO CONTADOR DE CLIENTES PARA PODER RECEBER UM NOVO EM OUTRA POSIÇÃO DO VETOR
			geracodigo++; //INCREMENTANDO O GERACODIGO, PARA GERAR UM NOVO CODIGO DO CLIENTE	
			
			backupcliente();
			
			cout << endl;
			cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|               -> CLIENTE CADASTRADO COM SUCESSO!!!                 |" << endl;	
			cout << "\t\t\t\t\t\t\t|____________________________________________________________________|" << endl;
		}
		else if(op == 'N')
		{
			cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|               -> CADASTRO CANCELADO COM SUCESSO!!!                 |" << endl;	
			cout << "\t\t\t\t\t\t\t|____________________________________________________________________|" << endl;
		}
		
		cout << "\n\t\t\t\t\t\t\tDESEJA REALIZAR NOVO CADASTRO? (S|N): ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
		op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		
		while(op != 'S' && op !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\n\t\t\t\t\t\t\tDESEJA REALIZAR NOVO CADASTRO? (S|N): ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
			op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		}
			
		system("cls"); //LIMPANDO A TELA
			
	} while(op == 'S'); //ENQUANTO FOR 'S', O LOOP CONTINUARÁ PARA CADASTRAR NOVO CLIENTE
}

//FUNÇÃO PARA LISTAR CLIENTES CADASTRADOS (ABRINDO DO TXT)
void list_cliente()
{
	clientes cli_lista; //VETOR PARA RECEBER A VARIÁVEL COM O CONTEÚDO DA LINHA DO ARQUIVO E MOSTRAR NA TELA
	
	system("cls"); //LIMPANDO A TELA
	
	arquivo.open("arquivocadastros.txt", ios::in); //ABRINDO ARQUIVO SOMENTE PARA LEITURA
	
	if(arquivo.is_open()) //SE O ARQUIVO ESTIVER ABERTO
	{
		string linha; //VARIÁVEL PARA RECEBER LINHA DO ARQUIVO
		int numlinha = 1; //CONTADOR DE LINHAS DO ARQUIVO
		
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t ____________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t|                 <<LISTA DE CLIENTES CADASTRADOS>>                  |" << endl;
		cout << "\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t|====================================================================|" << endl;
		while(getline(arquivo, linha)) //PEGANDO LINHA A LINHA DO ARQUIVO E PASSANDO PARA A VARIÁVEL STRING LINHA
		{
			if(numlinha%8 == 1) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 1
			{
				cli_lista.nomecliente = linha; //VETOR RECEBENDO LINHA COM NOME
				cout << "\n\t\t\t\t\t\t ____________________________________________________________________" << endl;	
				cout << "\t\t\t\t\t\t|" << endl;							
				cout << "\t\t\t\t\t\t|             NOME: " << cli_lista.nomecliente << endl;
			}
			else if(numlinha%8 == 2) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 2
			{
				cli_lista.CPFcliente = linha; //VETOR RECEBENDO LINHA COM CPF
				cout << "\t\t\t\t\t\t|              CPF: " << cli_lista.CPFcliente << endl;			
			}
			else if(numlinha%8 == 3) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 3
			{
				cli_lista.telefonecliente = linha; //VETOR RECEBENDO LINHA COM TELEFONE
				cout << "\t\t\t\t\t\t|         TELEFONE: " << cli_lista.telefonecliente << endl;
			}
			else if(numlinha%8 == 4) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 4
			{
				cli_lista.enderecocliente = linha; //VETOR RECEBENDO LINHA COM ENDEREÇO
				cout << "\t\t\t\t\t\t|         ENDEREÇO: " << cli_lista.enderecocliente << endl;
			}
			else if(numlinha%8 == 5) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 5
			{
				cli_lista.datacliente = linha; //VETOR RECEBENDO LINHA COM DATA
				cout << "\t\t\t\t\t\t| DATA DE CADASTRO: " << cli_lista.datacliente << endl;
			}
			else if(numlinha%8 == 6) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 6
			{
				cout << "\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << linha << endl; //MOSTRANDO NA TELA O CÓDIGO DO CLIENTE
				cout << "\t\t\t\t\t\t|____________________________________________________________________" << endl;	
			}
			numlinha++; //INCREMENTANDO CONTADOR DE LINHAS DO ARQUIVO
		}
		arquivo.close(); //FECHANDO O ARQUIVO
		
		cout << "\n";
		cout << "\t\t\t\t\t\t ____________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t|            -> PRESSIONE ENTER PARA RETORNAR AO MENU!               |" << endl;
		cout << "\t\t\t\t\t\t|____________________________________________________________________|";
		getch();
	}
	else //SENÃO, SE NÃO TIVER ARQUIVO PARA ABRIR
	{
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t _________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                         |" << endl;
		cout << "\t\t\t\t\t\t| NÃO HÁ CADASTROS OU NÃO FOI POSSÍVEL ABRIR O ARQUIVO!!! |" << endl;
		cout << "\t\t\t\t\t\t|       -> PRESSIONE ENTER PARA RETORNAR AO MENU!         |" << endl;
		cout << "\t\t\t\t\t\t|_________________________________________________________|";
		getch();
	}
}

//FUNÇÃO PARA CONSULTAR UM CLIENTE ESPECÍFICO UTILIZANDO O CÓDIGO
void consulta_cliente()
{
	int opcaoconsulta = 0; //VARIÁVEL PARA RECEBER A OPÇÃO DO MENU DE CONSULTA DE CLIENTE
	string consultaCPF; //VARIÁVEL PARA RECEBER CPF DIGITADO NA CONSULTA E COMPARAR COM O CPF CADASTRADO NA STRUCT CLIENTE
	int cod = 0; //VARIÁVEL PARA RECEBER CÓDIGO DIGITADO NA CONSULTA E COMPARAR COM O CÓDIGO CADASTRADO NA STRUCT CLIENTE
	
		
	do{	
		system("cls");
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t _________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|  <<CONSULTAR CLIENTE>>  |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|=========================|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|1 - CONSULTA POR CÓDIGO  |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                         |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|2 - CONSULTA POR CPF     |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|_________________________|" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";
		sonumeros();
		opcaoconsulta = digitofinal;
		
		while(opcaoconsulta != 1 && opcaoconsulta != 2)
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (1|2)_____|" << endl;
       	 	cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";
			sonumeros();
			opcaoconsulta = digitofinal;
		}
		
		switch(opcaoconsulta)
		{
			case 1:
			{
			system("cls");
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|                  <<CONSULTAR CLIENTE POR CÓDIGO>>                  |" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;		
			cout << "\t\t\t\t\t\t\t| -> DIGITE O CÓDIGO DO CLIENTE: ";
			fflush(stdin);
			sonumeros();
			cod = digitofinal;
			cout << endl;
						
			for(i = 0; i < contador; i++)
			{
				if(Cliente[i].codigocliente == cod)
				{
					if(Cliente[i].clienteativo == 1)
					{
					cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t|" << endl;
					cout << "\t\t\t\t\t\t\t|             NOME: " << Cliente[i].nomecliente << endl;
					cout << "\t\t\t\t\t\t\t|              CPF: " << Cliente[i].CPFcliente << endl;
					cout << "\t\t\t\t\t\t\t|         TELEFONE: " << Cliente[i].telefonecliente << endl;
					cout << "\t\t\t\t\t\t\t|         ENDEREÇO: " << Cliente[i].enderecocliente << endl;
					cout << "\t\t\t\t\t\t\t| DATA DE CADASTRO: " << Cliente[i].datacliente << endl;
					cout << "\t\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << Cliente[i].codigocliente << endl;
					cout << "\t\t\t\t\t\t\t|____________________________________________________________________" << endl;
					}	
					else if(Cliente[i].clienteativo == 0)
					{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t|          CLIENTE NÃO ENCONTRADO!!!          |" << endl;
					cout << "\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
					}
					break;					
				}
			}
			
			if(Cliente[i].codigocliente != cod || Cliente[i].codigocliente == 0)
				{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t|          CLIENTE NÃO ENCONTRADO!!!          |" << endl;
					cout << "\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
				}
			}
			break;
		
			case 2:
			system("cls");
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|                     <<CONSULTAR CLIENTE POR CPF>>                  |" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
		
			do{
			cout << "\t\t\t\t\t\t\t| -> DIGITE O CPF DO CLIENTE: ";
			fflush(stdin);
			getline(cin,consultaCPF);
			validacampobranco(consultaCPF);
			
				if(verificador == 1)
				{
					validanumerico(consultaCPF);
				}
			
			}while(verificador == 0);
					
			for(i = 0; i < contador; i++)
			{
				if(Cliente[i].CPFcliente == consultaCPF)
				{
					if(Cliente[i].clienteativo == 1)
					{
					cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t|" << endl;
					cout << "\t\t\t\t\t\t\t|             NOME: " << Cliente[i].nomecliente << endl;					
					cout << "\t\t\t\t\t\t\t|              CPF: " << Cliente[i].CPFcliente << endl;
					cout << "\t\t\t\t\t\t\t|         TELEFONE: " << Cliente[i].telefonecliente << endl;
					cout << "\t\t\t\t\t\t\t|         ENDEREÇO: " << Cliente[i].enderecocliente << endl;
					cout << "\t\t\t\t\t\t\t| DATA DE CADASTRO: " << Cliente[i].datacliente << endl;
					cout << "\t\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << Cliente[i].codigocliente << endl;
					cout << "\t\t\t\t\t\t\t|____________________________________________________________________" << endl;	
					}
					else if(Cliente[i].clienteativo == 0)
					{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t|          CLIENTE NÃO ENCONTRADO!!!          |" << endl;
					cout << "\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
					}
					break;
				}
			}
				if(Cliente[i].CPFcliente != consultaCPF)
				{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t|          CLIENTE NÃO ENCONTRADO!!!          |" << endl;
					cout << "\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
				}
			break;
		}

		cout << "\n\t\t\t\t\t\t\t\t-> DESEJA REALIZAR NOVA CONSULTA? (S|N): ";
		fflush(stdin);
		cin >> op;
		op = toupper(op);
		
		while(op != 'S' && op !='N')
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\n\t\t\t\t\t\t\t\t-> DESEJA REALIZAR NOVA CONSULTA? (S|N): ";
			cin.clear();
       		cin.ignore(INT_MAX, '\n');
       		fflush(stdin);
			cin >> op;
			op = toupper(op);
		}
					
	}while(op == 'S');
}

void excluir_cliente()
{
	string CPFexcliente;
	
	do{
		
	bool opcaodeletar = false;	
		
	system("cls");
	cout << "\n" << endl;
	cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
	cout << "\t\t\t\t\t\t\t|                 <<EXCLUSÃO DE CADASTRO DE CLIENTE>>                |" << endl;
	cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
	cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
	
	do{
	cout << "\t\t\t\t\t\t\t -> DIGITE O CPF DO CLIENTE: ";
	fflush(stdin);
	getline(cin,CPFexcliente);
	validacampobranco(CPFexcliente);
	
	if(verificador == 1)
			{
				validanumerico(CPFexcliente);	
			}
	
	}while(verificador == 0);
	
		for(i = 0; i < (contador+1); i++)
		{
			if(Cliente[i].CPFcliente == CPFexcliente)
			{
				if(Cliente[i].clienteativo == 0)
				{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t\t|          CLIENTE NÃO ENCONTRADO!!!          |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
					break;
				}
				else if(Cliente[i].clienteativo == 1)
				{
					cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t|" << endl;
					cout << "\t\t\t\t\t\t\t|             NOME: " << Cliente[i].nomecliente << endl;					
					cout << "\t\t\t\t\t\t\t|              CPF: " << Cliente[i].CPFcliente << endl;
					cout << "\t\t\t\t\t\t\t|         TELEFONE: " << Cliente[i].telefonecliente << endl;
					cout << "\t\t\t\t\t\t\t|         ENDEREÇO: " << Cliente[i].enderecocliente << endl;
					cout << "\t\t\t\t\t\t\t| DATA DE CADASTRO: " << Cliente[i].datacliente << endl;
					cout << "\t\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << Cliente[i].codigocliente << endl;
					cout << "\t\t\t\t\t\t\t|____________________________________________________________________" << endl;		
				
					cout << "\n\t\t\t\t\t\t\t -> DESEJA REALMENTE EXCLUIR ESTE CLIENTE? (S/N): ";
					fflush(stdin);
					cin >> op;
					op = toupper(op);
					
						while(op != 'S' && op !='N')
						{
							cout << "\n" << endl;
							cout << "\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
							cout << "\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
							cout << "\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
							cout << "\n\t\t\t\t\t\t\t -> DESEJA REALMENTE EXCLUIR ESTE CADASTRO? (S/N): ";
							cin.clear();
					       	cin.ignore(INT_MAX, '\n');
					       	fflush(stdin);
							cin >> op;
							op = toupper(op);
						}
						
					opcaodeletar = true;
					
					if(op == 'S')
					{
						Cliente[i].clienteativo = 0;
						backupcliente();
						cout << "\n" << endl;
						cout << "\t\t\t\t\t\t\t\t ___________________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t|       ** EXCLUSÃO EFETUADA COM SUCESSO!!! **      |" << endl;
						cout << "\t\t\t\t\t\t\t\t|___________________________________________________|" << endl;
						break;
					}
					else if(op == 'N')
					{
						cout << "\n" << endl;
						cout << "\t\t\t\t\t\t\t\t ___________________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t|             ** EXCLUSÃO CANCELADA!!! **           |" << endl;
						cout << "\t\t\t\t\t\t\t\t|___________________________________________________|" << endl;
					}
				}
				break;
			}	
		}

		if(opcaodeletar == false)
		{
			if(Cliente[i].CPFcliente != CPFexcliente)
			{
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t _____________________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|          CLIENTE NÃO ENCONTRADO!!!          |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
			}
			
		}
		
		cout << "\n\t\t\t\t\t\t\t -> DESEJA EXCLUIR OUTRO CLIENTE? (S/N): ";
		fflush(stdin);
		cin >> op;
		op = toupper(op);
		
			while(op != 'S' && op !='N')
			{
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
				cout << "\n\t\t\t\t\t\t\t -> DESEJA EXCLUIR OUTRO CLIENTE? (S/N): ";
				cin.clear();
		       	cin.ignore(INT_MAX, '\n');
		       	fflush(stdin);
				cin >> op;
				op = toupper(op);
			}
		
	}while(op == 'S');
}

void realiza_login()
{
	char usuarioatd01[8];
	char senhaatd01[11];
	int i = 0;
	char mascara_senhaatd01[11];
	
	strcpy(usuarioatd01, "admin01");
	strcpy(senhaatd01, "adminpizza");
	
	char recebe_usuarioatd01[8];
	char recebe_senhaatd01[11];
	char guarda_digito;
	
	cout << "\n" << endl;
	
	cout << "\t\t\t\t\t\t\t\t _____________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t\t|                    |                                |" << endl;
	cout << "\t\t\t\t\t\t\t\t| B E M - V I N D O  |  S Y S T E M   N E O C H E F Z |" << endl;
	cout << "\t\t\t\t\t\t\t\t|____________________|________________________________|" << endl;
	cout << "\t\t\t\t\t\t\t\t _____________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t\t|                                                     |" << endl;
	cout << "\t\t\t\t\t\t\t\t|       ** [REALIZE O LOGIN PARA PROSSEGUIR] **       |" << endl;
	cout << "\t\t\t\t\t\t\t\t|                                                     |" << endl;
	cout << "\t\t\t\t\t\t\t\t|=====================================================|" << endl;
	cout << "\t\t\t\t\t\t\t\t|USUÁRIO: ";
	fflush(stdin);
	cin.getline(recebe_usuarioatd01, 8);
	cout << "\t\t\t\t\t\t\t\t|SENHA: ";
	fflush(stdin);
	
	for(i = 0; i < 20; i++)
	{
		guarda_digito = getch();
		mascara_senhaatd01[i] = guarda_digito;
		putchar('*');
		if(guarda_digito == 13)
		{
			break;
		}
	}
	
	cout << "\n";
	mascara_senhaatd01[i] = '\0';
	strcpy(recebe_senhaatd01, mascara_senhaatd01);
	
	if(strcmp(recebe_usuarioatd01, usuarioatd01) != 0 || strcmp(recebe_senhaatd01, senhaatd01) != 0)
	{
		cout << "\t\t\t\t\t\t\t\t|=====================================================|" << endl;
		cout << "\t\t\t\t\t\t\t\t|                                                     |" << endl;
		cout << "\t\t\t\t\t\t\t\t|       **** USUÁRIO OU SENHA INCORRETA!!! ****       |" << endl;
		cout << "\t\t\t\t\t\t\t\t|                                                     |" << endl;
		cout << "\t\t\t\t\t\t\t\t|=====================================================|" << endl;
		cout << "\t\t\t\t\t\t\t\t| -> PRESSIONE ENTER PARA RETORNAR AO LOGIN NOVAMENTE |" << endl;
		cout << "\t\t\t\t\t\t\t\t|_____________________________________________________|";
		getch();
		system("cls");
		logado = 1;
	}
	else if(strcmp(recebe_usuarioatd01, usuarioatd01) == 0 || strcmp(recebe_senhaatd01, senhaatd01) == 0)
	{
		logado = 2;
		cout << "\t\t\t\t\t\t\t\t|=====================================================|" << endl;
		cout << "\t\t\t\t\t\t\t\t|                                                     |" << endl;
		cout << "\t\t\t\t\t\t\t\t|       **** LOGIN REALIZADO COM SUCESSO!!! ****      |" << endl;
		cout << "\t\t\t\t\t\t\t\t|                                                     |" << endl;
		cout << "\t\t\t\t\t\t\t\t|=====================================================|" << endl;
		cout << "\t\t\t\t\t\t\t\t|        -> PRESSIONE ENTER PARA ABRIR O MENU         |" << endl;
		cout << "\t\t\t\t\t\t\t\t|_____________________________________________________|";
		getch();
	}
}

void adm_login()
{
		char codigoadm[6];
		char recebe_codigoadm[6];
		char mascara_codigoadm[6];
		char guarda_digito;
		int i = 0;
		
		strcpy(codigoadm, "26N19");
	
		system("cls");
		cout << "\n " << endl;
		cout << "\t\t\t\t\t\t\t\t __________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t|      ###################                                 |" << endl;
		cout << "\t\t\t\t\t\t\t\t|      ## GERENCIAMENTO ##     [NECESSÁRIO REALIZAR LOGIN] |" << endl;
		cout << "\t\t\t\t\t\t\t\t|      ###################                                 |" << endl;
		cout << "\t\t\t\t\t\t\t\t|==========================================================|" << endl;
		cout << "\t\t\t\t\t\t\t\t|DIGITE O CÓDIGO ADMINISTRATIVO: ";
		fflush(stdin);
			
		for(i = 0; i < 20; i++)
		{
			guarda_digito = getch();
			mascara_codigoadm[i] = guarda_digito;
			putchar('*');
			
			if(guarda_digito == 13)
			{
				break;
			}
		}
	
		cout << endl;
		mascara_codigoadm[i] = '\0';
		strcpy(recebe_codigoadm, mascara_codigoadm);
		
		if(strcmp(recebe_codigoadm, codigoadm) != 0)
		{
			adm_logado = 1;
			cout << "\t\t\t\t\t\t\t\t|==========================================================|" << endl;
			cout << "\t\t\t\t\t\t\t\t|                                                          |" << endl;
			cout << "\t\t\t\t\t\t\t\t|       **** CÓDIGO ADMINISTRATIVO INCORRETO!!! ****       |" << endl;
			cout << "\t\t\t\t\t\t\t\t|__________________________________________________________|" << endl;
			cout << "\t\t\t\t\t\t\t\t|_________ PRESSIONE ENTER PARA RETORNAR AO MENU __________|" << endl;
			getch();
			system("cls");
				
		}
		else if(strcmp(recebe_codigoadm, codigoadm) == 0)
		{
			adm_logado = 2;
			cout << "\t\t\t\t\t\t\t\t|==========================================================|" << endl;
			cout << "\t\t\t\t\t\t\t\t|                                                          |" << endl;
			cout << "\t\t\t\t\t\t\t\t| [LOGIN REALIZADO]  **BEM-VINDO À ÁREA ADMINISTRATIVA**   |" << endl;
			cout << "\t\t\t\t\t\t\t\t|__________________________________________________________|" << endl;
			cout << "\t\t\t\t\t\t\t\t|____________ PRESSIONE ENTER PARA ABRIR O MENU ___________|" << endl;
			getch();
			
		}
}

void ped_pizza()
{
	int EscolhaPizza;
	char maispizza;
			
	system ("cls");
		
	//Cardapio de pizzas
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
		cout << "\t\t\t\t\t\t|                                        <<CARDÁPIO DE PIZZAS>>                                             |" << endl;
		cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
		cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
							Americana.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Atum.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Brocolis.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Calabresa.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							CincoQueijos.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							FrangCat.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Marguerita.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Portuguesa.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Rucula.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Siciliana.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Banana.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Passione.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							RomeuJulieta.visualizapizzas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
	
		
		do{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t|INSIRA O CÓDIGO DA PIZZA: ";
			fflush(stdin);
			sonumeros();
			EscolhaPizza = digitofinal;
			cout << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
		while(EscolhaPizza < 1 || EscolhaPizza > 13 || EscolhaPizza == '\0')
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t _________________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t|              **OPÇÃO INVÁLIDA!!!**              |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t|____ DIGITE UMA OPÇÃO DENTRE AS APRESENTADAS ____|" << endl;	
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t|INSIRA O CÓDIGO DA PIZZA: ";
			fflush(stdin);
			sonumeros();
			EscolhaPizza = digitofinal;
			cout << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
		}
		
				//QUANTIDADE DA PIZZA ESCOLHIDA	
		cout << "\t\t\t\t\t\t|QUANTIDADE: ";
		fflush(stdin);
		sonumeros();
		Pedido[contadorpedido].quantidade_pizzapedido = digitofinal;
		cout << endl;
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
		
		while(Pedido[contadorpedido].quantidade_pizzapedido < 1)
		{
			cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
			cout << "\t\t\t\t\t\t|                   **QUANTIDADE INVÁLIDA!!!**    QUANTIDADE DEVE SER MAIOR OU IGUAL [1]                    |" << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
			cout << "\t\t\t\t\t\t|QUANTIDADE: ";
			fflush(stdin);
			sonumeros();
			Pedido[contadorpedido].quantidade_pizzapedido = digitofinal;
			cout << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;	
		}
			
		while(EscolhaPizza == 1)
		{
			
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			PALMITO.quantidadeproduto = PALMITO.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			ERVILHA.quantidadeproduto = ERVILHA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			PRESUNTO.quantidadeproduto = PRESUNTO.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			BACON.quantidadeproduto = BACON.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  PALMITO.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  ERVILHA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  PRESUNTO.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  BACON.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				PALMITO.quantidadeproduto = 4000;
				ERVILHA.quantidadeproduto = 4000;
				PRESUNTO.quantidadeproduto = 4000;
				BACON.quantidadeproduto = 4000;
				break;
			}
			else
			{
				MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
				MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
				MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
				PALMITO.quantidadeproduto = PALMITO.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
				ERVILHA.quantidadeproduto = ERVILHA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
				PRESUNTO.quantidadeproduto = PRESUNTO.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
				BACON.quantidadeproduto = BACON.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);	
					
				Pedido[contadorpedido].nome_pizzapedido = Americana.nomepizza;
				Pedido[contadorpedido].tamanho_pizzapedido = Americana.tamanhopizza;
				Pedido[contadorpedido].ingredientes_pizzapedido = Americana.ingredientes;
				Pedido[contadorpedido].preco_pizzapedido = Americana.precopizza;
				Pedido[contadorpedido].codigo_pizzapedido = Americana.codigopizza;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
				cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
				
				//OBSERVAÇÕES DO PEDIDO
				cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
				fflush(stdin);
				getline(cin,Pedido[contadorpedido].obs_pizzapedido);
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 2)
		{
			
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			ATUM.quantidadeproduto = ATUM.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			TOMATE.quantidadeproduto = TOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			CEBOLA.quantidadeproduto = CEBOLA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  ATUM.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  TOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CEBOLA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
			MASSA.quantidadeproduto = 100;
			MOLHOTOMATE.quantidadeproduto = 4000;
			MUSSARELA.quantidadeproduto = 4000;
			ATUM.quantidadeproduto = 4000;
			TOMATE.quantidadeproduto = 4000;
			CEBOLA.quantidadeproduto = 4000;
				break;
			}
			else
			{
				Pedido[contadorpedido].nome_pizzapedido = Atum.nomepizza;
				Pedido[contadorpedido].tamanho_pizzapedido = Atum.tamanhopizza;
				Pedido[contadorpedido].ingredientes_pizzapedido = Atum.ingredientes;
				Pedido[contadorpedido].preco_pizzapedido = Atum.precopizza;
				Pedido[contadorpedido].codigo_pizzapedido = Atum.codigopizza;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
				cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;	
				
				//OBSERVAÇÕES DO PEDIDO
				cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
				fflush(stdin);
				getline(cin,Pedido[contadorpedido].obs_pizzapedido);
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 3)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			TOMATE.quantidadeproduto = TOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			CATUPIRY.quantidadeproduto = CATUPIRY.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			BROCOLIS.quantidadeproduto = BROCOLIS.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			PEPPERONI.quantidadeproduto = PEPPERONI.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			ALHO.quantidadeproduto = ALHO.quantidadeproduto-(50*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  TOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CATUPIRY.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  BROCOLIS.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  PEPPERONI.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  ALHO.quantidadeproduto < (50*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				TOMATE.quantidadeproduto = 4000;
				CATUPIRY.quantidadeproduto = 4000;
				BROCOLIS.quantidadeproduto = 4000;
				PEPPERONI.quantidadeproduto = 4000;
				ALHO.quantidadeproduto = 4000;	
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = Brocolis.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = Brocolis.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = Brocolis.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = Brocolis.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = Brocolis.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			}
			break;
		}
			
		while(EscolhaPizza == 4)
		{	
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			CALABRESA.quantidadeproduto = CALABRESA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			TOMATE.quantidadeproduto = TOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			CEBOLA.quantidadeproduto = CEBOLA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			OREGANO.quantidadeproduto = OREGANO.quantidadeproduto-(50*Pedido[contadorpedido].quantidade_pizzapedido);
			AZEITONA.quantidadeproduto = AZEITONA.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
		
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CALABRESA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  TOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CEBOLA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  OREGANO.quantidadeproduto < (50*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  AZEITONA.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				CALABRESA.quantidadeproduto = 4000;
				TOMATE.quantidadeproduto = 4000;
				CEBOLA.quantidadeproduto = 4000;
				OREGANO.quantidadeproduto = 4000;
				AZEITONA.quantidadeproduto = 4000;
				break;
			}
			else
			{
		
			Pedido[contadorpedido].nome_pizzapedido = Calabresa.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = Calabresa.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = Calabresa.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = Calabresa.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = Calabresa.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}

			break;
		}
			
		while(EscolhaPizza == 5)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			PARMESAO.quantidadeproduto = PARMESAO.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			PROVOLONE.quantidadeproduto = PROVOLONE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			GORGONZOLA.quantidadeproduto = GORGONZOLA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			CATUPIRY.quantidadeproduto = CATUPIRY.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  PARMESAO.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  PROVOLONE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  GORGONZOLA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CATUPIRY.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				PARMESAO.quantidadeproduto = 4000;
				PROVOLONE.quantidadeproduto = 4000;
				GORGONZOLA.quantidadeproduto = 4000;
				CATUPIRY.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = CincoQueijos.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = CincoQueijos.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = CincoQueijos.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = CincoQueijos.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = CincoQueijos.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 6)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			FRANGO.quantidadeproduto = FRANGO.quantidadeproduto-(200*Pedido[contadorpedido].quantidade_pizzapedido);
			CATUPIRY.quantidadeproduto = CATUPIRY.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			AZEITONA.quantidadeproduto = AZEITONA.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			OREGANO.quantidadeproduto = OREGANO.quantidadeproduto-(50*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  FRANGO.quantidadeproduto < (200*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CATUPIRY.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  AZEITONA.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  OREGANO.quantidadeproduto < (50*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				FRANGO.quantidadeproduto = 4000;
				CATUPIRY.quantidadeproduto = 4000;
				AZEITONA.quantidadeproduto = 4000;
				OREGANO.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = FrangCat.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = FrangCat.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = FrangCat.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = FrangCat.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = FrangCat.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 7)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			TOMATE.quantidadeproduto = TOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MANJERICAO.quantidadeproduto = MANJERICAO.quantidadeproduto-(50*Pedido[contadorpedido].quantidade_pizzapedido);
			AZEITONA.quantidadeproduto = AZEITONA.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			OREGANO.quantidadeproduto = OREGANO.quantidadeproduto-(50*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  TOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MANJERICAO.quantidadeproduto < (50*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  AZEITONA.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  OREGANO.quantidadeproduto < (50*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				TOMATE.quantidadeproduto = 4000;
				MANJERICAO.quantidadeproduto = 4000;
				AZEITONA.quantidadeproduto = 4000;
				OREGANO.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = Marguerita.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = Marguerita.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = Marguerita.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = Marguerita.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = Marguerita.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 8)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MILHO.quantidadeproduto = MILHO.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			ERVILHA.quantidadeproduto = ERVILHA.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			OVO.quantidadeproduto = OVO.quantidadeproduto-(5*Pedido[contadorpedido].quantidade_pizzapedido);
			CALABRESA.quantidadeproduto = CALABRESA.quantidadeproduto-(200*Pedido[contadorpedido].quantidade_pizzapedido);
			CEBOLA.quantidadeproduto = CEBOLA.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			AZEITONA.quantidadeproduto = AZEITONA.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			OREGANO.quantidadeproduto = OREGANO.quantidadeproduto-(50*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MILHO.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  ERVILHA.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  OVO.quantidadeproduto < (5*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CALABRESA.quantidadeproduto < (200*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CEBOLA.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  AZEITONA.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  OREGANO.quantidadeproduto < (50*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				MILHO.quantidadeproduto = 4000;
				ERVILHA.quantidadeproduto = 4000;
				OVO.quantidadeproduto = 4000;
				CALABRESA.quantidadeproduto = 4000;
				CEBOLA.quantidadeproduto = 4000;
				AZEITONA.quantidadeproduto = 4000;
				OREGANO.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = Portuguesa.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = Portuguesa.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = Portuguesa.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = Portuguesa.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = Portuguesa.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 9)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			TOMATE.quantidadeproduto = TOMATE.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			RUCULA.quantidadeproduto = RUCULA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  TOMATE.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  RUCULA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				TOMATE.quantidadeproduto = 4000;
				RUCULA.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = Rucula.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = Rucula.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = Rucula.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = Rucula.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = Rucula.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 10)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MOLHOTOMATE.quantidadeproduto = MOLHOTOMATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			BACON.quantidadeproduto = BACON.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			CHAMPIGNON.quantidadeproduto = CHAMPIGNON.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MOLHOTOMATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  BACON.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CHAMPIGNON.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MOLHOTOMATE.quantidadeproduto = 4000;
				MUSSARELA.quantidadeproduto = 4000;
				BACON.quantidadeproduto = 4000;
				CHAMPIGNON.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = Siciliana.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = Siciliana.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = Siciliana.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = Siciliana.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = Siciliana.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 11)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			DOCELEITE.quantidadeproduto = DOCELEITE.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			BANANA.quantidadeproduto = BANANA.quantidadeproduto-(100*Pedido[contadorpedido].quantidade_pizzapedido);
			CANELA.quantidadeproduto = CANELA.quantidadeproduto-(50*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  DOCELEITE.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  BANANA.quantidadeproduto < (100*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CANELA.quantidadeproduto < (50*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				DOCELEITE.quantidadeproduto = 4000;
				BANANA.quantidadeproduto = 100;
				CANELA.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = Banana.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = Banana.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = Banana.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = Banana.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = Banana.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
		 
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 12)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			CHOCOLATE.quantidadeproduto = CHOCOLATE.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			MORANGO.quantidadeproduto = MORANGO.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			SORVETECREME.quantidadeproduto = SORVETECREME.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  CHOCOLATE.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MORANGO.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  SORVETECREME.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				CHOCOLATE.quantidadeproduto = 4000;
				MORANGO.quantidadeproduto = 4000;
				SORVETECREME.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = Passione.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = Passione.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = Passione.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = Passione.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = Passione.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
			
		while(EscolhaPizza == 13)
		{
			MASSA.quantidadeproduto = MASSA.quantidadeproduto-(1*Pedido[contadorpedido].quantidade_pizzapedido);
			MUSSARELA.quantidadeproduto = MUSSARELA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			GOIABADA.quantidadeproduto = GOIABADA.quantidadeproduto-(150*Pedido[contadorpedido].quantidade_pizzapedido);
			
			if(MASSA.quantidadeproduto < (1*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  MUSSARELA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) ||
			  GOIABADA.quantidadeproduto < (150*Pedido[contadorpedido].quantidade_pizzapedido) )
			{
				cout << "\t\t\t\t\t\t **********INGREDIENTES INSUFICIENTES**********" << endl;
				MASSA.quantidadeproduto = 100;
				MUSSARELA.quantidadeproduto = 4000;
				GOIABADA.quantidadeproduto = 4000;
				break;
			}
			else
			{
			
			Pedido[contadorpedido].nome_pizzapedido = RomeuJulieta.nomepizza;
			Pedido[contadorpedido].tamanho_pizzapedido = RomeuJulieta.tamanhopizza;
			Pedido[contadorpedido].ingredientes_pizzapedido = RomeuJulieta.ingredientes;
			Pedido[contadorpedido].preco_pizzapedido = RomeuJulieta.precopizza;
			Pedido[contadorpedido].codigo_pizzapedido = RomeuJulieta.codigopizza;
			
			cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_pizzapedido << "............." << Pedido[contadorpedido].ingredientes_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[contadorpedido].tamanho_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_pizzapedido << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

			//OBSERVAÇÕES DO PEDIDO
			cout << "\t\t\t\t\t\t|OBSERVAÇÕES: ";
			fflush(stdin);
			getline(cin,Pedido[contadorpedido].obs_pizzapedido);
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			break;
		}
		
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t-> DESEJA OUTRA PIZZA? (S|N): ";
	 	fflush(stdin);
		cin >> maispizza;
		maispizza = toupper(maispizza);
		
		while(maispizza != 'S' && maispizza !='N')
		{
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t-> DESEJA OUTRA PIZZA? (S|N): ";
		cin.clear();
	   	cin.ignore(INT_MAX, '\n');
		fflush(stdin);
		cin >> maispizza;
		maispizza = toupper(maispizza);
		}
		
		contadorpedido++;
		
		}while(maispizza == 'S');
}

void ped_bebida()
{
	int EscolhaBebida;
	char maisbebida;
	
		//Bebidas
		system("cls");
		
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
		cout << "\t\t\t\t\t\t|                                        <<CARDÁPIO DE BEBIDAS>>                                            |" << endl;
		cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
		cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
							CocaCola.visualizabebidas();
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							CocaColaZero.visualizabebidas();							
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							CocaCola2.visualizabebidas();		
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Guarana.visualizabebidas();		
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							FantaUva.visualizabebidas();		
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Sprite.visualizabebidas();		
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Brahma.visualizabebidas();		
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Skol.visualizabebidas();		
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
							Eisenbahn.visualizabebidas();		
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
		
		do{
		
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|INSIRA O CÓDIGO DA BEBIDA: ";
		fflush(stdin);
		sonumeros();
		EscolhaBebida = digitofinal;
		cout << endl;
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

	        
	        while(EscolhaBebida < 0 || EscolhaBebida > 9 || EscolhaBebida == '\0')
			{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t _________________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t|              **OPÇÃO INVÁLIDA!!!**              |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t|____ DIGITE UMA OPÇÃO DENTRE AS APRESENTADAS ____|" << endl;	
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t|INSIRA O CÓDIGO DA BEBIDA: ";
			fflush(stdin);
			sonumeros();
			EscolhaBebida = digitofinal;
			cout << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			}
			
			//QUANTIDADE DA PIZZA ESCOLHIDA	
			cout << "\t\t\t\t\t\t|QUANTIDADE: ";
			fflush(stdin);
			sonumeros();
			Pedido[contadorpedido].quantidade_bebidapedido = digitofinal;
			cout << endl;
			cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
			
			while(Pedido[contadorpedido].quantidade_bebidapedido < 1)
			{
				cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
				cout << "\t\t\t\t\t\t|                   **QUANTIDADE INVÁLIDA!!!**    QUANTIDADE DEVE SER MAIOR OU IGUAL [1]                    |" << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
				cout << "\t\t\t\t\t\t|QUANTIDADE: ";
				fflush(stdin);
				sonumeros();
				Pedido[contadorpedido].quantidade_bebidapedido = digitofinal;
				cout << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;	
			}
	        
			while(EscolhaBebida == 1)
			{			
				Pedido[contadorpedido].nome_bebidapedido = CocaCola.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = CocaCola.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = CocaCola.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________"<< endl;
				
				COCACOLA.quantidadeproduto = COCACOLA.codigoproduto-Pedido[contadorpedido].quantidade_bebidapedido;
								
				break;
			}
			
			while(EscolhaBebida == 2)
			{
				Pedido[contadorpedido].nome_bebidapedido = CocaColaZero.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = CocaColaZero.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = CocaColaZero.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

				COCACOLAZERO.quantidadeproduto = COCACOLAZERO.quantidadeproduto-Pedido[contadorpedido].quantidade_bebidapedido;

				break;
			}
				
			while(EscolhaBebida == 3)
			{
				Pedido[contadorpedido].nome_bebidapedido = CocaCola2.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = CocaCola2.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = CocaCola2.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;
				
				COCACOLAZERO.quantidadeproduto = COCACOLAZERO.quantidadeproduto-Pedido[contadorpedido].quantidade_bebidapedido;
				
				break;
			}
				
			while(EscolhaBebida == 4)
			{
				Pedido[contadorpedido].nome_bebidapedido = Guarana.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = Guarana.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = Guarana.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

				GUARANA.quantidadeproduto = GUARANA.quantidadeproduto-Pedido[contadorpedido].quantidade_bebidapedido;

				break;
			}
			
			while(EscolhaBebida == 5)
			{
				Pedido[contadorpedido].nome_bebidapedido = FantaUva.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = FantaUva.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = FantaUva.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

				FANTAUVA.quantidadeproduto = FANTAUVA.quantidadeproduto-Pedido[contadorpedido].quantidade_bebidapedido;

				break;
			}
			
			while(EscolhaBebida == 6)
			{
				Pedido[contadorpedido].nome_bebidapedido = Sprite.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = Sprite.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = Sprite.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

				SPRITE.quantidadeproduto = SPRITE.quantidadeproduto-Pedido[contadorpedido].quantidade_bebidapedido;

				break;
			}
			
			while(EscolhaBebida == 7)
			{
				Pedido[contadorpedido].nome_bebidapedido = Brahma.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = Brahma.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = Brahma.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

				BRAHMA.quantidadeproduto = BRAHMA.quantidadeproduto-Pedido[contadorpedido].quantidade_bebidapedido;

				break;
			}
			
			while(EscolhaBebida == 8)
			{
				Pedido[contadorpedido].nome_bebidapedido = Skol.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = Skol.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = Skol.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

				SKOL.quantidadeproduto = SKOL.quantidadeproduto-Pedido[contadorpedido].quantidade_bebidapedido;

				break;
			}
			
			while(EscolhaBebida == 9)
			{
				Pedido[contadorpedido].nome_bebidapedido = Eisenbahn.nomebebida;
				Pedido[contadorpedido].preco_bebidapedido = Eisenbahn.precobebida;
				Pedido[contadorpedido].codigo_bebidapedido = Eisenbahn.codigobebida;
				
				cout << "\t\t\t\t\t\t|NOME: " << Pedido[contadorpedido].nome_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[contadorpedido].preco_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[contadorpedido].codigo_bebidapedido << endl;
				cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________" << endl;

				EISENBAHN.quantidadeproduto = EISENBAHN.quantidadeproduto-Pedido[contadorpedido].quantidade_bebidapedido;

				break;
			}
			
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t-> DESEJA OUTRA BEBIDA? (S|N): ";
			fflush(stdin);
			cin >> maisbebida;
			maisbebida = toupper(maisbebida);
			
			while(maisbebida != 'S' && maisbebida !='N')
			{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t-> DESEJA OUTRA BEBIDA? (S|N): ";
			cin.clear();
		   	cin.ignore(INT_MAX, '\n');
			fflush(stdin);
			cin >> maisbebida;
			maisbebida = toupper(maisbebida);
			}
		
		contadorpedido++;
		
		}while(maisbebida == 'S');		
}

void sonumeros()
{
	char digitado[50];//armazena o que foi digitado pelo usuário
    char guarda_digito;//armazena cada caractere digitado pelo usuário
    int i=0;//variável para controlar o índice do vetor de caracteres
	digitofinal=0;//variável para armazenar a conversão do que foi digitado pelo usuário
	
   	 do
        {
       guarda_digito=getch();//captura o caractere digitado pelo usuário
           if (isdigit(guarda_digito)!=0)//se for um número
           {
          digitado[i] = guarda_digito;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          cout << guarda_digito;//exibe o caractere digitado
       }
       else if(guarda_digito == 8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          cout << "\b \b";//o caractere digitado é apagado da tela
       }
    }while(guarda_digito!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)
   
    digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
    digitofinal = atoi(digitado);//a variável numero recebe o valor do vetor de caracteres convertido para inteiro

}

void realiza_pedido()
{
		int statuscliente; //VARIÁVEL PARA RECEBER A OPÇÃO DE CLIENTE CADASTRADO OU NÃO NO PRIMEIRO MENU DE REALIZAR PEDIDO
		int opcaopedido = 0; //VARIÁVEL PARA RECEBER O TIPO DE PEDIDO, SE É PIZZA OU BEBIDA
		string CPFstatuscliente; //VARIÁVEL PARA RECEBER O CPF DO CLIENTE PARA VERIFICAR SE ESTÁ CADASTRADO
		int confirmacliente = 0; //VARIÁVEL PARA RECEBER A CONFIRMAÇÃO SE ESTÁ CORRETO O CLIENTE OU NÃO
		int i = 0; //CONTADOR QUE SERÁ UTILIZADO EM UM LAÇO DE REPETIÇÃO PARA ENCONTRAR (OU NÃO) O CLIENTE
		int j = 0; //CONTADOR QUE SERÁ UTILIZADO EM UM LAÇO DE REPETIÇÃO PARA MOSTRAR NA TELA O PEDIDO REALIZADO

		
		cout << "\n" << endl; //MOSTRANDO AS OPÇÕES PARA IDENTIFICAR O CLIENTE PARA REALIZAR PEDIDO
		cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|       <<REALIZAR PEDIDO>>      |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|================================|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[1] - RETORNAR AO MENU          |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[2] - CLIENTE JÁ CADASTRADO     |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|[3] - CLIENTE SEM CADASTRO      |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t -> STATUS DO CLIENTE: ";
		fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
		sonumeros(); //FUNÇÃO PARA RECEBER SÓ NÚMEROS, EVITANDO ERROS
		statuscliente = digitofinal; //PASSANDO VALOR RETORNADO DA FUNÇÃO SÓ NUMEROS, PARA A VARIÁVEL QUE RECEBE O MENU
		
		while(statuscliente != 1 && statuscliente != 2 && statuscliente != 3) //VALIDAÇÃO DA OPÇÃO DIGITADA
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|____-> DIGITE UMA OPÇÃO VÁLIDA (1|2|3)____|" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t -> STATUS DO CLIENTE: ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			sonumeros(); //FUNÇÃO PARA RECEBER SÓ NUMEROS, EVITANDO ERROS
			statuscliente = digitofinal; //PASSANDO VALOR RETORNADO DA FUNÇÃO SÓ NUMEROS, PARA A VARIÁVEL QUE RECEBE O MENU
		}
		
			while(statuscliente == 1) //OPÇÃO (1) RETORNAR AO MENU
			{
				break; //RETORNA AO MENU PRINCIPAL
			}
			
			while(statuscliente == 2) //OPÇÃO (2) CLIENTE JÁ CADASTRADO
			{
				do{ //INICIANDO LAÇO DE REPETIÇÃO PARA CONFIRMAÇÃO DO CLIENTE
				
					system("cls"); //LIMPANDO A TELA
				
				cout << "\n" << endl; //SOLICITANDO A ENTRADA DO CPF DO CLIENTE PARA VERIFICAR CADASTRO
				cout << "\t\t\t\t\t\t\t\t\t\t ______________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                      |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|       <<CLIENTE JÁ CADASTRADO>>      |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                      |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|======================================|" << endl;
				
				do{
				cout << "\t\t\t\t\t\t\t\t\t\t -> INFORME O CPF DO CLIENTE: ";
					fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
					getline(cin,CPFstatuscliente); //RECEBENDO A LINHA DIGITADA PELO USUÁRIO, GUARDANDO NA VARIÁVEL CPFstatuscliente
					validacampobranco(CPFstatuscliente);
					
					if(verificador == 1)
					{
						validanumerico(CPFstatuscliente);
					}
					
				}while(verificador == 0);
					
					for(i = 0; i < contador; i++) //INICIANDO UM LAÇO DE REPETIÇÃO PARA VERIFICAR SE EXISTE O CLIENTE
					{
						if(Cliente[i].CPFcliente == CPFstatuscliente) //VERIFICANDO SE O CPF INFORMADO ESTÁ CADASTRADO NA ESTRUTURA DE CLIENTES
						{
							if(Cliente[i].clienteativo == 1) //VERIFICANDO SE O CLIENTE ESTÁ ATIVO, SE (1), É MOSTRADO NA TELA
							{	
								cout << "\t\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
								cout << "\t\t\t\t\t\t\t\t|" << endl;
								cout << "\t\t\t\t\t\t\t\t|CPF: " << Cliente[i].CPFcliente << endl;
								cout << "\t\t\t\t\t\t\t\t|NOME: " << Cliente[i].nomecliente << endl;					
								cout << "\t\t\t\t\t\t\t\t|TELEFONE: " << Cliente[i].telefonecliente << endl;
								cout << "\t\t\t\t\t\t\t\t|ENDEREÇO: " << Cliente[i].enderecocliente << endl;
								cout << "\t\t\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << Cliente[i].codigocliente << endl;
								cout << "\t\t\t\t\t\t\t\t|____________________________________________________________________" << endl;
								cout << "\t\t\t\t\t\t\t\t -> CONFIRMA O CLIENTE?  [1]-SIM | [2]-NÃO | [3]-RETORNAR AO MENU : ";
								fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
								sonumeros(); //FUNÇÃO PARA SÓ RECEBER NÚMEROS
								confirmacliente = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE TRATARÁ O DADO
									
									while(confirmacliente != 1 && confirmacliente != 2 && confirmacliente != 3) //VALIDAÇÃO DA OPÇÃO DIGITADA
									{
										cout << "\n" << endl;
										cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
										cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
										cout << "\t\t\t\t\t\t\t\t\t\t|____-> DIGITE UMA OPÇÃO VÁLIDA (1|2|3)____|" << endl;
										cout << "\n" << endl;
										cout << "\t\t\t\t\t\t\t\t -> CONFIRMA O CLIENTE?  [1]-SIM | [2]-NÃO | [3]-RETORNAR AO MENU : ";
										fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
										sonumeros(); //FUNÇÃO PARA SÓ RECEBER NÚMEROS
										confirmacliente = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE TRATARÁ O DADO
									}
								
								if(confirmacliente == 1) //SE CONFIRMA CLIENTE OPÇÃO (1), [1]-SIM
								{	
								//PASSA OS DADOS DO CLIENTE DA ESTRUTURA DE CLIENTES PARA A ESTRUTURA DE PEDIDO
								Pedido[contadorpedido].CPF_clientepedido = Cliente[i].CPFcliente;
								Pedido[contadorpedido].nome_clientepedido = Cliente[i].nomecliente;
								Pedido[contadorpedido].telefone_clientepedido = Cliente[i].telefonecliente;
								Pedido[contadorpedido].endereco_clientepedido = Cliente[i].enderecocliente;
								Pedido[contadorpedido].codigo_clientepedido = Cliente[i].codigocliente;
								
								cout << "\n" << endl;
								cout << "\t\t\t\t\t\t\t\t\t -> UNIDADE DA PIZZARIA?  [1] | [2] | [3] : ";
								sonumeros();
								unidadepizzaria = digitofinal;
								
									while(unidadepizzaria != 1 && unidadepizzaria != 2 && unidadepizzaria != 3) //VALIDAÇÃO DA OPÇÃO DIGITADA
									{
										cout << "\n" << endl;
										cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
										cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
										cout << "\t\t\t\t\t\t\t\t\t\t|____-> DIGITE UMA OPÇÃO VÁLIDA (1|2|3)____|" << endl;
										cout << "\n" << endl;
										cout << "\t\t\t\t\t\t\t\t\t -> UNIDADE DA PIZZARIA?  [1] | [2] | [3] : ";
										fflush(stdin); //LIMPANDO O BUFFER DE ENTRADA DE DADOS
										sonumeros(); //FUNÇÃO PARA SÓ RECEBER NÚMEROS
										unidadepizzaria = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE TRATARÁ O DADO
									}
								
								cout << "\n" << endl;
								cout << "\t\t\t\t\t\t\t\t\t -> PRESSIONE ENTER PARA PROSSEGUIR PARA O PEDIDO";
								getch(); //SISTEMA ESPERA O PRESSIONAMENTO NA TECLA PARA PROSSEGUIR
								
								system("cls"); //LIMPANDO A TELA
																								
								cout << "\n" << endl; //DANDO AS OPÇÕES PARA PEDIDO
								cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|       <<REALIZAR PEDIDO>>      |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|================================|" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|[1] - PEDIDO PIZZA              |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|[2] - PEDIDO BEBIDA             |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t -> OPÇÃO DE PEDIDO: ";
								fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
								sonumeros(); //FUNÇÃO PARA RECEBER SÓ NÚMEROS
								opcaopedido = digitofinal; //PASSANDO O VALOR RETORNADO DA FUNÇÃO PARA A VARIÁVEL QUE TRATARÁ O DADO
								
								while(opcaopedido != 1 && opcaopedido != 2) //VALIDAÇÃO DA OPÇÃO DIGITADA
								{
									cout << "\n" << endl;
									cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
									cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
									cout << "\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (1|2)_____|" << endl;
									cout << "\n\t\t\t\t\t\t\t\t\t\t -> OPÇÃO DE PEDIDO: ";
									fflush(stdin);
									sonumeros();
									opcaopedido = digitofinal;
								}
								
								while(opcaopedido == 1) //OPÇÃO (1) PEDIDO PIZZA
								{
									ped_pizza(); //CHAMADA DA FUNÇÃO PARA PEDIDO DE PIZZA
									
									cout << "\n\t\t\t\t\t\t-> DESEJA INCLUIR BEBIDAS NO PEDIDO? (S|N): "; //OPÇÃO DE INCLUIR BEBIDAS OU NÃO
									fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
									cin >> op; //RECEBENDO A OPÇÃO DIGITADA PELO USUÁRIO
									op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
									
									while(op != 'S' && op !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA PELO USUÁRIO
									{
										cout << "\n" << endl;
										cout << "\t\t\t\t\t\t\t\t __________________________________________" << endl;
										cout << "\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
										cout << "\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
										cout << "\n\t\t\t\t -> DESEJA INCLUIR BEBIDAS NO PEDIDO? (S|N): ";
										fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
										cin >> op; //RECEBENDO A OPÇÃO DIGITADA PELO USUÁRIO
										op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
									}
									
									if(op == 'S') //SE A OPÇÃO FOR "S" PARA INCLUIR BEBIDAS NO PEDIDO
									{
										ped_bebida(); //CHAMADA DA FUNÇÃO PARA PEDIDO DE BEBIDA
										
										cout << "\t\t\t\t\t\t __________________________________________________" << endl;
										cout << "\t\t\t\t\t\t|              ** PEDIDO CONCLUIDO **              |" << endl;
										cout << "\t\t\t\t\t\t|   -> PRESSIONE ENTER PARA VISUALIZAR O PEDIDO.   |" << endl;
										cout << "\t\t\t\t\t\t|__________________________________________________|";
										getch();
										
										system("cls"); //LIMPANDO A TELA
										
										//MOSTRANDO NA TELA O CLIENTE QUE REALIZOU O PEDIDO
										cout << "\n" << endl; 
										cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
										cout << "\t\t\t\t\t\t|                                                   CLIENTE                                                 |" << endl;
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl; 
										cout << "\t\t\t\t\t\t|" << endl;
										cout << "\t\t\t\t\t\t|CPF: " << Pedido[0].CPF_clientepedido << endl;
										cout << "\t\t\t\t\t\t|NOME: " << Pedido[0].nome_clientepedido << endl;					
										cout << "\t\t\t\t\t\t|TELEFONE: " << Pedido[0].telefone_clientepedido << endl;
										cout << "\t\t\t\t\t\t|ENDEREÇO: " << Pedido[0].endereco_clientepedido << endl;
										cout << "\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << Pedido[0].codigo_clientepedido << endl;
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
										
								for(j = 0; j < contadorpedido; j++) //LAÇO DE REPETIÇÃO PARA MOSTRAR AS PIZZAS E BEBIDAS PEDIDAS NO PEDIDO REALIZADO
								{															
									if(Pedido[j].codigo_pizzapedido != 0) //SE O CODIGO DA PIZZA FOR DIFERENTE DE '0', É POR QUE FOI PEDIDO ALGUMA PIZZA, SENDO EXIBIDA NA TELA													
									{	 								//A VERIFICAÇÃO VAI CONTINUAR ATÉ O CODIGO SER '0', QUE É QUANDO NÃO TEM MAIS PIZZAS PEDIDAS E NÃO TEM MAIS O QUE MOSTRAR
										cout << "\t\t\t\t\t\t|                                                    PIZZA                                                  |" << endl;
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
										cout << "\t\t\t\t\t\t|NOME: " << Pedido[j].nome_pizzapedido << "............." << Pedido[j].ingredientes_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[j].tamanho_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[j].preco_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[j].codigo_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|" << endl;
										cout << "\t\t\t\t\t\t|QUANTIDADE: " << Pedido[j].quantidade_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
										cout << "\t\t\t\t\t\t|OBSERVAÇÕES: " << Pedido[j].obs_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
										valortotal = valortotal + (Pedido[j].preco_pizzapedido*Pedido[j].quantidade_pizzapedido); //É PASSADO CADA VALOR DA PIZZA PEDIDA E SOMADA AO VALOR TOTAL DO PEDIDO
									}										
								}
								
								for(j = 0; j < contadorpedido; j++) //LAÇO DE REPETIÇÃO PARA MOSTRAR AS PIZZAS E BEBIDAS PEDIDAS NO PEDIDO REALIZADO
								{
									if(Pedido[j].codigo_bebidapedido != 0) //SE O CODIGO DA BEBIDA FOR DIFERENTE DE '0', É POR QUE FOI PEDIDO ALGUMA BEBIDA, SENDO EXIBIDA NA TELA	
										{									 //A VERIFICAÇÃO VAI CONTINUAR ATÉ O CODIGO SER '0', QUE É QUANDO NÃO TEM MAIS BEBIDAS PEDIDAS E NÃO TEM MAIS O QUE MOSTRAR
											cout << "\t\t\t\t\t\t|                                                    BEBIDA                                                 |" << endl;
											cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
											cout << "\t\t\t\t\t\t|NOME: " << Pedido[j].nome_bebidapedido << endl;
											cout << "\t\t\t\t\t\t|PREÇO: " << "(R$" << Pedido[j].preco_bebidapedido << ")" << endl;
											cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[j].codigo_bebidapedido << endl;
											cout << "\t\t\t\t\t\t|" << endl;
											cout << "\t\t\t\t\t\t|QUANTIDADE: " << Pedido[j].quantidade_bebidapedido << endl;
											cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
											valortotal = valortotal + (Pedido[j].preco_bebidapedido*Pedido[j].quantidade_bebidapedido); //É PASSADO CADA VALOR DA BEBIDA PEDIDA E SOMADA AO VALOR TOTAL DO PEDIDO
										}
								}
								
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
										cout << "\t\t\t\t\t\t|                                                 VALOR TOTAL: " << "R$" << valortotal << endl; //MOSTRANDO O VALOR TOTAL DO PEDIDO
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
										
										realizapagamento();
										
										arquivo.open("arquivopedidos.txt", ios::out | ios::app); //ABRINDO ARQUIVO PARA ESCRITA NO FINAL DO ARQUIVO
										
										arquivo << "\n"; 
										arquivo << " ___________________________________________________________________________________________________________" << endl;
										arquivo << "|                                                   CLIENTE                                                 |" << endl;
										arquivo << "|===========================================================================================================|" << endl; 
										arquivo << "|" << endl;
										arquivo << "|CPF: " << Pedido[0].CPF_clientepedido << endl;
										arquivo << "|NOME: " << Pedido[0].nome_clientepedido << endl;					
										arquivo << "|TELEFONE: " << Pedido[0].telefone_clientepedido << endl;
										arquivo << "|ENDEREÇO: " << Pedido[0].endereco_clientepedido << endl;
										arquivo << "|CÓDIGO DO CLIENTE: " << Pedido[0].codigo_clientepedido << endl;
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
										
								for(j = 0; j < contadorpedido; j++) //LAÇO DE REPETIÇÃO PARA MOSTRAR AS PIZZAS E BEBIDAS PEDIDAS NO PEDIDO REALIZADO
								{															
									if(Pedido[j].codigo_pizzapedido != 0) //SE O CODIGO DA PIZZA FOR DIFERENTE DE '0', É POR QUE FOI PEDIDO ALGUMA PIZZA, SENDO EXIBIDA NA TELA													
									{	 								//A VERIFICAÇÃO VAI CONTINUAR ATÉ O CODIGO SER '0', QUE É QUANDO NÃO TEM MAIS PIZZAS PEDIDAS E NÃO TEM MAIS O QUE MOSTRAR
										arquivo << "|                                                    PIZZA                                                  |" << endl;
										arquivo << "|===========================================================================================================|" << endl;
										arquivo << "|NOME: " << Pedido[j].nome_pizzapedido << "............." << Pedido[j].ingredientes_pizzapedido << endl;
										arquivo << "|TAMANHO: " << Pedido[j].tamanho_pizzapedido << endl;
										arquivo << "|PREÇO: " << "R$" << Pedido[j].preco_pizzapedido << endl;
										arquivo << "|CÓDIGO: " << Pedido[j].codigo_pizzapedido << endl;
										arquivo << "|" << endl;
										arquivo << "|QUANTIDADE: " << Pedido[j].quantidade_pizzapedido << endl;
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
										arquivo << "|OBSERVAÇÕES: " << Pedido[j].obs_pizzapedido << endl;
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
									}										
								}
								
								for(j = 0; j < contadorpedido; j++) //LAÇO DE REPETIÇÃO PARA MOSTRAR AS PIZZAS E BEBIDAS PEDIDAS NO PEDIDO REALIZADO
								{
									if(Pedido[j].codigo_bebidapedido != 0) //SE O CODIGO DA BEBIDA FOR DIFERENTE DE '0', É POR QUE FOI PEDIDO ALGUMA BEBIDA, SENDO EXIBIDA NA TELA	
										{									 //A VERIFICAÇÃO VAI CONTINUAR ATÉ O CODIGO SER '0', QUE É QUANDO NÃO TEM MAIS BEBIDAS PEDIDAS E NÃO TEM MAIS O QUE MOSTRAR
											arquivo << "|                                                    BEBIDA                                                 |" << endl;
											arquivo << "|===========================================================================================================|" << endl;
											arquivo << "|NOME: " << Pedido[j].nome_bebidapedido << endl;
											arquivo << "|PREÇO: " << "(R$" << Pedido[j].preco_bebidapedido << ")" << endl;
											arquivo << "|CÓDIGO: " << Pedido[j].codigo_bebidapedido << endl;
											arquivo << "|" << endl;
											arquivo << "|QUANTIDADE: " << Pedido[j].quantidade_bebidapedido << endl;
											arquivo << "|___________________________________________________________________________________________________________|" << endl;
										}
								}
										
										arquivo << "|===========================================================================================================|" << endl;
										arquivo << "|                                                 VALOR TOTAL: " << "R$" << valortotal << endl; //MOSTRANDO O VALOR TOTAL DO PEDIDO
										arquivo << "|___________________________________________________________________________________________________________|" << endl; 
										arquivo << "\n" << endl;
										arquivo << "*************************************************************************************************************" << endl;
										arquivo << "**                                F  I  N  A  L    D  O    P  E  D  I  D  O                                **" << endl;
										arquivo << "*************************************************************************************************************" << endl;
										
										arquivo.close();
										
										pedidos Pedido[1000]; //ZERANDO O VETOR DE PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
										contadorpedido = 0; //ZERANDO O CONTADOR DE PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
										valortotal = 0; //ZERANDO O VALOR TOTAL DO PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
										
										getch(); //AGUARDANDO O USUÁRIO PRESSIONAR ALGUMA TECLA
										break;
									}
									else if(op == 'N') //SE A OPÇÃO FOR "N" PARA INCLUIR BEBIDAS NO PEDIDO
									{
										cout << "\t\t\t\t\t\t\t\t\t __________________________________________________" << endl;
										cout << "\t\t\t\t\t\t\t\t\t|               **PEDIDO CONCLUIDO**               |" << endl;
										cout << "\t\t\t\t\t\t\t\t\t|   -> PRESSIONE ENTER PARA VISUALIZAR O PEDIDO.   |" << endl;
										cout << "\t\t\t\t\t\t\t\t\t|__________________________________________________|";
										getch();
										
										system("cls"); //LIMPANDO A TELA
										
										//MOSTRANDO NA TELA O CLIENTE QUE REALIZOU O PEDIDO
										cout << "\n" << endl;
										cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
										cout << "\t\t\t\t\t\t|                                                   CLIENTE                                                 |" << endl;
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl; 
										cout << "\t\t\t\t\t\t|" << endl;
										cout << "\t\t\t\t\t\t|CPF: " << Pedido[0].CPF_clientepedido << endl;
										cout << "\t\t\t\t\t\t|NOME: " << Pedido[0].nome_clientepedido << endl;					
										cout << "\t\t\t\t\t\t|TELEFONE: " << Pedido[0].telefone_clientepedido << endl;
										cout << "\t\t\t\t\t\t|ENDEREÇO: " << Pedido[0].endereco_clientepedido << endl;
										cout << "\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << Pedido[0].codigo_clientepedido << endl;
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
								
								for(j = 0; j < contadorpedido; j++) //LAÇO DE REPETIÇÃO PARA MOSTRAR AS PIZZAS PEDIDAS NO PEDIDO REALIZADO
								{								
							
									if(Pedido[j].codigo_pizzapedido != 0) //SE O CODIGO DA PIZZA FOR DIFERENTE DE '0', É POR QUE FOI PEDIDO ALGUMA PIZZA, SENDO EXIBIDA NA TELA														
									{	 								//A VERIFICAÇÃO VAI CONTINUAR ATÉ O CODIGO SER '0', QUE É QUANDO NÃO TEM MAIS PIZZAS PEDIDAS E NÃO TEM MAIS O QUE MOSTRAR
										cout << "\t\t\t\t\t\t|                                                    PIZZA                                                  |" << endl;
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
										cout << "\t\t\t\t\t\t|NOME: " << Pedido[j].nome_pizzapedido << "............." << Pedido[j].ingredientes_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|TAMANHO: " << Pedido[j].tamanho_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << Pedido[j].preco_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[j].codigo_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|" << endl;
										cout << "\t\t\t\t\t\t|QUANTIDADE: " << Pedido[j].quantidade_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
										cout << "\t\t\t\t\t\t|OBSERVAÇÕES: " << Pedido[j].obs_pizzapedido << endl;
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
										valortotal = valortotal + (Pedido[j].preco_pizzapedido*Pedido[j].quantidade_pizzapedido); //É PASSADO CADA VALOR DA PIZZA PEDIDA E SOMADA AO VALOR TOTAL DO PEDIDO
									}
										
								}
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
										cout << "\t\t\t\t\t\t|                                                 VALOR TOTAL: " << "R$" << valortotal << endl; //MOSTRANDO O VALOR TOTAL DO PEDIDO
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
																		
										realizapagamento();						
										
										arquivo.open("arquivopedidos.txt", ios::out | ios::app); //ABRINDO ARQUIVO PARA ESCRITA NO FINAL DO ARQUIVO
										
										arquivo << "\n";
										arquivo << " ___________________________________________________________________________________________________________" << endl;
										arquivo << "|                                                   CLIENTE                                                 |" << endl;
										arquivo << "|===========================================================================================================|" << endl; 
										arquivo << "|" << endl;
										arquivo << "|CPF: " << Pedido[0].CPF_clientepedido << endl;
										arquivo << "|NOME: " << Pedido[0].nome_clientepedido << endl;					
										arquivo << "|TELEFONE: " << Pedido[0].telefone_clientepedido << endl;
										arquivo << "|ENDEREÇO: " << Pedido[0].endereco_clientepedido << endl;
										arquivo << "|CÓDIGO DO CLIENTE: " << Pedido[0].codigo_clientepedido << endl;
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
								
								for(j = 0; j < contadorpedido; j++) //LAÇO DE REPETIÇÃO PARA MOSTRAR AS PIZZAS PEDIDAS NO PEDIDO REALIZADO
								{								
							
									if(Pedido[j].codigo_pizzapedido != 0) //SE O CODIGO DA PIZZA FOR DIFERENTE DE '0', É POR QUE FOI PEDIDO ALGUMA PIZZA, SENDO EXIBIDA NA TELA														
									{	 								//A VERIFICAÇÃO VAI CONTINUAR ATÉ O CODIGO SER '0', QUE É QUANDO NÃO TEM MAIS PIZZAS PEDIDAS E NÃO TEM MAIS O QUE MOSTRAR
										arquivo << "|                                                    PIZZA                                                  |" << endl;
										arquivo << "|===========================================================================================================|" << endl;
										arquivo << "|NOME: " << Pedido[j].nome_pizzapedido << "............." << Pedido[j].ingredientes_pizzapedido << endl;
										arquivo << "|TAMANHO: " << Pedido[j].tamanho_pizzapedido << endl;
										arquivo << "|PREÇO: " << "R$" << Pedido[j].preco_pizzapedido << endl;
										arquivo << "|CÓDIGO: " << Pedido[j].codigo_pizzapedido << endl;
										arquivo << "|" << endl;
										arquivo << "|QUANTIDADE: " << Pedido[j].quantidade_pizzapedido << endl;
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
										arquivo << "|OBSERVAÇÕES: " << Pedido[j].obs_pizzapedido << endl;
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
									}
										
								}
										arquivo << "|===========================================================================================================|" << endl;
										arquivo << "|                                                 VALOR TOTAL: " << "R$" << valortotal << endl; //MOSTRANDO O VALOR TOTAL DO PEDIDO
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
										arquivo << "\n" << endl;
										arquivo << "*************************************************************************************************************" << endl;
										arquivo << "**                                F  I  N  A  L    D  O    P  E  D  I  D  O                                **" << endl;
										arquivo << "*************************************************************************************************************" << endl;
										
										arquivo.close();
										
										pedidos Pedido[1000]; //ZERANDO O VETOR DE PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
										contadorpedido = 0; //ZERANDO O CONTADOR DE PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
										valortotal = 0;//ZERANDO O VALOR TOTAL DO PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
									
										getch(); //AGUARDANDO O USUÁRIO PRESSIONAR ALGUMA TECLA
										break;
									}
									break;
								}
								
								while(opcaopedido == 2)
								{
									ped_bebida(); //CHAMADA DA FUNÇÃO PARA PEDIDO DE BEBIDA
									
									cout << "\t\t\t\t\t\t __________________________________________________" << endl;
									cout << "\t\t\t\t\t\t|               **PEDIDO CONCLUIDO**               |" << endl;
									cout << "\t\t\t\t\t\t|   -> PRESSIONE ENTER PARA VISUALIZAR O PEDIDO.   |" << endl;
									cout << "\t\t\t\t\t\t|__________________________________________________|";
									getch();
									
									system("cls"); //LIMPANDO A TELA
									
										//MOSTRANDO NA TELA O CLIENTE QUE REALIZOU O PEDIDO
										cout << "\n" << endl;
										cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
										cout << "\t\t\t\t\t\t|                                                   CLIENTE                                                 |" << endl;
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl; 
										cout << "\t\t\t\t\t\t|" << endl;
										cout << "\t\t\t\t\t\t|NOME: " << Pedido[0].nome_clientepedido << endl;										
										cout << "\t\t\t\t\t\t|CPF: " << Pedido[0].CPF_clientepedido << endl;				
										cout << "\t\t\t\t\t\t|TELEFONE: " << Pedido[0].telefone_clientepedido << endl;
										cout << "\t\t\t\t\t\t|ENDEREÇO: " << Pedido[0].endereco_clientepedido << endl;
										cout << "\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << Pedido[0].codigo_clientepedido << endl;
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
								
								for(j = 0; j < contadorpedido; j++) //LAÇO DE REPETIÇÃO PARA MOSTRAR AS BEBIDAS PEDIDAS NO PEDIDO REALIZADO
								{								
																							
									if(Pedido[j].codigo_bebidapedido != 0) //SE O CODIGO DA BEBIDA FOR DIFERENTE DE '0', É POR QUE FOI PEDIDO ALGUMA BEBIDA, SENDO EXIBIDA NA TELA		
									{									//A VERIFICAÇÃO VAI CONTINUAR ATÉ O CODIGO SER '0', QUE É QUANDO NÃO TEM MAIS BEBIDAS PEDIDAS E NÃO TEM MAIS O QUE MOSTRAR
										cout << "\t\t\t\t\t\t|                                                    BEBIDA                                                 |" << endl;
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
										cout << "\t\t\t\t\t\t|NOME: " << Pedido[j].nome_bebidapedido << endl;
										cout << "\t\t\t\t\t\t|PREÇO: " << "(R$" << Pedido[j].preco_bebidapedido << ")" << endl;
										cout << "\t\t\t\t\t\t|CÓDIGO: " << Pedido[j].codigo_bebidapedido << endl;
										cout << "\t\t\t\t\t\t|" << endl;
										cout << "\t\t\t\t\t\t|QUANTIDADE: " << Pedido[j].quantidade_bebidapedido << endl;
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
										valortotal = valortotal + (Pedido[j].preco_bebidapedido*Pedido[j].quantidade_bebidapedido); //É PASSADO CADA VALOR DA PIZZA PEDIDA E SOMADA AO VALOR TOTAL DO PEDIDO
									}
								}
										cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
										cout << "\t\t\t\t\t\t|                                                 VALOR TOTAL: " << "R$" << valortotal << endl; //MOSTRANDO O VALOR TOTAL DO PEDIDO
										cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
										
										realizapagamento();
										
										arquivo.open("arquivopedidos.txt", ios::out | ios::app); //ABRINDO ARQUIVO PARA ESCRITA NO FINAL DO ARQUIVO
										
										arquivo << "\n";
										arquivo << " ___________________________________________________________________________________________________________" << endl;
										arquivo << "|                                                   CLIENTE                                                 |" << endl;
										arquivo << "|===========================================================================================================|" << endl; 
										arquivo << "|" << endl;
										arquivo << "|CPF: " << Pedido[0].CPF_clientepedido << endl;
										arquivo << "|NOME: " << Pedido[0].nome_clientepedido << endl;					
										arquivo << "|TELEFONE: " << Pedido[0].telefone_clientepedido << endl;
										arquivo << "|ENDEREÇO: " << Pedido[0].endereco_clientepedido << endl;
										arquivo << "|CÓDIGO DO CLIENTE: " << Pedido[0].codigo_clientepedido << endl;
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
								
								for(j = 0; j < contadorpedido; j++) //LAÇO DE REPETIÇÃO PARA MOSTRAR AS BEBIDAS PEDIDAS NO PEDIDO REALIZADO
								{								
																							
									if(Pedido[j].codigo_bebidapedido != 0) //SE O CODIGO DA BEBIDA FOR DIFERENTE DE '0', É POR QUE FOI PEDIDO ALGUMA BEBIDA, SENDO EXIBIDA NA TELA		
									{									//A VERIFICAÇÃO VAI CONTINUAR ATÉ O CODIGO SER '0', QUE É QUANDO NÃO TEM MAIS BEBIDAS PEDIDAS E NÃO TEM MAIS O QUE MOSTRAR
										arquivo << "|                                                    BEBIDA                                                 |" << endl;
										arquivo << "|===========================================================================================================|" << endl;
										arquivo << "|NOME: " << Pedido[j].nome_bebidapedido << endl;
										arquivo << "|PREÇO: " << "(R$" << Pedido[j].preco_bebidapedido << ")" << endl;
										arquivo << "|CÓDIGO: " << Pedido[j].codigo_bebidapedido << endl;
										arquivo << "|" << endl;
										arquivo << "|QUANTIDADE: " << Pedido[j].quantidade_bebidapedido << endl;
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
										valortotal = valortotal + (Pedido[j].preco_bebidapedido*Pedido[j].quantidade_bebidapedido); //É PASSADO CADA VALOR DA PIZZA PEDIDA E SOMADA AO VALOR TOTAL DO PEDIDO
									}
								}
										arquivo << "|===========================================================================================================|" << endl;
										arquivo << "|                                                 VALOR TOTAL: " << "R$" << valortotal << endl; //MOSTRANDO O VALOR TOTAL DO PEDIDO
										arquivo << "|___________________________________________________________________________________________________________|" << endl;
										arquivo << "\n" << endl;
										arquivo << "*************************************************************************************************************" << endl;
										arquivo << "**                                F  I  N  A  L    D  O    P  E  D  I  D  O                                **" << endl;
										arquivo << "*************************************************************************************************************" << endl;
										
										arquivo.close();
										
										pedidos Pedido[1000]; //ZERANDO O VETOR DE PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
										contadorpedido = 0; //ZERANDO O CONTADOR DE PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
										valortotal = 0;//ZERANDO O VALOR TOTAL DO PEDIDO PARA NÃO INTERFERIR NO PRÓXIMO PEDIDO
										
										getch(); //AGUARDANDO O USUÁRIO PRESSIONAR ALGUMA TECLA
										break;
								}
								
								}
							break;		
							}
							else if(Cliente[i].clienteativo == 0) //VERIFICANDO SE O CLIENTE ESTÁ ATIVO, SE (0), CLIENTE NÃO ENCONTRADO
							{
								cout << "\n";
								cout << "\t\t\t\t\t\t\t\t\t ______________________________________________" << endl;
								cout << "\t\t\t\t\t\t\t\t\t|         -> CLIENTE NÃO ENCONTRADO <-         |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t|   **RETORNE AO MENU E REALIZE O CADASTRO**   |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t|   -> PRESSIONE ENTER PARA RETORNAR AO MENU.  |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t|______________________________________________|";
								getch(); //AGUARDANDO O USUÁRIO PRESSIONAR ALGUMA TECLA
								break;	
							}
							break;
						}
					}
					
					if(Cliente[i].CPFcliente != CPFstatuscliente) //SE O CPF INFORMADO FOR DIFERENTE, NÃO FOR LOCALIZADO NA ESTRUTURA DE CLIENTES
					{
						cout << "\n";
						cout << "\t\t\t\t\t\t\t\t\t ______________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t\t|         -> CLIENTE NÃO ENCONTRADO <-         |" << endl;
						cout << "\t\t\t\t\t\t\t\t\t|   **RETORNE AO MENU E REALIZE O CADASTRO**   |" << endl;
						cout << "\t\t\t\t\t\t\t\t\t|   -> PRESSIONE ENTER PARA RETORNAR AO MENU.  |" << endl;
						cout << "\t\t\t\t\t\t\t\t\t|______________________________________________|";
						getch(); //AGUARDANDO O USUÁRIO PRESSIONAR ALGUMA TECLA
						break;
					}
					
					if(confirmacliente == 3) //SE CONFIRMA CLIENTE OPÇÃO (3), [3]-RETORNAR AO MENU
					{
						break; //QUEBRA O LAÇO DE REPETIÇÃO E RETORNA AO MENU PRINCIPAL
					}
					
				}while(confirmacliente == 2); //ENQUANTO CONFIRMA CLIENTE OPÇÃO (2), [2]-NÃO, LAÇO CONTINUA NO LOOP
					
				break;	
			}
			
			while(statuscliente == 3) //OPÇÃO (3), CLIENTE SEM CADASTRO
			{
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tDESEJA REALIZAR O CADASTRO? (S|N): ";
				fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
				cin >> op; //RECEBENDO A OPÇÃO DIGITADA PELO USUÁRIO
				op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
				
				while(op != 'S' && op !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA PELO USUÁRIO
				{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\tDESEJA REALIZAR O CADASTRO? (S|N): ";
					fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
					cin >> op; //RECEBENDO A OPÇÃO DIGITADA PELO USUÁRIO
					op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
				}
				
				if(op == 'S')
				{
					cadastrar_cliente();
					break;
				}
				else if(op == 'N')
				{
					cout << "\n";
					cout << "\t\t\t\t\t\t\t\t\t\t ______________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|   -> PRESSIONE ENTER PARA RETORNAR AO MENU.  |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|______________________________________________|";
					getch(); //AGUARDANDO O USUÁRIO PRESSIONAR ALGUMA TECLA
					break;
				}
				
			}	
}

int validanumerico(string campo)
{
	int contador;
	int tamanhostring;
	int valida;
	
	tamanhostring = campo.size();
	
	for(contador = 0; contador < tamanhostring; contador++)
	{
		if(isalpha(campo[contador]))
		{
			valida = 0;
			contador = tamanhostring + 1;
		}
		else
		{
			valida = 1;
		}
	}
	
	if(valida == 0)
	{
		cout << "\n\t\t\t\t\t\t\t -> CARACTERE INVÁLIDO! LETRAS NÃO SÃO PERMITIDAS." << endl << endl;
		verificador = 0;
	}
	else
	{
		verificador = 1;
	}
	
}

int validaletra(string campo)
{
	int contador;
	int tamanhostring;
	int valida;
	
	tamanhostring = campo.size();
	
	for(contador = 0; contador < tamanhostring; contador++)
	{
		if(isdigit(campo[contador]))
		{
			valida = 0;
			contador = tamanhostring + 1;
		}
		else
		{
			valida = 1;
		}
	}
	
	if(valida == 0)
	{
		cout << "\n\t\t\t\t\t\t\t -> CARACTERE INVÁLIDO! NÚMEROS NÃO SÃO PERMITIDOS." << endl << endl;
		verificador = 0;
	}
	else
	{
		verificador = 1;
	}
	
}

int validacampobranco(string campo)
{
	int tamanhostring;
	tamanhostring = campo.size();

	if(tamanhostring < 1)
	{
		cout << "\n\t\t\t\t\t\t\t -> NÃO SÃO PERMITIDOS CAMPOS VAZIOS." << endl << endl;
		verificador = 0;
	}
	else
	{
		verificador = 1;
	}
	
}

void excluir_pedido()
{
	string CPFexcluipedido;
	char confexcluipedido;
	char novaexclusao;
		
		do
		{
		system("cls");
		cout << "\n " << endl; //SOLICITANDO O CPF DO CLIENTE QUE REALIZOU O PEDIDO
		cout << "\t\t\t\t\t\t\t\t\t ___________________________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t|                                           |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t|             <<EXCLUIR PEDIDO>>            |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t|                                           |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t|===========================================|" << endl;
		
		do{
			cout << "\t\t\t\t\t\t\t\t\t -> DIGITE O CPF DO CLIENTE: ";
			fflush(stdin);
			sonumeros();
			CPFexcluipedido = digitofinal;
			
			validacampobranco(CPFexcluipedido);
		
		}while(verificador == 0);
		
		cout << "\n" << endl; 
		cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                   CLIENTE                                                 |" << endl;
		cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl; 
		cout << "\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t\t\t\t|CPF: " << "0000000000" << endl;
		cout << "\t\t\t\t\t\t|NOME: " << "xxxxxx xxxxxxxxx xxxxxxx" << endl;				
		cout << "\t\t\t\t\t\t|TELEFONE: " << "00 000000000" << endl;
		cout << "\t\t\t\t\t\t|ENDEREÇO: " << "xxx xxxxxxxxx 0000, xxxxxx xxxxxxxx, xxxxxxxx-xx" << endl;
		cout << "\t\t\t\t\t\t|CÓDIGO DO CLIENTE: " << "1" << endl;
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
		cout << "\t\t\t\t\t\t|                                                    PIZZA                                                  |" << endl;
		cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
		cout << "\t\t\t\t\t\t|NOME: " << "AMERICANA" << endl;
		cout << "\t\t\t\t\t\t|TAMANHO: " << "ÚNICO (4 PESSOAS)" << endl;
		cout << "\t\t\t\t\t\t|PREÇO: " << "R$" << "22.99" << endl;
		cout << "\t\t\t\t\t\t|CÓDIGO: " << "1" << endl;
		cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
		cout << "\t\t\t\t\t\t|QUANTIDADE: " << "1" << endl;
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
		cout << "\t\t\t\t\t\t|OBSERVAÇÕES: " << "xxxxxxxxxxx" << endl;
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
		cout << "\t\t\t\t\t\t|                                                    BEBIDA                                                 |" << endl;
		cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
		cout << "\t\t\t\t\t\t|NOME: " << "COCA-COLA 350ml" << endl;
		cout << "\t\t\t\t\t\t|PREÇO: " << "(R$" << "4.59" << ")" << endl;
		cout << "\t\t\t\t\t\t|CÓDIGO: " << "1" << endl;
		cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
		cout << "\t\t\t\t\t\t|QUANTIDADE: " << "1" << endl;
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
		cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
		cout << "\t\t\t\t\t\t|                                                 VALOR TOTAL: " << "R$" << "27.58" << endl; //MOSTRANDO O VALOR TOTAL DO PEDIDO
		cout << "\t\t\t\t\t\t|___________________________________________________________________________________________________________|" << endl;
		
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t-> DESEJA REALMENTE EXCLUIR O PEDIDO? (S|N): ";
		fflush(stdin);
		cin >> confexcluipedido;
		confexcluipedido = toupper(confexcluipedido);
		
		while(confexcluipedido != 'S' && confexcluipedido !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA PELO USUÁRIO
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\n\t\t\t\t\t\t-> DESEJA REALMENTE EXCLUIR O PEDIDO? (S|N): ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			cin >> confexcluipedido; //RECEBENDO A OPÇÃO DIGITADA PELO USUÁRIO
			confexcluipedido = toupper(confexcluipedido); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		}
		
		if(confexcluipedido == 'S')
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t -> EXCLUINDO PEDIDO, AGUARDE..." << endl;
			Sleep(3000);
			cout << "\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t|   ** PEDIDO EXCLUÍDO COM SUCESSO!!! **   |" << endl;
			cout << "\t\t\t\t\t\t|__________________________________________|" << endl;
		}
		else if(confexcluipedido == 'N')
		{
			cout << "\t\t\t\t\t\t _____________________________________________" << endl;
			cout << "\t\t\t\t\t\t|   ** EXCLUSÃO CANCELADA COM SUCESSO!!! **   |" << endl;
			cout << "\t\t\t\t\t\t|_____________________________________________|" << endl;
		}
		
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t-> DESEJA REALIZAR NOVA EXCLUSÃO (S|N): ";
		fflush(stdin);
		cin >> novaexclusao;
		novaexclusao = toupper(novaexclusao);
		
		while(novaexclusao != 'S' && novaexclusao !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA PELO USUÁRIO
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\t\t\t\t\t\t-> DESEJA REALIZAR NOVA EXCLUSÃO (S|N): ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			cin >> novaexclusao; //RECEBENDO A OPÇÃO DIGITADA PELO USUÁRIO
			novaexclusao = toupper(novaexclusao); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		}
		
		}while(novaexclusao == 'S');
										
		cout << "\n\t\t\t\t\t\t-> PRESSIONE ENTER PARA RETORNAR AO MENU!" << endl;
		getch(); //AGUARDANDO O USUÁRIO PRESSIONAR ALGUMA TECLA
}

void cadastrar_funcionario()
{
	time_t agora;
    char datahora[100];

    /* Recupera a quantidade de segundos desde 01/01/1970 */
    agora = time(NULL);

    /* Formata a data e a hora da forma desejada */
    strftime( datahora, sizeof(datahora), "%d.%m.%Y - %H:%M:%S", localtime( &agora ) );
    
    Funcionario[contadorfuncionario].datafuncionario = (std::string) datahora;

	do{ //LAÇO DE REPETIÇÃO PARA REALIZAR CADASTROS DE FUNCIONÁRIOS
		
		Funcionario[contadorfuncionario].codigofuncionario = geracodigofun; //PASSANDO PARA O FUNCIONARIO NA POSIÇÃO [] DO VETOR, O CÓDIGO GERADO PELA VARIÁVEL GERACODIGO
		
		system("cls"); //LIMPANDO A TELA
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t\t|                    <<NOVO CADASTRO FUNCIONÁRIO>>                   |" << endl;
		cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
				
		do{
		cout << "\t\t\t\t\t\t\t|                 NOME: ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		getline(cin,Funcionario[contadorfuncionario].nomefuncionario); //PEGANDO A LINHA DIGITADA PELO USUÁRIO NA POSIÇÃO [] DO VETOR
		validacampobranco(Funcionario[contadorfuncionario].nomefuncionario);
		
			if(verificador == 1)
			{
				validaletra(Funcionario[contadorfuncionario].nomefuncionario);	
			}
		}while(verificador == 0);
		
		
		do{
		cout << "\t\t\t\t\t\t\t|                  CPF: ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		getline(cin,Funcionario[contadorfuncionario].CPFfuncionario); //PEGANDO A LINHA DIGITADA PELO USUÁRIO NA POSIÇÃO [] DO VETOR
		validacampobranco(Funcionario[contadorfuncionario].CPFfuncionario);
		
			if(verificador == 1)
			{
				validanumerico(Funcionario[contadorfuncionario].CPFfuncionario);	
			}
		}while(verificador == 0);
		
		
		do{
		cout << "\t\t\t\t\t\t\t|               FUNÇÃO: ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		getline(cin,Funcionario[contadorfuncionario].funcaofuncionario); //PEGANDO A LINHA DIGITADA PELO USUÁRIO NA POSIÇÃO [] DO VETOR
		validacampobranco(Funcionario[contadorfuncionario].funcaofuncionario);
		}while(verificador == 0);
		
		
		do{
		cout << "\t\t\t\t\t\t\t|              UNIDADE: ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		getline(cin,Funcionario[contadorfuncionario].unidadefuncionario); //PEGANDO A LINHA DIGITADA PELO USUÁRIO NA POSIÇÃO [] DO VETOR
		validacampobranco(Funcionario[contadorfuncionario].unidadefuncionario);
		
		if(verificador == 1)
			{
				validanumerico(Funcionario[contadorfuncionario].unidadefuncionario);
			}
		}while(verificador == 0);
		
		
		cout << "\t\t\t\t\t\t\t|     DATA DE CADASTRO: " << Funcionario[contadorfuncionario].datafuncionario << endl;
		
		//MOSTRANDO O CÓDIGO DO FUNCIONARIO QUE ESTÁ SENDO CADASTRADO
		cout << "\t\t\t\t\t\t\t|CÓDIGO DO FUNCIONÁRIO: " << Funcionario[contadorfuncionario].codigofuncionario; 
		
		Funcionario[contadorfuncionario].funcionarioativo = 1; //PASSANDO O VALOR (1), SIGNIFICANDO QUE O FUNCIONARIO ESTÁ ATIVO


		
		cout << "\n\t\t\t\t\t\t\t -> CONFIRMA CADASTRO DO FUNCIONÁRIO? (S|N): ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
		op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		
		while(op != 'S' && op !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\n\t\t\t\t\t\t\t -> CONFIRMA CADASTRO DO FUNCIONÁRIO? (S|N): ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
			op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		}
		
		if(op == 'S')
		{			
			contadorfuncionario++; //INCREMENTANDO CONTADOR DE FUNCIONARIO PARA PODER RECEBER UM NOVO EM OUTRA POSIÇÃO DO VETOR
			geracodigofun++;
			
			backupfuncionario();
			
			cout << endl;
			cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|              -> FUNCIONÁRIO CADASTRADO COM SUCESSO!!!              |" << endl;	
			cout << "\t\t\t\t\t\t\t|____________________________________________________________________|" << endl;
		}
		else if(op == 'N')
		{
			cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|               -> CADASTRO CANCELADO COM SUCESSO!!!                 |" << endl;	
			cout << "\t\t\t\t\t\t\t|____________________________________________________________________|" << endl;
		}

		
		cout << "\n\t\t\t\t\t\t\tDESEJA REALIZAR NOVO CADASTRO? (S|N): ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
		op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		
		while(op != 'S' && op !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\n\t\t\t\t\t\t\tDESEJA REALIZAR NOVO CADASTRO? (S|N): ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
			op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		}
			
		system("cls"); //LIMPANDO A TELA
			
	} while(op == 'S'); //ENQUANTO FOR 'S', O LOOP CONTINUARÁ PARA CADASTRAR NOVO FUNCIONARIO
}

void excluir_funcionario()
{
	string CPFexfuncionario;
		
	do{
		
	bool opcaodeletar = false;
		
	system("cls");
	cout << "\n" << endl;
	cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
	cout << "\t\t\t\t\t\t\t|               <<EXCLUSÃO DE CADASTRO DE FUNCIONÁRIO>>              |" << endl;
	cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
	cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;	
	
	do{
	cout << "\t\t\t\t\t\t\t -> DIGITE O CPF DO FUNCIONÁRIO: ";
	fflush(stdin);
	getline(cin, CPFexfuncionario);
	validacampobranco(CPFexfuncionario);
	
		if(verificador == 1)
		{
			validanumerico(CPFexfuncionario);
		}
		
	}while(verificador == 0);
		
		for(i = 0; i < contadorfuncionario; i++)
		{
			if(Funcionario[i].CPFfuncionario == CPFexfuncionario)
			{
				if(Funcionario[i].funcionarioativo == 0)
				{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t\t|        FUNCIONÁRIO NÃO ENCONTRADO!!!        |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
					break;
				}
				else if(Funcionario[i].funcionarioativo == 1)
				{
					cout << "\n";
					cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t|" << endl;
					cout << "\t\t\t\t\t\t\t|                 NOME: " << Funcionario[i].nomefuncionario << endl;
					cout << "\t\t\t\t\t\t\t|                  CPF: " << Funcionario[i].CPFfuncionario << endl;
					cout << "\t\t\t\t\t\t\t|               FUNÇÃO: " << Funcionario[i].funcaofuncionario << endl;
					cout << "\t\t\t\t\t\t\t|              UNIDADE: " << Funcionario[i].unidadefuncionario << endl;
					cout << "\t\t\t\t\t\t\t|     DATA DE CADASTRO: " << Funcionario[i].datafuncionario << endl;
					cout << "\t\t\t\t\t\t\t|CÓDIGO DO FUNCIONÁRIO: " << Funcionario[i].codigofuncionario << endl;
					cout << "\t\t\t\t\t\t\t|____________________________________________________________________" << endl;		
				
					cout << "\n\t\t\t\t\t\t\t -> DESEJA REALMENTE EXCLUIR ESTE CADASTRO? (S/N): ";
					fflush(stdin);
					cin >> op;
					op = toupper(op);
					
						while(op != 'S' && op !='N')
						{
							cout << "\n" << endl;
							cout << "\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
							cout << "\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
							cout << "\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
							cout << "\n\t\t\t\t\t\t\t -> DESEJA REALMENTE EXCLUIR ESTE CADASTRO? (S/N): ";
							cin.clear();
					       	cin.ignore(INT_MAX, '\n');
					       	fflush(stdin);
							cin >> op;
							op = toupper(op);
						}
					
					opcaodeletar = true;
					
					if(op == 'S')
					{
						Funcionario[i].funcionarioativo = 0;
						backupfuncionario();
						cout << "\n" << endl;
						cout << "\t\t\t\t\t\t\t\t ___________________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t|       ** EXCLUSÃO EFETUADA COM SUCESSO!!! **      |" << endl;
						cout << "\t\t\t\t\t\t\t\t|___________________________________________________|" << endl;
						break;
					}
					else if(op == 'N')
					{
						cout << "\n" << endl;
						cout << "\t\t\t\t\t\t\t\t ___________________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t|             ** EXCLUSÃO CANCELADA!!! **           |" << endl;
						cout << "\t\t\t\t\t\t\t\t|___________________________________________________|" << endl;
					}
				}
				break;
			}	
		}
			
		if(opcaodeletar == false)
		{
			if(Funcionario[i].CPFfuncionario != CPFexfuncionario)
			{
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t _____________________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|         FUNCIONÁRIO NÃO ENCONTRADO!!!       |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
			}		
		}
		
		cout << "\n\t\t\t\t\t\t\t -> DESEJA EXCLUIR OUTRO CADASTRO? (S/N): ";
		fflush(stdin);
		cin >> op;
		op = toupper(op);
		
			while(op != 'S' && op !='N')
			{
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
				cout << "\n\t\t\t\t\t\t\t -> DESEJA EXCLUIR OUTRO CADASTRO? (S/N): ";
				cin.clear();
		       	cin.ignore(INT_MAX, '\n');
		       	fflush(stdin);
				cin >> op;
				op = toupper(op);
			}
		
	}while(op == 'S');		
}

void consulta_funcionarios()
{
	string consfuncionario;
		
		do{
			system("cls");
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|                 <<CONSULTAR FUNCIONÁRIO POR CPF>>                  |" << endl;
			cout << "\t\t\t\t\t\t\t|                                                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|====================================================================|" << endl;
		
			do{
			cout << "\t\t\t\t\t\t\t| -> DIGITE O CPF DO FUNCIONÁRIO: ";
			fflush(stdin);
			getline(cin, consfuncionario);
			validacampobranco(consfuncionario);
			
				if(verificador == 1)
				{
					validanumerico(consfuncionario);
				}
			
			}while(verificador == 0);
		
			for(i = 0; i < contadorfuncionario; i++)
			{
				if(Funcionario[i].CPFfuncionario == consfuncionario)
				{
					if(Funcionario[i].funcionarioativo == 1)
					{
						cout << "\n";
						cout << "\t\t\t\t\t\t\t ____________________________________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t|" << endl;
						cout << "\t\t\t\t\t\t\t|                 NOME: " << Funcionario[i].nomefuncionario << endl;
						cout << "\t\t\t\t\t\t\t|                  CPF: " << Funcionario[i].CPFfuncionario << endl;
						cout << "\t\t\t\t\t\t\t|               FUNÇÃO: " << Funcionario[i].funcaofuncionario << endl;
						cout << "\t\t\t\t\t\t\t|              UNIDADE: " << Funcionario[i].unidadefuncionario << endl;
						cout << "\t\t\t\t\t\t\t|     DATA DE CADASTRO: " << Funcionario[i].datafuncionario << endl;
						cout << "\t\t\t\t\t\t\t|CÓDIGO DO FUNCIONÁRIO: " << Funcionario[i].codigofuncionario << endl;
						cout << "\t\t\t\t\t\t\t|____________________________________________________________________" << endl;	
					}
					else if(Funcionario[i].funcionarioativo == 0)
					{
						cout << "\n" << endl;
						cout << "\t\t\t\t\t\t\t\t\t _____________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t\t|        FUNCIONÁRIO NÃO ENCONTRADO!!!        |" << endl;
						cout << "\t\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
						break;
					}
					break;					
				}
			}
			
			if(Funcionario[i].CPFfuncionario != consfuncionario)
				{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t\t|        FUNCIONÁRIO NÃO ENCONTRADO!!!        |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t|_____________________________________________|" << endl;
				}
		
		
		cout << "\n\t\t\t\t\t\t\t\t-> DESEJA REALIZAR NOVA CONSULTA? (S|N): ";
		fflush(stdin);
		cin >> op;
		op = toupper(op);
		
		while(op != 'S' && op !='N')
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\n\t\t\t\t\t\t\t\t-> DESEJA REALIZAR NOVA CONSULTA? (S|N): ";
			cin.clear();
       		cin.ignore(INT_MAX, '\n');
       		fflush(stdin);
			cin >> op;
			op = toupper(op);
		}
					
	}while(op == 'S');
}

void list_funcionarios()
{
	funcionarios fun_lista; //VETOR PARA RECEBER A VARIÁVEL COM O CONTEÚDO DA LINHA DO ARQUIVO E MOSTRAR NA TELA
	
	system("cls"); //LIMPANDO A TELA
				
	arquivo.open("arquivofuncionarios.txt", ios::in); //ABRINDO ARQUIVO SOMENTE PARA LEITURA
	
	if(arquivo.is_open()) //SE O ARQUIVO ESTIVER ABERTO
	{
		string linha; //VARIÁVEL PARA RECEBER LINHA DO ARQUIVO
		int numlinha = 1; //CONTADOR DE LINHAS DO ARQUIVO
		
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t ____________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t|               <<LISTA DE FUNCIONÁRIOS CADASTRADOS>>                |" << endl;
		cout << "\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t|====================================================================|" << endl;
		
		while(getline(arquivo, linha)) //PEGANDO LINHA A LINHA DO ARQUIVO E PASSANDO PARA A VARIÁVEL STRING LINHA
		{
			if(numlinha%8 == 1)
					{
				fun_lista.nomefuncionario = linha; //VETOR RECEBENDO LINHA COM NOME
				cout << "\n\t\t\t\t\t\t ____________________________________________________________________" << endl;
				cout << "\t\t\t\t\t\t|" << endl;
				cout << "\t\t\t\t\t\t|                 NOME: " << fun_lista.nomefuncionario << endl;			
			}
			else if(numlinha%8 == 2)
			{
				fun_lista.CPFfuncionario = linha;
				cout << "\t\t\t\t\t\t|                  CPF: " << fun_lista.CPFfuncionario << endl;
			}
			else if(numlinha%8 == 3) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 2
			{
				fun_lista.funcaofuncionario = linha; //VETOR RECEBENDO LINHA COM FUNÇÃO
				cout << "\t\t\t\t\t\t|               FUNÇÃO: " << fun_lista.funcaofuncionario << endl;
			}
			else if(numlinha%8 == 4) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 3
			{
				fun_lista.unidadefuncionario = linha; //VETOR RECEBENDO LINHA COM UNIDADE
				cout << "\t\t\t\t\t\t|              UNIDADE: " << fun_lista.unidadefuncionario << endl;
			}
			else if(numlinha%8 == 5)
			{
				fun_lista.datafuncionario = linha; //VETOR RECEBENDO LINHA COM UNIDADE
				cout << "\t\t\t\t\t\t|     DATA DE CADASTRO: " << fun_lista.datafuncionario << endl;
			}
			else if(numlinha%8 == 6) //SE O RESTO DE DIVISÃO DO NÚMERO DE LINHA POR 9(QUANTIDADE DE LINHAS QUE TEM O CADASTRO DO SISTEMA) FOR 6
			{
				cout << "\t\t\t\t\t\t|CÓDIGO DO FUNCIONÁRIO: " << linha << endl; //MOSTRANDO NA TELA O CÓDIGO DO FUNCIONÁRIO
				cout << "\t\t\t\t\t\t|____________________________________________________________________" << endl;	
			}
			numlinha++; //INCREMENTANDO CONTADOR DE LINHAS DO ARQUIVO
		}
		arquivo.close(); //FECHANDO O ARQUIVO
		
		cout << "\n";
		cout << "\t\t\t\t\t\t ____________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                                    |" << endl;
		cout << "\t\t\t\t\t\t|            -> PRESSIONE ENTER PARA RETORNAR AO MENU!               |" << endl;
		cout << "\t\t\t\t\t\t|____________________________________________________________________|";
		getch();
	}
	else //SENÃO, SE NÃO TIVER ARQUIVO PARA ABRIR
	{
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t _________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t|                                                         |" << endl;
		cout << "\t\t\t\t\t\t| NÃO HÁ CADASTROS OU NÃO FOI POSSÍVEL ABRIR O ARQUIVO!!! |" << endl;
		cout << "\t\t\t\t\t\t|       -> PRESSIONE ENTER PARA RETORNAR AO MENU!         |" << endl;
		cout << "\t\t\t\t\t\t|_________________________________________________________|";
		getch();
	}
}

void realizapagamento()
{
		int confpedido = 0;
		int formadepagamento = 0;
		bool pagamento = false;
		double valorpagamento = 0;
	
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t CONFIRMAR PEDIDO DE " << Pedido[0].nome_clientepedido << " ?  [1] - CONFIRMAR | [2] - CANCELAR : ";
		fflush(stdin);
		sonumeros();
		confpedido = digitofinal;																	
		cout << endl;
										
		while(confpedido != 1 && confpedido != 2)
		{
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (1|2)_____|" << endl;	
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t CONFIRMAR PEDIDO DE " << Pedido[0].nome_clientepedido << " ?  [1] - CONFIRMAR | [2] - CANCELAR : ";
		cin.clear();
       	cin.ignore(INT_MAX, '\n');
		fflush(stdin);
		sonumeros();
		confpedido = digitofinal;																	
		cout << endl;
		}
		
		if(confpedido == 1)
		{										
			cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t|                                            ** PEDIDO CONFIRMADO **                                        |" << endl;
			cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
			cout << "\t\t\t\t\t\t -> FORMA DE PAGAMENTO?  [1] - CARTÃO   |   [2] - DINHEIRO : ";
			fflush(stdin);
			sonumeros();
			formadepagamento = digitofinal;
											
			while(formadepagamento != 1 && formadepagamento != 2)
			{
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (1|2)_____|" << endl;	
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t -> FORMA DE PAGAMENTO?  [1] - CARTÃO   |   [2] - DINHEIRO : ";
				cin.clear();
       			cin.ignore(INT_MAX, '\n');
				fflush(stdin);
				sonumeros();
				formadepagamento = digitofinal;
			}
																						
			if(formadepagamento == 1)
			{
				bool pagamento = true;
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t _________________________________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t|                                                         |" << endl;
				cout << "\t\t\t\t\t\t\t\t| REALIZANDO PAGAMENTO UTILIZANDO A MÁQUINA DE CARTÕES... |" << endl;
				cout << "\t\t\t\t\t\t\t\t|_________________________________________________________|" << endl;
				Sleep(4000);
				cout << "\n";
				cout << "\t\t\t\t\t\t\t\t\t _______________________________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|                                                       |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|*********** PAGAMENTO REALIZADO COM SUCESSO ***********|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t|_______________________________________________________|" << endl;
				cout << "\n\t\t\t\t\t\t\t\t\t -> PRESSIONE ENTER PARA RETORNAR AO MENU PRINCIPAL";
				getch();
				}
				else if(formadepagamento == 2)
				{	
					
					while(!pagamento)
					{
						do{
							cout << "\n" << endl;
							cout << "\t\t\t\t\t\t -> INFORME O VALOR DO PAGAMENTO: ";
							fflush(stdin);
							cin >> valorpagamento;
														
							valorpagamento = valorpagamento - valortotal;
														
							if(valorpagamento > 0)
							{
								cout << "\n\t\t\t\t\t\t -> TROCO: " << "R$" << valorpagamento << endl;
								valorpagamento = 0;
								break;
							}
							else if(valorpagamento < 0)
							{
							cout << "\n\t\t\t\t\t\t -> VALOR INSUFICIENTE, INFORME OUTRO VALOR." << endl;
							cin.clear();
				       		cin.ignore(INT_MAX, '\n');
				       		fflush(stdin);
							}
							
							}while(valorpagamento < 0);
													
							if(valorpagamento == 0)
							{
								bool pagamento = true;
								cout << "\n";
								cout << "\t\t\t\t\t\t\t\t\t _______________________________________________________" << endl;
								cout << "\t\t\t\t\t\t\t\t\t|                                                       |" << endl;
								cout << "\t\t\t\t\t\t\t\t\t|*********** PAGAMENTO REALIZADO COM SUCESSO ***********|" << endl;
								cout << "\t\t\t\t\t\t\t\t\t|_______________________________________________________|" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t -> PRESSIONE ENTER PARA RETORNAR AO MENU PRINCIPAL";
								fflush(stdin);
								getch();
								break;
							}
					}
												
				}
											
							if(unidadepizzaria == 1)
							{
							Unidade1.faturamento_bruto1 = Unidade1.faturamento_bruto1 + valortotal;
							Unidade1.lucro1 = Unidade1.lucro1 + (Unidade1.faturamento_bruto1*0.25);
							}
							else if(unidadepizzaria == 2)
							{
							Unidade2.faturamento_bruto2 = Unidade2.faturamento_bruto2 + valortotal;
							Unidade2.lucro2 = Unidade2.lucro2 + (Unidade2.faturamento_bruto2*0.25);
							}
							else if(unidadepizzaria == 3)
							{
							Unidade3.faturamento_bruto3 = Unidade3.faturamento_bruto3 + valortotal;
							Unidade3.lucro3 = Unidade3.lucro3 + (Unidade3.faturamento_bruto3*0.25);
							}
		}	
		else if(confpedido == 2)
		{
			estoqueinsere();
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t -> PRESSIONE ENTER PARA RETORNAR AO MENU!" << endl;
			getch();
		}
}

void contabil()
{
	int opcaocontabil = 0;
	int unidpizzaria = 0;
	int outraunid = 0;
	
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;	
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|          <<CONTÁBIL>>          |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|================================|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|[1] - RETORNAR AO MENU          |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|[2] - FATURAMENTO & LUCRO       |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|[3] - FAT. & LUCRO REDE         |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|________________________________|" << endl;
				cout << "\n\t\t\t\t\t\t\t\t\t\t-> O QUE DESEJA REALIZAR: ";	
				fflush(stdin);
				sonumeros();
				opcaocontabil = digitofinal;
				cout << endl;
				
				while(opcaocontabil == 1)
				{
					break;
				}
				
				while(opcaocontabil == 2)
				{
					do{
					system("cls");
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;	
					cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|    <<FATURAMENTO & LUCRO>>     |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|================================|" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t -> UNIDADE DA PIZZARIA: ";
					fflush(stdin);
					sonumeros();
					unidpizzaria = digitofinal;
					cout << endl;
					
					if(unidpizzaria == 1)
					{
						cout << "\n";
						cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|TOTAL FATURAMENTO: " << Unidade1.faturamento_bruto1 << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|================================" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|TOTAL LUCRO: " << Unidade1.lucro1 << endl; 
						cout << "\t\t\t\t\t\t\t\t\t\t|________________________________" << endl;
					}
					else if(unidpizzaria == 2)
					{
						cout << "\n";
						cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|TOTAL FATURAMENTO: " << Unidade2.faturamento_bruto2 << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|================================" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|TOTAL LUCRO: " << Unidade2.lucro2 << endl; 
						cout << "\t\t\t\t\t\t\t\t\t\t|________________________________" << endl;
					}
					else if(unidpizzaria == 3)
					{
						cout << "\n";
						cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|TOTAL FATURAMENTO: " << Unidade3.faturamento_bruto3 << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|================================" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|TOTAL LUCRO: " << Unidade3.lucro3 << endl; 
						cout << "\t\t\t\t\t\t\t\t\t\t|________________________________" << endl;
					}
					
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t CONFERIR OUTRO FATURAMENTO & LUCRO? [1]-SIM | [2]-NÃO: ";
					fflush(stdin);
					sonumeros();
					outraunid = digitofinal;
					
					
					while(outraunid != 1 && outraunid != 2)
					{
						cout << "\n" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (1|2)_____|" << endl;
						cout << "\n";
						cout << "\t\t\t\t\t\t\t\t\t\t CONFERIR OUTRO FATURAMENTO & LUCRO? [1]-SIM | [2]-NÃO: ";
			       		fflush(stdin);
						sonumeros();
						outraunid = digitofinal;
					}
					
					}while(outraunid == 1);
					
					break;
				}
				
				while(opcaocontabil == 3)
				{
					double faturamentorede = 0;
					double lucrorede = 0;
					
					faturamentorede = (Unidade1.faturamento_bruto1+Unidade2.faturamento_bruto2+Unidade3.faturamento_bruto3);
					lucrorede = (Unidade1.lucro1+Unidade2.lucro2+Unidade3.lucro3);
					
					system("cls");
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;	
					cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|      <<FAT. & LUCRO REDE>>     |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|================================|" << endl;
					
					cout << "\n";
					cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|TOTAL FATURAMENTO: " << faturamentorede << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|================================" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t|TOTAL LUCRO: " << lucrorede << endl; 
					cout << "\t\t\t\t\t\t\t\t\t\t|________________________________" << endl;
					
					cout << "\n";
					cout << "\t\t\t\t\t\t\t\t\t\t -> PRESSIONE ENTER PARA RETORNAR AO MENU";
					getch();
					
					break;
				}
}

void gerenciaestoque()
{	
	int codigoproduto = 0;
	long novaquantidade = 0;

	cout << "\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t ________________________________" << endl;	
	cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t|           <<ESTOQUE>>          |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t|                                |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t|================================|" << endl;
	
	MOLHOTOMATE.visualizestoque(); 
	MUSSARELA.visualizestoque();
	PALMITO.visualizestoque();
	ERVILHA.visualizestoque();
	PRESUNTO.visualizestoque();
	BACON.visualizestoque();
	ATUM.visualizestoque();
	TOMATE.visualizestoque();
	CEBOLA.visualizestoque();
	CATUPIRY.visualizestoque();
	BROCOLIS.visualizestoque();
	PEPPERONI.visualizestoque();
	ALHO.visualizestoque();
	CALABRESA.visualizestoque();
	OREGANO.visualizestoque();
	AZEITONA.visualizestoque();
	PARMESAO.visualizestoque();
	PROVOLONE.visualizestoque();
	GORGONZOLA.visualizestoque();
	FRANGO.visualizestoque();
	MANJERICAO.visualizestoque();
	MILHO.visualizestoque();
	OVO.visualizestoque();
	RUCULA.visualizestoque();
	CHAMPIGNON.visualizestoque();
	DOCELEITE.visualizestoque();
	BANANA.visualizestoque();
	CANELA.visualizestoque();
	CHOCOLATE.visualizestoque();
	MORANGO.visualizestoque();	
	SORVETECREME.visualizestoque();
	GOIABADA.visualizestoque();
	COCACOLA.visualizestoque();
	COCACOLAZERO.visualizestoque();
	COCACOLA2.visualizestoque();
	FANTAUVA.visualizestoque();
	SPRITE.visualizestoque();
	BRAHMA.visualizestoque();
	SKOL.visualizestoque();
	EISENBAHN.visualizestoque();
	MASSA.visualizestoque();
	ACUCAR.visualizestoque();
	FERMENTO.visualizestoque();
	SAL.visualizestoque();
	OLEO.visualizestoque();
	MANTEIGA.visualizestoque();
	
	cout << "\n";
	cout << "\t\t\t\t\t\t\t\t\t\t -> DESEJA ALTERAR O ESTOQUE DE ALGUM PRODUTO? (S|N): ";
	fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
	cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
	op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		
		while(op != 'S' && op !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA
		{
			cout << "\n" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
			cout << "\n";
			cout << "\t\t\t\t\t\t\t\t\t\t -> DESEJA ALTERAR O ESTOQUE DE ALGUM PRODUTO? (S|N): ";
			fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
			cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
			op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		}
	
	if(op == 'S')
	{
		do{
			
		codigoproduto = 0;
		cout << "\n";	
		cout << "\t\t\t\t\t\t\t\t\t\t -> DIGITE O CÓDIGO DO PRODUTO: ";
		fflush(stdin);
		sonumeros();
		codigoproduto = digitofinal;
		cout << endl;
		
		
		switch(codigoproduto)
		{
			case 1:
				{
					MOLHOTOMATE.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					MOLHOTOMATE.quantidadeproduto = novaquantidade;
				}
				break;
			case 2:
				{
					MUSSARELA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					MUSSARELA.quantidadeproduto = novaquantidade;	
				}
				break;
			case 3:
				{
					PALMITO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					PALMITO.quantidadeproduto = novaquantidade;
				}
				break;
			case 4:
				{
					ERVILHA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					ERVILHA.quantidadeproduto = novaquantidade;
				}
				break;
			case 5:
				{
					PRESUNTO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					PRESUNTO.quantidadeproduto = novaquantidade;
				}
				break;
			case 6:
				{
					BACON.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					BACON.quantidadeproduto = novaquantidade;
				}
				break;
			case 7:
				{
					ATUM.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					ATUM.quantidadeproduto = novaquantidade;
				}
				break;
			case 8:
				{
					TOMATE.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					TOMATE.quantidadeproduto = novaquantidade;
				}
				break;
			case 9:
				{
					CEBOLA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					CEBOLA.quantidadeproduto = novaquantidade;
				}
				break;
			case 10:
				{
					CATUPIRY.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					CATUPIRY.quantidadeproduto = novaquantidade;
				}
				break;
			case 11:
				{
					BROCOLIS.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					BROCOLIS.quantidadeproduto = novaquantidade;
				}
				break;
			case 12:
				{
					PEPPERONI.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					PEPPERONI.quantidadeproduto = novaquantidade;
				}
				break;
			case 13:
				{
					ALHO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					ALHO.quantidadeproduto = novaquantidade;
				}
				break;
			case 14:
				{
					CALABRESA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					CALABRESA.quantidadeproduto = novaquantidade;
				}
				break;
			case 15:
				{
					OREGANO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					OREGANO.quantidadeproduto = novaquantidade;
				}
				break;
			case 16:
				{
					AZEITONA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					AZEITONA.quantidadeproduto = novaquantidade;
				}
				break;
			case 17:
				{
					PARMESAO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					PARMESAO.quantidadeproduto = novaquantidade;
				}
				break;
			case 18:
				{
					PROVOLONE.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					PROVOLONE.quantidadeproduto = novaquantidade;
				}
				break;
			case 19:
				{
					GORGONZOLA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					GORGONZOLA.quantidadeproduto = novaquantidade;
				}
				break;
			case 20:
				{
					FRANGO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					FRANGO.quantidadeproduto = novaquantidade;
				}
				break;
			case 21:
				{
					MANJERICAO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					MANJERICAO.quantidadeproduto = novaquantidade;
				}
				break;
			case 22:
				{
					MILHO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					MILHO.quantidadeproduto = novaquantidade;
				}
				break;
			case 23:
				{
					OVO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					OVO.quantidadeproduto = novaquantidade;
				}
				break;
			case 24:
				{
					RUCULA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					RUCULA.quantidadeproduto = novaquantidade;
				}
				break;
			case 25:
				{
					CHAMPIGNON.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					CHAMPIGNON.quantidadeproduto = novaquantidade;
				}
				break;
			case 26:
				{
					DOCELEITE.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					DOCELEITE.quantidadeproduto = novaquantidade;
				}
				break;	
			case 27:
				{
					BANANA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					BANANA.quantidadeproduto = novaquantidade;
				}
				break;
			case 28:
				{
					CANELA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					CANELA.quantidadeproduto = novaquantidade;
				}
				break;
			case 29:
				{
					CHOCOLATE.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					CHOCOLATE.quantidadeproduto = novaquantidade;
				}
				break;
			case 30:
				{
					MORANGO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					MORANGO.quantidadeproduto = novaquantidade;
				}
				break;
			case 31:
				{
					SORVETECREME.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					SORVETECREME.quantidadeproduto = novaquantidade;
				}
				break;
			case 32:
				{
					GOIABADA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					GOIABADA.quantidadeproduto = novaquantidade;
				}
				break;
			case 33:
				{
					COCACOLA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					COCACOLA.quantidadeproduto = novaquantidade;
				}
				break;
			case 34:
				{
					COCACOLAZERO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					COCACOLAZERO.quantidadeproduto = novaquantidade;
				}
				break;
			case 35:
				{
					COCACOLA2.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					COCACOLA2.quantidadeproduto = novaquantidade;
				}
				break;
			case 36:
				{
					GUARANA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					GUARANA.quantidadeproduto = novaquantidade;
				}
				break;
			case 37:
				{
					FANTAUVA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					FANTAUVA.quantidadeproduto = novaquantidade;
				}
				break;
			case 38:
				{
					SPRITE.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					SPRITE.quantidadeproduto = novaquantidade;
				}
				break;
			case 39:
				{
					BRAHMA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					BRAHMA.quantidadeproduto = novaquantidade;
				}
				break;
			case 40:
				{
					SKOL.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					SKOL.quantidadeproduto = novaquantidade;
				}
				break;
			case 41:
				{
					EISENBAHN.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					EISENBAHN.quantidadeproduto = novaquantidade;
				}
				break;
			case 42:
				{
					MASSA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					MASSA.quantidadeproduto = novaquantidade;
				}
				break;
			case 43:
				{
					FARINHA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					FARINHA.quantidadeproduto = novaquantidade;
				}
				break;
			case 44:
				{
					ACUCAR.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					ACUCAR.quantidadeproduto = novaquantidade;
				}
				break;
			case 45:
				{
					FERMENTO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					FERMENTO.quantidadeproduto = novaquantidade;
				}
				break;
			case 46:
				{
					SAL.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					SAL.quantidadeproduto = novaquantidade;
				}
				break;
			case 47:
				{
					OLEO.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					OLEO.quantidadeproduto = novaquantidade;
				}
				break;
			case 48:
				{
					MANTEIGA.visualizestoque();
					cout << "\t\t\t\t\t\t\t\t\t\t -> ALTERAÇÃO QUANTIDADE PARA: "; 
					fflush(stdin);
					sonumeros();
					novaquantidade = digitofinal;
					cout << endl;
					MANTEIGA.quantidadeproduto = novaquantidade;
				}
				break;
				
		}
		
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t -> DESEJA ALTERAR O ESTOQUE DE OUTRO PRODUTO? (S|N): ";
		fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
		cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
		op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
		
			while(op != 'S' && op !='N') //VALIDAÇÃO DA OPÇÃO DIGITADA
			{
				cout << "\n" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t __________________________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|           **OPÇÃO INVÁLIDA!!!**          |" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t|_____-> DIGITE UMA OPÇÃO VÁLIDA (S|N)_____|" << endl;
				cout << "\n";
				cout << "\t\t\t\t\t\t\t\t\t\t -> DESEJA ALTERAR O ESTOQUE DE OUTRO PRODUTO? (S|N): ";
				fflush(stdin); //LIMPANDO BUFFER DE ENTRADA DE DADOS
				cin >> op; //RECEBENDO A OPÇÃO NA VARIÁVEL
				op = toupper(op); //CONVERTENDO A OPÇÃO DIGITADA PARA LETRA MAIÚSCULA EX: DE "s" PARA "S"
			}
			
		}while(op == 'S');
	}
	
	cout << "\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t -> PRESSIONE ENTER PARA RETORNAR AO MENU.";
	getch();
}

void pizzasmaispedidas()
{
					string linha;
			
				arquivo.open("arquivopedidos.txt", ios::in); //ABRINDO ARQUIVO SOMENTE PARA LEITURA
				
				if(arquivo.is_open()) //SE O ARQUIVO ESTIVER ABERTO
				{
					cout << "\n " << endl; //EXIBINDO NA TELA TODOS OS PEDIDOS REALIZADOS
					cout << "\t\t\t\t\t\t ___________________________________________________________________________________________________________" << endl;
					cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
					cout << "\t\t\t\t\t\t|                                             <<PIZZAS + PEDIDAS>>                                          |" << endl;
					cout << "\t\t\t\t\t\t|                                                                                                           |" << endl;
					cout << "\t\t\t\t\t\t|===========================================================================================================|" << endl;
					cout << "\n" << endl;
				
					while(getline(arquivo,linha))
					{
						cout << "\t\t\t\t\t\t" << linha << endl;
					}
					
					arquivo.close();
				
					cout << "\n";
					cout << "\t\t\t\t\t\t ____________________________________________________________________" << endl;
					cout << "\t\t\t\t\t\t|                                                                    |" << endl;
					cout << "\t\t\t\t\t\t|            -> PRESSIONE ENTER PARA RETORNAR AO MENU!               |" << endl;
					cout << "\t\t\t\t\t\t|____________________________________________________________________|";
					getch();
				}
				else //SENÃO, SE NÃO TIVER ARQUIVO PARA ABRIR
				{
					cout << "\n" << endl;
					cout << "\t\t\t\t\t\t _________________________________________________________" << endl;
					cout << "\t\t\t\t\t\t|                                                         |" << endl;
					cout << "\t\t\t\t\t\t|  NÃO HÁ PEDIDOS OU NÃO FOI POSSÍVEL ABRIR O ARQUIVO!!!  |" << endl;
					cout << "\t\t\t\t\t\t|       -> PRESSIONE ENTER PARA RETORNAR AO MENU!         |" << endl;
					cout << "\t\t\t\t\t\t|_________________________________________________________|";
					getch();
				}
}

void estoqueinsere()
{
	MOLHOTOMATE.inserirdadosEst("MOLHO DE TOMATE", "GRAMAS", 4000, 1);
	MUSSARELA.inserirdadosEst("MUSSARELA", "GRAMAS", 4000, 2);
	PALMITO.inserirdadosEst("PALMITO", "GRAMAS", 4000, 3);
	ERVILHA.inserirdadosEst("ERVILHA", "GRAMAS", 4000, 4);
	PRESUNTO.inserirdadosEst("ERVILHA", "GRAMAS", 4000, 5);
	BACON.inserirdadosEst("BACON", "GRAMAS", 4000, 6);
	ATUM.inserirdadosEst("ATUM", "GRAMAS", 4000, 7);
	TOMATE.inserirdadosEst("TOMATE", "GRAMAS", 4000, 8);
	CEBOLA.inserirdadosEst("CEBOLA", "GRAMAS", 4000, 9);
	CATUPIRY.inserirdadosEst("CATUPIRY", "GRAMAS", 4000, 10);
	BROCOLIS.inserirdadosEst("BRÓCOLIS", "GRAMAS", 4000, 11);
	PEPPERONI.inserirdadosEst("PEPPERONI", "GRAMAS", 4000, 12);
	ALHO.inserirdadosEst("ALHO", "GRAMAS", 4000, 13);
	CALABRESA.inserirdadosEst("CALABRESA", "GRAMAS", 4000, 14);
	OREGANO.inserirdadosEst("ORÉGANO", "GRAMAS", 4000, 15);
	AZEITONA.inserirdadosEst("AZEITONA", "GRAMAS", 4000, 16);
	PARMESAO.inserirdadosEst("PARMESÃO", "GRAMAS", 4000, 17);
	PROVOLONE.inserirdadosEst("PROVOLONE", "GRAMAS", 4000, 18);
	GORGONZOLA.inserirdadosEst("GORGONZOLA", "GRAMAS", 4000, 19);
	FRANGO.inserirdadosEst("FRANGO", "GRAMAS", 4000, 20);
	MANJERICAO.inserirdadosEst("MANJERICÃO", "GRAMAS", 4000, 21);
	MILHO.inserirdadosEst("MILHO", "GRAMAS", 4000, 22);
	OVO.inserirdadosEst("OVO", "UNIDADES", 4000, 23);
	RUCULA.inserirdadosEst("RÚCULA", "GRAMAS", 4000, 24);
	CHAMPIGNON.inserirdadosEst("CHAMPIGNON", "GRAMAS", 4000, 25);
	DOCELEITE.inserirdadosEst("DOCE DE LEITE", "GRAMAS", 4000, 26);
	BANANA.inserirdadosEst("BANANA", "UNIDADES", 100, 27);
	CANELA.inserirdadosEst("CANELA", "GRAMAS", 4000, 28);
	CHOCOLATE.inserirdadosEst("CHOCOLATE", "GRAMAS", 4000, 29);
	MORANGO.inserirdadosEst("MORANGO", "GRAMAS", 4000, 30);
	SORVETECREME.inserirdadosEst("SORVETE DE CREME", "GRAMAS", 4000, 31);
	GOIABADA.inserirdadosEst("GOIABADA", "GRAMAS", 4000, 32);
	COCACOLA.inserirdadosEst("COCA-COLA 350ml", "UNIDADES", 100, 33);
	COCACOLAZERO.inserirdadosEst("COCA-COLA ZERO 350ml", "UNIDADES", 100, 34);
	COCACOLA2.inserirdadosEst("COCA-COLA 2L", "UNIDADES", 100, 35);
	GUARANA.inserirdadosEst("GUARANÁ 350ml", "UNIDADES", 100, 36);
	FANTAUVA.inserirdadosEst("FANTA UVA 350ml", "UNIDADES", 100, 37);
	SPRITE.inserirdadosEst("SPRITE 350ml", "UNIDADES", 100, 38);
	BRAHMA.inserirdadosEst("BRAHMA 350ml", "UNIDADES", 100, 39);
	SKOL.inserirdadosEst("SKOL 350ml", "UNIDADES", 100, 40);
	EISENBAHN.inserirdadosEst("EISENBAHN 350ml", "UNIDADES", 100, 41);
	MASSA.inserirdadosEst("MASSA PRONTA", "PIZZAS", 0, 42);
	FARINHA.inserirdadosEst("FARINHA", "GRAMAS", 100000, 43);
	ACUCAR.inserirdadosEst("AÇÚCAR", "GRAMAS", 5000, 44);
	FERMENTO.inserirdadosEst("FERMENTO", "GRAMAS", 6000, 45);
	SAL.inserirdadosEst("SAL", "GRAMAS", 5000, 46);
	OLEO.inserirdadosEst("OLEO", "MILILITROS(ML)", 6000, 47);
	MANTEIGA.inserirdadosEst("MANTEIGA", "GRAMAS", 2000, 48);
	//E GUARDANDO NO VETOR DA ESTRUTURA
	estoque vEstoque[48] = {MOLHOTOMATE, MUSSARELA, PALMITO, ERVILHA, PRESUNTO, BACON, ATUM, TOMATE, CEBOLA, CATUPIRY, BROCOLIS, PEPPERONI, ALHO, CALABRESA, OREGANO, AZEITONA,
	 PARMESAO, PROVOLONE, GORGONZOLA, FRANGO, MANJERICAO, MILHO, OVO, RUCULA, CHAMPIGNON, DOCELEITE, BANANA, CANELA, CHOCOLATE, MORANGO, SORVETECREME, GOIABADA, COCACOLA, 
	 COCACOLAZERO, COCACOLA2, GUARANA, FANTAUVA, SPRITE, BRAHMA, SKOL, EISENBAHN, MASSA, FARINHA, ACUCAR, FERMENTO, SAL, OLEO, MANTEIGA};
	 
	//INICIANDO O SISTEMA COM A QUANTIDADE DE MASSA PADRÃO DEFINIDA PELO CLIENTE
	MASSA.quantidadeproduto = MASSA.quantidadeproduto+100;
	if(MASSA.quantidadeproduto == 100)
	{
		FARINHA.quantidadeproduto = FARINHA.quantidadeproduto-50000;
		ACUCAR.quantidadeproduto = ACUCAR.quantidadeproduto-1000;
		FERMENTO.quantidadeproduto = FERMENTO.quantidadeproduto-2000;
		SAL.quantidadeproduto = SAL.quantidadeproduto-1000;
		OLEO.quantidadeproduto = OLEO.quantidadeproduto-2000;
		MANTEIGA.quantidadeproduto = MANTEIGA.quantidadeproduto-500;
	} 
}

void pizzainsere()
{
	Americana.inserirdadosPiz("AMERICANA", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, PALMITO, ERVILHA, PRESUNTO E BACON)",
	 (22.99), 1);
	Atum.inserirdadosPiz("ATUM", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, ATUM, TOMATE E CEBOLA)",
	 (23.99), 2);
	Brocolis.inserirdadosPiz("BRóCOLIS", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, TOMATE, CATUPIRY, BRÓCOLIS, PEPPERONI E ALHO)",
	 (28.99), 3);
	Calabresa.inserirdadosPiz("CALABRESA", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, CALABRESA, TOMATE, CEBOLA, ORÉGANO E AZEITONA)",
	 (24.99), 4);	 
	CincoQueijos.inserirdadosPiz("CINCO QUEIJOS", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, PARMESÃO, PROVOLONE, GORGONZOLA E CATUPIRY)",
	 (30.99), 5);
	FrangCat.inserirdadosPiz("FRANGO COM CATUPIRY", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, FRANGO, CATUPIRY, AZEITONA E ORÉGANO)",
	 (24.99), 6);	
	Marguerita.inserirdadosPiz("MARGUERITA", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, TOMATE, MANJERICÃO, AZEITONA E ORÉGANO)",
	 (21.99), 7);	
	Portuguesa.inserirdadosPiz("PORTUGUESA", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, MILHO, ERVILHA, OVO, CALABRESA, CEBOLA, AZEITONA E ORÉGANO)",
	 (29.99), 8);	
	Rucula.inserirdadosPiz("RúCULA", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, TOMATE E RÚCULA)",
	 (24.99), 9);	
	Siciliana.inserirdadosPiz("SICILIANA", "ÚNICO (4 PESSOAS)", "(MOLHO, MUSSARELA, BACON E CHAMPIGNON)",
	 (29.99), 10);	
	Banana.inserirdadosPiz("BANANA", "ÚNICO (4 PESSOAS)", "(DOCE DE LEITE, BANANA E CANELA)",
	 (17.59), 11);
	Passione.inserirdadosPiz("PASSIONE", "ÚNICO (4 PESSOAS)", "(CHOCOLATE, MORANGO E SORVETE DE CREME)",
	 (25.99), 12);	
	RomeuJulieta.inserirdadosPiz("ROMEU & JULIETA", "ÚNICO (4 PESSOAS)", "(MUSSARELA E GOIABADA)",
	 (20.99), 13);
	 //E GUARDANDO NO VETOR DA ESTRUTURA
	pizzas vPizzas[13] = {Americana, Atum, Brocolis, Calabresa, CincoQueijos, FrangCat, Marguerita, Portuguesa, Rucula, Siciliana, Banana, Passione, RomeuJulieta};
}

void bebidainsere()
{
	CocaCola.inserirdadosBeb("COCA-COLA 350ml", (4.59), 1);
	CocaColaZero.inserirdadosBeb("COCA-COLA ZERO 350ml", (4.59), 2);
	CocaCola2.inserirdadosBeb("COCA-COLA 2L", (10.49), 3);
	Guarana.inserirdadosBeb("GUARANÁ 350ml", (4.59), 4);
	FantaUva.inserirdadosBeb("FANTA UVA 350ml", (4.59), 5);
	Sprite.inserirdadosBeb("SPRITE 350ml", (4.59), 6);
	Brahma.inserirdadosBeb("BRAHMA 350ml", (5.59), 7);
	Skol.inserirdadosBeb("SKOL 350ml", (5.59), 8);
	Eisenbahn.inserirdadosBeb("EISENBAHN 350ml", (5.59), 9);
	//E GUARDANDO NO VETOR DA ESTRUTURA
	bebidas vBebidas[9] = {CocaCola, CocaColaZero, CocaCola2, Guarana, FantaUva, Sprite, Brahma, Skol, Eisenbahn};
}

void carregarfuncionarios()
{
	char caminhofuncionarios[35];
			
		strcpy(caminhofuncionarios, "arquivofuncionarios.txt");
		
		funcionarios fun[300];
		
		arquivo.open(caminhofuncionarios, ios::in);
		
		if(arquivo.is_open())
			{
				string linhafun;
				int numlinhafun = 1;
				
				while(getline(arquivo, linhafun))
				{
					if(numlinhafun%8 == 1)
					{
						fun[contadorfuncionario].nomefuncionario = linhafun;
						Funcionario[contadorfuncionario].nomefuncionario = fun[contadorfuncionario].nomefuncionario;
					}
					else if(numlinhafun%8 == 2)
					{
						fun[contadorfuncionario].CPFfuncionario = linhafun;
						Funcionario[contadorfuncionario].CPFfuncionario = fun[contadorfuncionario].CPFfuncionario;
					}
					else if(numlinhafun%8 == 3)
					{
						fun[contadorfuncionario].funcaofuncionario = linhafun;
						Funcionario[contadorfuncionario].funcaofuncionario = fun[contadorfuncionario].funcaofuncionario;
					}
					else if(numlinhafun%8 == 4)
					{
						fun[contadorfuncionario].unidadefuncionario = linhafun;
						Funcionario[contadorfuncionario].unidadefuncionario = fun[contadorfuncionario].unidadefuncionario;
					}
					else if(numlinhafun%8 == 5)
					{
						fun[contadorfuncionario].datafuncionario = linhafun;
						Funcionario[contadorfuncionario].datafuncionario = fun[contadorfuncionario].datafuncionario;
					}
					else if(numlinhafun%8 == 6)
					{
						int convertefun;
						convertefun = atoi(linhafun.c_str());
						fun[contadorfuncionario].codigofuncionario = convertefun;
						Funcionario[contadorfuncionario].codigofuncionario = fun[contadorfuncionario].codigofuncionario;
					}
					else if(numlinhafun%8 == 7)
					{																		
						int convertefun2;
						convertefun2 = atoi(linhafun.c_str());
						fun[contadorfuncionario].funcionarioativo = convertefun2;
						Funcionario[contadorfuncionario].funcionarioativo = fun[contadorfuncionario].funcionarioativo;
						contadorfuncionario++;
						geracodigofun++;																
					}						
				numlinhafun++;					
				}					
			arquivo.close();				
			}
}

void carregarclientes()
{
	//TRAZENDO OS CLIENTES NOVAMENTE PARA O SISTEMA, DO ARQUIVO TXT
	char caminhocadastros[35];
		
		strcpy(caminhocadastros, "arquivocadastros.txt");

		clientes cli[5000];

		arquivo.open(caminhocadastros, ios::in);
		
		if(arquivo.is_open())
		{
			string linha;
			int numlinha = 1;
			
			while(getline(arquivo, linha))
			{
				if(numlinha%8 == 1)
				{
					cli[contador].nomecliente = linha;
					Cliente[contador].nomecliente = cli[contador].nomecliente;
				}
				else if(numlinha%8 == 2)
				{
					cli[contador].CPFcliente = linha;
					Cliente[contador].CPFcliente = cli[contador].CPFcliente;
				}
				else if(numlinha%8 == 3)
				{
					cli[contador].telefonecliente = linha;
					Cliente[contador].telefonecliente = cli[contador].telefonecliente;
				}
				else if(numlinha%8 == 4)
				{
					cli[contador].enderecocliente = linha;
					Cliente[contador].enderecocliente = cli[contador].enderecocliente;
				}
				else if(numlinha%8 == 5)
				{
					cli[contador].datacliente = linha;
					Cliente[contador].datacliente = cli[contador].datacliente;
				}
				else if(numlinha%8 == 6)
				{
					int converte;
					converte = atoi(linha.c_str());
					cli[contador].codigocliente = converte;
					Cliente[contador].codigocliente = cli[contador].codigocliente;
				}
				else if(numlinha%8 == 7)
				{
					int converte2;
					converte2 = atoi(linha.c_str());
					cli[contador].clienteativo = converte2;
					Cliente[contador].clienteativo = cli[contador].clienteativo;
					contador++;
					geracodigo++;
				}
			numlinha++;
			}
		arquivo.close();
		}
}

void backupcliente()
{
	arquivo.open("arquivocadastros.txt", ios::out | ios::trunc);
	
	for(i = 0; i < contador; i++)
	{
		if(Cliente[i].clienteativo == 1)
		{
			arquivo << Cliente[i].nomecliente << endl; //ESCREVENDO NO ARQUIVO A LINHA DIGITADA PELO USUÁRIO
			arquivo << Cliente[i].CPFcliente << endl; //ESCREVENDO NO ARQUIVO A LINHA DIGITADA PELO USUÁRIO
			arquivo << Cliente[i].telefonecliente << endl; //ESCREVENDO NO ARQUIVO A LINHA DIGITADA PELO USUÁRIO
			arquivo << Cliente[i].enderecocliente << endl; //ESCREVENDO NO ARQUIVO A LINHA DIGITADA PELO USUÁRIO
			arquivo << Cliente[i].datacliente << endl; //ESCREVENDO NO ARQUIVO A DATA
			arquivo << Cliente[i].codigocliente << endl; //ESCREVENDO NO ARQUIVO O CÓDIGO DO CLIENTE CADASTRADO
			arquivo << Cliente[i].clienteativo << endl;
			
			arquivo << "\n"; //PULANDO LINHA NO ARQUIVO
		}						
	}
	arquivo.close(); //FECHANDO O ARQUIVO
}

void backupfuncionario()
{
	
	arquivo.open("arquivofuncionarios.txt", ios::out | ios::trunc);

	for(i = 0; i < contadorfuncionario; i++)
	{
		if(Funcionario[i].funcionarioativo == 1)
		{
			arquivo << Funcionario[i].nomefuncionario << endl;
			arquivo << Funcionario[i].CPFfuncionario << endl;
			arquivo << Funcionario[i].funcaofuncionario << endl;
			arquivo << Funcionario[i].unidadefuncionario << endl;
			arquivo << Funcionario[i].datafuncionario << endl;
			arquivo << Funcionario[i].codigofuncionario << endl;
			arquivo << Funcionario[i].funcionarioativo << endl;
			
			arquivo << "\n";
		}						
	}
	arquivo.close();
}
