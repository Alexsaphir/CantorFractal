#include "fractale.h"

Fractale::Fractale()
{
	isCantor = false;
}

bool Fractale::isLikeCantor() const
{
	return isCantor;
}

void Fractale::AddAppli(bool isSimi, qreal k, qreal r, QPointF Centre)
{
	Application A(isSimi, k, r, Centre);
	EnsA.append(A);
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
		Tmp+=EnsA.at(i).doForEns(EnsF);
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
