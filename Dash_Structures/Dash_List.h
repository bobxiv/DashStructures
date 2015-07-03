#pragma once

#ifndef DASH_LIST

#define DASH_LIST

#include "CommonTypes.h"

#include "Utility.h"



#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_BEGIN_DASH_STRUCTURES_NAMESPACE
#endif


struct _List_Node_base{

	_List_Node_base* _M_next;
	_List_Node_base* _M_prev;

	};

	template<class _Tp>
struct _List_Node:public _List_Node_base{
	_Tp _M_data;

	};


struct _List_Iterator_base{

	typedef size_t  size_type;
	typedef ptrdiff_t difference_type;

	_List_Node_base* _M_node;

	_List_Iterator_base(){}

	_List_Iterator_base( const _List_Iterator_base& __Cp ):_M_node(__Cp._M_node){}

	_List_Iterator_base(_List_Node_base* __pN):_M_node(__pN){}
	

		bool operator==( const _List_Iterator_base& __B) const{
			
			return (this->_M_node == __B._M_node);

		}

	bool operator!=(const _List_Iterator_base& __B) const{
		
			return ( this->_M_node != __B._M_node);

		}


	};

	template<class _Tp>
struct _List_Iterator:public _List_Iterator_base{

	typedef _Tp type_value;
	typedef _Tp* pointer;
	typedef _Tp& reference;


	_List_Iterator( _List_Node<_Tp>* __N ): _List_Iterator_base(__N){};
	_List_Iterator(){};
	_List_Iterator( const _List_Iterator<_Tp>& __Cp ): _List_Iterator_base(__Cp._M_node) {};

	reference operator*() const{

		return ( ((_List_Node<_Tp>*)this->_M_node)->_M_data);
		}

	pointer operator->() const{

		return ( &( ((_List_Node<_Tp>*) this->_M_node)->_M_data) );
		}

	_List_Iterator<_Tp>& operator++(){
		this->_M_node = this->_M_node->_M_next;
		return *this;

		}

	_List_Iterator<_Tp>& operator++(int){
		_List_Iterator<_Tp> __tmp = (*this);
		this->_M_node = this->_M_node->_M_next;

		return __tmp;

		}

	_List_Iterator<_Tp>& operator--(){
		this->_M_node = this->_M_node->_M_prev;
		return *this;

		}
	
	_List_Iterator<_Tp>& operator--(int){
		List_Iterator<_Tp> __tmp = (*this);
		this->_M_node = this->_M_node->_M_prev;

		return __tmp;

		}


	};


//Allocador para clase list
//Se encarga de la peticion de memoria al sistema y el reintegro de la memoria al sistema
//Posee los miembros claves para el almacenamiento de datos
	template<class _Tp>
class DList_alloc{
protected:
	_List_Node<_Tp>* _M_node;

public:

	_List_Node<_Tp>* _M_get_node( ){
			return (new _List_Node<_Tp>);
		}

	void _M_put_node(_List_Node<_Tp>* __p){
		delete __p;
	}

		DList_alloc(){}

		DList_alloc( _List_Node<_Tp>* __V ): _M_node(__V){}

		

	};


//Esta clase se encarga de la comunicacion en la construccion de nuevas instancias
//y tambien de la destruccion de instancias. Pero solo reserva el espacio en la instancia, no 
//inicializa la posicion del ultimo elemento
	template<class _Tp>
class BaseDList:protected DList_alloc<_Tp>{
public:
	BaseDList(){
		this->_M_node = this->_M_get_node();
		this->_M_node->_M_next=this->_M_node;
		this->_M_node->_M_prev=this->_M_node;

		}


	BaseDList(BaseDList<_Tp>& __Cp):DList_alloc(__Cp._M_node){}

	BaseDList(_List_Node<_Tp>& __V):_M_node(__V){}


	~BaseDList(){
	//	clear();
		this->_M_put_node(this->_M_node);
		}

	};


	template<class _Tp>
class DList:protected BaseDList<_Tp>{
public:

	typedef _Tp value_type;
	typedef _List_Iterator<_Tp> iterator;
	typedef const _List_Iterator<_Tp> const_iterator;
	typedef _Tp* pointer;
	typedef const _Tp* const_pointer;
	typedef _Tp& reference;
	typedef const _Tp& const_reference;
	typedef _List_Node<_Tp> _Node;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;


	DList():BaseDList<_Tp>(){};

	DList( DList<_Tp>& __Cp ):BaseDList<_Tp>( (BaseDList<_Tp>)__Cp ){};

	~DList(){
		//this->clear();
		delete _M_node;
		};

	iterator begin(){
		return ((_List_Node<_Tp>*)(this->_M_node->_M_next));
		}
	
	const_iterator begin ()const{
		return (this->_M_node->_M_next);
		}

	iterator end(){
		return this->_M_node;
		}

	const_iterator end() const{
		return this->_M_node;
		}

	bool empty(){
		return (this->_M_node->_M_next == this->_M_node);
		}

	size_type size() const{
		size_type __aux=0;
		iterator __p = (_List_Node<_Tp>*)this->_M_node->_M_next;
		while( __p != (_List_Node<_Tp>*)this->_M_node ){
			__aux++;

			__p++;
			
			}

		return __aux;

		}

	size_type max_size(){
		return size_type(-1);//devuelve el entero sin signo mas grande posible
		}

	reference front(){
		return *((_List_Node)this->_M_node->_M_next->_M_data);
		}

	const_reference front() const{
		return *((_List_Node)this->_M_node->_M_next->_M_data);
		}

	reference back(){
		return *((_List_Node)this->_M_node->_M_data);
		}

	const_reference back() const{
		return *((_List_Node)this->_M_node->_M_data);
		}

	void push_front( const _Tp& __V){
		_Node* __new=new _Node;
		__new->_M_data=__V;
		__new->_M_next= this->_M_node->_M_next;
		__new->_M_prev= this->_M_node;

		this->_M_node->_M_next->_M_prev= __new;
		this->_M_node->_M_next= __new;

		}

	void push_back( const _Tp& __V){
		_Node* __new= new _Node;
		__new->_M_data=__V;
		__new->_M_next= this->_M_node;
		__new->_M_prev= this->_M_node->_M_prev;

		this->_M_node->_M_prev->_M_next= __new;
		this->_M_node->_M_prev= __new;

		}

	iterator insert(iterator __p,const _Tp& __V){
		_Node* __tmp= new _Node;
		__tmp->_M_data=__V;
		__tmp->_M_next=__p._M_node;
		__tmp->_M_prev=__p._M_node->_M_prev;

		__p._M_node->_M_prev->_M_next=__tmp;
		__p._M_node->_M_prev=__tmp;

		return __tmp;


		}

	iterator erase( iterator __p){
		__p._M_node->_M_prev->_M_next=__p._M_node->_M_next;
		__p._M_node->_M_next->_M_prev=__p._M_node->_M_prev;

		return (_List_Node<_Tp>*)__p._M_node->_M_prev;

		}


	};





#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_END_DASH_STRUCTURES_NAMESPACE
#endif

#endif