#pragma once

//Encabezado que incluye todas las estructuras de datos y algoritmos de Dash_Library

//no quiero que en absolutamente todas las subcategorias este el nombre de
//espacios Dash_Structures, sino que este solo afuera
//pero si no se usa este .h para agregar todas las estructuras, luego quiero
//que todo este en Dash_Structures por separado. Esta opcion se usa solo en Dash_It_All
#define NOT_NAMESPACE_DASH_STRUCTURES_IN_ALL_CPPS

#include "stdafx.h"

namespace Dash_Structures{

	//Contiene tipos y algunos define
	#include "CommonTypes.h"

	//Utilidades Varias
	#include "Utility.h"

	//Algoritmos varios
	#include "Dash_Algorithm.h"


	//Tipos Basicos
	namespace Basic_ADT{//ADT = Abstract Data Type
	#include "Dash_Vector.h"
	#include "Dash_List.h"
		}

	//Adaptadores, con templates para utilizar el contenedor mas conveniente
	namespace Adaptor_ADT{//ADT = Abstract Data Type
	#include "Dash_Queue.h"
	#include "Dash_Stack.h"
		}

	//Diccionarios, implementados con Listas o con Vectores
	namespace Map_ADT{//ADT = Abstract Data Type
	#include "Dash_MapL.h"
	#include "Dash_MapV.h"
		}

	//Arboles, Ordenado Orientado y Binario
	namespace Tree_ADT{//ADT = Abstract Data Type
	#include "Dash_Tree.h"
	#include "Dash_BTree.h"
		}


	}