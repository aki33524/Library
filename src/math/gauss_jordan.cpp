#include "template.cpp"

typedef vector<double> vec;
typedef vector<vec> mat;

vec gauss_jordan(mat& A){
    int m = A.size();
    int n = A[0].size();

    for(int i=0; i<m; i++){
        int pivot = i;
        for(int j=i; j<m; j++)
            if(abs(A[pivot][i]) < abs(A[j][i])) pivot = j;
        swap(A[i], A[pivot]);

        if(EQ(A[i][i], 0)) return vec();

        for(int j=i+1; j<n; j++)
            A[i][j] /= A[i][i];
        A[i][i] = 1; //for debugging

        for(int j=0; j<m; j++) if(i != j){
            for(int k=i+1; k<n; k++)
                A[j][k] -= A[j][i] * A[i][k];
            A[j][i] = 0; //for debugging
        }
    }
    vec res(m);
    for(int i=0; i<m; i++)
        res[i] = A[i][n-1];
    return res;
}
