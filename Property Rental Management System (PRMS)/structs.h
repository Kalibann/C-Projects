#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

//Structs:

typedef struct { //dados imovel

    char pago;
    char nome_imovel[20];
    char cod_registro[6];
    float valor_imovel;


} dados_imovel;

typedef struct { //endereço

    char logradouro[30];
    char bairro[30];
    char cidade[30];
    char estado[30];
    char pais[30];
    int numero;
    long int cep;

} address;

typedef struct {


    int tipo_telefone; //0-Fixo 1-Celular
    int existencia_fiador; //0-Não 1-Sim
    char genero;
    char telefone[12];
    char nome[30];
    char cod_registro[6];
    char cpf[14];
    address endereco;

} dados_locatario;

typedef struct {

    int tipo_telefone; //0-Fixo 1-Celular
    char telefone[12];
    char nome[50];
    char cpf[14];
    float pagamento;

} fiador;

typedef struct {

    int tipo_calcao; //0-Cheque 1-Dinheiro 2-Cartão
    float valor_calcao;

} nao_fiador;

#endif // STRUCTS_H_INCLUDED
