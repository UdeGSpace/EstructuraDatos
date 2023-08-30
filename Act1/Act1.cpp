/******************************************************************************

     Sergio Sanchez

*******************************************************************************/

#include <iostream>
#include <iomanip> 
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#ifdef _WIN32
  #include<windows.h>
#endif  

using namespace std;

struct CD
{
   int codigo;
   char artista[30];
   char album[30];
   int no_canciones;
   float precio;
   int existencias;
};



string Menu = " 1. Agregar\n 2. Mostrar todos los CD’s\n 3. Buscar por c ́odigo\n 4. Modificar\n 5. Realizar una venta\n 6. Salir\n";
string MenuMod = "1. Artista\n 2. Album\n 3. Codigo\n 4. Numero de Canciones\n 5. Precio\n 6. Existencia\n";

int option =10;
int registro, tempCode;
vector<int> codeList;

void cleanScrean()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

bool isUnique(int code){
   bool flag = true;
    for (int i = 0; i < codeList.size(); i++) {
        if (codeList[i] == code) {
            flag = false;
            break; 
        }
    }
   return flag;
};

bool add(CD& test,int tempCode){
   test.codigo = tempCode;
   cin.ignore(100, '\n'); 
   cout << "Ingresa el artista: \n"; cin.getline(test.artista, sizeof(test.artista));
   cout << "Ingresa el album \n"; cin.getline(test.album, sizeof(test.album));
   cout << "Ingresa el numero de canciones: \n"; cin >> test.no_canciones;
   cout << "Ingresa el precio: \n"; cin >> test.precio;
   cout << "Ingresa la cantidad en existencia: \n"; cin >> test.existencias;
   codeList.push_back(tempCode);
   return true;
};



CD* search(CD test[], int numReg, int target) {
    for (int i = 0; i < numReg; i++) {
        if (test[i].codigo == target) {
            return &test[i];
        }
    };
    return nullptr;
};

void show(const CD& test){
   cout << left << setw(9) << test.codigo << "| ";
   cout << left << setw(25) << test.artista << "| ";
   cout << left << setw(25) << test.album << "| ";
   cout << right << setw(10) << test.no_canciones << "| ";
   cout << right << setw(8) << fixed << setprecision(2) << test.precio << "| ";
   cout << right << setw(11) << test.existencias << std::endl;
   
};

void modInt(CD* test, int selection) {
   cin.ignore(100, '\n'); 
    switch (selection) {
        case 1:
            cout << "Ingresa el nuevo artista: ";cin.getline(test->artista, sizeof(test->artista));
            break;
        case 2:
            cout << "Ingresa el nuevo album: ";cin.getline(test->album, sizeof(test->album));
            break;
        case 3:
            cout << "Ingresa el nuevo codigo: ";cin >> test->codigo;
            break;
        case 4:
            cout << "Ingresa el numero de canciones actualizado: ";cin >> test->no_canciones;
            break;
        case 5:
            cout << "Ingresa el nuevo precio: ";cin >> test->precio;
            break;
        case 6:
            cout << "Ingresa el nuevo valor para existencias: ";cin >> test->existencias;
            break;
        default:
            cout << "Campo no válido." << endl;
            cleanScrean();
    }
}


void getOption(int select, vector<string> split){
    if (select >= 0 && select < split.size()+1) {
        cout << "Agrega el nuevo valor para opcion " << split[select-1]<< ": " << endl;
    } else {
        cout << "Opción no disponible." << endl;
        cleanScrean();
    }
};

int main(){
   CD test[50];
   
   stringstream ss(MenuMod);
   string line;
   vector<string> split;
   while (getline(ss, line, '\n')) {
        split.push_back(line);
   }

   while(option !=6){
      cout << Menu;
      cin >> option;
      bool flag = false;
      switch (option){
         case 1:
            cout << "Ingresa el codigo del nuevo disco: \n"; cin >> tempCode;
            if(isUnique(tempCode)){
               flag = add(test[registro], tempCode);
            }else{
                cout << "El codigo " << tempCode << " ya existe en la base de datos.\n";
            };
            registro++;
            cleanScrean();
            if(flag){cout <<  "Agregado Correctamente\n";}
            break;
         case 2:
            {
               cleanScrean();
               if(registro !=0){
                  cout << "Código   | Artista                  | Álbum                    | Canciones | Precio  | Existencias" << endl;
                  cout << "----------------------------------------------------------------------------------------------------------" << endl;
               }
               for (int i = 0; i < registro;i++) {
                  show(test[i]);
               }
            }
            break;
         case 3:
            {
               int target;
               cout << "Ingrese el código del disco a buscar: ";
               cin >> target;

               CD* found = search(test, registro, target);
               if (found != nullptr) {
                  cout << "Disco encontrado:" << endl;
                  show(*found);
               } else {
                  cout << "Disco no encontrado." << endl;
                  cleanScrean();
               }
            }
            break;
         case 4:
            {
               int target, selection = 0;
               char newValue;

               cout << "Ingrese el código del disco a modificar: ";
               cin >> target;
               CD* found = search(test, registro, target);
               if (found != nullptr) {
                  cout << "Disco encontrado:" << endl;
                  show(*found);
                  cout << MenuMod;
                  cin >> selection;
                  getOption(selection, split);
                  modInt(found, selection);
                  cout << "Disco modificado:" << endl;
                  show(*found);
               } else {
                  cout << "Disco no encontrado." << endl;
                  cleanScrean();
               }
            }
            break;
         case 5:
            {
               int target;
               cout << "Ingrese el código del disco: ";
               cin >> target;
               CD* found = search(test, registro, target);
               if (found != nullptr && found->existencias > 0) {
                  show(*found);
                  found->existencias = found->existencias -1;
                  cout << "Venta realizada." << endl;
               } else {
                  cout << "Disco no disponible." << endl;
                  cleanScrean();
               }
            }  
         default:
            break;
      }
   }
   return 0;
}