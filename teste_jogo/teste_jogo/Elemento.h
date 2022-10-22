#pragma once

template<class TIPO>
class Elemento
{
private:
	TIPO* info;
	Elemento<TIPO>* proximo_elemento;
	Elemento<TIPO>* anterior_elemento;

public:
	Elemento();
	~Elemento();
	void set_info(TIPO* info_input);
	TIPO* get_info();
	void set_proximo_elemento(Elemento<TIPO>* elemento_input);
	Elemento<TIPO>* get_proximo_elemento();
	void set_anterior_elemento(Elemento<TIPO>* elemento_input);
	Elemento<TIPO>* get_anterior_elemento();
};

template<class TIPO>
Elemento<TIPO>::Elemento()
{
	info = nullptr;
	proximo_elemento = nullptr;
	anterior_elemento = nullptr;
}

template<class TIPO>
Elemento<TIPO>::~Elemento()
{
	info = nullptr;
	proximo_elemento = nullptr;
	anterior_elemento = nullptr;
}

template<class TIPO>
void Elemento<TIPO>::set_info(TIPO* info_input)
{
	info = info_input;
}

template<class TIPO>
TIPO* Elemento<TIPO>::get_info()
{
	return(info);
}

template<class TIPO>
void Elemento<TIPO>::set_proximo_elemento(Elemento<TIPO>* elemento_input)
{
	proximo_elemento = elemento_input;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_proximo_elemento()
{
	return(proximo_elemento);
}

template<class TIPO>
void Elemento<TIPO>::set_anterior_elemento(Elemento<TIPO>* elemento_input)
{
	anterior_elemento = elemento_input;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_anterior_elemento()
{
	return(anterior_elemento);
}
