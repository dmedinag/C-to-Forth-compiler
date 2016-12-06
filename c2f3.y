%{                              // SECCION 1 Declaraciones de C-Yacc
#include <stdio.h>
#include <string.h>             // declaraciones para cadenas
#include <stdlib.h>             // declaraciones para exit ()
#define FF fflush(stdout);      // para forzar la impresion inmediata
char funcion_actual [256] ;     // almacena el nombre de la función actual
char *variable[32] ;            // almacena los nombres de variable de la función actual
int variable_cnt;
char matrix_initiated;
int there_are_matrices;
char *return_expression;

// prototipos de funciones

int createVariable(char *variable_id);
int createArray(char *variable_id, int size);
char *getScopeVariableId(char *variable_id);
int createMatrix(char *id, int x, int y);

%}
%union
{                               // El tipo de la pila tiene caracter dual
    int valor ;                   // - valor numerico de un NUMERO
    char *cadena ;                // - para pasar los nombres de IDENTIFES
}

%token <cadena> NUMERO          // Todos los token tienen un tipo para la pila
%token <cadena> IDENTIF         // Identificador=variable
%token <cadena> INTEGER         // identifica la definicion de un entero
%token <cadena> STRING
%token <cadena> PUTS
%token <cadena> WHILE
%token <cadena> FOR
%token <cadena> DO
%token <cadena> IF
%token <cadena> ELSE
%token <cadena> PRINTF
%token <cadena> RETURN
%token <cadena> INC
%token <cadena> DEC
%token <cadena> EQUALS
%token <cadena> NOTEQUALS
%token <cadena> THISPLUS
%token <cadena> THISTIMES
%token <cadena> THISDIVIDED
%token <cadena> THISMINUS
%token <cadena> GE
%token <cadena> LE
%token <cadena> OR
%token <cadena> AND
%token <cadena> MAIN            // identifica el comienzo del proc. main
%right '='                      // menor orden de precedencia
%left OR
%left AND
%left '|'
%left '&'
%left NOTEQUALS EQUALS
%left GE LE '<' '>'
%left '+' '-' THISPLUS THISMINUS
%left '*' '/' '%' THISTIMES THISDIVIDED
%left INC DEC '!'
%left SIGNO_UNARIO              // mayor orden de precedencia

%type <cadena> parameters
%type <cadena> sentencia
%type <cadena> expresion
%type <cadena> operando
%type <cadena> termino
%type <cadena> funcall
%type <cadena> arguments
%type <cadena> more_arguments

%%
                                // Seccion 3 Gramatica - Semantico

program:            vars functions main    { ; }
                ;

functions:          /* no functions  */                 { variable_cnt = 0; }
                |   IDENTIF '('                         {
                                                            strcpy (funcion_actual, $1) ;
                                                            variable_cnt = 0;
                                                        }
                        parameters ')' '{'
                        vars                            {
                                                            if(strcmp("", $4)) {
                                                                char * id = malloc(64*sizeof(char));
                                                                if (id == NULL) { perror("Error at malloc\n");}
                                                                sprintf(id, "%s", $4);
                                                                printf("%s !\n", getScopeVariableId(id));
                                                            }
                                                        }
                        codigo '}'                 { printf (" ;\n"); }
                        functions
                ;

parameters:           /* no parameters declaration */                   { sprintf($$, ""); }
                | INTEGER IDENTIF                                       {
                                                                            sprintf($$, "%s", $2);
                                                                            createVariable($2);
                                                                        }
                ;

main:               MAIN '(' ')' '{'        {
                                                sprintf (funcion_actual, "main");
                                                variable_cnt = 0;
                                            }
                    vars codigo '}'	        { printf (" ;\n"); }
                ;

vars:           /* no variable declaration */  {
                                                    if(strcmp(funcion_actual, "global")) {
                                                        printf (": %s \n", funcion_actual);

                                                    }
                                                }
                | INTEGER IDENTIF ';'                                      { createVariable($2); }
                    vars
                | INTEGER IDENTIF '[' NUMERO ']' ';'                       { createArray($2, atoi($4)); }
                    vars
                | INTEGER IDENTIF '[' NUMERO ']' '[' NUMERO ']' ';'        { createMatrix($2, atoi($4), atoi($7)); }
                    vars
                ;

codigo:                 /* lambda */                    { ; }
                | sentencia ';' codigo                  { ; }
                | flujo codigo                          { ; }
                ;

