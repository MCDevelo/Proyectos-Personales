#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>

	using namespace std;
	#define usr "adm"
	#define pass "c++123"
//funciones
	void login();
	void Registro(void);
	void UsrEst_tst();
	void UsrEst_Carr();
	void AdmMenu();
	void MenEst();
	void carr_Artes();
	void carr_Electrom();
	void carr_Const();
	void carr_Indust();
	void carr_Inf();
	void carr_salud();
	void carr_Turis();
	void AdmVerReg();
	void Editar();
	void crear_txt();
	
	//variables globales
	struct variables{
			string nombre;
			string matricula;
			string sexo;
			string user_est;
			string passw_est;
			int opc_registro;
			char categoria1 [20] = "Estudiante";
			char categoria2 [20] = "Administrador";
			int volver_menu;
			string name_user;
			string carrera;
			string pass_ur_adm;	
			string cargo;			
	}datos;
	
		void leerPasw(string passw)
			{
				int i = 0;
				cout.flush();
			do {
			passw[i] = (unsigned char)getch();
				if (passw[i] !=8){
					cout<<"*";
					i++;
				}
				else if (i>0){
					cout<<(char)8<<(char)32<<(char)8;
					i--;
				}
				cout.flush();
			}
			    while (passw[i-1]!=13);
			    
			    passw[i-1] =NULL;
			    cout<<endl;
			    
			}	
			
	void Registro(void){
		system ("cls");//Limpiando pantalla.
		system("color 6");
			cin.ignore(256, '\n');//Limpiando buffer.
			ofstream archivo;
				archivo.open("Registro.txt", ios::app);
		
		if (archivo.fail()){
			cout<<"No se pudo abrir el archivo.";
			exit(1);
		}
		
	while (datos.opc_registro != 1 && datos.opc_registro != 2) {
	
		cout<<"\t\t\t\t\t******* REGISTRO ********\n";
		cout<<"\n\n";
		cout<<"\t\t\t _______________________________________________________________\n";
		cout<<"\t\t\t|\t\t\t\t\t\t\t\t|\n";
		cout<<"\t\t\t|\t\t\t1.COMO ALUMNO\t\t\t\t|\n";
		cout<<"\t\t\t|\t\t\t2.COMO ADMIN\t\t\t\t|\n";
		cout<<"\t\t\t|_______________________________________________________________|\n";
		cout<<"\t\t\t  "; cin>>datos.opc_registro; 
	}
	
		switch(datos.opc_registro)
		{
		
		case 1:
		system("cls");
		cin.ignore(256, '\n');
		cout<<"\n";
		cout<<"\t\t\t\t***** REGISTRO *****\n";
		cout<<"\n\n";
		cout<<"\t\t\tNOMBRE: ";
		getline(cin,datos.nombre);
		cout<<"\n\t\t\tMATRICULA: ";
		getline(cin,datos.matricula);
		cout<<"\n\t\t\tSEXO: ";
		getline(cin,datos.sexo);
		cout<<"\t\t\tCARRERA: ";
		getline(cin,datos.carrera);
		
		//clave de usuario
		cout<<"Su nombre de usuario Sr. "<<datos.nombre<<" es: "<<datos.matricula<<" y su clave es: "<<datos.matricula<<endl;
				Sleep(5000);
		//guardando en el registro
		
		archivo<<datos.matricula<<"\t"<<datos.matricula<<"\t"<<datos.categoria1<<"\t"<<datos.nombre<<"\t"<<datos.matricula<<"\t"<<datos.cargo<<"\t"<<datos.sexo<<"\t\t"<<datos.carrera<<endl;
					
		archivo.close();
		
		break;
		
		case 2:
		//	cin.ignore(256, '\n');
			system("cls");
			string us;
			char pas[14];
			cout<<"Para registrarse como Administrador debe logiarse el administrador del servidor.";
			cin.ignore();
			do{
				system("cls");
				cout<<"\t\t\t\t\t**** LOGIN ****"<<endl;
				cout<<"\n\n";
				cout<<"\t\t\tUSUARIO : ";
				cin>>us;
				cout<<"\t\t\tPASSORD : ";
				leerPasw(pas);
				
				if ((us != usr)&&(pas != pass)){
					cout<<"Los datos ingresados no son de admin"<<endl;
				cout<<"\tVolver al menu, precione ( 1 ).: ";
				cout<<"\t";cin>>datos.volver_menu;
				
				}
				system("cls");
			} while ((us != usr)&&(pas != pass));
			
			cin.ignore(256, '\n');
			cout<<"\n";
			cout<<"\t\t\t\t\t**** REGISTRO ADMINISTRADOR ****"<<endl;
		cout<<"\n\t\t\tNOMBRE: ";
		getline(cin,datos.nombre);
		cout<<"\n\t\t\tCARGO: ";
		getline(cin,datos.cargo);
		cout<<"\n\t\t\tSexo: ";
		getline(cin, datos.sexo);
		cout<<"\n\t\t\tNOMBRE DE USUARIO: ";
		getline(cin, datos.name_user);
		cout<<"\n\t\t\tCLAVE DE USUARIO: ";
		getline(cin, datos.pass_ur_adm);
		
		archivo<<datos.name_user<<"\t"<<datos.pass_ur_adm<<"\t"<<datos.categoria2<<"\t"<<datos.nombre<<"\t"<<datos.matricula<<"\t"<<datos.cargo<<"\t"<<datos.sexo<<endl;	

		archivo.close();
				
		cout<<"\n\nASEGURE GUARDAR BIEN SU CONTRASELA. AQUI ESTA NUEVAMENTE LA MISMA----->  "<<datos.pass_ur_adm<<endl;	
				Sleep(2000);
				
				system("cls");
				
				cout<<"VERIFIQUEMOS QUE SU USUARIO EXISTE. DEBE LOGIARSE PARA ELLO.";
			Sleep(2000);
			break;	
		}
		
	}
	
	
