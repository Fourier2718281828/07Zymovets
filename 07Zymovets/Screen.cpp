#include "Screen.h"

template<size_t height, size_t width>
const size_t Screen<height, width>::maxHeight = 2000;

template<size_t height, size_t width>
const size_t Screen<height, width>::maxWidth = 2000;

template<size_t height, size_t width>
const char Screen<height, width>::_filler = '*';

template<size_t height, size_t width>
const char Screen<height, width>::thick_delim = '#';

template<size_t height, size_t width>
const char Screen<height, width>::thin_delim = '-';