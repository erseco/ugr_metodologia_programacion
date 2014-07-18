/******************************************************************************
 *
 * Metodología de la Programación
 * Grado en Ingeniería Informática
 *
 * 2014 - Ernesto Serrano Collado
 *
 ******************************************************************************/
#ifndef MIVECTORDINAMICO
#define MIVECTORDINAMICO

typedef int TipoBase;

class MiVectorDinamico {

	// Atributos
private:
	TipoBase * vector;
	int size;
	int pos;
	int dimension_type;

public:
	// Constructores;
	MiVectorDinamico(void);
	MiVectorDinamico(int size, TipoBase defaultvalue = 0);

	// Constructor de copia
	MiVectorDinamico(const MiVectorDinamico & otro); 

	// Destructor
	~MiVectorDinamico();

	// Métodos
	void AddValue(TipoBase);
	void PrintValues();

	int GetSize();
	int GetUsed();

	void SetRedimensionType(int type);
	int GetRedimensionType();

	// Operador de asignacion
	MiVectorDinamico & operator = (const MiVectorDinamico & otro);
	MiVectorDinamico & operator = (const TipoBase & defaultvalue);

	// Sobrecarga del operador []
	TipoBase & operator [] (const int indice);

	// Sobrecarga de los operadores == y !=
	bool operator == (const MiVectorDinamico & otro);
	bool operator != (const MiVectorDinamico & otro);

	// Operadores combinados
	bool operator > (const MiVectorDinamico & otro);
	bool operator < (const MiVectorDinamico & otro);
	bool operator >= (const MiVectorDinamico & otro);
	bool operator <= (const MiVectorDinamico & otro);
	
private:
	void Incrementa_En_Uno();
	void Incrementa_En_Doble();
	void Incrementa_En_Bloque(int increment);

	void AsignarValor(TipoBase defaultvalue);

	void LiberarMemoria();

	void ReservarMemoria (int num_casillas);
	void CopiarDatos (const MiVectorDinamico & otro);

	bool SonIguales(const MiVectorDinamico & otro);



};


#endif