sentencia:                                              { ; }
                |   funcall                             { printf("%s\n", $1) }
                |   IDENTIF '=' expresion               { printf("%s %s ! \n", $3, getScopeVariableId($1)); }
                |   IDENTIF '[' expresion ']' '=' expresion  { printf("%s %s %s CELLS + ! \n", $6, getScopeVariableId($1), $3); }
                |   IDENTIF '[' expresion ']' '[' expresion ']' '=' expresion
                    { printf("%s %s %s %s ! \n", $9, $3, $6, getScopeVariableId($1)); }
    	        |   PUTS '(' STRING ')'                 { printf (".\" %s \"\n", $3); }
                |   IDENTIF INC                         { printf("%s @ 1 + %s !\n", getScopeVariableId($1), getScopeVariableId($1)); }
                |   IDENTIF DEC                         { printf("%s @ 1 - %s !\n", getScopeVariableId($1), getScopeVariableId($1)); }
                |   IDENTIF THISPLUS expresion           { printf("%s %s @ + %s !\n", $3, getScopeVariableId($1), getScopeVariableId($1)); }
                |   IDENTIF THISMINUS expresion         { printf("%s %s @ - %s !\n", $3, getScopeVariableId($1), getScopeVariableId($1)); }
                |   IDENTIF THISTIMES expresion         { printf("%s %s @ * %s !\n", $3, getScopeVariableId($1), getScopeVariableId($1)); }
                |   IDENTIF THISDIVIDED expresion       { printf("%s %s @ / %s !\n", $3, getScopeVariableId($1), getScopeVariableId($1)); }
                |   PRINTF '(' STRING formatting ')'
                |   RETURN expresion                    { printf("%s\n", $2); }
                ;

flujo:              WHILE expresion                     { printf("begin %s while\n", $2) ; }
                        '{' codigo '}'                  { printf("repeat\n") ; }
                |   DO                                  { printf("begin\n") ; }
                        '{' codigo '}'
                        WHILE expresion ';'             { printf("%s while repeat\n", $7) ; }
                |   IF expresion                        { printf("%s if\n", $2) ; }
                        '{' codigo '}'
                        else_block
                |   FOR '(' sentencia ';'               { ; }
                        expresion ';'                   { printf("begin %s while\n", $6) ; }
                        sentencia ')' '{' codigo '}'    { printf("repeat\n") ; }

                ;

formatting:         /* no more parameters */
                |   ',' expresion                   { printf ("%s .\n", $2) ; }
                        formatting
                ;

else_block:         /* lambda */                    { printf ( " then\n" ) ; }
                |                                   { printf ( " else " ) ; }
                    ELSE '{' codigo '}'             { printf ( " then\n" ) ; }


expresion:          termino                         { sprintf($$, "%s", $1); }
                |   expresion '+' expresion         { sprintf($$, "%s %s +", $1, $3); }
                |   expresion '-' expresion         { sprintf($$, "%s %s -", $1, $3); }
                |   expresion '*' expresion         { sprintf($$, "%s %s *", $1, $3); }
                |   expresion '/' expresion         { sprintf($$, "%s %s /", $1, $3); }
                |   expresion '&' expresion         { sprintf($$, "%s %s and", $1, $3); }
                |   expresion '|' expresion         { sprintf($$, "%s %s or", $1, $3); }
                |   expresion '%' expresion         { sprintf($$, "%s %s mod", $1, $3); }
                |   expresion '>' expresion         { sprintf($$, "%s %s >", $1, $3); }
                |   expresion '<' expresion         { sprintf($$, "%s %s <", $1, $3); }
                |   IDENTIF INC                     { sprintf($$, "%s @", getScopeVariableId($1)); }
                |   IDENTIF DEC                     { sprintf($$, "%s @", getScopeVariableId($1)); }
                |   INC IDENTIF                     { sprintf($$, "%s @ 1 +", getScopeVariableId($2)); }
                |   DEC IDENTIF                     { sprintf($$, "%s @ 1 -", getScopeVariableId($2)); }
                |   '!' expresion                   { sprintf($$, "%s 0=", $2); }
                |   expresion EQUALS expresion      { sprintf($$, "%s %s =", $1, $3); }
                |   expresion NOTEQUALS expresion   { sprintf($$, "%s %s = 0=", $1, $3); }
                |   expresion LE expresion          { sprintf($$, "%s %s <=", $1, $3); }
                |   expresion GE expresion          { sprintf($$, "%s %s >=", $1, $3); }
                |   expresion AND expresion         { sprintf($$, "%s %s and", $1, $3); }
                |   expresion OR expresion          { sprintf($$, "%s %s or", $1, $3); }
                ;


