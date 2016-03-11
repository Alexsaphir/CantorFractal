#include "forme.h"

///
/// \brief Forme::Forme
///
Forme::Forme()
{

}

///
/// \brief Forme::GetSize
/// \return Nombre de points constituant la forme
///
int Forme::GetSize() const
{
	return L.size();
}

///
/// \brief Forme::GetPoint
/// \param i Indice du point
/// \return Retourne le i-ème point(s) de la forme
/// Nécessite que l'indice soit VALIDE.
///
QPointF Forme::GetPoint(int i) const
{
	return L.at(i);
}

///
/// \brief Forme::AddPoint Ajoute le point P à la forme
/// \param P QPointF
///
///
void Forme::AddPoint(const QPointF &P)
{
	L.append(P);
}

///
/// \brief operator == Teste si les deux formes sont egales
/// \param A Forme 1
/// \param B Forme 2
/// \return
///
bool operator ==(Forme const &A, Forme const &B)
{
	if (A.GetSize() != B.GetSize())
		return false;
	for(int i=0; i<A.GetSize(); ++i)
	{
		if (A.GetPoint(i)!=B.GetPoint(i))
			return false;
	}
	return true;
}

///
/// \brief Forme::generateExisting Génére une forme par défaut
/// \n		 n=0 : Segment
/// \n		 n=1 : Triangle
/// \param n
///
void Forme::generateExisting(quint32 n)
{
	if(n==0)
	{
		//Segment0-1
		this->AddPoint(QPointF(0.,0.));
		this->AddPoint(QPointF(1.,0.));
	}
	else if(n==1)
	{
		//Triangle
		this->AddPoint(QPointF(0.,0.));
		this->AddPoint(QPointF(1.,0.));
		this->AddPoint(QPointF(1./2.,qSqrt(3./4.)));
	}
}