void login()
	{
		system("cls");
		system("color 8");
	//	cin.ignore(2556, '\n');
		ifstream archivo;
		int opciones;
		string usre, facultad;
		string clave;
		string fusuario, fclave, fcategoria, fnombre, fmatricula, fcargo, fcarrera;

		cout<<"\t\t\t\t***** LOGIN ******\n";
		cout<<"\n\n";
		cout<<"\t\t\tUSUARIO: ";
		getline(cin, usre);
		cout<<"\n\t\t\tCLAVE: ";
		getline(cin, clave); 
		
		archivo.open("Registro.txt");
		
		
		
		while(!archivo.eof())
		{
			archivo>>fusuario>>fclave>>fcategoria>>fnombre>>fmatricula>>fcargo>>fcarrera;
			if ((usre == fusuario) && (clave == fclave) && (datos.categoria1 == fcategoria))			
			{
				system("cls");
				cin.ignore(256, '\n');
					MenEst();
			}

			if ((usre == fusuario) && (clave == fclave) && (datos.categoria2 == fcategoria) || (usre == usr) && (clave == pass))
			{
				system("cls");
				system("color 2");
				//cin.ignore(256, '\n');
					AdmMenu();
			}
		 
		}
		archivo.close();	
	}

//menu de los estudiantes
		void MenEst(){
			volvera: //<-- ese es parte esencial				
		system("cls");
		int seleccion;
		cout<<"\n";
		cout<<"\t\t\t\t******** BIENVENIDO ********";
		cout<<"\n\n";
		cout<<"\t\t\t1. TOMAR TEST ";
		cout<<"\t\t\t2. VER CARRERAS ";
		cout<<"\n\n";
		cout<<"\t\tingrese la opcion: ";
		cout<<"\t\t"; cin>>seleccion;
		
				if (seleccion == 1){
					UsrEst_tst();
				}
				if(seleccion == 2){
					UsrEst_Carr();
				}
				if (seleccion != 1 && seleccion != 2){
					cout<<"\n\t\tLA OPCION DIGITADA NO ES VALIDA ' "<<seleccion<<" '"<<endl;
					Sleep(3000);
				goto volvera; //<--- lo que lo hace volver
				}
		}
		//examen de los estudiantes
		void UsrEst_tst()
		{
			string vcon;
			char s[] = "s";
			char n[] = "n";
			
					cin.ignore(256, '\n');
					int contadorA;
					system("cls");
					system("color 6");
					cout<<"\n\n\n";
					char opc1[5], opc2[5], opc3[5], opc4[5], opc5[5], opc6[5], opc7[5], opc8[5], opc9[5], opc10[5];
					int opcA= 0, opcB= 0, opcC= 0, opcD= 0;
					
				//	cin.ignore(256, '\n');
					
					cout<<"\n";
					cout<<"\t\t\t\t\t******* TEST VOCACIONAL *******";
					cout<<"\n\n\n\n";
					cout<<"\n\t1. Si te consedieran un deseo relacionado al conocimiento, Que pedirias?\n\t\tA). Entender porque el ser humano es tan complejo.\n\t\tB). Saber las leyes abstractas que rigen el universo.\n\t\tC). Inventar las mejores tecnologias del futuro.\n\t\tD). Ver todas las cosas hermosas del mundo.\n";
					cout<<"\t";cin.getline(opc1, 5, '\n');//cin>>op1;
					cout<<"\t2. Cuando estudias, ¿que estrategia usas?\n\t\tA). Subrayo las ideas principales.\n\t\tB). Anoto las palabras clave.\n\t\tC). Hago un esquema.\n\t\tD). No tengo estrategia.\n";
					cout<<"\t";cin.getline(opc2, 5, '\n');//cin>>op1;
					cout<<"\t3. Cuando estudias una materia, ¿que es lo mas importante?\n\t\tA). Aprender con presicion cada detalle de lo leido.\n\t\tB). Comprender las ideas generales.\n\t\tC). Relacionarla con las otras materias.\n\t\tD). hacer un resumen.\n";
					cout<<"\t";cin.getline(opc3, 5, '\n');//cin>>op1;
					cout<<"\t4. Cuando aprendes algo nuevo, ¿que haces con ese aprendizaje?\n\t\tA). Trato de ponerlo en practica.\n\t\tB). Analizo su significado y lo dejo guardado en mi mente.\n\t\tC). Reflexiono en torno a su utilidad.\n\t\tD). No me he puesto a pensar en lo que hago.\n";
					cout<<"\t";cin.getline(opc4, 5, '\n');//cin>>op1;
					cout<<"\t5. Con cual de las siguientes actividades de clase te motivas mas?\n\t\tA). Debatiendo.\n\t\tB). Realizando experimentos.\n\t\tC). Resolviendo ecuaciones.\n\t\tD). Dibujando o Pintando.\n";
					cout<<"\t";cin.getline(opc5, 5, '\n');//cin>>op1;
					cout<<"\t6. En un futuro, ¿Cual de las siguientes te gustaria que estuviera presente en tu dia a dia?\n\t\tA). Escuchar a las personas para entenderlas.\n\t\tB). Investigas la naturaleza para entenderla.\n\t\tC). Idear nuevas formas para mejorar los procesos.\n\t\tD). Diseñar nuevas formas para embellecer los ambientes.\n";
					cout<<"\t";cin.getline(opc6, 5, '\n');//cin>>op1;
					cout<<"\t7. En una discucion, ¿que es realmente importante?\n\t\tA). Entender la opinion ajena.\n\t\tB). Identificar las causa y consecuencias.\n\t\tC). Examinar una unica solucion posible.\n\t\tD). Dejar que todos se expresen libremente.\n";
					cout<<"\t";cin.getline(opc7, 5, '\n');//cin>>op1;
					cout<<"\t8. Como te proyectar en un futuro?\n\t\tA). Ayudando a que el mundo sea mejor.\n\t\tB). Procurando el bienestar de los otros.\n\t\tC). Resolviendo mis problemas por mi cuenta.\n\t\tD). Trabajando solo.\n";
					cout<<"\t";cin.getline(opc8, 5, '\n');//cin>>op1;
					cout<<"\t9. Cuando piensas en trabajo, ¿En que posicion te ves trabajando?\n\t\tA). Creo que trabajare en algo que me de libertad.\n\t\tB). Me gustaria estar en una gran empresa.\n\t\tC). Intentare emprender.\n\t\tD). No visualizo nada muy especifico.\n";
					cout<<"\t";cin.getline(opc9, 5, '\n');//cin>>op1;
					cout<<"\t10. Cual de las siguientes frases te representa mas?\n\t\tA). 'Analizo por que los otros actuan como actuan'.\n\t\tB). 'Pregunto sobre cosas que otros dan por obvias'.\n\t\tC). 'Invento soluciones que otros no se les ocurren'.\n\t\tD). 'Siento que veo detalles que otros no ven'.\n";
					cout<<"\t";cin.getline(opc10, 5, '\n'); //>>op1;
					
					for (int i = 0; i < 10; i++){
						switch(opc1[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc2[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc3[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc4[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc5[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc6[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc7[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc8[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc9[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						switch(opc10[i]){
							case 'a':opcA++;break;
							case 'b':opcB++;break;
							case 'c':opcC++;break;
							case 'd':opcD++;break;
						}
						
					}
					/*debes poner que cuando haya un maximo de respuestas iguales el programa de ambas opciones al usuario.*/
							if (opcA > opcB && opcA > opcC && opcA > opcD){
								char s[] = "s";
								char n[] = "n";
								cout<<"\n\n";
								cout<<"\t\tHUMANISTA\n";
								cout<<"\n\n";
								cout<<"\t\tsegun sus resultados usted es una persona HUMANISTA. Usted aplica para carreras como: ";
								
								FILE *artes = fopen ("Artes.txt", "r");
				 			int se;
				 			while ((se = fgetc(artes)) != EOF){
				 				putchar(se);
							 }
							 cout<<"\n\t_____________________________________________________________________________________________\n";
								
								cout<<"\n\n Si desea ver los pensum, digite (s), de lo contrariodigite (n) para salir: ";
								cin>>vcon;
								if (vcon == s){
									UsrEst_Carr();
								}		
								else if (vcon == n){
									cout<<"\n\t\tGracias por utilizar nuestros servicios.";
									Sleep(2000);
									exit(0);
								}
						
							}
							if (opcB > opcA && opcB > opcC && opcB > opcD){
								cout<<"\n\n";
								cout<<"\t\tCIENTIFICO\n";
								cout<<"\n\n";
								cout<<"\t\tsegun sus resultados usted es una persona CINETIFICA. Usted aplica para carreras como: ";
								
							FILE *salud = fopen ("Salud.txt", "r");
				 			int si;
				 			while ((si = fgetc(salud)) != EOF){
				 				putchar(si);
							 }
							 cout<<"\n\t____________________________________________________________________________________________\n";
							 cout<<"\n\n Si desea ver los pensum, digite (s), de lo contrariodigite (n) para salir: ";
								cin>>vcon;
								if (vcon == s){
									UsrEst_Carr();
								}		
								else if (vcon == n){
									cout<<"\n\t\tGracias por utilizar nuestros servicios.";
									Sleep(2000);
									exit(0);
								}
								
							}
								if (opcC > opcA && opcC > opcB && opcC > opcD){
								cout<<"\n\n";
								cout<<"\t\tMATEMATICO\n";
								cout<<"\n\n";
								cout<<"\t\tsegun sus resultados usted es una persona MATEMATICO. Usted aplica para carreras como: ";
									FILE *informatica = fopen ("Informatica.txt", "r");
				 			int inf;
				 			while ((inf = fgetc(informatica)) != EOF){
				 				putchar(inf);
							 }
							 cout<<"\n\t________________________________________________________________________________________\n";
							 	
								 FILE *cons = fopen ("Construccion.txt", "r");
				 			int con;
				 			while ((con = fgetc(cons)) != EOF){
				 				putchar(con);
							 }
							 cout<<"\n\t_______________________________________________________________________________________\n";
									
									FILE *elect = fopen ("Electromecanica.txt", "r");
				 			int ele;
				 			while ((ele = fgetc(elect)) != EOF){
				 				putchar(ele);
							 }
							 cout<<"\n\t_________________________________________________________________________________________\n";
								cout<<"\n\n Si desea ver los pensum, digite (s), de lo contrariodigite (n) para salir: ";
								cin>>vcon;
								if (vcon == s){
									UsrEst_Carr();
								}		
								else if (vcon == n){
									cout<<"\n\t\tGracias por utilizar nuestros servicios.";
									Sleep(2000);
									exit(0);
								}
								
							}
								if (opcD > opcA && opcD > opcC && opcD > opcB){
								cout<<"\n\n";
								cout<<"\t\tARTISTICO\n";
								cout<<"\n\n";
								cout<<"\t\tsegun sus resultados usted es una persona ARTISTICO. Usted aplica para carreras como: ";
								
									FILE *Arte = fopen ("Arte.txt", "r");
				 			int art;
				 			while ((art = fgetc(Arte)) != EOF){
				 				putchar(art);
							 }
								 cout<<"\n\t_________________________________________________________________________________________\n";
									FILE *indus = fopen ("Insdustrial.txt", "r");
				 			int ind;
				 			while ((ind = fgetc(indus)) != EOF){
				 				putchar(ind);
							 }
							  cout<<"\n\t_________________________________________________________________________________________\n";
							  
								cout<<"\n\n Si desea ver los pensum, digite (s), de lo contrariodigite (n) para salir: ";
								cin>>vcon;
								if (vcon == s){
									UsrEst_Carr();
								}		
								else if (vcon == n){
									cout<<"\n\t\tGracias por utilizar nuestros servicios.";
									Sleep(2000);
									exit(0);
								}
							}
							
		}	
			//carreras de estudiantes
	   void UsrEst_Carr()
	   {
	   	
	   			int facultad;
				do{
				system("cls");
				system("color 1");
				FILE *carreras = fopen("facultades.txt", "r");
				int c;
				 while ((c = fgetc(carreras)) != EOF){
				 	putchar(c);
				 }
				 		cout<<"\n\nDIGITE QUE FACULTAD DESEA VER: ";
				 		cin>> facultad;
			
				 	switch (facultad){
				 		case 1:
				 			carr_Artes();
							break;
									
						case 2:
							carr_Const();
									break;
							case 3:
								carr_Electrom();
									break;
						case 4:
							carr_Indust();
						break;
						
						case 5:
							carr_Inf();
						break;			
						
						case 6:
							carr_salud();
							break;
						case 7:
								carr_Turis();
							break;	
				 	 }
				 	 
				 }while(facultad > 7);
	   }
	//funcion principal 
	int main() 		{
				system("cls");
				system("color 2");
			int opc1;
			
			cout<<"\n\n\n\n\n\n\n\n\n\n";
			cout<<"\t\t\t _______________________________________________________________\n";
			cout<<"\t\t\t|\t\t\t\t\t\t\t\t|\n";
			cout<<"\t\t\t|\t\t\tBIENVENIDOS ITSCSERVICE\t\t\t|\n";
			cout<<"\t\t\t|_______________________________________________________________|\n";
			Sleep (2500);
			system("cls");
		//login	
	do {
	system("cls");
			cout<<"\t\t\t\t\t\tITSCSERVICE";
			cout<<"\n\n";
			cout<<"\t\t\t _______________________________________________________________\n";
			cout<<"\t\t\t|\t\t\t\t\t\t\t\t|\n";
			cout<<"\t\t\t|\t\t\t1.INGRESAR\t\t\t\t|\n";
			cout<<"\t\t\t|\t\t\t2.REGISTRARSE\t\t\t\t|\n";
			cout<<"\t\t\t|_______________________________________________________________|\n";
			cout<<"\t\t\tIngrese la opcion: "; cin>>opc1;
} while (opc1 > 2);
			switch (opc1){
				case 1:
					system("cls");
					cin.ignore(256, '\n');
					login();		
				break;
					
				case 2:
						Registro();
						system ("cls");
						cout<<"\t\t\tPARA VERIFICAR QUE LA CUENTA SE A CREADO CORRECTAMENTE DEBE LOGIARSE.";
						Sleep (2500);
						system("cls");
						cin.ignore(256, '\n');
						login();	
				break;
			}
			int opciones;
				cout<<"\n\n";
				cout<<"\t\t1. REGRESAR AL INICIO.\n";
				cout<<"\t\t2. SALIR.\n";
				cout<<"\tDigite su opcion: ";cin>>opciones;
				
				if(opciones == 1){
					main();
				} 
				if (opciones == 2){
					cout<<"\n\n";
						cout<<"\t\t\tGracias por utilizar nuestro servicios.";
						Sleep(2000);
							exit(0);
				}
		}
		//artes
		void carr_Artes(){
			int pensum;
				 			do{
							 system("cls");
				 			FILE *artes = fopen ("Artes.txt", "r");
				 			int se;
				 			while ((se = fgetc(artes)) != EOF){
				 				putchar(se);
							 }
							 cout<<"\n-------------------------------------------------------------------\n";
							 cout<<"\nQUE PENSUM DESEA USTED VER: ";
							 cin>>pensum;
						
										switch(pensum){
											case 1:
											system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Artes\\PensumDisenoGrafico.pdf");
												break;
											case 2:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Artes\\PensumDisenoInteriores.pdf");
												break;
											case 3:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Artes\\PensumDisenoModa.pdf");
												break;
											case 4:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Artes\\PensumEventos.pdf");
												break;
											case 5:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Artes\\PensumFotografia.pdf");
												break;
											case 6:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Artes\\PensumIndustriaDelMueble.pdf");
												break;
								}
								
							}while (pensum > 7);
							string desicion;
								char s[]= "s";
								char n[] = "n";
									cout<<"\n\n";
									cout<<"Volver al menu (S o N): ";
									cin>> desicion;
										if (desicion == s ){
											MenEst();
										} 
										if (desicion == n){
											cout<<"\n\n";
											cout<<"\t\t\tGracias por utilizar nuestro servicios.";
											Sleep(2000);
											exit(0);
										}
		}
		//Construccion
		void carr_Const(){
									int pensum;
								do{
							 system("cls");
				 			FILE *constr = fopen ("Construccion.txt", "r");
				 			int con;
				 			while ((con = fgetc(constr)) != EOF){
				 				putchar(con);
							 }
							 cout<<"\n-------------------------------------------------------------------\n";
							 cout<<"\nQUE PENSUM DsESEA USTED VER: ";
							 cin>>pensum;
						
										switch(pensum){
											case 1:
											system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Construccion\\PensumConstruccion.pdf");
												break;
								}
								
							}while (pensum > 1);
							string desicion;
								char s[]= "s";
								char n[] = "n";
									cout<<"\n\n";
									cout<<"Volver al menu (S o N): ";
									cin>> desicion;
										if (desicion == s ){
											MenEst();
										} 
										if (desicion == n){
											cout<<"\n\n";
											cout<<"\t\t\tGracias por utilizar nuestro servicios.";
											Sleep(2000);
											exit(0);
										}
		}
		
		//electromecanica
		void carr_Electrom(){
			int pensums;
									do{
							 system("cls");
				 			FILE *eletr = fopen ("Electromecanica.txt", "r");
				 			int ele;
				 			while ((ele = fgetc(eletr)) != EOF){
				 				putchar(ele);
							 }
							 cout<<"\n-------------------------------------------------------------------\n";
							 cout<<"\nQUE PENSUM DESEA USTED VER: ";
							 cin>>pensums;
						
										switch(pensums){
											case 1:
											system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Electromecanica\\PensumElectricidad.pdf");
												break;
											case 2:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Electromecanica\\PensumElectronica.pdf");
												break;
											case 3:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Electromecanica\\PensumMecanicaAutomotriz.pdf");
												break;
											case 4:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Electromecanica\\PensumRefrigeracion.pdf");
												break;
								}
								
							}while (pensums > 4);
							string desicion;
								char s[]= "s";
								char n[] = "n";
									cout<<"\n\n";
									cout<<"Volver al menu (S o N): ";
									cin>> desicion;
										if (desicion == s ){
											MenEst();
										} 
										if (desicion == n){
											cout<<"\n\n";
											cout<<"\t\t\tGracias por utilizar nuestro servicios.";
											Sleep(2000);
											exit(0);
										}
		}
		
		//Industrial
		void carr_Indust(){
										int pensums;
									do{
							 system("cls");
				 			FILE *ind = fopen ("Industrial.txt", "r");
				 			int in;
				 			while ((in = fgetc(ind)) != EOF){
				 				putchar(in);
							 }
							 cout<<"\n-------------------------------------------------------------------\n";
							 cout<<"\nQUE PENSUM DESEA USTED VER: ";
							 cin>>pensums;
						
										switch(pensums){
											case 1:
											system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Industrial\\PensumLogistica.pdf");
												break;
											case 2:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Industrial\\PensumManufactura.pdf");
												break;
								}
								
							}while (pensums > 2);
							string desicion;
								char s[]= "s";
								char n[] = "n";
									cout<<"\n\n";
									cout<<"Volver al menu (S o N): ";
									cin>> desicion;
										if (desicion == s ){
											MenEst();
										} 
										if (desicion == n){
											cout<<"\n\n";
											cout<<"\t\t\tGracias por utilizar nuestro servicios.";
											Sleep(2000);
											exit(0);
										}
		}
		//Informatica
		void carr_Inf(){
			int pensums;
									do{
							 system("cls");
				 			FILE *info = fopen ("Informatica.txt", "r");
				 			int inft;
				 			while ((inft = fgetc(info)) != EOF){
				 				putchar(inft);
							 }
							 cout<<"\n-------------------------------------------------------------------\n";
							 cout<<"\nQUE PENSUM DESEA USTED VER: ";
							 cin>>pensums;
						
										switch(pensums){
											case 1:
											system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Informatica\\PensumAdministracionRedes.pdf");
												break;
											case 2:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Informatica\\PensumDesarrolloSoftware.pdf");
												break;
											case 3:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Informatica\\PensumSoporteInformatico.pdf");
												break;
								}
								
							}while (pensums > 3);
							string desicion;
								char s[]= "s";
								char n[] = "n";
									cout<<"\n\n";
									cout<<"Volver al menu (S o N): ";
									cin>> desicion;
										if (desicion == s ){
											MenEst();
										} 
										if (desicion == n){
											cout<<"\n\n";
											cout<<"\t\t\tGracias por utilizar nuestro servicios.";
											Sleep(2000);
											exit(0);
										}
		}
		//Enfermeria
		void carr_salud(){
			int pensums;
									do{
							 system("cls");
				 			FILE *sal = fopen ("Salud.txt", "r");
				 			int sa;
				 			while ((sa = fgetc(sal)) != EOF){
				 				putchar(sa);
							 }
							 cout<<"\n-------------------------------------------------------------------\n";
							 cout<<"\nQUE PENSUM DESEA USTED VER: ";
							 cin>>pensums;
						
										switch(pensums){
											case 1:
											system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Salud\\PensumEnfermeria.pdf");
												break;
											case 2:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Salud\\PensumHigieneDental.pdf");
												break;
											case 3:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Salud\\PensumImagenesMedicas.pdf");
												break;
											case 4:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Salud\\PensumMecanicaDental.pdf");
												break;
								}
								
							}while (pensums > 4);
							string desicion;
								char s[]= "s";
								char n[] = "n";
									cout<<"\n\n";
									cout<<"Volver al menu (S o N): ";
									cin>> desicion;
										if (desicion == s ){
											MenEst();
										} 
										if (desicion == n){
											cout<<"\n\n";
											cout<<"\t\t\tGracias por utilizar nuestro servicios.";
											Sleep(2000);
											exit(0);
										}
		}
		//Turismo
		void carr_Turis(){
			int pensums;
									do{
							 system("cls");
				 			FILE *tur = fopen ("Turismo.txt", "r");
				 			int tu;
				 			while ((tu = fgetc(tur)) != EOF){
				 				putchar(tu);
							 }
							 cout<<"\n-------------------------------------------------------------------\n";
							 cout<<"\nQUE PENSUM DESEA USTED VER: ";
							 cin>>pensums;
						
										switch(pensums){
											case 1:
											system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Turismo\\PensumAlimentosBebidas.pdf");
												break;
											case 2:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Turismo\\PensumAlojamientoTuristico.pdf");
												break;
											case 3:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Turismo\\PensumGastronomia.pdf");
												break;
											case 4:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Turismo\\PensumInformacionTuristica.pdf");
												break;
											case 5:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Turismo\\PensumIntermediacionTuristica.pdf");
												break;
											case 6:
												system("C:\\Users\\rober\\Desktop\\Proyecto\\itsc\\Turismo\\PensumPanaderiaRepoteria.pdf");
												break;
								}
								
							}while (pensums > 6);
							string desicion;
								char s[]= "s";
								char n[] = "n";
									cout<<"\n\n";
									cout<<"Volver al menu (S o N): ";
									cin>> desicion;
										if (desicion == s ){
											MenEst();
										} 
										if (desicion == n){
											cout<<"\n\n";
											cout<<"\t\t\tGracias por utilizar nuestro servicios.";
											Sleep(2000);
											exit(0);
										}
		}
		//menu administrador
		void AdmMenu(){
			system("cls");
			int ver;
			while (ver > 3){
			cout<<"\t\t\t******** BIENVENIDO *********";
			cout<<"\n\n";
			cout<<"\t1. Ver Regisro.";
			cout<<"\n\t2. Editar Registro.";
			cout<<"\n\t3. crear test.";
			cout<<"\n\nDigite la opcion: ";
			cin>>ver;
		}
				switch (ver){
					case 1:
						AdmVerReg();
						break;
					case 2:
						Editar();
						break;
					case 3:
						crear_txt();
						break;
				}
			
		}
		//Adm ver registro
		
			void AdmVerReg(){
				char si[] = "s";
				char no[] = "n";
				string volv;
							system("cls");
				 			FILE *verR = fopen ("Registro.txt", "r");
				 			int re;
				 			while ((re = fgetc(verR)) != EOF){
				 				putchar(re);
							 }
							 
					while ((volv != si )|| (volv != no)){
					
					cout<<"\n\n Desea volver al menu principal de Administrador (s o n): ";
					cin>>volv;
					
					if (volv == si){
						
						AdmMenu();
					}
					
					if (volv == no){
						cout<<"\n\n\t\t\tGracias por Utilizar Nuestros servicios.";
						exit(1);
					}
					else {
						cout<<"caracter invalido '"<<volv<<"' intente de nuevo.";
							Sleep(2000);
					}
					
					}
			}
	
	void Editar(){
		
		string contenido;
  string contenido2;
		cout << "Ingresa el nombre del archivo que quieres modificar(sin el .txt): ";
        cin.ignore();
        getline(cin, contenido2);
        contenido2 += ".txt";

        cout << "Ingresa el NUEVO contenido del archivo: ";
        getline(cin, contenido);
        ofstream fs(contenido2.c_str(), ios::app);
        fs << contenido << endl;
        fs.close();
        cout << "El archivo ha sido modificado correctamente" << endl;
        system("pause");
	}
	
	void crear_txt(){
		system("cls");
		string most;
		string contenido2;
		int contador;
		string prg, opcionA, opcionB, opcionC, opcionD;
		contador = 1;
				cout << "Ingresa el nombre del archivo que quieres crear(sin el .txt): ";
        cin.ignore();
        getline(cin, contenido2);
        contenido2 += ".txt";
        ofstream fs(contenido2.c_str(), ios::app);
		while (contador <= 10){
			cout<<"Digite la pegunta"<<contador<<": ";
			getline(cin, prg);
			cout<<"opcion A: ";
			getline(cin, opcionA);
			cout<<"opcion B: ";
			getline(cin, opcionB);
			cout<<"opcion C: ";
			getline(cin, opcionC);
			cout<<"opcion D: ";
			getline(cin, opcionD);
			//guardadno en el archivo
			fs<<contador<<"."<<prg<<"\n\t"<<"A)."<<opcionA<<"\n\t"<<"B)."<<opcionB<<"\n\t"<<"C)."<<opcionC<<"\n\t"<<"D)."<<opcionD<<endl;
			contador++;
		}
        fs.close();
        
        cout << "El archivo ha sido creado correctamente" << endl;
        system("pause");
        
        cout<<"Mostrar el test creado (s o n): ";
        getline(cin, most);
        
        if (most == "s" || most == "S"){
        	ifstream see(contenido2.c_str(), ios::in);
        	while(!see.eof()){
        		see>>prg>>opcionA>>opcionB>>opcionC>>opcionD;
			}
			see.close();
		}
		if (most == "n" || most == "N"){
			exit(1);
		}
	}
