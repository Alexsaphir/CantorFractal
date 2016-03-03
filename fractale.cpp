#include "fractale.h"

Fractale::Fractale()
{
	isCantor = false;
}

bool Fractale::isLikeCantor() const
{
	return isCantor;
}

void Fractale::AddHomothetie(qreal k)
{
	Homothetie H(k);
	EnsA.append(H);
}

void Fractale::AddHomothetie(qreal k, QPointF Centre)
{
	Homothetie H(k, Centre);
	EnsA.append(H);
}

void Fractale::AddHomothetie(qreal k, qreal x, qreal y)
{
	Homothetie H(k,QPointF(x,y));
	EnsA.append(H);
}

void Fractale::AddRotation(qreal theta)
{
	Rotation H(theta);
	EnsA.append(H);
}

void Fractale::AddRotation(qreal theta, QPointF Centre)
{
	Rotation H(theta, Centre);
	EnsA.append(H);
}

void Fractale::AddRotation(qreal theta, qreal x, qreal y)
{
	Rotation H(theta, QPointF(x,y));
	EnsA.append(H);
}



void Fractale::AddForme(const Forme &F)
{
	EnsF.append(F);
}

void Fractale::RunOnce()
{
	QList<Forme> Tmp;
	for(int i=0;i<EnsA.size();++i)
	{
		Tmp+=EnsA.at(i).DoForEns(EnsF);
	}

//	//On retire les doublons
//	for(int i=0;i<Tmp.size();++i)
//	{
//		if(Tmp.count(Tmp.at(i))>1)
//		{
//			Tmp.removeOne(Tmp.at(i));
//		}
//	}
	EnsF.clear();
	EnsF.swap(Tmp);
}

Forme Fractale::getFromEnsForme(int i) const
{
	return EnsF.at(i);
}

int Fractale::getSizeEnsForme() const
{
	return EnsF.size();
}

int Fractale::getSizeEnsAppli() const
{
	return EnsA.size();
}
