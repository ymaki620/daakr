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
    //int len2 = predictor.size();
    if(len != predictor.size())return(-1.0);
    
    int cnt=0;
    for(int i=0;i<len;i++){
        if(response[i]==true)cnt++;
    }
    double s_t[cnt];
    double s_f[len-cnt];
    int p_t=0;
    int p_f=0;
    
    for(int i=0; i<len; i++){
        if(response[i]==true){
            s_t[p_t] = predictor[i];
            p_t++;
        }else{
            s_f[p_f] = predictor[i];
            p_f++;
        }
    }
    
    double auc=0.0;
    for(int i=0; i<cnt; i++){
        for(int j=0; j<len-cnt; j++){
            if(s_t[i] > s_f[j]){
                auc += 1.0;
            }else if(s_t[i] == s_f[j]){
                auc += 0.5;
            }
        }
    }
    auc = auc/double(cnt)/double(len-cnt);
    return(auc);
}
