#include "Directions.h"
#include "exception"


Direction inverse(Direction direction)
{
    switch (direction) {
        case None:
            throw std::exception();
        case Up:
            return Down;
        case Down:
            return Up;
        case Left:
            return Right;
        case LeftUp:
            return RightDown;
        case LeftDown:
            return RightUp;
        case Right:
            return Left;
        case RightUp:
            return LeftDown;
        case RightDown:
            return LeftUp;
    }
}

Direction operator!(Direction direction)
{
    return inverse(direction);
}