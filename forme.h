#ifndef FORME_H
#define FORME_H

#include <QList>
#include <QPointF>
class Forme
{
public:
	Forme();

	int GetSize() const;
	QPointF GetPoint(int i) const;
	void AddPoint(const QPointF &P);

private:
	QList<QPointF> L;
};

bool operator ==(Forme const &A, Forme const &B);

#endif // FORME_H
