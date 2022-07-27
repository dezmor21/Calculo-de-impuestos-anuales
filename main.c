#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Declaración y definición de constantes simbólicas
#define MES_CAPTURA 1
#define CAPTURA_INGRESOS 2
#define CAPTURA_GASTOS 3
#define MOSTRAR_LISTA_INGRESOS 4
#define MOSTRAR_LISTA_GASTOS 5
#define CALCULO_IMPUESTOS_ANUAL 6
#define ELIMINAR_INGRESO 7
#define ELIMINAR_GASTO 8
#define SALIR 9
#define TOTAL_MESES 12
#define MAXIMO_CARACT_RFC 13
#define MAXIMO_CARACTERES 40
#define C_0 0
#define C_1 1
#define C_2 2
#define IVA 16
#define RET_ISR 10
#define RET_IVA 10
#define C_100 100
#define ISR 11

int opc;
int i;
char* meses[TOTAL_MESES];
int mesCapturado;
float ingresoDelMes[TOTAL_MESES];
float gastoDelMes[TOTAL_MESES];
float porcentajeIsr[C_2];
int matrizMontos[C_1][C_2];
int procentajesISR[C_0][C_2];
int salidaPrograma;
int porcentaje;
float montoTotal;
int opcIngreso;
int opcGasto;

void inicializacion();
void mostrarMenu();
void CapturarMes();
void capturarIngreso();
void capturarGastos();
void mostrarListaDeIngreso();
void mostrarListaDeGasto();
void calcularImpuestoAnual();
void guardarArchivo();
void pausar();
void eliminarIngreso();

typedef struct
{
    char capturaRfcIngreso[MAXIMO_CARACT_RFC];
    char conceptoIngreso[MAXIMO_CARACTERES+C_1];
    float montoIngreso;
}Ingreso;

typedef struct
{
    char conceptoGasto[MAXIMO_CARACTERES+C_1];
    float montoGasto;
    char justificacion[MAXIMO_CARACTERES+C_1];
}Gasto;

int main()
{
    //Declaración de variables para entrada de datos
    //Declaración de variables para cómputo
    setlocale(LC_ALL,"");
    meses[0]="ENERO";
    meses[1]="FEBRERO";
    meses[2]="MARZO";
    meses[3]="ABRIL";
    meses[4]="MAYO";
    meses[5]="JUNIO";
    meses[6]="JULIO";
    meses[7]="AGOSTO";
    meses[8]="SEPTIEMBRE";
    meses[9]="OCTUBRE";
    meses[10]="NOVIEMBRE";
    meses[11]="DICIEMBRE";
    do
    {
        mostrarMenu();
        scanf("%d",&opc);
        switch (opc)
        {
        case MES_CAPTURA:
            CapturarMes();
            break;
        case CAPTURA_INGRESOS:
            capturarIngreso();
            break;
        case CAPTURA_GASTOS:
            capturarGastos();
            break;
        case MOSTRAR_LISTA_INGRESOS:
            mostrarListaDeIngreso();
            break;
        case MOSTRAR_LISTA_GASTOS:
            mostrarListaDeGasto();
            break;
        case CALCULO_IMPUESTOS_ANUAL:
            calcularImpuestoAnual();
            break;
        case ELIMINAR_INGRESO:
            break;
        case ELIMINAR_GASTO:
            break;
        case SALIR:
            salidaPrograma=(opc==SALIR) ? C_1:C_0;
            break;
        default:
            printf("Opción no válida\n");
            getchar();
            printf("Presione entrar para continuar\n");
            getchar();
            break;
        }
    }
    while(salidaPrograma==C_0);
    return 0;
}
void inicializacion()
{
    opc=C_0;
    mesCapturado=C_0;
    salidaPrograma=C_0;
}
void mostrarMenu()
{
    printf("CÁLCULO DE IMPUESTOS ANUAL\n");
    printf("Menú principal:\n");
    printf("1. Establecer mes para captura (mes actual es %s)\n",meses[mesCapturado]);
    printf("2. Captura de ingresos\n");
    printf("3. Captura de gastos\n");
    printf("4. Mostrar lista de ingresos anual\n");
    printf("5. Mostrar lista de gastos anual\n");
    printf("6. Cálculo de impuestos anual\n");
    printf("7. Eliminar un ingreso\n");
    printf("8. Eliminar un gasto\n");
    printf("9. Salir\n");
    printf("Opción \n");
}
void CapturarMes()
{
    int i;
    printf("Establecer mes para captura\n");
    for (i=0; i<TOTAL_MESES; i++)
    {
        printf("%d)%s\n",i+1,meses[i]);
    }
    printf("Elige el mes (1-12): \n");
    scanf("%d",&mesCapturado);
    if (mesCapturado<=TOTAL_MESES)
    {
        mesCapturado=mesCapturado-C_1;
        printf("Se ha establecido el mes de captura en %s\n",meses[mesCapturado]);

    }
    else
    {
        printf("Mes no valido");
    }

}

void capturarIngreso()
{
    Ingreso ingreso;
    printf("Captura de ingresos\n");
    printf("Dame un  ingreso mas para el mes de %s:",meses[mesCapturado]);
    printf("Provee los datos para el ingreso #%d",i);
    i=i+C_1;
    i++;
    printf("RFC: ");
    scanf("%s",&Ingreso.capturaRfc);
    printf("Concepto: ");
    scanf("%s",&.conceptoIngreso);
    printf("Monto: ");
    scanf("%f",&Ingreso.montoIngreso);
    ingresoDelMes[mesCapturado]+=Ingreso.montoIngreso;
    pausar();
}
void capturarGastos()
{
     Gasto gasto;
    printf("Captura de gastos\n");
    printf("Dame el gasto del mes de %s:",meses[mesCapturado]);
    printf("Provee los datos para el ingreso #%d",i);
    i=i+C_1;
    i++;
    printf("Concepto: ");
    scanf("%s",&Gasto.conceptoGasto);
    printf("Monto: ");
    scanf("%f",&Gasto.montoGasto);
    gastoDelMes[mesCapturado]+=Gasto.montoGasto;
    printf("Justificación: ");
    scanf("%s",Gasto.justificacion);
    pausar();

}

