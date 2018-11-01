#include "Video.h"

Video::Video() {}

Video::~Video() {

}

const std::string &Video::getName() const {
    return name;
}

void Video::setName(const std::string &name) {
    Video::name = name;
}
