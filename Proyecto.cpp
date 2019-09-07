#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define tarifaHoraParquadero 800;


struct Usuario{
	string Nombre;
	string Contrasena;
};

struct Automovil{
	string Placa;
	int horaIngreso;
	int horaSalida;
	int ParqueaderoX;
	int ParqueaderoY;
};


char Parqueadero [6][6];
Automovil Automoviles[36];
Usuario Usuarios[10];
int cantidadAutos = 0;

void mostrarUsuarios(){
	for(int i=0;i < 10;i++){
		if(Usuarios[i].Nombre != ""){
			cout<<"							     Usuario "<<i+1<<endl;
			cout<<"							Nombre usuario: "<<Usuarios[i].Nombre<<endl;
			cout<<"							Contrasena: "<<Usuarios[i].Contrasena<<endl<<endl;
		}
	}
}

int valorParqueo(int horaIngreso,int horaSalida){
	int unsigned valor;
	valor = horaSalida - horaIngreso - 40;
	valor = (valor/60) * tarifaHoraParquadero;

	return valor;
}

void imprimirParqueaderos(){
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"							"<<"  1 2 3 4 5 6"<<endl;
	cout<<"							"<<"______________"<<endl;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(j==0){
				cout<<"							"<<i+1<<"|"<<Parqueadero[i][j]<<" ";
			}else{
				cout<<Parqueadero[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

int bucarAutomovil(string Placa){
	int i=0;
	while((Placa!=Automoviles[i].Placa)&&(i < 36)){
		i=i+1;
	}
	return i;
}

int eliminarUsuario(int usuariosExitentes){
	int usuarioEliminar;

	cout<<"Usuarios registrados.";
	mostrarUsuarios();

	cout<<"Indique el numero del usuario que desea eliminar: ";
	cin>>usuarioEliminar;
	cout<<endl;
	Usuarios[usuarioEliminar-1].Nombre = "";
	Usuarios[usuarioEliminar-1].Contrasena = "";

	return usuariosExitentes = usuariosExitentes -1;
}

int crearUsuario(int usuariosExitentes){

	system("CLS");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	if(usuariosExitentes==10){
		cout<<endl<<"					Se alcanzo la cantidad maxima de usuarios."<<endl;
		system("pause");
		return usuariosExitentes;
	}
	int buscarEspacio=0;
	while((Usuarios[buscarEspacio].Nombre != "")&&(buscarEspacio < 10)){
		buscarEspacio = buscarEspacio+1;
	}
	cout<<"					Ingrese un nombre de Usuario: ";
	cin>>Usuarios[buscarEspacio].Nombre;
	cout<<endl<<"					Ingrese la Contrasena: ";
	cin>>Usuarios[buscarEspacio].Contrasena;
	cout<<endl;

	return usuariosExitentes=usuariosExitentes+1;
}


int menuInicio(){
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"						--------------------------"<<endl;
	cout<<"						|BIENVENIDO AL PARQUADERO|"<<endl;
	cout<<"				 		--------------------------"<<endl;
	cout<<endl;
	cout<<"						1. Ingresar."<<endl;
	cout<<"						2. Crear Usuario."<<endl;
	cout<<"						3. Listar usuarios existentes."<<endl;
	cout<<"						4. Salir."<<endl<<endl;
	int Opcion;
	cout<<"						Seleccione una opcion: ";
	cin>>Opcion;

	return Opcion;
}

int salidaAutomovil(){
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	string Placa;
	int Auto;
	int precioParqueo;
	cout<<"					Ingrese la placa del vehiculo: ";
	cin>>Placa;
	cout<<endl;

	Auto = bucarAutomovil(Placa);

	if((Automoviles[Auto].Placa == Placa)&&(cantidadAutos >= 1)){
		int horaIngreso, horaSalida;
		cout<<"				Ingrese la hora de salida en hora militar ej la 1:30pm seria 1330: ";
		cin>>Automoviles[Auto].horaSalida;
		cout<<endl;

		horaIngreso = Automoviles[Auto].horaIngreso;
		horaSalida = Automoviles[Auto].horaSalida;

		precioParqueo = valorParqueo(horaIngreso,horaSalida);

		cout<<"				El valor del parqueo del auto es: "<<precioParqueo<<" colones"<<endl;

		Parqueadero[Automoviles[Auto].ParqueaderoX][Automoviles[Auto].ParqueaderoY]='D';

		cantidadAutos = cantidadAutos-1;
	}else if(cantidadAutos == 0){
		cout<<"				El parqueadero aun no cuenta con automoviles.";
	}else{
		cout<<"				Este auto no se encuentra en el parqueadero."<<endl;
	}

	return cantidadAutos;
}

bool buscarUsuario(string Users,string Password){
	int buscarUsuario=0;

	while((Users != Usuarios[buscarUsuario].Nombre)&&(buscarUsuario < 10)){
		buscarUsuario = buscarUsuario+1;
	}

	if(Users==Usuarios[buscarUsuario].Nombre){
		if(Password == Usuarios[buscarUsuario].Contrasena){
			return true;
		}else{
			cout<<"						Contrasena incorrecta "<<endl;
			return false;
		}
	}else{
		cout<<"						El usuario "<<Users<<" no existe."<<endl;
		return false;
	}
}

void inicializarParqueadero(){
	for (int i =0; i < 6;i++){
		for(int j=0;j < 6;j++){
			Parqueadero[i][j]='D';
		}
	}
}

int ingresarAutomovil(){
	if(cantidadAutos>=36){
		cout<<"						Parqueadero copado"<<endl;
	}else{
		cout<<"					Ingrese la placa del vehiculo: ";
		cin>>Automoviles[cantidadAutos].Placa;
		cout<<"				Ingrese la hora en hora militar ej la 1:30pm seria 1330."<<endl;
		cout<<"						Hora de ingreso: ";
		cin>>Automoviles[cantidadAutos].horaIngreso;
		int i=0,j=0;

		while(Parqueadero[i][j] != 'D'){
			if(j >= 6){
				i=i+1;
				j=0;
			}
			j=j+1;
		}

		Automoviles[cantidadAutos].ParqueaderoX = i;
		Automoviles[cantidadAutos].ParqueaderoY = j;
		cout<<endl<<"				El auto ocupara la posicion de parqueadero "<<i+1<<"-"<<j+1<<endl;
		Parqueadero[i][j]='X';
		cantidadAutos = cantidadAutos+1;
	}
	return cantidadAutos;
}

void menuUsuario(){

	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"						--------------------------"<<endl;
	cout<<"						|BIENVENIDO AL PARQUADERO|"<<endl;
	cout<<"						--------------------------"<<endl;
	cout<<"						|     MENU DE USUARIO    |"<<endl;
	cout<<"				 		--------------------------"<<endl;
	cout<<endl;
	cout<<"						1. Ingresar automovil."<<endl;
	cout<<"						2. Salida automovil."<<endl;
	cout<<"						3. Revisar posiciones parqueadero."<<endl;
	cout<<"						4. Menu anterior."<<endl;
	cout<<"						Seleccione una opcion: "<<endl;
}

void contrladorMenuUsuario(){
	int option;

  do{
  		system("CLS");
  		menuUsuario();
  		cout<<"						Escoja una opcion: ";
  		cin>>option;
  		cout<<endl;

  		switch(option){
  			case 1:
  				system("CLS");
  				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
  				cantidadAutos = ingresarAutomovil();
  				system("PAUSE");
  				break;

  			case 2:
  				system("CLS");
  				cantidadAutos = salidaAutomovil();
  				system("pause");
  				break;

  			case 3:
  				system("CLS");
  				imprimirParqueaderos();
  				cout<<"						La X significa que esta ocupado."<<endl;
  				cout<<"						La D significa que esta desocupado"<<endl;
  				system("PAUSE");
  				break;
  		}

	}while(option != 4);
}



void ingreso(int usuariosExitentes){
		string Users, Password;
		system("CLS");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"							USUARIO: ";
		cin>>Users;
		cout<<endl<<"							CONTRASENA: ";
		cin>>Password;
		cout<<endl;

		if(buscarUsuario(Users,Password)){
		 contrladorMenuUsuario();
		}else{
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("PAUSE");
		}
}




void crearPrimerUsuario(){
	cout<<endl<<endl<<endl;
	cout<<"				                 --------------------------"<<endl;
	cout<<"					         |BIENVENIDO AL PARQUADERO|"<<endl;
	cout<<"				 		 --------------------------"<<endl;
	cout<<endl<<endl;
	cout<<"						----------------------------"<<endl;
	cout<<"						|CREACION DE PRIMER USUARIO|"<<endl;
	cout<<"				 		----------------------------"<<endl;
	cout<<"						Nombre de usuario nuevo: ";
	cin>>Usuarios[0].Nombre;
	cout<<endl<<"						Contrasena de usuario: ";
	cin>>Usuarios[0].Contrasena;
	cout<<endl;
}

void contrlador(int usuariosExitentes){
	int option;

	do
	{
		option = menuInicio();
		switch(option){
			case 1:
				ingreso(usuariosExitentes);
				system("CLS");
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"					";
				system("pause");
				break;
			case 2:
				usuariosExitentes = crearUsuario(usuariosExitentes);
				break;
			case 3:
				system("CLS");
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"				Exiten "<< usuariosExitentes <<" usuario(s), solo se permiten crear hasta 10 usuarios."<<endl<<endl;
				mostrarUsuarios();
				system("pause");
				break;
			case 4:
				cout<<"HASTA PRONTO...";
				break;
		}
		system("CLS");
	}while(option!=4);
}


int main()
{
	inicializarParqueadero();
	//contrladorMenuUsuario();
	crearPrimerUsuario();
	int usuariosExitentes=1;
	system("CLS");
	contrlador(usuariosExitentes);
	//menuInicio();
	//ingreso();
	return 0;
}
