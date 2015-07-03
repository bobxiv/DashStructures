#pragma once

#ifndef DASH_MAPV

#define DASH_MAPV

#include "Utility.h"

#include "CommonTypes.h"

#include "Dash_Vector.h"


#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
	_BEGIN_DASH_STRUCTURES_NAMESPACE
#else
//Clave, como ya compile DList en Dash_It_All luego tengo que acceder a DList por medio del 
//espacio de nombres de las listas y vectores en Dash_It_All...
//Pero si no se utiliza el unico include este namespace no seria nesesario y el include 
//de arriba de Dash_List seria nesesario
//			IMPORTENTE: como esta linea ya estaba en Dash_Map_L, que esta antes que este .h en 
//			Dash_It_All, luego no es nesesario esta linea, pero s ela deja porque no afecta
//			el funcionamiento y si se cambia de orden en Dash_It_All seguiria andando
using namespace Dash_Structures::Basic_ADT;

#endif





	template<class _key,class _value>
class DMapV{
public:

	typedef DPair<_key,_value> value_type;
	typedef _key key_type;
	typedef typename DVector< DPair< _key,_value> >::size_type size_type;
	typedef typename DVector< DPair<_key,_value> >::iterator iterator;
	typedef typename DVector< DPair<_key,_value> >::const_iterator const_iterator;

	
private:

	typedef typename DVector< DPair<_key,_value> > _vector;

	_vector V;

	iterator lower_bound( _key k){
	
		int p= 0;
		int q= V.size();

		if( (!q) || V[p].first > k ){
			return V.begin();
			}

		int aux;

		while( (q-p) > 1 ){
			aux= (p+q)/2;

			if( V[aux].first > k ){
				q= aux;
				}else if( V[aux].first < k){
					p= aux;
				}else{
					return &(V[aux]);
					}
			}

		if( V[p].first == k ){
			return &(V[p]);
			}else{
				return &(V[q]);
			}
	
		}


public:

	DMapV(){}

	iterator begin(){
		return V.begin();
		}

	iterator end(){
		return V.end();
		}

	bool empty(){
		return V.empty();
		}

	size_type size(){
		return V.size();
		}

	iterator find(_key k){
		iterator p = lower_bound(k);

		if( p != V.end() && (*p).first == k){ 
			return p;
			}

		return V.end();

		}

		

	_value& operator[](_key k){

		iterator p = find(k);

		if( p == V.end() ){
			p= lower_bound(k);

			p = V.insert(p, value_type(k,_value() ) );

			return (*p).second;
			}

		return (*p).second;

		}




	};


#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_END_DASH_STRUCTURES_NAMESPACE
#endif




#endif