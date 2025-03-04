#include "Serializer.hpp"
#include <string>
#include <iostream>

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &other) {(void)other;}

Serializer &Serializer::operator=(const Serializer &other) {(void)other; return *this;}

/* uintptr_t Serializer::serialize(Data* ptr)
{

}

Data *Serializer::deserialize(uintptr_t raw)
{

} */
