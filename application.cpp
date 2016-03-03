#include "application.h"

Application::Application()
{
	y=1+0i;
	w=0+0i;
}

std::complex<qreal> Application::getApplication() const
{
	return y;
}

QPointF Application::getCentre() const
{
	return QPointF(w.real(),w.imag());
}

void Application::setW(std::complex<qreal> W)
{
	w=W;
}

void Application::setY(std::complex<qreal> Y)
{
	y=Y;
}

bool Application::isHomothetie() const
{
	if (y.imag() == 0.0)
		return true;
	return false;
}

bool Application::isRotation() const
{
	if (std::norm(y)==1 && y.real()!= 1)
		return true;
	return false;
}

QPointF Application::DoForQPointF(const QPointF &P) const
{
	std::complex<qreal> z=P.x() +1i*P.y();
	z=y*(z-w)+w;//Forme de la rotation ou de l'homothetie
	return QPointF(z.real(),z.imag());
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


bool operator ==(Application const &A, Application const &B)
{
	if ( (A.getApplication() == B.getApplication()) && (A.getCentre() == B.getCentre()) )
		return true;
	return false;
}


