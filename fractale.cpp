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
		Forme F1,F2,F3;
		SimilitudeDirecte S1,S2,S3,S4,S5,S6,S7;
		//F.generateExisting(0);
		F1.AddPoint(QPointF(0.,0.));
		F1.AddPoint(QPointF(1.,0.));
		//Si triangle This is based on a dragon curve construction
		F1.AddPoint(QPointF(1./2.,qSqrt(3.)/2.));
		QPointF Centre;

		S1.setSimilitudeDirecte(1./3.		,-2.*M_PI/3., Centre, QPointF(1./6., qSqrt(3.)/6.)	);
		S2.setSimilitudeDirecte(1./3.		,M_PI/3.	, Centre, QPointF(1./6., qSqrt(3.)/6.)	);
		S3.setSimilitudeDirecte(1./3.		,0.			, Centre, QPointF(1./3., qSqrt(3.)/3.)	);
		S4.setSimilitudeDirecte(1./3.		,-M_PI/3.	, Centre, QPointF(2./3., qSqrt(3.)/3.)	);
		S5.setSimilitudeDirecte(1./qSqrt(3.),M_PI/6.	, Centre, QPointF(1./3., 0.)			);
		S6.setSimilitudeDirecte(1./3.		,M_PI		, Centre, QPointF(2./3., 0.)			);
		S7.setSimilitudeDirecte(1./3.		,0.			, Centre, QPointF(2./3., 0.)			);


		this->AddApplication(S1);
		this->AddApplication(S2);
		this->AddApplication(S3);
		this->AddApplication(S4);
		this->AddApplication(S5);
		this->AddApplication(S6);
		this->AddApplication(S7);
	}
	else if(n==4)
	{
		std::complex<qreal> beta=1./2.-1i*qSqrt(3.)/6.;
		//std::complex<qreal> beta(0-1i*0.5);
		Forme F1,F2;
		F1.generateExisting(0);//genere segment
		F2.AddPoint(QPointF(0.,0.));
		F2.AddPoint(QPointF(std::real(beta),std::imag(beta)));
		this->AddForme(F1);
		this->AddForme(F2);

		SimilitudeIndirecte S1,S2;
		S1.setSimilitudeIndirecte(abs(beta), arg(beta), QPointF(0.,0.));
		S2.setSimilitudeIndirecte(1-abs(beta)*abs(beta), 0, QPointF(abs(beta)*abs(beta),0.));

		this->AddApplication(S1);
		this->AddApplication(S2);

	}
	else if(n==5)
	{
		Forme F;
		F.generateExisting(0);
		this->AddForme(F);
		SimilitudeDirecte S1,S2;

		S1.setK(qSqrt(2.)/2);
		S1.setTheta(M_PI/4.);

		S2.setK(qSqrt(2.)/2);
		S2.setTheta(-M_PI/4.);
		S2.setCentre(QPointF(1.,0.));

		this->AddApplication(S1);
		this->AddApplication(S2);
	}
	else if(n==6)
	{
		//pentakun

		Forme F;
		for(qreal i=0.;i<5.;++i)
			F.AddPoint(QPointF(-qSin(2.*i*M_PI/5.), qCos(2.*i*M_PI/5.)));
		this->AddForme(F);
		for(int i=0;i<5;++i)
		{
			this->AddHomothetie((3.-qSqrt(5.))/2.,F.GetPoint(i));
		}
	}
	else if(n==7)
	{
		Forme F;
		F.AddPoint(QPointF(0.,0.));
		F.AddPoint(QPointF(1.,0.));
		F.AddPoint(QPointF(1.,1.));
		F.AddPoint(QPointF(0.,1.));
		this->AddForme(F);

		for (int i=0;i<4;++i)
			this->AddHomothetie(1./3.,F.GetPoint(i));
		SimilitudeDirecte S;
		S.setK(1./3.);
		QList<QPointF> P;
		P << QPointF(1./2.,0.) << QPointF(1.,1./2.) << QPointF(1./2.,1.) << QPointF(0.,1./2.);
		for (qreal i=0.;i<4.;++i)
		{
			S.setCentre(P.at(i));
			this->AddApplication(S);
		}

	}
}
