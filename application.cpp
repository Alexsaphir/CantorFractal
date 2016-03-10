#include "application.h"


///
/// \brief Application::Application
///Constructeur par default de Application
///
Application::Application()
{
	//Application identité
	k=1;

	m11 = 1;
	m12 = 0;
	m21 = 0;
	m22 = 1;

	v1 = 0;
	v2 = 0;

	Centre.setX(0);
	Centre.setY(0);
}

///
/// \brief Application::setm11
/// \param m Modifie la valeur de m11
void Application::setm11(qreal m)
{
	m11 = m;
}

///
/// \brief Application::setm12
/// \param m Modifie la valeur de m12
///
void Application::setm12(qreal m)
{
	m12 = m;
}

///
/// \brief Application::setm21
/// \param m Modifie la valeur de m21
///
void Application::setm21(qreal m)
{
	m21 = m;
}

///
/// \brief Application::setm22
/// \param m Modifie la valeur de m22
///
void Application::setm22(qreal m)
{
	m22 = m;
}

///
/// \brief Application::setv1
/// \param m Modifie la valeur de v1
///
void Application::setv1(qreal m)
{
	v1 = m;
}

///
/// \brief Application::setv2
/// \param m Modifie la valeur de v2
///
void Application::setv2(qreal m)
{
	v2 = m;
}

///
/// \brief Application::setCentre
/// \param P Modifie la valeur du centre
///
void Application::setCentre(QPointF P)
{
	Centre = P;
}

///
/// \brief Application::setK
/// \param K Modifie la valeur de k
///
void Application::setK(qreal K)
{
	k = K;
}

///
/// \brief Application::getm11
/// \return Retourne la valeur de m11
///
qreal Application::getm11() const
{
	return m11;
}

///
/// \brief Application::getm12
/// \return Retourne la valeur de m12
///
qreal Application::getm12() const
{
	return m12;
}

///
/// \brief Application::getm21
/// \return Retourne la valeur de m21
///
qreal Application::getm21() const
{
	return m21;
}

///
/// \brief Application::getm22
/// \return Retourne la valeur de m22
///
qreal Application::getm22() const
{
	return m22;
}

///
/// \brief Application::getv1
/// \return Retourne la valeur de v1
///
qreal Application::getv1() const
{
	return v1;
}

///
/// \brief Application::getv2
/// \return Retourne la valeur de v2
///
qreal Application::getv2() const
{
	return v2;
}

///
/// \brief Application::getCentre
/// \return Retourne le centre de l'application
///
QPointF Application::getCentre() const
{
	return Centre;
}

///
/// \brief Application::getK
/// \return Retourne le rapport de l'application
///
qreal Application::getK() const
{
	return k;
}

///
/// \brief Application::getTheta
/// \return Retourne l'angle de rotation de l'application
///
qreal Application::getTheta() const
{
	return qAsin(m21);//Toujours egale que ce soit une similitude directe ou indirecte
}

///
/// \brief Application::isHomothetie
/// \return Verifie si l'application est une homothetie?
///
bool Application::isHomothetie() const
{
	if ((v1 == 1) && (v2 == 0) && (m11 == 1) && (m12 == 0) && (m21 == 0) && (m22 == 1))
		return true;
	return false;
}

///
/// \brief Application::isRotation
/// \return Verifie si l'application est une rotation?
///
bool Application::isRotation() const
{
	if ((k == 0) && (v1 == 0) && (v2 == 0))
		return true;
	return false;
}

///
/// \brief Application::DoForQPointF
/// \param P
/// \return Image de l'application en P
///
QPointF Application::DoForQPointF(const QPointF &P) const
{

	QPointF z;
	z.setX(k*((P.x()-Centre.x())*m11 + (P.y()-Centre.y())*m12)+v1+Centre.x());
	z.setY(k*((P.x()-Centre.x())*m21 + (P.y()-Centre.y())*m22)+v2+Centre.y());
	return z;
}

///
/// \brief Application::DoForForme
/// \param F Forme
/// \return Image de l'application sur la forme
///
Forme Application::DoForForme(const Forme &F) const
{
	Forme tmp;
	for (int i=0;i<F.GetSize();++i)
	{
		tmp.AddPoint(this->DoForQPointF(F.GetPoint(i)));
	}
	return tmp;
}

///
/// \brief Application::DoForEns
/// \param EnsForme
/// \return Image de l'application sur chaqune des forme
///
QList<Forme> Application::DoForEns(const QList<Forme> &EnsForme) const
{
	QList<Forme> EnsT;
	EnsT.reserve(EnsForme.size());//Préalloue le nombre d'élement pour éviter les réallocations
	for (int i=0;i<EnsForme.size();++i)
	{
		EnsT.append(this->DoForForme(EnsForme.at(i)));
	}
	return EnsT;
}

///
/// \brief operator ==
/// \param A
/// \param B
/// \return true si A==B, false si A!=B
///
bool operator ==(Application const &A, Application const &B)
{
	//Faire une liste de poiuiteur de fct pour chaque varialbe de Application
		return true;
	return false;
}
