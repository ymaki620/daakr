// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// aucAk
double aucAk(LogicalVector response, NumericVector predictor);
RcppExport SEXP daakr_aucAk(SEXP responseSEXP, SEXP predictorSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< LogicalVector >::type response(responseSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type predictor(predictorSEXP);
    __result = Rcpp::wrap(aucAk(response, predictor));
    return __result;
END_RCPP
}