termino:            operando				                { $$ = $1; }
                |   { ; } '+' operando %prec SIGNO_UNARIO	{ sprintf($$, "%s", $3); }
                |   { ; } '-' operando %prec SIGNO_UNARIO	{ sprintf($$, "%s negate", $3); }
                ;

operando:           IDENTIF                         { sprintf($$, "%s @", getScopeVariableId($1)); }
                |   IDENTIF '[' expresion ']'       {
                                                        char* aux = malloc(64*sizeof(char));
                                                        if (aux == NULL) { perror("Error at malloc\n");}
                                                        sprintf(aux, "%s", $3);
                                                        sprintf($$, "%s %s CELLS + @", getScopeVariableId($1), aux);
                                                        free(aux);
                                                    }
                |   IDENTIF '[' expresion ']' '[' expresion ']'
                	{ sprintf($$, "%s %s %s @", $3, $6, getScopeVariableId($1)); }
                |   NUMERO                          { sprintf($<cadena>$, "%s", $<cadena>1); }
                |   '(' expresion ')'               { sprintf($<cadena>$, "%s", $<cadena>2); }
                |   funcall                         { sprintf($<cadena>$, "%s", $<cadena>1); }
                ;

funcall:            IDENTIF '(' arguments ')'       {
                                                        char* aux = malloc(64*sizeof(char));
                                                        if (aux == NULL) { perror("Error at malloc\n"); }
                                                        sprintf(aux, "%s", $1);
                                                        sprintf($<cadena>$, "%s%s", $<cadena>3, aux);
                                                    }
                ;

arguments:                                          { sprintf($<cadena>$, ""); }
                |   expresion more_arguments        { sprintf($<cadena>$, "%s%s ", $<cadena>1, $<cadena>2); }
                ;

more_arguments:                                     { sprintf($<cadena>$, ""); }
                |   ',' expresion more_arguments    { sprintf($<cadena>$, " %s%s", $<cadena>2, $<cadena>3); }
                ;

%%
                            // SECCION 4    Codigo en C
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
    printf ( "bye\n") ;
    exit(1);
}

char *mi_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_pal_reservadas { // para las palabras reservadas de C
    char *nombre ;
    int token ;
} t_reservada ;


t_reservada pal_reservadas [] = { // define las palabras reservadas y los
    {"main",        MAIN},           // y los token asociados
    {"int",         INTEGER},
    {"puts",        PUTS},
    {"while",       WHILE},
    {"for",         FOR},
    {"do",          DO},
    {"if",          IF},
    {"else",        ELSE},
    {"printf",      PRINTF},
    {"return",      RETURN},
    {"++",          INC},
    {"--",          DEC},
    {"+=",          THISPLUS},
    {"-=",          THISMINUS},
    {"*=",          THISTIMES},
    {"/=",          THISDIVIDED},
    {"==",          EQUALS},
    {"!=",          NOTEQUALS},
    {">=",          GE},
    {"<=",          LE},
    {"||",          OR},
    {"&&",          AND},
    {NULL,          0}               // para marcar el fin de la tabla
} ;

t_reservada *busca_pal_reservada (char *nombre_simbolo)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_reservada *sim ;

    i = 0 ;
    sim = pal_reservadas ;
    while (sim [i].nombre != NULL) {
        if (strcmp (sim [i].nombre, nombre_simbolo) == 0) {
            return &(sim [i]);
        }
        i++ ;
    }

    return NULL ;
}


/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *genera_cadena (char *nombre)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l;
    l = strlen (nombre)+1 ;
    p = (char *) mi_malloc (l) ;
    strcpy (p, nombre);
    return p ;
}


