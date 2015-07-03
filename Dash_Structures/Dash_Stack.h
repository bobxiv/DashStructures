#pragma once

#ifndef DASH_STACK

#define DASH_STACK


#ifndef NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS
_BEGIN_DASH_STRUCTURES_NAMESPACE
#endif


	template< class _Tp , class _Container = DVector<_Tp> >
class DStack{
private:

_Container* C;

public:

	typedef _Tp value_type;
	typedef typename _Container::size_type size_type;
	typedef typename _Container container_type;

	DStack(){
		C= new _Container();
		}

	_Tp& top(){
		return (*C).back();
		}

	void push(const _Tp& __V ){
		(*C).push_back(__V);
		}

	void pop(){
		(*C).pop_back();
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