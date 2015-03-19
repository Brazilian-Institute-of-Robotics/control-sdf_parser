#include "sdf_parser.hpp"

namespace sdf_parser
{


void read_paths() {

    std::string home = std::string(getenv("HOME"));

    sdf::addURIPath("model://", home + "/.gazebo/models");

    char *pathCStr = getenv("GAZEBO_MODEL_PATH");

    if (!pathCStr || *pathCStr == '\0') {
        return;
    }

    std::string delim(":");
    std::string path = pathCStr;

    std::cout << "GAZEBO_MODEL_PATH: " << path << std::endl;

    size_t pos1 = 0;
    size_t pos2 = path.find(delim);
    while (pos2 != std::string::npos) {
        sdf::addURIPath("model://", path.substr(pos1, pos2-pos1));


        pos1 = pos2 + 1;
        pos2 = path.find(delim, pos2 + 1);
    }

    sdf::addURIPath("model://", path.substr(pos1, path.size()-pos1));
}


sdf::SDFPtr load(std::string filename)
{
    read_paths();

    sdf::SDFPtr sdf(new sdf::SDF);

    if (!sdf::init(sdf))
    {
        std::cerr << "unable to initialize sdf" << std::endl;
        return sdf;
    }

    std::cout << "initialize sdf with success" << std::endl;

    if (!sdf::readFile(filename, sdf)){
        std::cerr << "unable to read sdf file" << std::endl;
        return sdf;
    }

    return sdf;
}

}
