// Dash_Structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <set>
#include <list>
#include <map>

#include <limits>

#include "Dash_It_All.h"
#include "Dash_Algorithm2.h"

//No tengo ganas de poner el nombre de espacios siempre


namespace Dash_Structures{

using namespace Basic_ADT;
using namespace Adaptor_ADT;
using namespace Map_ADT;
using namespace Tree_ADT;

	}

bool listados(int val){
	switch(val){
		case 7:{
			return true;
			break;
			}
		default:{
			return false;
			break;
			}
		}

	}


//#include <vector>

#include <queue>


bool odd( int val){
	if( val % 2 ){
		return true;
		}
	return false;

	}

void Tree_count( Dash_Structures::DTree<int> &A , Dash_Structures::_Tree_Iterator<int> p, int& cant){

	//cant debe entrar la primera vez como 0

	if( p == A.end() ){
		return;	
		}

	cant++;

	Dash_Structures::DTree<int>::iterator q = p.lchild();

	while( q != A.end() ){
		Tree_count( A,q,cant);
		q++;
		}

	

	}

bool ABScmp(const int a, const int b ){
	return ( abs(a) < abs(b) );


	}

using namespace AED_Parciales;

int _tmain(int argc, _TCHAR* argv[])
	{
/*
Dash_Structures::DVector<int> A(5);
		for(int i=0;i<A.size();i++){
		std::cout<<A[i]<<" ";

			}std::cout<<"\n\n\n";

	int h=A.capacity();
	int k=A.size();
	int y=A.front();

	A.push_back(2);

	h=A.capacity();
	k=A.size();

	Dash_Structures::DVector<int>::iterator p = A.begin();
	std::vector<int> N(3);

		for(int i=0;i<N.size();i++){
		std::cout<<N[i]<<" ";

			}std::cout<<"\n\n\n";

	try{

		A.at(200);		
		
		}catch( Dash_Structures::OUT_OF_RANGE E)
			{
			std::cout<<E.what()<<"\n\n";

			}


	A.insert(p,15);
		A.insert(A.end(),15);
			A.insert(A.end(),15);
				A.insert(A.end(),15);
					A.insert(A.end(),15);

	int yk=A.size();

	for(int i=0;i<A.size();i++){
		std::cout<<A[i]<<" ";

		}

	std::cout<<"\n\n";



	Dash_Structures::DList<int> Dash;
//Dash.push_front(2);
	Dash.insert(Dash.begin(),2);

		Dash.insert(Dash.begin(),3);

			Dash.insert(Dash.begin(),4);

				Dash.insert(Dash.begin(),5);

				Dash.push_back(75);
				Dash.push_back(85);
				Dash.push_back(6);



	Dash_Structures::DList<int>::iterator point= Dash.begin();
	while(point != Dash.end()){
		std::cout<<(*point)<<" ";

		point++;
		}

	std::cout<<"\nEl tamano es: "<<Dash.size()<<"\n\n";


	std::cout<<"\n"<<"Ahora probando a eliminar elemento queda:\n";

				Dash.erase(--Dash.end());

				Dash.erase( (Dash_Structures::_List_Node<int>*)Dash.begin()._M_node->_M_next->_M_next->_M_next );


	point= Dash.begin();
	while(point != Dash.end()){
		std::cout<<(*point)<<" ";

		point++;
		}

	std::cout<<"\nEl tamano es: "<<Dash.size()<<"\n\n";
double* jkjk= new double[500];


Dash_Structures::DMapL<int,int> mm;

mm[500] = 1600;

mm[12] = 70;

mm[5] = 80;

mm[1] = 10;

mm.insert( Dash_Structures::DMapL<int,int>::value_type(600,3000));

mm.insert( Dash_Structures::DMapL<int,int>::value_type(12,140));

mm[1]=5;

mm[2]=10;

Dash_Structures::DMapL<int,int>::iterator pun = mm.begin();

while( pun != mm.end() ){

	std::cout<<"El indice es: "<<(*pun).first<<" El valor es: "<< (*pun).second<<'\n';

	pun++;
	}

std::cout<<"\nHay "<<mm.size()<<" elementos en el mapa";

std::cout<<"\n\n";

Dash_Structures::DMapV<int,int> vv;

vv[2]=15;

vv[60]= 10000;

vv[110]=23;
vv[1]=65;

//vv[110]=46;
vv[17]=18;
vv[90]=2;

vv[192]=180;
vv[1000]=888;
vv[1001]=888;
vv[10000]=777777;
vv[10001]=777777;
vv[10002]=777777;
vv[10003]=777777;
vv[10004]=777777;
vv[10005]=777777;
vv[10006]=777777;
vv[10007]=777777;
vv[10008]=777777;
std::list<int>::iterator hhh;



std::cout<<"\n\n"<<vv.size()<<"\n\n";



Dash_Structures::DMapV<int,int>::iterator punterito = vv.begin();

while( punterito != vv.end() ){

	std::cout<<"El indice es: "<<(*punterito).first<<" El valor es: "<< (*punterito).second<<'\n';

	punterito++;
	}

std::cout<<"\n\n\n";

Dash_Structures::DQueue<int> queue;

queue.push(4);
queue.push(5);
queue.push(6);
queue.push(7);
queue.push(8);
queue.push(9);

while(!queue.empty()){

	std::cout<< "Un valor es: "<<queue.front()<<'\n';
	queue.pop();

	}

std::cout<<"\n\n";

Dash_Structures::DStack<int > stack;

stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);
stack.push(5);
stack.push(6);

while(!stack.empty()){

	std::cout<< "Un valor es: "<< stack.top() <<'\n';
	stack.pop();

	}

std::cout<<"\n\n";


Dash_Structures::DTree<int> Tr;

Tr.insert( Tr.begin(), 5);
Dash_Structures::DTree<int>::iterator q = Tr.insert( (Tr.begin()).lchild(), 10);

q = Tr.insert( q , 15);
q = Tr.insert( q , 20);
q = Tr.insert( q , 25);
q = Tr.insert( q , 30);

int cant =0;
Tree_count(Tr,Tr.begin(),cant );
std::cout<<"\n\nEl arbol tiene " << cant << " nodos, contando la raiz\n";

	
Dash_Structures::DBTree<int> Bin;

Dash_Structures::DBTree<int>::iterator punt;

punt = Bin.insert( Bin.begin() , 8 );
Dash_Structures::DBTree<int>::iterator kkk =Bin.insert( punt.left_child() , 7 );
Bin.insert( kkk.left_child() , 9 );
Bin.insert( kkk.right_child() , 2 );
punt = Bin.insert( punt.right_child() , 3 );
Bin.insert( punt.right_child() , 1 );
punt = Bin.insert( punt.left_child() , 9 );
punt = Bin.insert( punt.left_child() , 6 );
Bin.insert( punt.left_child() , 1 );



std::string lisp=std::string();
Bin.Lisp_print(lisp);

puts(lisp.c_str() );

punt = Bin.find( Bin.begin() , 6 );

Dash_Structures::DBTree<int>::iterator kert;
Dash_Structures::DBTree<int> KOO(Bin);
kert = KOO.begin();
kert = kert.left_child();
KOO.erase( kert );
lisp= "";
KOO.Lisp_print( lisp);
puts(lisp.c_str()); 

std::cout<<"Verificion de que si el arbolde arriba es < a si mismo, es decir A < A: "
<< (bool)Dash_Structures::AED_Parciales::menor( Bin , Bin ) <<"\n\n"; 
std::cout<<"Verificion de que el el segundo arbol es < que el primero, es decir B < A: "
<< (bool)Dash_Structures::AED_Parciales::menor( KOO , Bin ) <<"\n\n"; 

Dash_Structures::DList<int> joliet;
Dash_Structures::AED_Parciales::list_if( Tr , odd , joliet );
Dash_Structures::DList<int>::iterator yui =joliet.begin();
while( yui != joliet.end() ){
	std::cout<< " " << *yui;
	yui++;
	}

lisp = "";


int la_altura=0;
Dash_Structures::AED_Parciales::Bheight( Bin , la_altura );

std::cout<<"La altura de el arbol es : "<< la_altura<<"\n\n";


Dash_Structures::AED_Parciales::Bremove_leaf( Bin , 10 );


Dash_Structures::AED_Parciales::Bremove_if( Bin , listados );


Dash_Structures::AED_Parciales::Bprune_odd( Bin );


Bin.Lisp_print(lisp);

puts( lisp.c_str() );

int jujuju =0;
Dash_Structures::AED_Parciales::Bcount_if( KOO, odd , jujuju );
std::cout<<"Cuenta alla arriba en el arbol qeu se dijo B  cuantos nodos impares tiene: "
<< jujuju<<"\n\n";

std::cout<<"Preorden\n";
lisp="";
KOO.prev_ord(lisp);

puts(lisp.c_str());

std::cout<<"Entreorden\n";
lisp="";
KOO.entre_ord(lisp);

puts(lisp.c_str());

std::cout<<"Postorden\n";
lisp="";
KOO.post_ord(lisp);

puts(lisp.c_str());

std::map<int , std::list<int> > pent;

Dash_Structures::AED_Parciales::list_nodes_per_level( Tr, pent );


std::list<int>::iterator josesito = (pent[0]).begin();
while( josesito != (pent[0]).end() ){
	std::cout<< *josesito<<" ";
	josesito++;
	}
std::cout<<"\n";
josesito = (pent[1]).begin();
while( josesito != (pent[1]).end() ){
	std::cout<< *josesito<<" ";
	josesito++;
	}

*/

std::vector<int> julia;
julia.push_back(9);
julia.push_back(8);
julia.push_back(0);
julia.push_back(4);
julia.push_back(-1);
julia.push_back(1);
julia.push_back(500);
julia.push_back(-6);
julia.push_back(5);
julia.push_back(1);
std::vector<int>::iterator first = julia.begin();
std::vector<int>::iterator last = julia.end();
//std::vector<int>::iterator dif = (last-first);
//std::cerr<<*first<<" "<<*(first+1);
Dash_Structures::Sort_Algorithms::quick_sort<std::vector<int> , 
std::less<int > >( first , last , std::less<int>() );

//std::cerr<<"\n\n\n";
for( int i=0;i<julia.size();i++)
	std::cerr<<julia[i]<<" ";


std::vector< std::set<int>> G(4);
G[0].insert(1);
G[0].insert(2);

G[1].insert(0);
G[1].insert(2);

G[2].insert(0);
G[2].insert(1);
G[2].insert(3);

G[3].insert(2);

std::vector< std::set<int> > L;
mklayer( G , 0 , L);

std::cerr<<"\n\nLos niveles del grafo empezando por 0 estan formadors por...\n";
for( int i=0; i < L.size() ;i++ ){

	std::set<int>::iterator it=L[i].begin();
	std::cerr<<"El nivel "<<i<<" del grafo esta formado por:\n";
	while( it != L[i].end() ){
		std::cerr<<(*it)<<" ";
		it++;
		}
	std::cerr<<"\n";

	}

std::cout<<"\n\n";

std::list<int> Li;
Li.push_back(9);
Li.push_back(8);
Li.push_back(0);
Li.push_back(4);
Li.push_back(-1);
Li.push_back(1);
Li.push_back(500);
Li.push_back(-6);
Li.push_back(5);
Li.push_back(1);

Dash_Structures::Sort_Algorithms::merge_sort( Li , std::less<int>() );

std::cerr<<"\n\nLa lista ordenada por merge_sort da:\n";
std::list<int>::iterator y=Li.begin();
while( y != Li.end() ){

	std::cerr<<*y<<" ";
	y++;
	}

std::cerr<<"\n\n\n";


std::list<int> lista;
lista.push_back(-3);
lista.push_back(5);
lista.push_back(3);
lista.push_back(2);
lista.push_back(-2);
lista.push_back(1);
lista.push_back(2);
lista.push_back(-3);

lista.sort( ABScmp );

std::list<int>::iterator k= lista.begin();
std::cerr<<"La lista ordenada con la relacion da:\n";
while( k != lista.end() ){

	std::cerr<<*k<<" ";
	k++;

	}

std::cerr<<"\n\n\n";



std::list<std::set<int>> Lk;

std::set<int> A;
A.insert(0);//se repite
A.insert(2);
A.insert(4);//se repite
A.insert(5);//se repite
std::cerr<<"El conjunto A posee:\n";
std::set<int>::iterator one = A.begin();
while( one != A.end() ){

	std::cerr<<*one<<" ";
	one++;

	}std::cerr<<"\n";
std::set<int> B;
B.insert(1);
B.insert(3);
B.insert(5);//se repite
B.insert(0);//se repite
std::cerr<<"El conjunto B posee:\n";
std::set<int>::iterator two = B.begin();
while( two != B.end() ){

	std::cerr<<*two<<" ";
	two++;

	}std::cerr<<"\n";
std::set<int> C;
C.insert(0);//se repite
C.insert(8);
C.insert(4);//se repite
std::cerr<<"El conjunto A posee:\n";
std::set<int>::iterator three = C.begin();
while( three != C.end() ){

	std::cerr<<*three<<" ";
	three++;

	}std::cerr<<"\n";

//deberia salir: 1 2 3 8


Lk.push_back(A);
Lk.push_back(B);
Lk.push_back(C);

std::set<int> out;

simetric_diff_1( Lk , out);

std::cerr<<"\n\nLa diferencia simetrica de los conjuntos es:\n";

std::set<int>::iterator i = out.begin();
while( i != out.end() ){

	std::cerr<<*i<<" ";
	i++;

	}
std::cerr<<"\n\n";

std::map<int,std::set<int>> Am;

Am[1].insert(2);Am[1].insert(5);Am[1].insert(7);
Am[2].insert(1);
Am[5].insert(1);Am[5].insert(6);
Am[6].insert(5);
Am[7].insert(1);

Am[3].insert(4);
Am[4].insert(3);

std::set<int> K;
connected_to( Am , 4 , K);

std::cerr<<"\nLa parte connexa es:\n";
std::set<int>::iterator ik = K.begin();
while( ik != K.end() ){

	std::cerr<<*ik<<" ";
	ik++;

	}

std::cerr<<"\n\n\n";

std::set<int> Hn;
Hn.insert(1);
Hn.insert(-1);
Hn.insert(1);
Hn.insert(-2);
Hn.insert(2);
Hn.insert(3);

std::list<std::set<int>> Uh;

eq_class( Hn , Uh , ABScmp );

std::cerr<<"\nLas clases dan:\n";
std::list<std::set<int>>::iterator nn = Uh.begin();
while( nn != Uh.end() ){

	std::set<int>::iterator mm = (*nn).begin();
	while( mm != (*nn).end() ){

	std::cerr<<*mm<<" ";
	mm++;

	}
	std::cerr<<"\n";
	nn++;

	}

std::cerr<<"\n\n\n";

double yuv = 1;
std::cerr<< std::numeric_limits<long long>::max() <<"  "<< UINT_MAX<< std::endl;
/*
enum h{ A , B , C ,
	int operator++(h a){
		return a;
	}
	
	
	}
*/
/*
int sin=0;
fpr(int y=0;y < 500; y++){
sin= ( pow(-1,y) * pow(x, y*2+1 ) )/(
	}
	*/
	system("pause");

	return 0;
}



