#include <iostream>

#include "methodslab5.h"

using namespace stepik;

void printVector(vector< shared_ptr<Shape> > &container, std::string name)
{
    std::cout << "Vector #" + name + ":" << std::endl;
    for(auto it = container.begin(); it != container.end(); it++)
    {
        (*it)->print(std::cout);
    }
    std::cout << std::endl << "___________" << std::endl;

}

int main(/*int argc, char *argv[]*/)
{
    system("clear");
    //vector< shared_ptr<Shape> > v1 = createRandomShapeVector(5);
    //vector< shared_ptr<Shape> > v2 = createRandomShapeVector(5);

    Shape *e = new Ellipse(0, 0, 5, 10, 0, 1, Color(165, 90, 50));
    Shape *r = new Round(5, 0, 10);
    Shape *a = new Arc(0, 0, -M_PI/2, M_PI/2, 10);
    Shape *r2 = new Round(-5, 0, 10, 0, 1, Color(220, 0, 0));

    vector< shared_ptr<Shape> > v1;
    v1.push_back(shared_ptr<Shape>(e));
    v1.push_back(shared_ptr<Shape>(r));
    v1.push_back(shared_ptr<Shape>(a));


    vector< shared_ptr<Shape> > v2
    ({
        shared_ptr<Shape>(e),
        shared_ptr<Shape>(r2)
     });

    /*v2.push_back(shared_ptr<Shape>(&e));
    v2.push_back(shared_ptr<Shape>(&a));
    v2.push_back(shared_ptr<Shape>(&r));
    v2.push_back(shared_ptr<Shape>(&r2));*/



    std::cout << std::endl << "Origin Vectors:" << std::endl;

    printVector(v1, "v1");
    printVector(v2, "v2");

    std::cout << std::endl << "___________" << std::endl << std::endl;


    std::cout << std::endl << "Unmodify Algorithm:" << std::endl;
    //bool isSplitted = checkVector(v1, redis);
    bool isSplitted = checkVector(v1, isIntersectWith);
    if(isSplitted)
    {
        std::cout << "Container v1 is split" << std::endl;
    }
    else
    {
        std::cout << "Container v1 is not split" << std::endl;
    }

    std::cout << std::endl << "Unmodify Algorithm:" << std::endl;
    //isSplitted = checkVector(v2, redis);
    isSplitted = checkVector(v2, isIntersectWith);
    if(isSplitted)
    {
        std::cout << "Container v2 is split" << std::endl;
    }
    else
    {
        std::cout << "Container v2 is not split" << std::endl;
    }

    std::cout << std::endl << "Modify Algorithm:" << std::endl;
    //printVector(v1, "v1");
    //printVector(v2, "v2");
    //std::cout << std::endl << "___________" << std::endl << std::endl;

    vector< shared_ptr<Shape> > difference = makeSortedDifference(v1, v2);
    std::cout << "Difference size = " << difference.size() << std::endl << std::endl;
    printVector(difference, "Sorted difference between v1 and v2");


    delete e;
    delete r;
    delete r2;
    delete a;
    return 0;
}
