#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiï¿³n: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "Campeonato",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	int partida;
	printf("Escriba que partida quiere saber sobre quien jugó en ella (ID):");
	scanf("%d",partida);
	
	char consulta[50];
	strcpy(consulta,"SELECT user FROM jug WHERE id_p=");
	strcat(consulta,partida);
	
	err=mysql_querry(conn, consulta);
	if (err!=0){
		
		printf("Error al consultar datos de la base %u %s\n",
			   mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	
	resultado = mysql_store_result(conn);
	row= mysql_fetch_row(resultado);
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {

			printf ("%s\n", row[0]);
			row = mysql_fetch_row (resultado);
	}
		
		mysql_close (conn);
		exit(0);
}

