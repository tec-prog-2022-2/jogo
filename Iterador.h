template<class TL>
class lista::Lista<TL>::Iterador
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
	TL* operator*() const;
};

#include"IteradorImplementacao.h"
