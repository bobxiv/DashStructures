#pragma once

#ifndef DASH_VECTOR

#define DASH_VECTOR

#include "CommonTypes.h"

#include "Utility.h"

#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_BEGIN_DASH_STRUCTURES_NAMESPACE
#endif

//Allocador para clase vector
//Se encarga de la peticion de memoria al sistema y el reintegro de la memoria al sistema
//Posee los miembros claves para el almacenamiento de datos
	template< class _Tp >
class DVector_alloc{
protected:

	//puntero al principio del vector
	_Tp* _start;
	//puntero al final del vector
	_Tp* _finish;
	//puntero al final del espacio reservado para el vector
	_Tp* _end_of_storage;

	_Tp* Allocate( const size_t n ){
			return new _Tp[n];
		}
	void DeAllocate( const _Tp* ptr ){
			delete[] ptr;//siempre va a ser un puntero a arreglo, es lo que abra 
			//en el vector
		}

public:

	DVector_alloc( ): _start( 0 ) , _finish( 0 ) , _end_of_storage( 0 ){}


	};


//Esta clase se encarga de la comunicacion en la construccion de nuevas instancias
//y tambien de la destruccion de instancias. Pero solo reserva el espacio en la instancia, no 
//inicializa la posicion del ultimo elemento
template< class _Tp >
class BaseDVector: public DVector_alloc<_Tp>{
public:

	BaseDVector(){
			this->_start= this->Allocate(0);
			this->_finish=this->_start;
			this->_end_of_storage = this->_start;
		}

	BaseDVector( const size_t n ){
			this->_start= this->Allocate(n);
			this->_finish=this->_start;//tener en cuenta que en el constructor del hijo se lleva a
									   //_start a la misma posicion que _end_of_storage, asi funciona en la stl
			this->_end_of_storage = this->_start+n;

		}

	~BaseDVector(){
			this->DeAllocate( this->_start );

		}

	};

template< class _Tp >
class DVector:protected BaseDVector<_Tp>{
public:

	typedef _Tp type_value;
	typedef _Tp* pointer;
	typedef const _Tp* const_pointer;
	//este es el unico constructor que no posee iterador como clase, sino que como puntero
	typedef _Tp* iterator;
	typedef const _Tp* const_iterator;
	typedef _Tp& reference;
	typedef const _Tp& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	DVector(){}
	
	DVector(const size_type n ):BaseDVector<_Tp>(n){
		
		this->_finish+=n;//llevo el final a la mismaposicion que _end_of_storage
		
		Fill(this->_start,this->_finish,type_value());
		

		}

	DVector(const size_type n , const_reference val ):BaseDVector<_Tp>(n){
			
			this->_finish+=n;

			Fill(this->_start,this->_finish,val);



		}

	iterator begin(){
		return this->_start;
		}

	const_iterator begin() const{
		return this->_start;
		}

	iterator end(){
		return this->_finish;
		}

	const_iterator end() const{
		return this->_finish;
		}

	size_type size() const{
		return size_type(this->_finish-this->_start);
		}

	size_type size_max() const{
			return (-1)/sizeof(type_value);
		}

	bool empty() const{
		return ( this->_start == this->_finish );
		}

	reference operator[](int n){
			return *(this->_start+n);
		}

	const_reference operator[](int n) const{
			return *(this->_start+n);
		}

	reference at(int n) throw (OUT_OF_RANGE){
		if( (this->size()-1) < n ){
				throw OUT_OF_RANGE();
			}
			return *(this->_start+n);
		}

	const_reference at(int n) const throw (OUT_OF_RANGE){
			if( (this->size()-1) < n ){
				throw OUT_OF_RANGE();
			}
			return *(this->_start+n);
		}

	void push_back(const _Tp& val ){
		if( this->_finish != this->_end_of_storage ){
			*(this->_finish)=val;
			this->_finish++;
		}else{
			insert(this->_finish , val);	
			}
		
		}
	void push_back(  ){
		if( this->_finish != this->_end_of_storage ){
			*(this->_finish)=type_value();
			this->_finish++;
		}else{
			insert(this->_finish , val);	
			}
		
		}

	void pop_back(  ){
		this->_finish--;
		}

	size_type capacity() const{
		return (this->_end_of_storage-this->_start);
		}

	void reserve(int n){
		if( capacity() < n ){
		pointer aux = this->_start;
		int size=this->_finish-this->_start;

		this->_start = Allocate( n );
		
		Copy(aux,this->_finish, this->_start );


		this->_finish = this->_start + size;
		this->_end_of_storage = this->_start + n;

		DeAllocate( aux );

			}

		return ;

		}

	reference front(){
		return *(this->_start);
		}

	const_reference front() const{
		return *(this->_start);
		}

	reference back(){
		return *(this->_finish-1);
		}

	const_reference back() const{
		return *(this->_finish-1);
		}

	iterator insert( iterator p, const_reference val){
		if( this->_finish != this->_end_of_storage ){

			iterator aux=this->_finish;//postultimo iterador
			iterator aux2=(this->_finish-1);//ante-postultimo iterador
			while( aux != p ){
				(*aux)=*(aux2);
				aux--;
				aux2--;
				}

			*p=val;
			this->_finish++;

			return p;

			}

		//como me va a invalidar p hago
		int forware = p - this->_start;

		if( this->_end_of_storage == this->_start){
		reserve( 5 );//esto es lominimo que por defecto tendra un vector
			}else{
		//aumento el almacen en el dobledel espacio anterior
		reserve( (this->_end_of_storage-this->_start)*2 );
			}

		//recupero p mapeado a la nueva terna de datos
		p= this->_start + forware;

			iterator aux=this->_finish;//postultimo iterador
			iterator aux2=(this->_finish-1);//ante-postultimo iterador
			while( aux != p ){
				(*aux)=*(aux2);
				aux--;
				aux2--;
				}


			*p=val;
			this->_finish++;

			return p;

		}


	iterator erase(iterator __p){

		iterator aux = __p;
		iterator aux2 = (++__p);

		while( aux2 != this->end() ){
			(*aux) = (*aux2);
			aux++;
			aux2++;
			}

		this->_finish--;

		return __p;

		}

	
	};




#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_END_DASH_STRUCTURES_NAMESPACE
#endif


#endif