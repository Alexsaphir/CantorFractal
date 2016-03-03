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

	enum Figure {
		SEGMENT,
		TRIANGLE
	};

private:
	QList<QPointF> L;
};

bool operator ==(Forme const &A, Forme const &B);

#endif // FORME_H
