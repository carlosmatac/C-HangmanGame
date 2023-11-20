/**
  * @file ahorcado.cpp
  * @brief Programa para jugar al ahorcado en consola
  *
  * @author Carlos Mata y Buenaventura Porcel...
  * @date Enero-2020
  *
  * El programa implementa una versi�n b�sica del juego del ahorcado como
  * ejercicio de uso de clases simples.
  *
  * El objetivo que se pretende es programar el juego en base a una clase "Ahorcado"
  * que resuelva las operaciones que se tienen que realizar. El programa principal
  * deber� declarar un objeto de esta clase y llamar a los distintos m�todos hasta
  * el final de la partida.
  *
  * Para hacerse una idea de qu� componentes formar�n parte de la clase:
  *
  * - Un objeto de esta clase, deber� tener informaci�n sobre:
  *    - La frase o palabra que hay que acertar.
  *    - La plantilla con el estado actual de la partida (la palabra con guiones).
  *    - El n�mero de intentos que quedan.
  *    - Las letras que ya se han dicho hasta el momento.
  *
  * - Para que la clase controle el proceso de la partida, deber� tener operaciones para:
  *    - Consultar el estado actual de la plantilla (la cadena de letras/guiones actual)
  *    - Consultar el n�mero de intentos que quedan.
  *    - Consultar la cadena de letras que ya se han usado.
  *    - Saber si la partida se ha terminado.
  *    - Saber si una letra se puede decir o no.
  *    - Saber si se ha ganado la partida.
  *    - Procesar una nueva letra seleccionada por el jugador, teniendo en cuenta que si
  *      se da en may�scula tambi�n debe funcionar. La funci�n devolver� si se ha procesado
  *      correctamente, es decir, si la letra ten�a sentido y no se hab�a usado antes. Por
  *      ejemplo, si le da un car�cter que no es una letra no se puede procesar.
  *
  * Para hacer el programa m�s interesante, el juego deber�a "inventarse" una palabra. Para
  * resolver esto, creamos una clase con la responsabilidad de seleccionar una palabra
  * aleatoria. El dise�o que se propone es crear una nueva clase "Bolsa" que nos hace de
  * generador aleatorio.
  *
  * Para hacerse una idea de qu� componenetes formar�n parte de la clase, tenga en cuenta
  * que deber� tener m�ltiples palabras y nos deber�a permitir "sacar palabras" en un orden
  * arbitrario. Para ello, puede considerar
  *     - Deber� contener un vector privado con las palabras que hay en la bolsa.
  *     - El constructor deber�a cargar ese vector privado con m�ltiples palabras en un
  *       orden aleatorio.
  *     - Deber�a tener un m�todo para seleccionar una nueva palabra.
  *
  * Ya que es una bolsa, podemos realizar el siguiente comportamiento:
  *     - Cuando se declara un objeto de la bolsa, se cargan las palabras y se barajan.
  *     - Se puede pedir la siguiente palabra, dando lugar a una secuencia de palabras que
  *       surgen con un orden aleatorio seg�n hayan quedado ordenadas al construir la bolsa.
  *     - Si se llegan a pedir todas las palabras, pedir la siguiente palabra implicar� volver
  *       a barajar la bolsa y comenzar con la primera de ellas.
  *
  * Para simplificar el problema sin entrar en soluciones que impliquen pedir palabras desde
  * cin, puede declarar un vector con un contenido predeterminado en el constructor y que nos
  * permite inicializar la bolsa. Si quiere, puede usar:
  *       "caballero",  "Dulcinea",   "historia",   "escudero",
  *       "rocinante",  "adelante",   "gobernador", "andantes",
  *       "voluntad",   "capitulo",   "menester",   "doncella",
  *       "caballeria", "castillo",   "Fernando",   "finalmente",
  *       "aventura",   "hermosura",  "palabras",   "gobierno",
  *       "intencion",  "cardenio",   "pensamientos", "Luscinda",
  *       "lagrimas",   "aposento",   "aventuras",  "quisiera",
  *       "libertad",   "desgracia",  "entendimiento", "pensamiento",
  *       "licencia",   "Mercedes",   "semejantes", "silencio",
  *       "valeroso",   "doncellas",  "labrador",   "caballerias",
  *       "cristiano",  "cristianos", "discreto",   "hicieron",
  *       "llegaron",   "quisiere",   "espaldas",   "muestras",
  *       "escuderos",  "discurso",   "grandeza",   "altisidora",
  *       "princesa",   "haciendo",   "renegado",   "provecho",
  *       "quedaron",   "resolucion", "presente",   "encantadores",
  *       "enamorado",  "valiente",   "encantado",  "molino",
  *       "licenciado", "necesidad",  "responder",  "discrecion",
  *       "ejercicio",  "hacienda",   "posadero",   "Rocinante",
  *       "presencia",  "historias",  "presentes",  "verdadero"
  *
  * Observe que una vez que tenga las dos clases, puede declarar una bolsa de palabras y despu�s
  * inicializar un objeto de la clase Ahorcado con una palabra aleatoria, ya que la palabra se pide
  * al objeto "Bolsa".
  *
  * Para programar el juego, puede definir la clase "Ahorcado" e inicializar el objeto con una palabra
  * fija y conocida (por ejemplo, en el constructor). Una vez que ya lo ha depurado y obtenido
  * una soluci�n que funciona, puede a�adir la clase bolsa y crear un programa que juega varias
  * partidas del ahorcado.
  *
  * En concreto, el programa pedir� cu�ntas palabras quiere adivinar y repetir� el juevo con un
  * bucle que permita al usuario jugar varias partidas. Note que declarar� una Bolsa al principio del
  * main y el bucle que repite las partidas pedir� a dicha bolsa una nueva palabra para cada nueva partida.
  *
  */
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
class Bolsa
{
private :
    static const int MAX=100;
    string cadena[MAX];
    int total_usados;
    int indice;

public:
    Bolsa():total_usados(0),indice(0){}
    Bolsa (int usados, string cadena1[]){
        total_usados=usados;
        indice=0;
        for (int i=0; i<total_usados; i++)
        {
            cadena[i]=cadena1[i];
        }
        Barajar();

    }
    string DevolverPalabra ()
    {
        if (indice==total_usados) indice=0;
        else indice++;
        return cadena[indice-1];
    }
    double Uniforme01(){
        double u01=rand()/(RAND_MAX +1.0); //esto nos produce un numero aleatorio en el rango [0,1)
        return u01;
    }
    void Barajar()
    {
        for (int i=0; i<5*total_usados; i++)
        {
            string aux;
            int indice1=Uniforme01()*total_usados;
            int indice2=Uniforme01()*total_usados;
            aux=cadena[indice1];
            cadena[indice1]=cadena[indice2];
            cadena[indice2]=aux;
        }
    }


};
class Ahorcado
{
private:
    static const int INTENTOS=10;
    string palabra;
    string palabra_juego;
    int intentos_restantes;
    string usadas;
public:
    Ahorcado():intentos_restantes(INTENTOS){}
    Ahorcado(string pal)
    {
        palabra=pal;
        for (int i=0; i<palabra.size(); i++)
        {
            palabra_juego+='_';
        }
        intentos_restantes=INTENTOS;
    }
    const string EstadoActual()
    {
        return palabra_juego;
    }
    const int GetIntentos()
    {
        return intentos_restantes;
    }
    const string GetPalabra()
    {
        return palabra;
    }
    const string GetUsadas ()
    {
        return usadas;
    }
    bool EstaTerminado ()
    {
        bool resultado=false;
        if (intentos_restantes>0 && palabra==palabra_juego) resultado=true;
        else if (intentos_restantes==0) resultado=true;
        return resultado;
    }
    bool EstaUsado (char letra)
    {
        bool resultado=false;
        for (int i=0; i<usadas.size(); i++)
        {
            if (usadas[i]==letra) resultado=true;
        }
        return resultado;
    }
    bool HaGanado ()
    {
        bool resultado=false;
        if (intentos_restantes>0 && palabra==palabra_juego) resultado=true;
        return resultado;
    }
    bool Procesar (char letra)
    {
        bool resultado=false;
        if (!EstaUsado(letra))
         {
            usadas+=letra;
            for (int i=0; i<palabra.size(); i++)
            {
                if (letra==palabra[i])
                {
                    palabra_juego[i]=letra;
                    resultado = true;
                }

            }
            if (!resultado) intentos_restantes--;
        }
        return resultado;
    }
    void ReiniciarPartida (string pal)
    {
        palabra=pal;
        for (int i=0; i<palabra.size(); i++)
        {
            palabra_juego+='_';
        }
        intentos_restantes=INTENTOS;
        usadas.clear();
    }



};
int main()
{
    int numero_partidas;
    char letra;
    string cadena[]= {"caballero",  "Dulcinea",   "historia",   "escudero",
         "rocinante",  "adelante",   "gobernador", "andantes",
         "voluntad",   "capitulo",   "menester",   "doncella",
         "caballeria", "castillo",   "Fernando",   "finalmente",
         "aventura",   "hermosura",  "palabras",   "gobierno",
         "intencion",  "cardenio",   "pensamientos", "Luscinda",
         "lagrimas",   "aposento",   "aventuras",  "quisiera",
         "libertad",   "desgracia",  "entendimiento", "pensamiento",
         "licencia",   "Mercedes",   "semejantes", "silencio",
         "valeroso",   "doncellas",  "labrador",   "caballerias",
         "cristiano",  "cristianos", "discreto",   "hicieron",
         "llegaron",   "quisiere",   "espaldas",   "muestras",
         "escuderos",  "discurso",   "grandeza",   "altisidora",
         "princesa",   "haciendo",   "renegado",   "provecho",
         "quedaron",   "resolucion", "presente",   "encantadores",
         "enamorado",  "valiente",   "encantado",  "molino",
         "licenciado", "necesidad",  "responder",  "discrecion",
         "ejercicio",  "hacienda",   "posadero",   "rocinante",
         "presencia",  "historias",  "presentes",  "verdadero"};

    srand(time(NULL));
    Bolsa primera(76, cadena);
    Ahorcado juego(primera.DevolverPalabra());
    cout<<"Cuantas partidas vas a jugar?: ";
    cin>>numero_partidas;
    for(int i=0; i<numero_partidas; i++)
    {
        cout<<"Va a comenzar el nuevo juego "<<endl;
        cout<<"Quedan "<<numero_partidas-i<<" juegos "<<endl;
        do
        {
            cout<<endl;
            cout<<"La longitud de la palabra es: ";
            cout<<juego.GetPalabra().size()<<endl;

            cout<<"Introduce la letra a procesar: ";
            cin>>letra;

            if(juego.Procesar(letra)) cout<<"letra acertada! "<<endl;
            else cout<<"letra erronea! "<<endl;

            cout<<"El estado actual del juego: "<<endl;
            cout<<juego.EstadoActual()<<endl;
            cout<<"Intentos restantes: "<<juego.GetIntentos()<<endl;
            cout<<"Letras usadas: "<<juego.GetUsadas()<<endl;




        }while(!juego.EstaTerminado());
        if (juego.HaGanado())cout<<"ENHORABUENA, VICTORIA! "<<endl;
        else cout<<"GAME OVER! "<<endl;
        juego.ReiniciarPartida(primera.DevolverPalabra());

    }



    return 0;
}
