%module geoda

%include "std_string.i"

%include "std_vector.i"
namespace std {
  %template(VecDouble) vector<double>;
  %template(VecVecDouble) vector< vector<double> >;
  %template(VecInt) vector<int>;
  %template(VecVecInt) vector< vector<int> >;
  %template(VecUINT8) vector<unsigned char>;
  %template(VecVecUINT8) vector<vector<unsigned char> >;
}

%{
#include "proxy.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
%}

#include <vector>

/**
 * is_arc: default value false -- using Euclidean distance
 *
 */

bool CreateRookWeights(std::string in_file, std::string out_file, int order=1, bool include_lower_order=false);

bool CreateQueenWeights(std::string in_file, std::string out_file, int order=1, bool include_lower_order=false);

bool CreateKNNWeights(std::string in_file, std::string out_file, int k, bool is_arc=false, bool is_mile=true);

bool CreateDistanceWeights(std::string in_file, std::string out_file, double threshold, bool is_arc=false, bool is_mile=true);

bool LISA(std::string in_w_file, std::vector<double> var_1, std::vector<double> var_2, std::vector<double>& localMoran, std::vector<double>& sigLocalMoran, std::vector<int>& sigFlag, std::vector<int>& clusterFlag, int lisa_type=0, int numPermutations=599);

