#pragma once

#ifndef DASH_QUEUE

#define DASH_QUEUE

#include "Utility.h"

#include "CommonTypes.h"

#include "Dash_Vector.h"
#include "Dash_List.h"


#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_BEGIN_DASH_STRUCTURES_NAMESPACE
#endif


	template<class _Tp,class _Container = DVector<_Tp> >
class DQueue{
private:

_Container* C;

public:

	typedef _Tp value_type;
	typedef typename _Container::size_type size_type;
	typedef typename _Container container_type;


	DQueue(){
		C= new _Container();
		}

	value_type& front(){
		return (*C).front();

		}

	void push( const value_type& __V){
		(*C).push_back(__V);
		}

	void pop(){
		(*C).erase( (*C).begin() );
		}

	bool empty(){
		return (*C).empty();
		}

	size_type size(){
		return (*C).size();
		}


	};


#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_END_DASH_STRUCTURES_NAMESPACE
#endif


#endif