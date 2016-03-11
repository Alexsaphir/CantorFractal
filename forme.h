#ifndef FORME_H
#define FORME_H

#include <QtGlobal>
#include <QtMath>

#include <QList>
#include <QPointF>


class Forme
{
public:

	Forme();

	int GetSize() const;
	QPointF GetPoint(int i) const;
	void AddPoint(const QPointF &P);

	void generateExisting(quint32 n=0);

private:
	///
	/// \brief Liste des points constituant la forme dans l'ordre de tracé
	///
	QList<QPointF> L;
};

bool operator ==(Forme const &A, Forme const &B);

#endif // FORME_H
