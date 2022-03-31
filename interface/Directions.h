#pragma once


enum Direction{None, Up, Down, Left, LeftUp, LeftDown, Right, RightUp, RightDown};

static_assert(Up+Left == LeftUp);
static_assert(Up+Right == RightUp);
static_assert(Down+Left == LeftDown);
static_assert(Down+Right == RightDown);

enum Orientation{Vertical, Horizontal};