int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "=!<>&|%+-*/" ;
    char cadena [256] ;
    t_reservada *simbolo ;

    do {
        c = getchar () ;
        if (c == '#') {	// Ignora las líneas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '\"') {
            i = 0 ;
            do {
                c = getchar () ;
                if (c != '\"') {cadena [i++] = c ;}
            } while (c != '\"' && i < 254) ;
            cadena [i] = '\0' ;
            yylval.cadena = genera_cadena (cadena) ;
            return (STRING) ;
         }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                if (cc == '*') {
                    while (c != '*' || cc != '/') {
                        c = cc;
                        cc = getchar ();
                    }
                    c = getchar ();
                } else {
                    ungetc (cc, stdin) ;
                }
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo Forth embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        }

        if (c == '\n')
            n_linea++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            cadena [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_linea) ;
        }		 	// habria que leer hasta el siguient " , pero, y si falta?
        cadena [--i] = '\0' ;
        yylval.cadena = genera_cadena (cadena) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        i = 0 ;
        while (( (c >= '0' && c <= '9') || c == '_') && i < 255) {
            cadena [i++] = c ;
            c = getchar () ;
        }
        cadena [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.cadena = genera_cadena (cadena) ;
        simbolo = busca_pal_reservada (yylval.cadena) ;
        if (simbolo == NULL) {    // no es palabra reservada -> NUMERO
            /*printf ("\nDEV: NUMERO %s\n", yylval.cadena) ;    // PARA DEPURAR*/
            return (NUMERO) ;
        } else {
            /*printf ("\nDEV: OTRO %s\n", yylval.cadena) ;       // PARA DEPURAR*/
            return (simbolo->token) ;
        }
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9') || c == '_') && i < 255) {

            cadena [i++] = tolower (c) ;
            c = getchar () ;
        }
        cadena [i] = '\0' ;
        ungetc (c, stdin) ;
        yylval.cadena = genera_cadena (cadena) ;
        simbolo = busca_pal_reservada (yylval.cadena) ;
        if (simbolo == NULL) {    // no es palabra reservada -> identificador
            /*printf ("\nDEV: IDENTIF %s\n", yylval.cadena) ;    // PARA DEPURAR*/
            return (IDENTIF) ;
        } else {
            /*printf ("\nDEV: OTRO %s\n", yylval.cadena) ;       // PARA DEPURAR*/
            return (simbolo->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (cadena, "%c%c", (char) c, (char) cc) ;
        simbolo = busca_pal_reservada (cadena) ;
        if (simbolo == NULL) {
            ungetc (cc, stdin) ;
            yylval.cadena = NULL ;
            return (c) ;
        } else {
            yylval.cadena = genera_cadena (cadena) ; // aunque no se use
            return (simbolo->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
        //printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}

int storeVariableId(char *variable_id)
{

    // copy variable name into local variable names storage
    sprintf(variable[variable_cnt], "%s", variable_id);

    // update the variable names storage pointer
    variable_cnt++;

    return 0; // success
}


int createVariable(char *variable_id)
{
    // store variable name in list
    storeVariableId(variable_id);

    // translate the declaration to forth
    printf ("variable %s\n", getScopeVariableId(variable_id));

    return 0; // success
}

int createArray(char *variable_id, int size)
{
    // store variable name in list
    storeVariableId(variable_id);

    // translate the declaration to forth
    printf("variable %s %d cells allot\n", getScopeVariableId(variable_id), size);

    return 0; // success
}

int createMatrix(char *id, int x, int y)
{
    storeVariableId(id);

    if(!there_are_matrices) {
        // declare aux function to create matrices only when necessary
        printf(": matrix-n-m ( #rows #cols -- )\nCREATE DUP , * ALLOT\nDOES> ( member: row col -- addr )\nROT OVER @ * + +  CELL+ ;\n");
        there_are_matrices = 1;
    }

    printf("%d %d matrix-n-m %s\n", x, y, getScopeVariableId(id));
    return 0; // success
}

char *getScopeVariableId(char *variable_id)
{
    int i, is_local = 0;
    char *nombre_completo = malloc(256*sizeof(char));

    // iterate over the stored names to obtain a match
    for (i = 0; i < variable_cnt; i++) {
        if(!strcmp(variable_id, variable[i])) {
            is_local = 1;
            break;
        }
    }

    if(is_local) { // when it is a local variable, print the function suffix
        sprintf (nombre_completo, "%s_%s", variable_id, funcion_actual);
    } else { // when it is a global variable, print the global suffix
        sprintf (nombre_completo, "%s_global", variable_id);
    }

    return nombre_completo; // success
}

int main ()
{
    int i;
    for(i = 0; i < 32; i++) {
        variable[i] = malloc(32*sizeof(char));
    }
    // initialize scope variable count
    variable_cnt = 0;
    // initialize global flag for matrices
    there_are_matrices = 0;
    // set global scope as default
    sprintf (funcion_actual, "global");
    yyparse () ;
    for(i = 0; i < 32; i++) {
        free(variable[i]);
    }
}
