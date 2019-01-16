/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

namespace w7{
 template <typename T = double>
    class DataTable {
        /* internal class Pair */
        template <typename TT = T>
        class Pair {
            TT xVal;
            TT yVal;

            public:
                // constructor 
                Pair(const TT& x, const TT& y) : xVal(x), yVal(y) {}

                // return X
                TT x() const { return xVal; }
                // return Y
                TT y() const { return yVal; }
        }; // end of internal class Pair

        int width;
        int decPrec;
        
        // a vector of pairs
        vector<Pair<T>> dataset;

        // passes func to accumulate
        template <typename Func>
        T calcSum(Func func) const {
            return accumulate(dataset.begin(), dataset.end(), T(0), func);
        }

        public:
            // constructor (filestream, field width, decimal precision)
            DataTable(ifstream& ifs, const int& fw, const int& prec) : width(fw), decPrec(prec) { 
                string buffer;
                int ln_cnt = 0;
                while (!ifs.eof()) {
                    getline(ifs, buffer);
                    ++ln_cnt;
                }

                ifs.clear();
                ifs.seekg(0, ifs.beg);

                T tmpX, tmpY;
                for (int i = 0; i < ln_cnt-1; i++) {
                    ifs >> tmpX >> tmpY;
                    Pair<T> tmpXY(tmpX, tmpY);
                    dataset.push_back(tmpXY);
                }
            }
            
            // mean of Y values
            T mean() const {
                T sum = calcSum([](const T& a, const Pair<T>& b) -> T {
                    return a + b.y();
                });

                return sum / dataset.size();
            }

            // standard deviation of Y values
            T sigma() const {
                // calculate mean & store in a variable
                T avg = mean();
                
                T sum = calcSum([&](const T& a, const Pair<T>& b) -> T {
                    return a + pow(b.y() - avg, 2);
                });
                // divide by num of elements minus 1
                sum = sum / (dataset.size() - 1);

                // square root everything
                sum = sqrt(sum);

                return sum;
            }

            // median
            T median() const {
                // sort the data set
                vector<Pair<T>> temp = dataset;
                sort(temp.begin(), temp.end(), [](const Pair<T>& a, const Pair<T>& b) -> bool {
                    return a.y() < b.y();
                });

                int i = (temp.size() + (temp.size() % 2) ) / 2;
                
                
                return temp[i].y();
            }

            // regression
            void regression(T& slope, T& y_intercept) const {
                // calculate required sums
                T sum_x = calcSum([](const T& a, const Pair<T>& b) -> T {
                    return (a + b.x());
                });

                T sum_y = calcSum([](const T& a, const Pair<T>& b) -> T {
                    return a + b.y();
                });

                T sum_xy = calcSum([](const T& a, const Pair<T>& b) -> T {
                    return a + b.x() * b.y();
                });

                T sum_xSq = calcSum([](const T& a, const Pair<T>&b) -> T {
                    return a + pow(b.x(), 2);
                });

                T n = dataset.size(); // n = size

                // calculate slope
                slope = ( (n * sum_xy) - (sum_x * sum_y) ) / ( (n * sum_xSq) - pow(sum_x,2) );

                // calculate y-intercept
                y_intercept = (sum_y - slope * sum_x) / n;
            } 

            // display the data set
            void display(ostream& os) const {
                os << setw(width) << "x" << setw(width) << "y" << endl;

                os << fixed << setprecision(decPrec);

                for_each(dataset.begin(), dataset.end(), [&](const Pair<T>& src) {
                    os << setw(width) << src.x()
                       << setw(width) << src.y() << endl;
                });
            }

            // return the size of the data set
            size_t getSize() const {
                return dataset.size();
            }
    };

    template<typename T>
    ostream& operator<<(ostream& os, const DataTable<T>& src) {
        src.display(os);
        return os;
    }
}

#endif