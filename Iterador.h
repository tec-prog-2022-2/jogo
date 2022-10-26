template<class TL>
class Listas::Lista<TL>::Iterador
{
private:
	Lista<TL>::Elemento<TL>* elemento;

public:
	Iterador();
	~Iterador();
	void operator++();
	void operator--();
	void operator=(Lista<TL>::Elemento<TL>* elemento_input);
	bool operator!=(Lista<TL>::Elemento<TL>* elemento_input) const;
	bool operator==(Lista<TL>::Elemento<TL>* elemento_input) const;
	TL* operator*() const; //pega a informação que elemento possui
};

#include"IteradorImplementacao.h"
