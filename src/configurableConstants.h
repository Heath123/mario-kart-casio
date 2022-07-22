#ifndef _CONFIGURABLE_CONSTANTS_H_
#define _CONFIGURABLE_CONSTANTS_H_

// #define range(min, max, step) {min, max, step}

// #ifdef __EMSCRIPTEN__
// #define define_constant(type, name, value, range, description) type name = value;
// #else
// #define define_constant(type, name, value, range, description) const type name = value;
// #endif

void initSliders();
void updateConstants();

#endif // _CONFIGURABLE_CONSTANTS_H_
