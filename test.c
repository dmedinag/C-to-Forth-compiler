/* comentario
    de
    varias
    líneas */
// declaración de variables globales
int a;
int b;
int c[400];

// declaración de función sin variables globales
function_ifs () {
    // asignación de variables globales
    a = 2;
    b = 3;
    // puts
    puts("I regret nothing\n");

    // bloque if sin else
    if (a == b) { // expresión ==
        puts("What the heck.\n");
    }

    // bloque if con else
    if (b < a) { // expresión <
        puts("This doesn't make any sense!\n");
    } else {
        b = a;
    }
}

// declaración de función con variables locales
function_loops () {
    // creación de variables locales
    int valui;
    int other_valui;
    // asignación de variables locales
    valui = 5;
    // asignación con un identificador
    other_valui = valui;

    // while loop
    while(valui >= other_valui) { // expresión >=
        // printf con parámetros extra
        printf ("I should be printed only once. %d\n", valui);
        // incremento
        other_valui++;
    }

    // asignación negativa
    other_valui = -1;

    if(other_valui++) {
        puts("I won't get printed.\n");
    }

    if(++other_valui) {
        puts("I should get printed.\n");
    }

    // do-while loop
    do {
        // decremento
        valui --;
        puts("Just keep swimming  (8)\n");
    } while (valui != other_valui); // expresión !=
}

function_thisoperators () {
    // asignaciones aumentadas
    a += b;
    a -= b;
    a *= b;
    a /= b;
}

function_arrays (int jeje) {
    // operaciones con elementos de un array
    c[0] = jeje;
    printf("%d", jeje);
    c[3] = 8;
    c[2] = c[0] + c[8];
}

function_matrices () {
    // matrices: declaración y operaciones
    int a_matrix[30][2];
    a_matrix[20][1] = 2;
    b = a_matrix[20][1];
    printf("%d", b);
}

funcion_con_parametros (int a) {
    return a+b;
}

// declaración del main
main () {
    int another_matrix[34][4];
    int valui;
    another_matrix[0][2] = 23;
    valui = b;
    printf("%d", another_matrix[0][2]);
    function_matrices();
    b = 3;
    funcion_con_parametros(6);
}

//@ main
