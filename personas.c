#include <stdio.h>


//hola
typedef struct 
{
    char nombre[20];
    int edad;
    int peso;
}Persona;
void mostrarPersona(Persona persona){
    printf("Nombre: %s, Edad: %d, Peso: %d\n", persona.nombre, persona.edad, persona.peso);
}

Persona hacerPersona(){
    Persona persona;
    printf("ingrese el nombre: ");
    scanf("%s", persona.nombre);
    printf("ingrese la edad: ");
    scanf("%d", &persona.  edad);
    printf("ingrese el peso: ");
    scanf("%d", &persona.peso);
    return persona;
}

void agregarPersona(Persona persona){
    FILE* archivo;
    archivo = fopen("personas.txt", "ab");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }else{
        fwrite(&persona, sizeof(Persona), 1, archivo);
    }
    fclose(archivo);
}

//mundo
void menu(){
    printf("1. Agregar persona\n");
    printf("2. Mostrar personas\n");
    printf("3. Salir\n");
}



int main(int argc, char const *argv[])
{
    FILE* archivo;
    
    Persona persona;
    
    //Para escribir un archivo binario se utiliza el modo "wb" (write binary)
    //para leer un archivo binario se utiliza el modo "rb" (read binary)

    menu();
    int opcion;
    while (opcion!=3)
    {
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                persona = hacerPersona();
                agregarPersona(persona);
                break;
            case 2:
                archivo = fopen("personas.txt", "rb");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo.\n");
                    return 1;
                }else{
                    while (fread(&persona, sizeof(Persona), 1, archivo)) {
                        mostrarPersona(persona);
                    }
                }
                fclose(archivo);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    }
    
   
    
    return 0;
}
