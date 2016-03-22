//' @useDynLib daakr
//' @importFrom Rcpp evalCpp

#include <Rcpp.h>
using namespace Rcpp;

//' compute auc
//' 
//' @param response input boolean vector
//' @param predictor input numerical vector
//' @return auc
//' @export
// [[Rcpp::export]]
double aucAk(LogicalVector response, NumericVector predictor){
    int len  = response.size();
    if(len != predictor.size())return(-1.0);
    
    int cnt=0;
    for(int i=0;i<len;i++){
        if(response[i]==true)cnt++;
    }
    double TP[cnt];
    double TN[len-cnt];
    int p_count=0;
    int n_count=0;
    
    for(int i=0; i<len; i++){
        if(response[i]==true){
            TP[p_count] = predictor[i];
            p_count++;
        }else{
            TN[n_count] = predictor[i];
            n_count++;
        }
    }
    
    double auc=0.0;
    for(int i=0; i<cnt; i++){
        for(int j=0; j<len-cnt; j++){
            if(TP[i] > TN[j]){
                auc += 1.0;
            }else if(TP[i] == TN[j]){
                auc += 0.5;
            }
        }
    }
    auc = auc/double(cnt)/double(len-cnt);
    return(auc);
}
