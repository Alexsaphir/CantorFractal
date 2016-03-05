#include "application.h"

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
}


bool Application::isHomothetie() const
{
	if ((v1 == 1) && (v2 == 0) && (m11 == 1) && (m12 == 0) && (m21 == 0) && (m22 == 1))
		return true;
	return false;
}

bool Application::isRotation() const
{
	if ((k == 0) && (v1 == 0) && (v2 == 0))
		return true;
	return false;
}

qreal Application::getm11() const
{
	return m11;
}

qreal Application::getm12() const
{
	return m12;
}

qreal Application::getm21() const
{
	return m21;
}

qreal Application::getm22() const
{
	return m22;
}

qreal Application::getv1() const
{
	return v1;
}

qreal Application::getv2() const
{
	return v2;
}

void Application::setm11(qreal m) const
{
	m11 = m;
}

void Application::setm11(qreal m)
{
	m11 = m;
}

void Application::setm12(qreal m)
{
	m12 = m;
}

void Application::setm21(qreal m)
{
	m21 = m;
}

void Application::setm22(qreal m)
{
	m22 = m;
}

void Application::setv1(qreal m)
{
	v1 = m;
}

void Application::setv2(qreal m)
{
	v2 = m;
}



QPointF Application::DoForQPointF(const QPointF &P) const
{

	QPointF z;
	z.setX(k*(P.x()*m11 + P.y()*m12)+v1);
	z.setY(k*(P.x()*m21 + P.y()*m22)+v2);
	return z;
}

Forme Application::DoForForme(const Forme &F) const
{
	Forme tmp;
	for (int i=0;i<F.GetSize();++i)
	{
		tmp.AddPoint(this->DoForQPointF(F.GetPoint(i)));
	}
	return tmp;
}

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

void Application::setuseConj(bool p)
{
	useConjB=p;
}

bool Application::useConj() const
{
	return useConjB;
}

bool operator ==(Application const &A, Application const &B)
{
	if ( (A.getApplication() == B.getApplication()) && (A.getCentre() == B.getCentre()) )
		return true;
	return false;
}


