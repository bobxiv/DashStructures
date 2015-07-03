#pragma once

#ifndef DASH_MAPL

#define DASH_MAPL


#include "Utility.h"

#include "CommonTypes.h"

#include "Dash_List.h"

#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
	_BEGIN_DASH_STRUCTURES_NAMESPACE
#else
//Clave, como ya compile DList en Dash_It_All luego tengo que acceder a DList por medio del 
//espacio de nombres de las listas y vectores en Dash_It_All...
//Pero si no se utiliza el unico include este namespace no seria nesesario y el include 
//de arriba de Dash_List seria nesesario
//using namespace Dash_Structures::Basic_ADT;


#endif






	template<class _key, class _value>
class DMapL{
public:
	
	typedef DPair<_key,_value> value_type;
	typedef _key key_value;
	typedef typename DList< DPair<_key,_value> >::size_type size_type;
	typedef typename DList< DPair<_key,_value> >::iterator iterator;
	typedef typename DList< DPair<_key,_value> >::const_iterator const_iterator;
	
	
private:

	typedef typename DList< DPair<_key,_value> > _list;

	 _list L;

	iterator lower_bound(_key& k){
		iterator p = L.begin();

		while( p != L.end() ){

			if( ( (*p).first) >= k ){
				return p;

				}
			p++;

			}

		return L.end();

		}

public:

	DMapL(){}

	iterator begin(){
		return L.begin();
		}

	iterator end(){
		return L.end();
		}

	bool empty(){
		return L.empty();
		}

	size_type size(){
		return L.size();
		}

	iterator find(_key& k){
		iterator p = lower_bound(k);

		if( p!=L.end() && (( (*p).first)==k) ){
			return p;
			}

	return L.end();

		}


	_value& operator[](_key k){

		iterator p = find(k);

		if( p != L.end() ){

			return p->second;
			}

		p= lower_bound(k);

		p = L.insert( p , value_type( k,_value() ) );

		return (*p).second;
	
	}

	DPair<iterator,bool> insert( value_type val){

		DPair<iterator,bool> res;
		res.second=true;

		iterator p = find(val.first);

		if( p != L.end() ){
			res.second=false;

			p->second = val.second;

			res.first=p;
			return res;
			}

		p = L.insert(p,val);
		res.first=p;

		return res;

		}

	

	};



#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_END_DASH_STRUCTURES_NAMESPACE
#endif


#endif