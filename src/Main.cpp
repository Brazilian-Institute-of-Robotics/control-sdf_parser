#include <iostream>
#include <sdf_parser/sdf_parser.hpp>

int main(int argc, char** argv)
{

    if (argc == 2){
        sdf::SDFPtr sdf = sdf_parser::load(argv[1]);
        std::cout << sdf->ToString() << std::endl;


        sdf::ElementPtr world = sdf->root->GetElement("world");


        if (world->HasElement("model")){
            sdf::ElementPtr model = world->GetElement("model");

            while (model) {

                std::cout << "MODEL: " << model->GetAttribute("name")->GetAsString() << std::endl;

                model = model->GetNextElement("model");
            }
        }

        return 0;
    }

    std::cerr << "number of arguments is invalid" << std::endl;

	return 1;
}
