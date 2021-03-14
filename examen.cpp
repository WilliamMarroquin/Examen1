//Examen 1
//William Geovany Marroquin Martinez
//3590-20-23926
#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;
const char *nombre_archivo = "archivo.dat";

struct Empleado{
	int codigo_Empleado;
	char nombre[50];
	char apellido[50];
	char puesto[50];
	int sueldo;
	int bonificaciones;
	int suma;
};
void ingresar_empleado();
void abrir_empleado();
void modificar_empleado();
void eliminar_empleado();

int main (){
abrir_empleado();
ingresar_empleado();
modificar_empleado();
eliminar_empleado();
	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"Que Codigo Desea Buscar: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo_Empleado == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo_Empleado << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
        cout<<"Sueldo: "<<empleado.sueldo<<endl;
  		cout<<"Bonificacion: "<<empleado.bonificaciones<<endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}


void buscar_indice(){
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int pos=0;
	cout<<"Que Registro Desea Ver: ";
	cin>>pos;
	cout<<"------------------ [ "<<pos<<" ] ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo_Empleado << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
        cout<<"Sueldo: "<<empleado.sueldo<<endl;
  		cout<<"Bonificacion: "<<empleado.bonificaciones<<endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_empleado(){

	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombre_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"  |"<< "CODIGO" <<"|  "<< "NOMBRE"<<"  |  "<<"APELLIDO"<<"  |  "<<"PUESTO"<<"  |  "<<"SUELDO"<<"  |  "<<"BONIFICACIONES"<<"  |  "<<"SUELDO TOTAL"<<"  |  "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<"  |  "<< empleado.codigo_Empleado <<"   |   "<< empleado.nombre<<"  |  "<<empleado.apellido<<"  |  "<<empleado.puesto<<"  |  "<<empleado.sueldo<<"  |  "<<empleado.bonificaciones<<"  |  "<<(empleado.sueldo+empleado.bonificaciones)<<endl;
        
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombre_archivo, "ab"); 
	
	int suma;
		Empleado empleado;
		 string nombre,apellido,puesto;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo: ";
		cin>>empleado.codigo_Empleado;
        cin.ignore();
        
		cout<<"Ingrese el Nombre: ";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido: ";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
		cout<<"Ingrese Salario Base: ";
		cin>>empleado.sueldo;
        cin.ignore();
        
        cout<<"Ingrese Bonificicones: ";
		cin>>empleado.bonificaciones;
        cin.ignore();
		
		suma=(empleado.sueldo+empleado.bonificaciones);
		cout<<"Su Sueldo Total Es: "<<suma<<endl;
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar Otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_empleado();

	buscar_codigo();
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombre_archivo, "r+b");
		
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
    	
    
		cout << "Ingrese el ID que Desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  
	
		cout<<"Ingrese el Codigo: ";
		cin>>empleado.codigo_Empleado;
        cin.ignore();
        
		cout<<"Ingrese el Nombre: ";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido: ";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
		cout<<"Ingrese el Sueldo ";
		cin>>empleado.sueldo;
        cin.ignore();
        
        cout<<"Ingrese la Bonificacion: ";
		cin>>empleado.bonificaciones;
        cin.ignore();
        
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
	
		system("PAUSE");
		}

void  eliminar_empleado () {
	FILE* archivo = fopen(nombre_archivo,"r+b");	
	int pos=0,indice=0,cod=0;

	cout<<"Que Codigo Desea Eliminar: ";
	cin>>cod;

	Empleado empleado;
	fread(&empleado,sizeof(Empleado),1,archivo);
	
	FILE* temporal = fopen("temp.dat","w+b");	

	do{
		if(empleado.codigo_Empleado == cod){
		  	cout<<"Codigo: "<<empleado.codigo_Empleado<<endl;
		  	cout<<"Nombres: "<<empleado.nombre<<endl;
		  	cout<<"Apellidos: "<<empleado.apellido<<endl;
		  	cout<<"Puesto: "<<empleado.puesto<<endl;
  			cout<<"Sueldo: "<<empleado.sueldo<<endl;
  			cout<<"Bonificacion: "<<empleado.bonificaciones<<endl;
	  }else{
	  	fwrite(&empleado,sizeof(Empleado),1,temporal);
	  }
	  
	  fread(&empleado,sizeof(Empleado),1,archivo);	

	} while(feof(archivo)==0);

	fclose(archivo);
	fclose(temporal);
	
	remove("archivo.dat");
	rename("temp.dat", "archivo.dat");
	abrir_empleado();
}
