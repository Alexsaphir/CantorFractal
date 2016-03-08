#ifndef SIMILITUDEINDIRECTE_H
#define SIMILITUDEINDIRECTE_H


class SimilitudeIndirecte
{
public:
	SimilitudeIndirecte();
	SimilitudeIndirecte(qreal K, qreal theta, QPointF P);
	SimilitudeIndirecte(qreal K, qreal theta, QPointF P, QPointF C);

	setSimilitudeIndirecte(qreal K, qreal theta, QPointF P);
	setSimilitudeIndirecte(qreal K, qreal theta, QPointF P, QPointF C);
};

#endif // SIMILITUDEINDIRECTE_H
