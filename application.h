#ifndef APPLICATION_H
#define APPLICATION_H

#include <complex>
#include <cmath>

#include "forme.h"


class Application
{
public:
	Application();

	void setm11(qreal m);
	void setm12(qreal m);
	void setm21(qreal m);
	void setm22(qreal m);
	void setv1(qreal m);
	void setv2(qreal m);
	void setCentre(QPointF P);
	void setK(qreal K);

	qreal getm11() const;
	qreal getm12() const;
	qreal getm21() const;
	qreal getm22() const;
	qreal getv1() const;
	qreal getv2() const;
	QPointF getCentre() const;
	qreal getK() const;
	qreal getTheta() const;//Calculer à partir de la matrice de rotation M


	bool isHomothetie() const;
	bool isRotation() const;


	QPointF DoForQPointF(QPointF const &P) const;
	Forme DoForForme(Forme const &F) const;
	QList<Forme> DoForEns(const QList<Forme> &EnsForme) const;

protected:
	///
	/// \brief k Rapport de l'application
	///
	qreal k;
	///
	/// \brief Décrit la matrice de rotation
	/// \f[
	/// \bf
	///  \left( \begin{array}{ccc}
	/// \bf m_{1,1} & \bf m_{1,2} \\
	/// \bf m_{2,1} & \bf m_{2,2} \\
	/// \end{array} \bf\right)
	/// \bf=
	/// \bf\left( \begin{array}{ccc}
	/// \bf cos(\bf\theta) & \bf -sin(\bf\theta) \\
	/// \bf sin(\bf\theta) & \bf cos(\bf\theta) \\
	/// \end{array} \bf\right)
	///  \bf ou
	/// \bf\left( \begin{array}{ccc}
	/// \bf cos(\bf\theta) & \bf sin(\bf\theta) \\
	/// \bf sin(\bf\theta) & \bf -cos(\bf\theta) \\
	/// \end{array} \bf\right)
	/// \f]
	qreal m11;
	///
	/// \brief Décrit la matrice de rotation
	/// \f[
	/// \bf
	///  \left( \begin{array}{ccc}
	/// \bf m_{1,1} & \bf m_{1,2} \\
	/// \bf m_{2,1} & \bf m_{2,2} \\
	/// \end{array} \bf\right)
	/// \bf=
	/// \bf\left( \begin{array}{ccc}
	/// \bf cos(\bf\theta) & \bf -sin(\bf\theta) \\
	/// \bf sin(\bf\theta) & \bf cos(\bf\theta) \\
	/// \end{array} \bf\right)
	///  \bf ou
	/// \bf\left( \begin{array}{ccc}
	///\bf cos(\bf\theta) & \bf sin(\bf\theta) \\
	/// \bf sin(\bf\theta) & \bf -cos(\bf\theta) \\
	/// \end{array} \bf\right)
	/// \f]
	qreal m12;
	///
	/// \brief Décrit la matrice de rotation
	/// \f[
	/// \bf
	///  \left( \begin{array}{ccc}
	/// \bf m_{1,1} & \bf m_{1,2} \\
	/// \bf m_{2,1} & \bf m_{2,2} \\
	/// \end{array} \bf\right)
	/// \bf=
	/// \bf\left( \begin{array}{ccc}
	/// \bf cos(\bf\theta) & \bf -sin(\bf\theta) \\
	/// \bf sin(\bf\theta) & \bf cos(\bf\theta) \\
	/// \end{array} \bf\right)
	///  \bf ou
	/// \bf\left( \begin{array}{ccc}
	/// \bf cos(\bf\theta) & \bf sin(\bf\theta) \\
	/// \bf sin(\bf\theta) & \bf -cos(\bf\theta) \\
	/// \end{array} \bf\right)
	/// \f]
	qreal m21;
	///
	/// \brief Décrit la matrice de rotation
	/// \f[
	/// \bf
	///  \left( \begin{array}{ccc}
	/// \bf m_{1,1} & \bf m_{1,2} \\
	/// \bf m_{2,1} & \bf m_{2,2} \\
	/// \end{array} \bf\right)
	/// \bf=
	/// \bf\left( \begin{array}{ccc}
	/// \bf cos(\bf\theta) & \bf -sin(\bf\theta) \\
	/// \bf sin(\bf\theta) & \bf cos(\bf\theta) \\
	/// \end{array} \bf\right)
	///  \bf ou
	/// \bf\left( \begin{array}{ccc}
	/// \bf cos(\bf\theta) & \bf sin(\bf\theta) \\
	/// \bf sin(\bf\theta) & \bf -cos(\bf\theta) \\
	/// \end{array} \bf\right)
	/// \f]
	qreal m22;
	///
	/// \brief v1 Parametre du vecteur de translation V
	/// \f[\bf V\bf=
	/// \bf\left( \begin{array}{ccc}
	/// \bf v_{1}\\
	/// \bf v_{2}\\
	/// \end{array} \bf\right)
	/// \f]
	qreal v1;
	///
	/// \brief v2 Parametre du vecteur de translation V
	/// \f[\bf V\bf=
	/// \bf\left( \begin{array}{ccc}
	/// \bf v_{1}\\
	/// \bf v_{2}\\
	/// \end{array} \bf\right)
	/// \f]
	qreal v2;
	///
	/// \brief
	/// Centre de l'application
	///
	QPointF Centre;
};

bool operator ==(Application const &A, Application const &B);

#endif // APPLICATION_H
