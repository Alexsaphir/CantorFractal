#include "application.h"

Application::Application()
{
	isSimi = false;
	Centre.setX(0.0);
	Centre.setY(0.0);
	k=1;
	r=0;
}
Application::Application(bool pSimi, qreal K, qreal R, QPointF CENTRE)
{
	isSimi = pSimi;
	k = K;
	r = R;
	Centre =CENTRE;
}

bool Application::isHomothetie() const
{
	return !isSimi;
}

bool Application::isSimilitude() const
{
	return isSimi;
}

QList<Forme> Application::doForEns(const QList<Forme> &EnsForme) const
{
	QList<Forme> EnsT;
	for (int i=0;i<EnsForme.size();++i)
	{
		Forme TmpF;
		for(int j=0;j<EnsForme.at(i).GetSize(); ++j)
		{
			QPointF P=EnsForme.at(i).GetPoint(j);
			QPointF tmp(k*(P-Centre)+Centre);
			TmpF.AddPoint(tmp);
		}
		EnsT.append(TmpF);
	}
	return EnsT;
}
