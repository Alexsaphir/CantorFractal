#include "fractale.h"

Fractale::Fractale()
{
	isCantor = false;
}

bool Fractale::isLikeCantor() const
{
	return isCantor;
}
void Fractale::setLikeCantor(bool p)
{
	isCantor = p;
}

void Fractale::AddApplication(Application A)
{
	EnsA.append(A);
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



void Fractale::AddForme( Forme F)
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

void Fractale::generateExisting(quint32 n)
{
	if(n==0)
	{
		//Cantor 1D
		Forme F;
		F.generateExisting(0);
		for(int i=0;i<F.GetSize();++i)
		{
			this->AddHomothetie(1./3.,F.GetPoint(i));
		}
		this->AddForme(F);
		this->setLikeCantor(true);
	}
	else if(n==1)
	{
		//triangle de spierski
		Forme F;
		F.generateExisting(1);//genere triangle
		this->AddForme(F);
		for(int i=0;i<F.GetSize();++i)
		{
			this->AddHomothetie(1./2.,F.GetPoint(i));
		}
	}
	else if(n==2)
	{
		Forme F;
		SimilitudeDirecte S1,S2,S3,S4;
		qreal k(1./3.);
		F.generateExisting(0);

		S1.setSimilitudeDirecte(k, 0.		,	QPointF(0.,0.)								);
		S2.setSimilitudeDirecte(k, M_PI/3.	,	QPointF(0.,0.), QPointF(1./3.,0.)			);
		S3.setSimilitudeDirecte(k, -M_PI/3.	,	QPointF(0.,0.), QPointF(1./2.,qSqrt(3.)/6.)	);
		S4.setSimilitudeDirecte(k, 0		,	QPointF(0.,0.), QPointF(2./3.,0.)			);

		this->AddForme(F);
		this->AddApplication(S1);
		this->AddApplication(S2);
		this->AddApplication(S3);
		this->AddApplication(S4);
	}
	else if(n==3)
	{
		Forme F;
		SimilitudeDirecte S1,S2,S3,S4;
		qreal k(7./18.);
		//F.generateExisting(0);
		F.AddPoint(QPointF(0.,0.));
		F.AddPoint(QPointF(1.,0.));
		this->AddForme(F);
//Vecteur (0,1)
		S1.setSimilitudeDirecte(k, 0.		,	QPointF(0.,0.)								);
		S2.setSimilitudeDirecte(1./4., M_PI/3.	,	QPointF(0.,0.), QPointF(1./4.,0.)			);
		S3.setSimilitudeDirecte(1./4., -M_PI/3.	,	QPointF(1.,0.), QPointF(-1./4.,0.)	);
		S4.setSimilitudeDirecte(k, 0		,	QPointF(1.,0.), QPointF(0.,0.)			);


		this->AddApplication(S1);
		this->AddApplication(S2);
		this->AddApplication(S3);
		this->AddApplication(S4);

		S3.setCentre(QPointF(3./4.,1./2.));
		S4.setCentre(QPointF(3./4.,1./2.));

		S3.setv1(-0.1473291);
		S3.setv2(-0.3444979);
		S4.setv1(0.1666667 );
		S4.setv2(0.3333333 );

		//this->AddApplication(S3);
		//this->AddApplication(S4);
	}
}
