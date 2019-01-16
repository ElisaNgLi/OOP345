/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
// Workshop 6 - STL Containers
// w6.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {
    
    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 2) {
        std::cerr << "\n***Incorrect number of arguments***\n";
        return 1;
    }
    std::ifstream productList(argv[1]);
    if (!productList) {
        std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
        return 2;
    }
    std::cout << std::fixed << std::setprecision(2);
    
    // TODO: Define a variable of type vector named "products"
    std::vector<w6::iProduct*> products;
    
    std::cout << "====================================\n";
    std::cout << "Reading data from the file\n";
    std::cout << "====================================\n";
    {
        // TODO: Read from the file one record at a time and create a product.
        //   - Print a message before starting processing a product.
        //   - Add the product to the vector "products", created above.
        //   - Handle any thrown exceptions and print the message.
        w6::iProduct* products_tmp = nullptr;
        int count = 0;
        do {
            std::cout << "Processing record " << ++count << ": ";
            try {
                products_tmp = w6::readProduct(productList);
                if (products_tmp) {
                    products.push_back(products_tmp);
                    std::cout << "done!" << std::endl;
                }
                else {
                    std::cout << "no such record! Reached the end of the file!" << std::endl;
                }
            }
            catch (std::string err) {
                std::cout << err << std::endl;
            };
        } while (products_tmp != nullptr);
    }
    std::cout << "====================================\n";
    
    std::cout << std::endl;
    std::cout << "====================================\n";
    std::cout << "Printing the content of the vector\n";
    std::cout << "====================================\n";
    
    double total = 0.0;
    std::cout << "      Product No         Taxable\n";
    std::cout << "------------------------------------\n";
    for (auto i = 0u; i < products.size(); i++) {
        total += products[i]->getPrice();
        std::cout << *products[i];
    }
    std::cout << "------------------------------------\n";
    std::cout << std::setw(22) << "Total: ";
    std::cout << std::setw(10) << total << std::endl;
    std::cout << "====================================\n";
    
    return 0;
}

//// Workshop 6 - STL Containers
//// w6.cpp
//// Author: Hwisun Bae
//// ID: 128-835-170
//
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include "iProduct.h"
//#include "ProdUtil.h"
//
//int main(int argc, char** argv) {
//
//    std::cout << "Command Line: ";
//    for (int i = 0; i < argc; i++) {
//        std::cout << argv[i] << ' ';
//    }
//    std::cout << std::endl;
//    if (argc != 2) {
//        std::cerr << "\n***Incorrect number of arguments***\n";
//        return 1;
//    }
//    std::ifstream productList(argv[1]);
//    if (!productList) {
//        std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
//        return 2;
//    }
//    std::cout << std::fixed << std::setprecision(2);
//
//    // TODO: Define a variable of type vector named "products"
//
//    std::vector <const w6::iProduct*> products;
//
//    std::cout << "====================================\n";
//    std::cout << "Reading data from the file\n";
//    std::cout << "====================================\n";
//    {
//        // TODO: Read from the file one record at a time and create a product.
//        // - Print a message before starting processing a product.
//        // - Add the product to the vector "products", created above.
//        // - Handle any thrown exceptions and print the message.
//
//        std::ofstream ofs("Lab6Output.txt");
//        double total = 0.0;
//        do {
//            products.push_back(w6::readProduct(productList));
//        } while (!productList.eof());
//
//        ofs << "Product No" << std::setw(10) << "Price" << std::setw(10) << "Taxable" << std::endl;
//        for (size_t i = 0; i < products.size(); i++) {
//            ofs << *products[i];
//            total += products[i]->getPrice();
//
//        }
//        ofs << "Total" << std::setw(15) << total << std::endl;
//
//        std::cout << "Results are in Lab6Output.txt\nPress any key to continue ... ";
//        std::cin.get();
//
//        ofs.close();
//
//    }
//    std::cout << "====================================\n";
//
//    std::cout << std::endl;
//    std::cout << "====================================\n";
//    std::cout << "Printing the content of the vector\n";
//    std::cout << "====================================\n";
//
//    double total = 0.0;
//    std::cout << " Product No Taxable\n";
//    std::cout << "------------------------------------\n";
//    for (auto i = 0u; i < products.size(); i++) {
//        total += products[i]->getPrice();
//        std::cout << *products[i];
//    }
//    std::cout << "------------------------------------\n";
//    std::cout << std::setw(22) <<"Total: ";
//    std::cout << std::setw(10) << total << std::endl;
//    std::cout << "====================================\n";
//
//    return 0;
//}
