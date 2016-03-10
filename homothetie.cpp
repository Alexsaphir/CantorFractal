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
/// \param K
///
Homothetie::Homothetie(qreal K) : Application()
{
	k = K;
}

///
/// \brief Homothetie::Homothetie
/// \param K
/// \param C
///
Homothetie::Homothetie(qreal K, QPointF C) :Application()
{
	k = K;
	Centre = C;
}

///
/// \brief Homothetie::setHomothetie
/// \param K
///
void Homothetie::setHomothetie(qreal K)
{
	k = K;
}

///
/// \brief Homothetie::setHomothetie
/// \param K
/// \param C
///
void Homothetie::setHomothetie(qreal K, QPointF C)
{
	k = K;
	Centre = C;
}
