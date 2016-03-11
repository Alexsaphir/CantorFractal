#include "homothetie.h"

///
/// \brief Homothetie::Homothetie
///
Homothetie::Homothetie() : Application()
{
	//Le constructeur de Application est appellé et *this= Id
}

///
/// \brief Homothetie::Homothetie
/// Construit une Homothetie de rapport k
/// \param K Rapport de l'Homothetie
///
Homothetie::Homothetie(qreal K) : Application()
{
	k = K;
}

///
/// \brief Homothetie::Homothetie
/// Construit une Homothetie de rapport k et de centre C
/// \param K Rapport de l'Homothetie
/// \param C Centre de l'Homothetie
///
Homothetie::Homothetie(qreal K, QPointF C) :Application()
{
	k = K;
	Centre = C;
}

///
/// \brief Homothetie::setHomothetie
/// Définie une Homothetie de rapport k
/// \param K Rapport de l'Homothetie
///
void Homothetie::setHomothetie(qreal K)
{
	k = K;
}

///
/// \brief Homothetie::setHomothetie
/// Définie une Homothetie de rapport k et de centre C
/// \param K Rapport de l'Homothetie
/// \param C Centre de l'Homothetie
///
void Homothetie::setHomothetie(qreal K, QPointF C)
{
	k = K;
	Centre = C;
}