void mostrarListaDeIngreso()
{
    printf(" #       Mes     Monto       RFC         Concepto \n");
    for (i=0; i<TOTAL_MESES; i++)
    {
        printf(" %d      %s     %.2f\n      %s          %s",i,meses[i],ingresoDelMes[i],
           Ingreso.capturaRfc,Ingreso.conceptoIngreso);
    }
    pausar();
}
void mostrarListaDeGasto()
{
    printf(" #       mes     monto       Justificación         Concepto \n");
    for (i=0; i<TOTAL_MESES; i++)
    {
    printf("%d      %s       %.2f       %s                     %s \n",i,meses[i],gastoDelMes[i],
           Gasto.justificacion,Gasto.conceptoGasto);
    }
}
void calcularImpuestoAnual()
{

    float ingresoTotal=0, gastoTotal=0, iva, subtotal, retIsr, retIva;
    float total, gananBruta, isr, gananNeta, isrPagar, gastoIva, totalIva;
    for(i=0; i<TOTAL_MESES; i++)
    {
        ingresoTotal+=ingresoDelMes[i];
    }
    for(i=0; i<TOTAL_MESES; i++)
    {
        gastoTotal+=gastoDelMes[i];
    }
    //Cálculo de impuestos
    iva= ingresoTotal*IVA/C_100;
    subtotal= ingresoTotal+iva;
    retIsr=ingresoTotal*RET_ISR/C_100;
    retIva=ingresoTotal*RET_IVA/C_100;
    total=subtotal-retIsr-retIva;
    montoTotal=ingresoTotal-gastoTotal;
    //Ganancias
    gananBruta=ingresoTotal-gastoTotal;
    isr=gananBruta*ISR/C_100;
    gananNeta=gananBruta-isr;
    isrPagar= isr-retIsr;
    gastoIva= gastoTotal*IVA/C_100;
    totalIva= iva-gastoIva-retIva;
    //Salida de datos
    printf("|CÁLCULO DE IMPUESTOS\n");
    printf("__________________________________\n");
    printf("|***Tabla Recibo de Honorarios***\n");
    printf("|INGRESOS            %.2f \n",ingresoTotal);
    printf("|(+) IVA             %.2f \n",iva);
    printf("|(=) Subtotal        %.2f \n",subtotal);
    printf("|(-) RETENCIÓN ISR   %.2f \n",retIsr);
    printf("|(-) RETENCIÓN IVA   %.2f \n",retIva);
    printf("|(=) Total           %.2f \n",total);
    printf("|________________________________\n");
    printf("|***Tabla Ganancias***\n");
    printf("|INGRESOS            %.2f \n",ingresoTotal);
    printf("|(-) Gasto           %.2f \n",gastoTotal);
    printf("|(=) Ganancia Bruta  %.2f \n",gananBruta);
    printf("|(-) ISR             %.2f \n",isr);
    printf("|(=) Ganancia Neta   %.2f \n",gananNeta);
    printf("|________________________________\n");
    printf("|***Tabla ISR***\n");
    printf("ISR                  %.2d\n",porcentaje);
    printf("|ISR                 %.2f \n",isr);
    printf("|(-) ISR Retenido    %.2f \n",retIsr);
    printf("|(=) ISR a pagar     %.2f \n",isrPagar);
    printf("|________________________________\n");
    printf("|***Tabla IVA***\n");
    printf("|IVA                 %.2f \n",iva);
    printf("|(-) Gastos IVA      %.2f \n",gastoIva);
    printf("|(-) Retención IVA   %.2f \n",retIva);
    printf("|(=) IVA a pagar     %.2f \n",totalIva);
    printf("|________________________________\n");
}

int porcentajeAplicable(float montoTotal)
{
    if ((montoTotal<=C_0)||(montoTotal>=10000.00))
    {
        porcentaje=11;
    }
    else if ((montoTotal<=10000.01)||(montoTotal<=20000.00))
    {
        porcentaje=15;
    }
    else if ((montoTotal<=20000.00)||(montoTotal>20000.01))
    {
        porcentaje=20;
    }
    else
    {

    }
    return porcentaje;
}

void pausar()
{
    getchar();
    printf("Presione entrar para continuar...");
    getchar();
}

void eliminarIngreso ()
{
    printf("1. Mostrar todos los registros \n");
    printf("2. Buscar por RFC \n");
    scanf("%d",&opcIngreso);
    if (opcIngreso==C_1)
    {
        printf("#           Ingreso \n");
        printf("%d          &.2f "i,IngresoDelMes[i]);
        printf("Indica el numero de registro a eliminar (1 a %d): ",TOTAL_MESES);
        scanf("%d",&i);
        i--;
        printf("\nEstas seguro de eliminar el registro (s/n)?");
        getchar();
        scanf("%c",&opcion);
        if (opcion=='S' || opcion=='s'){
            for(ingresoDelMes--;i<TOTAL_MESES;i++){
                ingresoDelMes[i]=ingresoDelMes[i+1];
            }
            ingresoDelMes[i]=C_0;//sera necesario limpiar este registro?
            printf("Registro eliminado!\n");
        }
        else{
            printf("Registro conservado!\n");
        }
    }
    else
    {

    }
}
