#include "forme.h"

Forme::Forme()
{

}

int Forme::GetSize() const
{
	return L.size();
}

QPointF Forme::GetPoint(int i) const
{
	return L.at(i);
}

void Forme::AddPoint(const QPointF &P)
{
	L.append(P);
}

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
