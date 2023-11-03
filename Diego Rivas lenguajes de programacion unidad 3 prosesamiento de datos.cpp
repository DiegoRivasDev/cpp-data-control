#include <iostream>
#include <fstream>

using namespace std;

	char escritura;
	char guardado[0];

int main()
{
   
   ofstream Archivo_Escritura;
   Archivo_Escritura.open("archivo.txt", ios::out | ios::app);

    if(Archivo_Escritura.is_open())
    {
       cout << "Escritura del archivo." << endl << endl;
       cout << "1 - escritura "<< endl;
       cout << "2 - lectura "<< endl;
       cin >> escritura;

        while((escritura == '1') || (escritura == 's'))
        {
           cout << endl << "Ingrese el texto que desee: ";
           cin >> guardado;
           Archivo_Escritura << guardado << endl;
           cout << "Desea agregar mas texto (s/n): ";
           cin >> escritura;
        }
    }

    else
    {
       cout << "error no se pudo realizar la operacion" << endl;
    }

    ifstream Archivo_Lectura;
    Archivo_Lectura.open("archivo.txt", ios::in); 

    if(Archivo_Lectura.is_open())
    {
      cout << endl;
      cout << "\tLectura del archivo."  << endl;
      Archivo_Lectura >> guardado;
      cout << "El texto que existe en su archivo es el siguiente: "<<endl;

      while(!Archivo_Lectura.eof())
      {
          cout << guardado << endl;
          Archivo_Lectura >> guardado;
      }
   }

   else
   {
      cout << "error no se pudo realizar la operacion" << endl;
   }

   Archivo_Lectura.close();
   Archivo_Escritura.close();
   return 0;
}
