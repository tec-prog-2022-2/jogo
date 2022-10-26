template<class TL>
template<class TE>
class Listas::Lista<TL>::Elemento
{
private:
	TE* info;
	Elemento<TE>* proximo_elemento;
	Elemento<TE>* anterior_elemento;

public:
	Elemento();
	~Elemento();
	void set_info(TE* info_input);
	TE* get_info() const;
	void set_proximo_elemento(Elemento<TE>* elemento_input);
	Elemento<TE>* get_proximo_elemento() const;
	void set_anterior_elemento(Elemento<TE>* elemento_input);
	Elemento<TE>* get_anterior_elemento() const;
};

#include"ElementoImplementacao.h"
